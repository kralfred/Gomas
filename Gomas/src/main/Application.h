#pragma once
#include "Core.h"


namespace Gomas {
	class GOMAS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}
