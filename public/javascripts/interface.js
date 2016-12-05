var socket = io();

var send = function() {
  var equation = $('#input').val();
  console.log(equation);
  socket.emit('new plot', equation);
  $("#output").empty();
}

socket.on("result", function(data) {
  var traces = [data.traces];

  var layout = {
    title: data.title,
    showlegend: true,
    yaxis: data.yaxis
  };
  console.log(data.error);
  $('#output').append(data.error);
  Plotly.newPlot('myDiv', traces[0], layout, {displayModeBar: false});
});
