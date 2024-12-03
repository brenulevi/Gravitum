#include <iostream>
#include <Engine.h>

class ProjectApplication : public Engine::Application
{
public:
	ProjectApplication() {}
	~ProjectApplication() {}

	void Init() override
	{
	}

	void Update() override
	{
	}

	void Render() override
	{
	}

	void Shutdown() override
	{
	}
};

int main()
{
	std::cout << "Hello World" << std::endl;

	return 0;
}