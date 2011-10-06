// Copyright 2011 Bruno Jouhier <bjouhier@gmail.com>
#ifndef CURSOR_H_
#define CURSOR_H_

#include <stdlib.h>
#include <node.h>
#include <node_buffer.h>
#include <node_events.h>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
#include <vector>
#include "./node_defs.h"
#include "./connection.h"
#include "./query.h"
#include "./exception.h"
#include "./result.h"

namespace node_db {
class Cursor : public node::ObjectWrap {
    public:
        static void Init(v8::Handle<v8::Object> target, v8::Persistent<v8::FunctionTemplate> constructorTemplate);
    protected:
        v8::Persistent<v8::Function>* cbNext;

        Cursor(Query* query, Result* result);
        ~Cursor();
        static v8::Handle<v8::Value> Next(const v8::Arguments& args);
    private:
        Query* query;
        Result* result;
};
}

#endif  // CURSOR_H_