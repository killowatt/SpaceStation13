#pragma once
#include <glm/mat4x4.hpp>

class Camera
{
	glm::mat4 View;
	glm::mat4 Projection;

public:
	const glm::mat4& GetView() const { return View; }
	const glm::mat4& GetProjection() const { return Projection; }

	void SetPosition(float x, float y);
	void SetOrthoDimensions(float width, float height);

	Camera(float width, float height);
};