#include "include/libhttp.h"
#include <iostream>

class HttpResponseImpl : public HttpResponse {
public:
    HttpResponseImpl() {
    }
public:

};


std::unique_ptr<HttpResponse> createHttpResponse() {
    // return std::unique_ptr<HttpResponse>(new HttpResponseImpl());
    return nullptr;
}
