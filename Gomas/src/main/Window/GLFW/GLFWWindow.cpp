
#include "GLFWWindow.h"
#include "main/Core/Logging/Log.h"

namespace Gomas {

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