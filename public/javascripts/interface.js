var socket = io();

var send = function() {
  var equation = $('#input').val();
  console.log(equation);
  socket.emit('new plot', equation);
}

socket.on("result", function(data) {
  var traces = [data.traces];

  var layout = {
    title: data.title,
    showlegend: true,
    yaxis: data.yaxis
  };
  console.log(JSON.stringify(traces[0][0], 4, null));
  Plotly.newPlot('myDiv', traces[0], layout, {displayModeBar: false});
});
