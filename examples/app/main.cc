#include "include/libhttp.h"
#include "route.h"

int main() {
    auto s = createDefaultServer("0.0.0.0:8000");
    configureRoute(*s);
    return s->run();
}