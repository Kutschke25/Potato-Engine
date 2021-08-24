#include <Potato.h>

class ExampleLayer : public Potato::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		PO_INFO("ExampleLayer::Update");
	}

	void OnEvent(Potato::Event& event) override
	{
		PO_TRACE( "{0}", event );
	}
};

class Sandbox : public Potato::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Potato::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Potato::Application* Potato:: CreateApplication()
{
	return new Sandbox();
}