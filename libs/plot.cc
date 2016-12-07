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

  std::ofstream equation("equation");
  equation << input << std::endl;
  equation.close();

  int systemMessage = std::system("./libs/run < equation");

  std::ifstream xStream("x");
  std::ifstream yStream("y");
  std::ifstream zStream("z");
  std::ifstream colorStream("color");
  std::ifstream yaxisStream("yaxis");
  std::ifstream titleStream("title");
  std::ifstream errorStream("error");

  double ymin, ymax;
  yaxisStream >> ymin >> ymax;


  Local<Object> data = Object::New(isolate);
  Local<Array> traces = Array::New(isolate);
  std::string fileInput;
  std::vector<std::vector<double> > yss;
  std::vector<double> xs;
  std::vector<double> zs;
  std::vector<std::string> colors;

  // check if file is empty
  if ( zStream.peek() == std::ifstream::traits_type::eof() ) {
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
      while(is >> yf) {
        ys.push_back(std::stod(yf));
      }
      yss.push_back(ys);
    }
    for (unsigned int i = 0; i < nbTrace; i++) {
      Local<Object> points = Object::New(isolate);
      Local<Array> x = Array::New(isolate);
      Local<Array> y = Array::New(isolate);
      // insertion des x et y
      for(unsigned int j=0; j < yss[0].size(); j++) {
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
    while (getline(errorStream, fileInput)) {
      message = message + fileInput + "<br>";
    }

    // yaxis control
    Local<Array> yrange = Array::New(isolate);
    yrange->Set(0, Number::New(isolate, ymin));
    yrange->Set(1, Number::New(isolate, ymax));
    Local<Object> yaxis = Object::New(isolate);
    yaxis->Set(String::NewFromUtf8(isolate, "range"), yrange);
    Local<Boolean> autorange = Boolean::New(isolate, false);
    yaxis->Set(String::NewFromUtf8(isolate, "autorange"), autorange);

    getline(titleStream, fileInput);
    data->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, fileInput.substr(0, fileInput.size()-1).c_str()) );
    data->Set(String::NewFromUtf8(isolate, "yaxis"), yaxis);
    data->Set(String::NewFromUtf8(isolate, "error"), String::NewFromUtf8(isolate, message.c_str()));
    data->Set(String::NewFromUtf8(isolate, "traces"), traces);

    args.GetReturnValue().Set(data);

  } else {
    // 3D
    std::string color;
    getline(colorStream, color);
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
    {
      getline(yStream, fileInput);
      std::istringstream is(fileInput);
      std::vector<double> ys;
      while(is >> yf) {
        ys.push_back(std::stod(yf));
      }
      yss.push_back(ys);
    }
    double zf;
    {
      getline(zStream, fileInput);
      std::istringstream is(fileInput);
      while(is >> zf) {
        zs.push_back(zf);
      }
    }
    Local<Object> points = Object::New(isolate);
    Local<Array> x = Array::New(isolate);
    Local<Array> y = Array::New(isolate);
    Local<Array> z = Array::New(isolate);
    // insertion des x et y
    for(unsigned int j=0; j < yss[0].size(); j++) {
      x->Set(j, Number::New(isolate, xs[j]));
      y->Set(j, Number::New(isolate, yss[0][j]));
      z->Set(j, Number::New(isolate, zs[j]));
    }
    // // gestion couleur
    std::string colorToAd = color;
    points->Set(String::NewFromUtf8(isolate, "color"), String::NewFromUtf8(isolate, colorToAd.c_str() ));
    // ajout dans les tableau de tous les graphes
    points->Set(String::NewFromUtf8(isolate, "x"), x );
    points->Set(String::NewFromUtf8(isolate, "y"), y );
    points->Set(String::NewFromUtf8(isolate, "z"), z );
    points->Set(String::NewFromUtf8(isolate, "type"), String::NewFromUtf8(isolate, "mesh3d") );
    traces->Set(0, points);
    fileInput = "";
    std::string message = "";
    while (getline(errorStream, fileInput)) {
      message = message + fileInput + "<br>";
    }

    // yaxis control
    Local<Array> yrange = Array::New(isolate);
    yrange->Set(0, Number::New(isolate, ymin));
    yrange->Set(1, Number::New(isolate, ymax));
    Local<Object> yaxis = Object::New(isolate);
    yaxis->Set(String::NewFromUtf8(isolate, "range"), yrange);
    Local<Boolean> autorange = Boolean::New(isolate, false);
    yaxis->Set(String::NewFromUtf8(isolate, "autorange"), autorange);


    getline(titleStream, fileInput);
    data->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, fileInput/*.substr(0, fileInput.size()-1)*/.c_str()) );
    data->Set(String::NewFromUtf8(isolate, "yaxis"), yaxis);
    data->Set(String::NewFromUtf8(isolate, "error"), String::NewFromUtf8(isolate, message.c_str()));
    data->Set(String::NewFromUtf8(isolate, "traces"), traces);
    args.GetReturnValue().Set(data);
  }

	return;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(parser, Init)
