#include "route.h"

#include "filters/log.h"
#include "filters/auth.h"

#include "controllers/home.h"
#include "controllers/about.h"
#include "controllers/static.h"


void configureRoute(HttpServer& s) {
    s.registerFilter(createLoggingFilter());
    s.registerFilter(createAuthenticationFilter());

    s.registerController(createStaticController("static"));
    s.registerController(createHomeController());
    s.registerController(createAboutController());
}