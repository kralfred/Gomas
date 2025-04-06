#pragma once
#include <iostream>
#ifdef GM_PLATFORM_WINDOWS
#include "../Events/Event.h"
#include "Logging/Log.h"
#include "Application.h"

#include <conio.h> // For _getch() on Windows
#include <thread>
#include <chrono>


extern Gomas::Application* Gomas::CreateApplication();


int main(int argc, char** argv) {

	Gomas::Log::Init();

	

	GM_CLIENT_INFO("third");

	auto app = Gomas::CreateApplication();
	app->Run();
	delete app;

}

#endif 
