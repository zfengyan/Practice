#include<iostream>
#include<vector>
#include<limits>
#include<Eigen/Dense>
#include<Eigen/Core>
#include"Geometry.h"

#include<GLFW/glfw3.h>

// https://en.wikipedia.org/wiki/Kahan_summation_algorithm
// https://github.com/delfrrr/delaunator-cpp/tree/master/include
// @brief: calculate the sum of all items in a vector

double sum(const std::vector<double>& x) {
    double sum = x[0];
    double err = 0.0;

    for (std::size_t i = 1; i < x.size(); ++i) {
        const double k = x[i];
        const double m = sum + k;
        err += std::fabs(sum) >= std::fabs(k) ? sum - m + k : k - m + sum;
        sum = m;
    }
    return sum + err;
}


// orient:
// @brief: if CW return 0 else(CCW) return 1
bool orient(
    const double px,
    const double py,
    const double qx,
    const double qy,
    const double rx,
    const double ry) {
    return (qy - py) * (rx - qx) - (qx - px) * (ry - qy) < 0.0;
}


std::pair<double, double> circumcenter(
    const double ax,
    const double ay,
    const double bx,
    const double by,
    const double cx,
    const double cy) {
    const double dx = bx - ax;
    const double dy = by - ay;
    const double ex = cx - ax;
    const double ey = cy - ay;

    const double bl = dx * dx + dy * dy;
    const double cl = ex * ex + ey * ey;
    const double d = dx * ey - dy * ex;

    const double x = ax + (ey * bl - dy * cl) * 0.5 / d;
    const double y = ay + (dx * cl - ex * bl) * 0.5 / d;

    return std::make_pair(x, y);
}


double verlet(double pos, double acc, double dt) {

    double prev_pos = pos;
    double time = 0;

    while (pos > 0) {
        time += dt;
        double next_pos = pos * 2 - prev_pos + acc * dt * dt;
        prev_pos = pos;
        pos = next_pos;
    }

    return time;
}


int main(int argc, const char** argv) {

    /* Initialize the window pointer with nullptr */
    GLFWwindow* window(nullptr);

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* User Modification */
        glBegin(GL_TRIANGLES);
        glVertex2f(-0.5f, -0.5f);
        glVertex2f(0.0f, 0.5f);
        glVertex2f(0.5f, -0.5f);
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    
    return 0;
}