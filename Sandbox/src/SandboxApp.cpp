#include <Potato.h>

class Sandbox : public Potato::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Potato::Application* Potato:: CreateApplication()
{
	return new Sandbox();
}