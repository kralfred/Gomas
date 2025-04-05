#pragma once
#include <iostream>
#ifdef GM_PLATFORM_WINDOWS
#include "../Events/Event.h"
#include "Logging/Log.h"
#include "Logging/FileLogger.h"
#include "Application.h"

#include <conio.h> // For _getch() on Windows
#include <thread>
#include <chrono>


extern Gomas::Application* Gomas::CreateApplication();


int main(int argc, char** argv) {

	Gomas::Log::Init();

	Gomas::Log::GetCoreLogger()->info("Application started.");

	Gomas::FileLogger fileLogger("special_log.txt"); // Logs to temp/logs/special_log.txt by default.
	fileLogger.LogToFile("Warning");

	Gomas::Log::GetCoreLogger()->warn("Application is shutting down.");


	GM_CORE_ERROR("ahoj");

	auto app = Gomas::CreateApplication();
	app->Run();
	delete app;

}

#endif 
