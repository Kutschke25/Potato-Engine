#pragma once

#ifdef PO_PLATFORM_WINDOWS

extern Potato::Application* Potato::CreateApplication();

int main(int argc, char** argv)
{
	Potato::Log::Init();
	PO_CORE_WARN("Initialized Log!");
	int a = 5;
	PO_INFO("Var={0}", a);

	auto app = Potato::CreateApplication();
	app->Run();
	delete app;
}

#endif