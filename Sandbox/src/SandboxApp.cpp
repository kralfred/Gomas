
#include "Gomas.h"

class Sandbox : public Gomas::Application
{
public: 
	Sandbox() {
	}
	~Sandbox() {
	
	}

};
int main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
	
}


