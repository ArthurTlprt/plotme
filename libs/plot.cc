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

  std::string color;
  colorStream >> color;
  std::cout << "################################" << std::endl;
  std::cout << color << std::endl;
  std::cout << "################################" << std::endl;
  double ymin, ymax;
  yaxisStream >> ymin >> ymax;


  Local<Object> data = Object::New(isolate);
  Local<Object> points = Object::New(isolate);
  Local<Array> x = Array::New(isolate);
  Local<Array> y = Array::New(isolate);
  Local<Object> line = Object::New(isolate);

  Local<Array> yrange = Array::New(isolate);
  yrange->Set(0, Number::New(isolate, ymin));
  yrange->Set(1, Number::New(isolate, ymax));
  Local<Object> yaxis = Object::New(isolate);
  yaxis->Set(String::NewFromUtf8(isolate, "range"), yrange);
  Local<Boolean> autorange = Boolean::New(isolate, false);
  yaxis->Set(String::NewFromUtf8(isolate, "autorange"), autorange);

  double xf, yf;
  unsigned int i=0;
  while(xStream >> xf && yStream >> yf) {
    x->Set(i, Number::New(isolate, xf));
    y->Set(i, Number::New(isolate, yf));
    i++;
  }

  line->Set(String::NewFromUtf8(isolate, "color"), String::NewFromUtf8(isolate, color.c_str() ));
  points->Set(String::NewFromUtf8(isolate, "x"), x );
  points->Set(String::NewFromUtf8(isolate, "y"), y );
  data->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, "y = f(x)") );
  points->Set(String::NewFromUtf8(isolate, "line"), line);
  data->Set(String::NewFromUtf8(isolate, "yaxis"), yaxis);
  data->Set(String::NewFromUtf8(isolate, "points"), points);

  args.GetReturnValue().Set(data);
  //std::cout << "The parsing is done" << std::endl;
	return;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(parser, Init)
