#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

void Camera::SetPosition(float x, float y)
{
	View = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0));
}
void Camera::SetOrthoDimensions(float width, float height)
{
	Projection = glm::ortho(0.0f, width, height, 0.0f, 0.0f, 1.0f);
}

Camera::Camera(float width, float height)
{
	SetPosition(0, 0);
	SetOrthoDimensions(width, height);
}