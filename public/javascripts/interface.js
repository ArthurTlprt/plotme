var socket = io();

var send = function() {
  var equation = $('#input').val();
  console.log(equation);
  socket.emit('new plot', equation);
}

socket.on("result", function(points) {
  var data = [points];

  var layout = {
    title: points.title,
    showlegend: true,
    yaxis: {
      range: points.range,
      autorange: points.autorange
    }
  };
  Plotly.newPlot('myDiv', data, layout, {displayModeBar: false});
  console.log(points);
});
