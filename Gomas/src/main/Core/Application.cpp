#pragma once

#include "Base.h"
#include "Application.h"


#include "../Events/Event.h" // Your Events.h header
#include <iostream>
#include <conio.h> // For _getch() on Windows
#include <thread>
#include <chrono>
#include "../Events/KeyEvent.h"
#include "../Events/MouseEvent.h"
#include <GLFW/glfw3.h>
#include "main/Window/GLFW/GLFWWindow.h"
#include "../tinyrenderer/tgaimage.h"


namespace Gomas {


	Application::Application() {

	}
	Application::~Application() {

	}

    const TGAColor white = TGAColor(255, 255, 255, 255);
    const TGAColor red = TGAColor(255, 0, 0, 255);

	void Application::Run()
	{
        TGAImage image2(100, 100, TGAImage::RGB);

        for (size_t i = 0; i < 50; i++)
        {
            
            image2.set(52, 40 + i, red);
        }

        image2.write_tga_file("output2.tga");



        Gomas::WindowProps& Main = Gomas::WindowProps("asd", 800, 1200);
        Gomas::GLFWWindow::Create(Main);


        std::cout << "Press keys and mouse buttons to generate events (press ESC to exit)." << std::endl;

        while (true) {
            if (_kbhit()) { // Check for keyboard input
                int key = _getch(); // Get the key code

                if (key == 27) { // ESC key
                    break;
                }

                std::cout << key << "  was pressed";

                // Simulate key press and release events
                KeyPressedEvent keyPressed(static_cast<KeyCode>(key));
                EventDispatcher keyPressedDispatcher(keyPressed);
                keyPressedDispatcher.Dispatch<KeyPressedEvent>([&](KeyPressedEvent& event) {
                    std::cout << "Key Pressed: " << static_cast<int>(event.GetKeyCode()) << " (Repeat: " << event.IsRepeat() << ")" << std::endl;
                    return true;
                    });

                KeyReleasedEvent keyReleased(static_cast<KeyCode>(key));
                EventDispatcher keyReleasedDispatcher(keyReleased);
                keyReleasedDispatcher.Dispatch<KeyReleasedEvent>([&](KeyReleasedEvent& event) {
                    std::cout << "Key Released: " << static_cast<int>(event.GetKeyCode()) << std::endl;
                    return true;
                    });
            }

            // Simulate mouse button press and release events (for demonstration)
            // You'd typically get these from a windowing library or input API.
            if (rand() % 100 == 0) {
                MouseButtonPressedEvent mousePressed(Mouse::ButtonLeft);
                EventDispatcher mousePressedDispatcher(mousePressed);
                mousePressedDispatcher.Dispatch<MouseButtonPressedEvent>([&](MouseButtonPressedEvent& event) {
                    std::cout << "Mouse Button Pressed: " << static_cast<int>(event.GetMouseButton()) << std::endl;
                    return true;
                    });

                MouseButtonReleasedEvent mouseReleased(Mouse::ButtonLeft);
                EventDispatcher mouseReleasedDispatcher(mouseReleased);
                mouseReleasedDispatcher.Dispatch<MouseButtonReleasedEvent>([&](MouseButtonReleasedEvent& event) {
                    std::cout << "Mouse Button Released: " << static_cast<int>(event.GetMouseButton()) << std::endl;
                    return true;
                    });
            }

            // Add a small delay for better console output
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }

	}


}
