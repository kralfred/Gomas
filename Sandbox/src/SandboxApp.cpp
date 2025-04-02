
#include "Gomas.h"

class Sandbox : public Gomas::Application
{
public: 
	Sandbox() {
	}
	~Sandbox() {
	
	}

};

Gomas::Application* Gomas::CreateApplication() {
	return new Sandbox();

}


