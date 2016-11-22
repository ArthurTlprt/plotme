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


void Evaluate(const FunctionCallbackInfo<Value>& args) {
  Isolate* isolate = args.GetIsolate();

	String::Utf8Value param1(args[0]->ToString());
	std::string input = std::string(*param1);
  //std::cout << input << std::endl;

  std::ofstream equation("equation");
  equation << input << std::endl;
  equation.close();

  int systemMessage = std::system("./libs/run < equation");
  // if(systemMessage == -1) {
  //   std::cout << "ça marche po" << std::endl;
  // } else {
  //   std::cout << "En Marche! " << std::endl;
  // }
  //std::cout << systemMessage << std::endl;
  std::ifstream xStream("x");
  std::ifstream yStream("y");

  // std::string xs, ys;
  //
  // getline(xStream, xs);
  // getline(yStream, ys);
  // std::cout << "xs: " << xs << std::endl;
  // std::cout << "ys: " << ys << std::endl;

  Local<Object> coord = Object::New(isolate);
  Local<Array> x = Array::New(isolate);
  Local<Array> y = Array::New(isolate);

  double xf, yf;
  unsigned int i=0;
  while(xStream >> xf && yStream >> yf) {
    x->Set(i, Number::New(isolate, xf));
    y->Set(i, Number::New(isolate, yf));
    i++;
  }

  coord->Set(String::NewFromUtf8(isolate, "x"), x );
  coord->Set(String::NewFromUtf8(isolate, "y"), y );
  coord->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, "y = f(x)") );

  args.GetReturnValue().Set(coord);
  //std::cout << "The parsing is done" << std::endl;
	return;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(parser, Init)
