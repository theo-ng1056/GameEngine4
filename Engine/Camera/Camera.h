#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

class Camera
{
public:
	Camera();
	~Camera();

	// Setter
	
	void SetPosition(vec3 position_);
	void SetRotation(float yaw_, float pitch_);

	// Getter

	mat4 GetView() const;
	mat4 GetPerspective() const;
	mat4 GetOrthographic()const;
	vec3 GetPosition() const;


private:
	void UpdateCameraVector();
	vec3 position;
	mat4 perspective, orthographic, view;
	float fieldOfView;
	float yaw, pitch;
	float nearPlane, farPlane; // two limit planes
	vec3 forward, up, right, worldUp;
};

#endif // !CAMERA_H


