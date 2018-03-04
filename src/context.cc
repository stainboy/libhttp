#include "include/libhttp.h"
#include <iostream>

class HttpContextImpl : public HttpContext {
public:
    HttpContextImpl() {
    }
public:

};


std::unique_ptr<HttpContext> createHttpContext() {
    // return std::unique_ptr<HttpContext>(new HttpContextImpl());
    return nullptr;
}
