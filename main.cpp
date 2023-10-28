#include "Human.h"
#include "GLFW/glfw3.h"
#include "cmake.h"

int main(int argc, char* argcv[])
{
  GLFWwindow *windows;
  const char *description;
  if (!glfwInit())
  {
    glfwGetError(&description);
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
  }

  std::cout << argcv[0] << " Version " << cmake_VERSION_MAJOR << "." << cmake_VERSION_MINOR << "\n";

  // Human *h = new Human(1, "Aditya");
  // h->show_age();
  // h->show_name();
  // delete h;

  windows = glfwCreateWindow(300, 300, "Multi-Window Example", NULL, NULL);
  while (true)
  {
    glfwMakeContextCurrent(windows);
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(windows);

    if (glfwWindowShouldClose(windows) ||
        glfwGetKey(windows, GLFW_KEY_ESCAPE))
    {
      glfwTerminate();
      exit(EXIT_SUCCESS);
    }

    glfwWaitEvents();
  }

  return 0;
}
