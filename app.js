var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');

var routes = require('./routes/index');

var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);


const parser = require('./libs/build/Release/parser');

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'pug');

// uncomment after placing your favicon in /public
//app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', routes);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  var err = new Error('Not Found');
  err.status = 404;
  next(err);
});

// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
  app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
      message: err.message,
      error: err
    });
  });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
  res.status(err.status || 500);
  res.render('error', {
    message: err.message,
    error: {}
  });
});

// partie connexion asynchrone

io.on('connection', function(socket){
  socket.on('new plot', function(equation) {
    console.log("the server gets an equation from the client");
    console.log(equation);
    points = parser.evaluate(equation);
    console.log("the server says the parser result is " + JSON.stringify(points, 4, null));
    socket.emit('result', points);
    console.log("the server emit the evaluation");
  });
});

var host = process.env.VCAP_APP_HOST || process.env.HOST || '0.0.0.0';
var port = process.env.VCAP_APP_PORT || process.env.PORT || 3000;

http.listen({
  host: host,
  port: port
}, function(){
  console.log('-----------------------------------');
  console.log('   listening on *:' + port);
  console.log('-----------------------------------');
});

module.exports = app;
