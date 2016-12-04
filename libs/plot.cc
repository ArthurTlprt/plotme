#include <node.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <unistd.h>


using v8::Exception;
using v8::FunctionCallbackInfo;
using v8::Isolate;
using v8::Local;
using v8::Number;
using v8::Object;
using v8::String;
using v8::Value;
using v8::Array;
using v8::Boolean;


void Evaluate(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

	String::Utf8Value param1(args[0]->ToString());
	std::string input = std::string(*param1);
  //std::cout << input << std::endl;

  std::ofstream equation("equation");
  equation << input << std::endl;
  equation.close();

  int systemMessage = std::system("./libs/run < equation");

  std::ifstream xStream("x");
  std::ifstream yStream("y");
  std::ifstream colorStream("color");
  std::ifstream yaxisStream("yaxis");
  std::ifstream errorStream("error");

  double ymin, ymax;
  yaxisStream >> ymin >> ymax;


  Local<Object> data = Object::New(isolate);
  Local<Array> traces = Array::New(isolate);
  std::string fileInput;
  std::vector<std::vector<double> > yss;
  std::vector<double> xs;
  std::vector<std::string> colors;
  unsigned int nbTrace=0;
  while (getline(colorStream, fileInput)) {
    colors.push_back(fileInput);
    nbTrace++;
  }
  double xf;
  {
    getline(xStream, fileInput);
    std::istringstream is(fileInput);
    while(is >> xf) {
      xs.push_back(xf);
    }
  }
  fileInput = "";
  std::string yf;
  while (getline(yStream, fileInput)) {
    std::istringstream is(fileInput);
    std::vector<double> ys;
    std::cout << "yf:" << std::endl;
    while(is >> yf) {
      std::cout << yf << std::endl;
      ys.push_back(std::stod(yf));
    }
    yss.push_back(ys);
  }
  for (unsigned int i = 0; i < nbTrace; i++) {
    Local<Object> points = Object::New(isolate);
    Local<Array> x = Array::New(isolate);
    Local<Array> y = Array::New(isolate);
    // insertion des x et y
    for(unsigned int j=0; j < xs.size(); j++) {
      x->Set(j, Number::New(isolate, xs[j]));
      y->Set(j, Number::New(isolate, yss[i][j]));
    }
    // // gestion couleur
    Local<Object> line = Object::New(isolate);
    std::string colorToAd = colors[i];
    line->Set(String::NewFromUtf8(isolate, "color"), String::NewFromUtf8(isolate, colorToAd.c_str() ));
    points->Set(String::NewFromUtf8(isolate, "line"), line);
    // ajout dans les tableau de tous les graphes
    points->Set(String::NewFromUtf8(isolate, "x"), x );
    points->Set(String::NewFromUtf8(isolate, "y"), y );
    traces->Set(i, points);
  }
  fileInput = "";
  std::string message = "";
  std::cout << "mesage:" << std::endl;
  while (getline(errorStream, fileInput)) {
    std::cout << fileInput << std::endl;
    message = message + fileInput + "<br>";
  }
  std::cout << message << std::endl;

  // yaxis control
  Local<Array> yrange = Array::New(isolate);
  yrange->Set(0, Number::New(isolate, ymin));
  yrange->Set(1, Number::New(isolate, ymax));
  Local<Object> yaxis = Object::New(isolate);
  yaxis->Set(String::NewFromUtf8(isolate, "range"), yrange);
  Local<Boolean> autorange = Boolean::New(isolate, false);
  yaxis->Set(String::NewFromUtf8(isolate, "autorange"), autorange);


  data->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, "y = f(x)") );
  data->Set(String::NewFromUtf8(isolate, "yaxis"), yaxis);
  data->Set(String::NewFromUtf8(isolate, "error"), String::NewFromUtf8(isolate, message.c_str()));
  data->Set(String::NewFromUtf8(isolate, "traces"), traces);

  args.GetReturnValue().Set(data);
  //std::cout << "The parsing is done" << std::endl;
	return;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(parser, Init)
