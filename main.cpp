#include <cmake.h>
#include <algorithm>
#include <iostream>
// #include <boost/lambda/lambda.hpp>
#ifdef USE_HUMAN
    #include "Human.h"
#endif
#ifdef USE_GRAPHICS
    #include "GLFW/glfw3.h"
#endif

int main() {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;
    std::for_each(in(std::cin), in(), std::cout << (_1 * _1) << " " );
#ifdef USE_HUMAN
    Human h(3, "Aditya");
    h.show_age();
    h.show_name();
#endif
#ifdef USE_GRAPHICS
    glfwInit();
    GLFWwindow *w = glfwCreateWindow(640, 360, "HELLO WORLD !!!", NULL, NULL);
    glfwMakeContextCurrent(w);
    while(true) {
        glfwSwapBuffers(w);
        glfwPollEvents();
    } 
    glfwTerminate();
#endif
    return 0;
}