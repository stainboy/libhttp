#include "include/libhttp.h"
#include <iostream>

class HttpRequestImpl : public HttpRequest {
public:
    HttpRequestImpl() {
    }
public:

};


std::unique_ptr<HttpRequest> createHttpRequest() {
    // return std::unique_ptr<HttpRequest>(new HttpRequestImpl());
    return nullptr;
}
