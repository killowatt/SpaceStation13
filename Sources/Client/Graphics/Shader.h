#ifndef SHADER_HEADER
#define SHADER_HEADER

#include <glm/mat4x4.hpp>

namespace Graphics
{
	enum class ShaderState
	{
		Static,
		Dynamic
	};
	enum class ShaderType
	{
		Vertex,
		Fragment
	};
	class Shader
	{
	public:
		unsigned int ShaderProgram; // TODO: across all gl types. consider copy constructor and whether it should be accessible.
		unsigned int VertexShader;
		unsigned int FragmentShader;

		ShaderState State;

		glm::mat4 Model;
		glm::mat4 View;
		glm::mat4 Projection;

		bool GetCompileStatus(ShaderType shaderType);
		char* GetCompileLog(ShaderType shaderType);

		virtual void Initialize() = 0;
		virtual void Update() = 0;
		
		Shader& operator =(Shader& other);

	protected:
		Shader();
		Shader(const char* vertexShader, const char* fragmentShader);
	public:
		~Shader();
	};
}

#endif