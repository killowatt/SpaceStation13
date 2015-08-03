#ifndef SHADER_HEADER
#define SHADER_HEADER

namespace Graphics
{
	enum class ShaderState
	{
		Static,
		Dynamic
	};
	class Shader
	{
	public:
		int ShaderProgram;
		int VertexShader;
		int FragmentShader;

		ShaderState State;

		virtual void Initialize() = 0;
		virtual void Update() = 0;

		Shader();
		~Shader();
	};
}

#endif