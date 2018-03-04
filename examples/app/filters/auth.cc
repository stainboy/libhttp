#include "auth.h"
#include <iostream>


class AuthenticationFilter : public Filter {
public:
    AuthenticationFilter() :
    _name("AuthenticationFilter") {
    }
private:
    std::string _name;
public:
    const std::string& name() const {
        return this->_name;
    }
    bool apply(const HttpContext& context, bool incoming) {
        // TODO:
        if (incoming) {
            std::cout << context.request().toString() << std::endl;
        }
        return true;
    }
};

std::unique_ptr<Filter> createAuthenticationFilter() {
    return std::unique_ptr<Filter>(new AuthenticationFilter());
}