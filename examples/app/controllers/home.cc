#include "home.h"


class HomeController : public Controller {
public:
    HomeController() :
    _name("HomeController"),
    _root("/") {
    }
private:
    std::string _name;
    std::string _root;
public:
    const std::string& name() const {
        return this->_name;
    }
    const std::string& root() const {
        return this->_root;
    }
    void serve(const HttpContext& context) const {
        context.response().statusCode(200);
        context.response().header("Content-Type", "text/plain");
        context.response().write("Hello libhttp!");
    }
};

std::unique_ptr<Controller> createHomeController() {
    return std::unique_ptr<Controller>(new HomeController());
}
