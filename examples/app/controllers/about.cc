#include "about.h"


class AboutController : public Controller {
public:
    AboutController() :
    _name("AboutController"),
    _root("/about") {
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
        context.response().header("Content-Type", "text/html");
        context.response().write("<h1>About Me</h1>");
    }
};

std::unique_ptr<Controller> createAboutController() {
    return std::unique_ptr<Controller>(new AboutController());
}
