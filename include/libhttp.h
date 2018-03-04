#pragma once
#include <memory>
#include <string>


class Filter;
class Controller;
class HttpContext;
class HttpServer;
class HttpRequest;
class HttpResponse;
class HttpSession;
std::unique_ptr<HttpServer> createDefaultServer(const std::string& address);




class HttpServer {
public:
    virtual int run() = 0;
    virtual void registerFilter(std::unique_ptr<Filter> filter) = 0;
    virtual void registerController(std::unique_ptr<Controller> controller) = 0;
};

class Filter {
public:
    virtual const std::string& name() const = 0;
    virtual bool apply(const HttpContext& context, bool incoming) = 0;
};

class Controller {
public:
    virtual const std::string& name() const = 0;
    virtual const std::string& root() const = 0;
    virtual void serve(const HttpContext& context) const = 0;
};

class HttpContext {
public:
    virtual const HttpRequest& request() const = 0;
    virtual HttpResponse& response() const = 0;
    virtual HttpSession& session() const = 0;
};

class HttpRequest {
public:
    virtual const std::string toString() const = 0;
    virtual const std::string mapPath(const std::string& server, const std::string& local) const = 0;
    // TODO:
};

class HttpResponse {
public:
    virtual void statusCode(const unsigned short code) = 0;
    virtual unsigned short statusCode() const = 0;
    virtual void header(const std::string& key, const std::string& value) = 0;
    virtual void write(const std::string& body) = 0;
    virtual void writeFile(const std::string& path) = 0;
};

class HttpSession {
public:
    // TODO:
};