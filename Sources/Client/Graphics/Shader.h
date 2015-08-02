#ifndef SHADER_HEADER
#define SHADER_HEADER

namespace Graphics
{
	class Shader
	{
	public:
		int ShaderProgram;
		int VertexShader;
		int FragmentShader;



		virtual void Initialize() = 0;
		virtual void Update() = 0;

		Shader();
		~Shader();
	};
}

#endif