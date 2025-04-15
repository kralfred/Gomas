
#include "GLFWWindow.h"
#include "main/Core/Logging/Log.h"
#include "../../Core/KeyCodes.h"

namespace Gomas {

    KeyCode GLFWKeyToGomasKey(int keycode)
    {
        switch (keycode)
        {
        case GLFW_KEY_SPACE:        return key::Space;
        case GLFW_KEY_APOSTROPHE:   return key::Apostrophe;
        case GLFW_KEY_COMMA:        return key::Comma;
        case GLFW_KEY_MINUS:        return key::Minus;
        case GLFW_KEY_PERIOD:       return key::Period;
        case GLFW_KEY_SLASH:        return key::Slash;
        case GLFW_KEY_0:            return key::D0;
        case GLFW_KEY_1:            return key::D1;
        case GLFW_KEY_2:            return key::D2;
        case GLFW_KEY_3:            return key::D3;
        case GLFW_KEY_4:            return key::D4;
        case GLFW_KEY_5:            return key::D5;
        case GLFW_KEY_6:            return key::D6;
        case GLFW_KEY_7:            return key::D7;
        case GLFW_KEY_8:            return key::D8;
        case GLFW_KEY_9:            return key::D9;
        case GLFW_KEY_SEMICOLON:    return key::Semicolon;
        case GLFW_KEY_EQUAL:        return key::Equal;
        case GLFW_KEY_A:            return key::A;
        case GLFW_KEY_B:            return key::B;
        case GLFW_KEY_C:            return key::C;
        default:                    return key::Unknown;
        }
    }


    GLFWWindow* GLFWWindow::Create(const WindowProps& props)
    {
        GM_CORE_INFO("Creating GLFW window {0} ({1}, {2})", props.Title, props.Width, props.Height);


        if (!glfwInit())
        {
            GM_CORE_ERROR("Could not initialize GLFW!");
            return nullptr;

        }

        GLFWwindow* window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
        if (!window)
        {
            GM_CORE_ERROR("Could not create GLFW window!");
            glfwTerminate();
            return nullptr;
        }

        GLFWWindow* glfwWindow = new GLFWWindow(props);
        glfwWindow->m_Window = window;
        glfwWindow->m_Width = props.Width;
        glfwWindow->m_Height = props.Height;
        glfwWindow->m_VSync = true;
        glfwSwapInterval(1);       

        glfwSetWindowUserPointer(window, glfwWindow);

        return glfwWindow;
    }

    GLFWWindow::GLFWWindow(const WindowProps& props)

    {
    }

    GLFWWindow::~GLFWWindow()
    {
        glfwDestroyWindow(m_Window);

    }

    void GLFWWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void GLFWWindow::SetEventCallBack()
    {

    }

    void GLFWWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);
        m_VSync = enabled;
    }

    int GLFWWindow::GetWidth() const
    {
        return m_Width;
    }

    int GLFWWindow::GetHeight() const
    {
        return m_Height;
    }

    bool GLFWWindow::IsVSync() const
    {
        return m_VSync;
    }


    GLFWwindow* GLFWWindow::GetNativeWindow() const
    {
        return m_Window;
    }

}