#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>



// clang++ -std=c++11 -stdlib=libc++ -Wno-deprecated-declarations -lglfw -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon open_window.cpp

int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    int numberOfMonitors;
    GLFWmonitor**  monitors = glfwGetMonitors(&numberOfMonitors); // gets a list of your monitors
    std::cout << numberOfMonitors << "\n";


    int monitor_width, monitor_height;
    glfwGetMonitorPhysicalSize(glfwGetPrimaryMonitor(), &monitor_width, &monitor_height);
    std::cout << "height: " << monitor_height << " width: " << monitor_width << "\n";
    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(monitor_width, monitor_height, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
      std::cout << "error\n";

    std::cout << glGetString(GL_VERSION) << "\n"; // prints version and hardware



    float positions[6] = {-0.5f, -0.5f, 0.0f, 0.0f, 0.5f, -0.5f};
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 *sizeof(float), positions, GL_STATIC_DRAW);
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glDrawArrays(GL_TRIANGLES, 0, 3);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate(); // this needs to be called before program termination;
    return 0;
}
