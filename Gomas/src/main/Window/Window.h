#pragma once

#include "../Core/Base.h"
#include <string>

namespace Gomas {


    struct WindowProps {
        std::string Title;
        unsigned int Width;
        unsigned int Height;

        WindowProps(const std::string& title = "MainWindow",
            unsigned int height = 720,
            unsigned int width = 1280)
            : Title(title), Height(height), Width(width) {
        }

    };


    class GOMAS_API Window {

    public:
        Window() {}
        virtual ~Window() {}

        virtual void OnUpdate() = 0;

        virtual int GetWidth() const = 0;
        virtual int GetHeight() const = 0;

        virtual void SetEventCallBack() = 0;
        virtual void SetVSync(bool enambled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());

	};


}
