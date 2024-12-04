#include <Engine.h>

class ProjectApplication : public Engine::Application
{
public:
	ProjectApplication() {}
	~ProjectApplication() {}

	void Init() override
	{
		va = new Engine::VertexArray();

		float vertices[] = {
			-0.5f, -0.5f, 0.0f,
			-0.5f,  0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};
		vb = new Engine::VertexBuffer(vertices, 4 * 3 * sizeof(float));

		Engine::BufferLayout layout;
		layout.Push<float>(3, false);

		va->AddBuffer(*vb, layout);

		unsigned int indices[] = { 0, 1, 2, 2, 3, 0 };
		ib = new Engine::IndexBuffer(indices, 6 * sizeof(unsigned int));

		shader = new Engine::Shader("res/shaders/basic.vert", "res/shaders/basic.frag");
	}

	void Update() override
	{
	}

	void Render() override
	{
	}

	void Shutdown() override
	{
		delete shader;
		delete ib;
		delete vb;
		delete va;
	}

private:
	Engine::VertexArray* va;
	Engine::VertexBuffer* vb;
	Engine::IndexBuffer* ib;

	Engine::Shader* shader;
};

int main()
{
	ProjectApplication app;
	app.Run();

	return 0;
}