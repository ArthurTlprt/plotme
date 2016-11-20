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

  std::string command_line = "./libs/run < " + input;
  std::system(command_line.c_str());

  std::ifstream stream("libs/evaluation");

  std::string xs, ys;

  getline(stream, xs); //On lit une ligne complète
  getline(stream, ys);
  std::cout << "xs: " << xs << std::endl;

  Local<Object> coord = Object::New(isolate);
  Local<Array> x = Array::New(isolate);
  Local<Array> y = Array::New(isolate);

  for(unsigned int i=0; i < 100; i++) {
    x->Set(i, Number::New(isolate, i));
    y->Set(i, Number::New(isolate, i*i));
  }

  coord->Set(String::NewFromUtf8(isolate, "x"), x );
  coord->Set(String::NewFromUtf8(isolate, "y"), y );
  coord->Set(String::NewFromUtf8(isolate, "title"), String::NewFromUtf8(isolate, "y = f(x)") );

  args.GetReturnValue().Set(coord);
  std::cout << "The parsing is done" << std::endl;
	return;
}

void Init(Local<Object> exports) {
  NODE_SET_METHOD(exports, "evaluate", Evaluate);
}

NODE_MODULE(parser, Init)
