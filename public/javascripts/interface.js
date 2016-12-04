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
  //console.log(JSON.stringify(traces[0][0], 4, null));
  // var trace1 = {
  // x: [-1,-0.95,-0.9,-0.85,-0.8,-0.75,-0.7,-0.65,-0.6,-0.55,-0.5,-0.45,-0.4,-0.35,-0.3,-0.25,-0.2,-0.15,-0.1,-0.05,3.19189e-16,0.05,0.1,0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5,0.55,0.6,0.65,0.7,0.75,0.8,0.85,0.9,0.95],
  // y: [-1,-1.05263,-1.11111,-1.17647,-1.25,-1.33333,-1.42857,-1.53846,-1.66667,-1.81818,-2,-2.22222,-2.5,-2.85714,-3.33333,-4,-5,-6.66667,-10,-20,3132940000000000,20,10,6.66667,5,4,3.33333,2.85714,2.5,2.22222,2,1.81818,1.66667,1.53846,1.42857,1.33333,1.25,1.17647,1.11111,1.05263],
  // type: 'scatter'
  // };
  //traces[0].push(trace1);
  Plotly.newPlot('myDiv', traces[0], layout, {displayModeBar: false});
});
