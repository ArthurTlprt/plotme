var socket = io();

var send = function() {
  var equation = $('#input').val();
  console.log(equation);
  socket.emit('new plot', equation);
}
