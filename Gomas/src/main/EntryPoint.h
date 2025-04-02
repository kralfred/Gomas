#pragma once

#ifdef GM_PLATFORM_WINDOWS

#include "Log.h"

extern Gomas::Application* Gomas::CreateApplication();

int main(int argc, char** argv) {

	Gomas::Log::Init();
	Gomas::Log::GetClientLogger()->warn("Client logger setup");
	Gomas::Log::GetCoreLogger()->info("Core logger setup");

	auto app = Gomas::CreateApplication();
	app->Run();
	
	delete app;

}

#endif 
