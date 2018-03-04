#include "include/libhttp.h"
#include <iostream>
#include <uv.h>

class HttpServerImpl : public HttpServer {
public:
    HttpServerImpl(const std::string& address) :
    _address(address) {
    }
private:
    std::string _address;
    uv_loop_t *loop;
public:
    int run() {
        return on_uv_run();
    }
    void registerFilter(std::unique_ptr<Filter> filter) {
        std::cout << "Registering filter -> " << filter->name() << std::endl;
    }
    void registerController(std::unique_ptr<Controller> controller) {
        std::cout << "Registering controller -> " << controller->name() << " (" << controller->root() << ")" << std::endl;
    }
private:
    int on_uv_run() {
        loop = uv_default_loop();
        uv_tcp_t server;
        uv_tcp_init(loop, &server);

        struct sockaddr_in bind_addr;
        uv_ip4_addr("0.0.0.0", 8000, &bind_addr);
        uv_tcp_bind(&server, (const struct sockaddr *)&bind_addr, 0);

        server.data = this;
        int r = uv_listen((uv_stream_t*) &server, 128, [] (uv_stream_t * stream, int status) {
            HttpServerImpl* p = (HttpServerImpl*)stream->data;
            p->on_new_connection(stream, status);
        });
        if (r) {
            std::cerr << "Listen error!" << std::endl;
            return 1;
        }
        std::cout << "Http server is running on " << this->_address << std::endl;
        return uv_run(loop, UV_RUN_DEFAULT);
    }
    void on_new_connection(uv_stream_t *server, int status) {
        if (status == -1) {
            return;
        }

        uv_tcp_t *client = (uv_tcp_t*) malloc(sizeof(uv_tcp_t));
        uv_tcp_init(loop, client);
        if (uv_accept(server, (uv_stream_t*) client) == 0) {
            // uv_read_start((uv_stream_t*) client, alloc_buffer, echo_read);
        }
        else {
            uv_close((uv_handle_t*) client, NULL);
        }
    }
    void echo_read(uv_stream_t *client, ssize_t nread, uv_buf_t buf) {
        if (nread == -1) {
            fprintf(stderr, "Read error!\n");
            uv_close((uv_handle_t*)client, NULL);
            return;
        }

        uv_write_t *write_req = (uv_write_t*)malloc(sizeof(uv_write_t));
        write_req->data = (void*)buf.base;
        buf.len = nread;
        // uv_write(write_req, client, &buf, 1, echo_write);
    }
    void echo_write(uv_write_t *req, int status) {
        if (status == -1) {
            fprintf(stderr, "Write error!\n");
        }
        char *base = (char*) req->data;
        free(base);
        free(req);
    }
    // inline uv_buf_t alloc_buffer(uv_handle_t *handle, size_t suggested_size) {
    //     return uv_buf_init((char*) malloc(suggested_size), suggested_size);
    // }
};


std::unique_ptr<HttpServer> createDefaultServer(const std::string& address) {
    return std::unique_ptr<HttpServer>(new HttpServerImpl(address));
}
