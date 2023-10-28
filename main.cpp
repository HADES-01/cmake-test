#include "Human.h"
#include <GLFW/glfw3.h>

int main()
{
  GLFWwindow *windows;
  const char *description;
  if (!glfwInit())
  {
    glfwGetError(&description);
    printf("Error: %s\n", description);
    exit(EXIT_FAILURE);
  }
  Human *h = new Human(1, "Aditya");
  h->show_age();
  h->show_name();
  delete h;
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
