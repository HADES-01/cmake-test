#include <cmake.h>
#ifdef USE_HUMAN
    #include "Human.h"
#endif
#ifdef USE_GRAPHICS
    #include "GLFW/glfw3.h"
#endif

int main() {
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