#include "log.h"
#include <iostream>


class LoggingFilter : public Filter {
public:
    LoggingFilter() :
    _name("LoggingFilter") {
    }
private:
    std::string _name;
public:
    const std::string& name() const {
        return this->_name;
    }
    bool apply(const HttpContext& context, bool incoming) {
        if (incoming) {
            std::cout << "Begin of http request -> " << context.request().toString() << std::endl;
        } else {
            std::cout << "End of http request -> " << context.request().toString() 
              << " (" << context.response().statusCode() << ")" << std::endl;
        }
        return true;
    }
};

std::unique_ptr<Filter> createLoggingFilter() {
    return std::unique_ptr<Filter>(new LoggingFilter());
}