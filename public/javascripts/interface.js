var socket = io();

var send = function() {
  var equation = $('#input').val();
  console.log(equation);
  socket.emit('new plot', equation);
}

socket.on("result", function(data) {
  var trace1 = [data.points];
  console.log(data.points.x);
  console.log(data.points.y);
  var layout = {
    title: data.title,
    showlegend: true,
    yaxis: data.yaxis
  };
  console.log(JSON.stringify(data, 4, null));
  //console.log(points.yaxis);
  Plotly.newPlot('myDiv', trace1, layout, {displayModeBar: false});
});
