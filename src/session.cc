#include "include/libhttp.h"
#include <iostream>

class HttpSessionImpl : public HttpSession {
public:
    HttpSessionImpl() {
    }
public:

};


std::unique_ptr<HttpSession> createHttpSession() {
    // return std::unique_ptr<HttpSession>(new HttpSessionImpl());
    return nullptr;
}
