#pragma once
#include "Base.h"


namespace Gomas {
	class GOMAS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();

}
