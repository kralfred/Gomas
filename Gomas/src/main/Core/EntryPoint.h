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

	Gomas::Log::StartFileLogging("test.txt");
    GM_CORE_ERROR("test");
	Gomas::Log::StopFileLogging();

	Gomas::Log::GetCoreLogger()->warn("Application is shutting down new.");

	Gomas::Log::StartFileLogging("test2.txt","temp/logs/new/");
    GM_CLIENT_INFO("second test");
	Gomas::Log::StopFileLogging();

	GM_CLIENT_INFO("third");

	auto app = Gomas::CreateApplication();
	app->Run();
	delete app;

}

#endif 
