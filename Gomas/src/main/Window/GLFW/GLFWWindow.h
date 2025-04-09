#include "../Window.h"
#include <GLFW/glfw3.h> 

namespace Gomas {

    class GOMAS_API GLFWWindow : Window {
    public:
        static GLFWWindow* Create(const WindowProps& props);
        GLFWWindow(const WindowProps& props);
        virtual ~GLFWWindow() override;

        virtual void OnUpdate() override;

        virtual int GetWidth() const override;
        virtual int GetHeight() const override;

        virtual void SetEventCallBack() override;
        virtual void SetVSync(bool enabled) override;
        virtual bool IsVSync() const override;



        GLFWwindow* GetNativeWindow() const;

    private:
        GLFWwindow* m_Window;
        int m_Width;
        int m_Height;
        bool m_VSync;
    };


}