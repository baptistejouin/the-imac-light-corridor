#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "game.h"
#include "3D_tools.h"

/* Window properties */
extern unsigned int WINDOW_WIDTH = 1280;
extern unsigned int WINDOW_HEIGHT = 720;
extern unsigned int CAMERA_ZOOM = 10;
extern float FOV = 60.0f;
static const char WINDOW_TITLE[] = "The IMAC light corridor";
static float aspectRatio = 1.0;

/* Minimal time wanted between two images */
static const double FRAMERATE_IN_SECONDS = 1. / 120.;

/* Error handling function */
void onError(int error, const char *description)
{
    fprintf(stderr, "GLFW Error: %s\n", description);
}

void onWindowResized(GLFWwindow *window, int width, int height)
{
    aspectRatio = width / (float)height;

    int fbWidth, fbHeight;
    glfwGetFramebufferSize(window, &fbWidth, &fbHeight);
    glViewport(0, 0, fbWidth, fbHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    WINDOW_WIDTH = width;
    WINDOW_HEIGHT = height;

    gluPerspective(FOV, aspectRatio, Z_NEAR, Z_FAR);

    glMatrixMode(GL_MODELVIEW);
}

void onKey(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    // press or hold
    if (action == GLFW_PRESS || action == GLFW_REPEAT)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
            glfwSetWindowShouldClose(window, GLFW_TRUE);
            break;
        case GLFW_KEY_L:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case GLFW_KEY_P:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        case GLFW_KEY_O:
            // only for debug
            if (cam_x == 0.0f)
            {
                cam_x = 2.0f;
                cam_y = 15.0f;
                cam_z = 15.0f;
            }
            else
            {
                cam_x = 0.0f;
                cam_y = 0.0f;
                cam_z = 0.0f;
            }
            break;
        // add controls cam with directionals arrows
        case GLFW_KEY_UP:
            if (mods == GLFW_MOD_SHIFT)
            {
                cam_z += 1.0f;
                break;
            }
            cam_x -= 1.0f;
            break;
        case GLFW_KEY_DOWN:
            if (mods == GLFW_MOD_SHIFT)
            {
                cam_z -= 1.0f;
                break;
            }
            cam_x += 1.0f;
            break;
        case GLFW_KEY_LEFT:
            cam_y += 1.0f;
            break;
        case GLFW_KEY_RIGHT:

            cam_y -= 1.0f;
            break;
        default:
            fprintf(stdout, "Touche \"%d\" non gérée\n", key);
        }
    }
}

int main(int argc, char **argv)

{
    /* GLFW initialisation */
    GLFWwindow *window;
    if (!glfwInit())
        return -1;

    /* Callback to a function if an error is rised by GLFW */
    glfwSetErrorCallback(onError);

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (!window)
    {
        // If no context created : exit !
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glfwSetWindowSizeCallback(window, onWindowResized);
    glfwSetWindowAspectRatio(window, 16, 9);
    glfwSetKeyCallback(window, onKey);

    onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);

    glPointSize(5.0);
    glEnable(GL_DEPTH_TEST);

    // random seed
    srand(time(0));

    Game *game = new Game;
    initGame(game);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Get time (in second) at loop beginning */
        double startTime = glfwGetTime();

        /* Cleaning buffers and setting Matrix Mode */
        glClearColor(0.0, 0.0, 0.2, 0.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        setCamera();

        /* RENDER HERE */
        gameLoop(window, game);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        /* Elapsed time computation from loop begining */
        double elapsedTime = glfwGetTime() - startTime;
        /* If to few time is spend vs our wanted FPS, we wait */
        if (elapsedTime < FRAMERATE_IN_SECONDS)
        {
            glfwWaitEventsTimeout(FRAMERATE_IN_SECONDS - elapsedTime);
        }
    }

    glfwTerminate();
    return 0;
}