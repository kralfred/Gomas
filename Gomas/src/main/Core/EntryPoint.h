#pragma once
#include <iostream>
#ifdef GM_PLATFORM_WINDOWS
#include "../Events/Event.h"
#include "Log.h"
#include "Application.h"

#include <conio.h> // For _getch() on Windows
#include <thread>
#include <chrono>


extern Gomas::Application* Gomas::CreateApplication();


int main(int argc, char** argv) {

	auto app = Gomas::CreateApplication();
	app->Run();
	delete app;

}

#endif 
