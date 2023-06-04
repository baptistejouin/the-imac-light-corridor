#define GLFW_INCLUDE_NONE
#define STB_IMAGE_IMPLEMENTATION

#include <GLFW/glfw3.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "game.h"

/* Window properties */
extern unsigned int WINDOW_WIDTH = 1280;
extern unsigned int WINDOW_HEIGHT = 720;
extern unsigned int CAMERA_ZOOM = 10;
extern float FOV = 60.0f;
static const char WINDOW_TITLE[] = "The IMAC light corridor";
static float aspectRatio = 1.0;
Game *game = new Game;

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
    if (action == GLFW_PRESS)
    {
        switch (key)
        {
        case GLFW_KEY_ESCAPE:
            closeGame(game);

            break;
        case GLFW_KEY_L:
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
            break;
        case GLFW_KEY_P:
            if (game->status == GameStatus::MENU)
                game->status = GameStatus::IN_GAME;
            break;
        case GLFW_KEY_A: // Q for AZERTY
            if (game->status == GameStatus::MENU || game->status == GameStatus::GAME_OVER)
                closeGame(game);
            break;
        case GLFW_KEY_R:
            if (game->status == GameStatus::GAME_OVER)
                resetGame(game);
            break;
        case GLFW_KEY_SPACE:
            game->isMoving = true;
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
            break;
        }
    }
    if (action == GLFW_REPEAT)
    {
        switch (key)
        {
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
            break;
        }
    }
    if (action == GLFW_RELEASE)
    {
        switch (key)
        {
        case GLFW_KEY_SPACE:
            game->isMoving = false;
            break;
        case GLFW_KEY_L:
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
            break;
        default:
            break;
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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);
    glfwSetKeyCallback(window, onKey);

    onWindowResized(window, WINDOW_WIDTH, WINDOW_HEIGHT);

    glPointSize(5.0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // random seed
    srand(time(0));

    game->window = window;

    initGame(game);
    initTextures(game);

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
    printf("Game closed\n");
    return 0;
}