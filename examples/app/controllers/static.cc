#include "static.h"


class StaticController : public Controller {
public:
    StaticController(const std::string& dir) :
    _name("StaticController"),
    _root("/static/"),
    _dir(dir) {
    }
private:
    std::string _name;
    std::string _root;
    std::string _dir;
public:
    const std::string& name() const {
        return this->_name;
    }
    const std::string& root() const {
        return this->_root;
    }
    void serve(const HttpContext& context) const {
        std::string path = context.request().mapPath(this->_root, this->_dir);
        context.response().writeFile(path);
    }
};

std::unique_ptr<Controller> createStaticController(const std::string& dir) {
    return std::unique_ptr<Controller>(new StaticController(dir));
}
