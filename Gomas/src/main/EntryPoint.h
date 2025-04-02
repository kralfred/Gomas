#pragma once

#ifdef GM_PLATFORM_WINDOWS

extern Gomas::Application* Gomas::CreateApplication();

int main(int argc, char** argv) {
	
	auto app = Gomas::CreateApplication();
	app->Run();
	delete app;

}

#endif 
