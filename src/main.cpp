#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

#include "graphics/shaderProgram.h"
#include "graphics/textureManager.h"
#include "math/vec2f.h"
#include "graphics/renderer.h"
#include "graphics/sprite.h"
#include "graphics/image.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main(){
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    TextureManager testTextureManager;
    View testView({0.0f, 0.0f}, {800.0f, 600.0f});

    Renderer testRenderer(&testTextureManager, testView);

    testTextureManager.loadTexture(TEST_TEXTURE2_LOCATION);
    testTextureManager.loadTexture(TEST_TEXTURE3_LOCATION);

    Sprite testSprite(TEST_TEXTURE2_LOCATION);
    testSprite.setPosition({100.0f, 100.0f});
    testSprite.setSize({67.0f, 62.0f});
    testSprite.setColor({1.0f, 1.0f, 1.0f, 1.0f});
    testSprite.generateQuads({0.0f, 0.0f}, {201.0f, 251.0f}, 4, 3);


    Image testImage(TEST_TEXTURE3_LOCATION, {80.0f, 80.0f}, {180.0f, 220.0f});
    testImage.setPosition({300.0f, 300.0f});
    testImage.setSize({100.0f, 100.0f});
    testImage.setColor({0.0f, 1.0f, 1.0f, 1.0f});


    short i = 0;
    // render loop
    // -----------
    while (!glfwWindowShouldClose(window)){
        // input
        // -----
        processInput(window);

        i++;
        if(i > 60){
            i = 0;
            testSprite.nextQuad();
        } 
        
        
        testRenderer.clear();
        testRenderer.renderQuad(testSprite, testSprite.getTexture());
        testRenderer.renderQuad(testImage, testImage.getTexture());
        testRenderer.render();
        

        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window){
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}