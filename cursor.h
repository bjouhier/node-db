// Copyright 2011 Bruno Jouhier <bjouhier@gmail.com>
#ifndef CURSOR_H_
#define CURSOR_H_

#include <stdlib.h>
#include <stdio.h>
#include <node.h>
#include <node_buffer.h>
//#include <node_events.h>
#include <algorithm>
#include <cctype>
#include <string>
#include <sstream>
#include "./node_defs.h"
#include "./connection.h"
#include "./query.h"
#include "./exception.h"
#include "./result.h"

namespace node_db {
class Cursor : public node::ObjectWrap {
    public:
		static v8::Persistent<v8::FunctionTemplate> constructorTemplate;
        static void Init(v8::Handle<v8::Object> target);
        //
		void setQuery(Query* q);
		void setResult(Result* r);
		//
        Cursor();
        ~Cursor();
    protected:
        struct execute_request_t {
            v8::Persistent<v8::Object> context;
            Cursor* cursor;
            Query* query;
            Result *result;
	        v8::Persistent<v8::Function>* cbNext;
            const char* error;
            uint16_t columnCount;
            bool buffered;
            Query::row_t* row;
        };
        static v8::Handle<v8::Value> New(const v8::Arguments& args);

        static v8::Handle<v8::Value> Next(const v8::Arguments& args);
        //
        static void eioNext(uv_work_t* eioRequest);
        static void eioNextFinished(uv_work_t* eioRequest, int dummy);
		//
        static void freeRequest(execute_request_t* request, bool freeAll = true);
    private:
        Query* query;
        Result* result;
    	uint64_t rowIndex;
};
}

#endif  // CURSOR_H_
