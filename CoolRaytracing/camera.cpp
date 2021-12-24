#include "camera.hpp"
#include "ray.h"
#include <math.h>

RT::Camera::Camera() {
	//default constructor
	m_CameraPos = qbVector<double>{ std::vector<double> {0.0, -10.0, 0.0} };
	m_CameraLookAt = qbVector<double>{ std::vector<double> {0.0, 0.0, 0.0} };
	m_CameraUp = qbVector<double>{ std::vector<double> {0.0, 0.0, 1.0} };
	m_CameraLength = 1.0;
	m_CameraHorSize = 1.0;
	m_CameraAspectRatio = 1.0; //change accordingly
}

void RT::Camera::SetPos(const qbVector<double>& newPosition) {
	m_CameraPos = newPosition;
}

void RT::Camera::LookAt(const qbVector<double>& newLookAt) {
	m_CameraLookAt = newLookAt;
}

void RT::Camera::SetUpVect(const qbVector<double>& upVector) {
	m_CameraUp = upVector;
}

void RT::Camera::setLength(double newLength) {
	m_CameraLength = newLength;
}

void RT::Camera::setHorSize(double newSize) {
	m_CameraHorSize = newSize;
}

void RT::Camera::setAspect(double newAspect) {
	m_CameraAspectRatio = newAspect;
}

//returns position of the camera
qbVector<double> RT::Camera::GetPosition() {
	return m_CameraPos;
}

//returns LookAt of the camera
qbVector<double> RT::Camera::GetLookAt() {
	return m_CameraLookAt;
}

//returns up vector of the camera
qbVector<double> RT::Camera::GetUp() {
	return m_CameraUp;
}

//returns length of the camera
double RT::Camera::GetLength() {
	return m_CameraLength;
}

//returns horizontal size of the camera
double RT::Camera::GetHorSize() {
	return m_CameraHorSize;
}

//returns aspect ratio of the camera
double RT::Camera::GetAspect() {
	return m_CameraAspectRatio;
}

//returns U vector
qbVector<double> RT::Camera::GetU() {
	return m_ProjectionScreenU;
}

//returns V vector
qbVector<double> RT::Camera::GetV() {
	return m_ProjectionScreenV;
}

//returns center of screen projection
qbVector<double> RT::Camera::GetScreenCenter() {
	return m_ProjectionScreenCenter;
}

//compute camera geometry
void RT::Camera::UpdateCameraGeometry() {
	//compute vector from the cam position to the lookAt position
	m_AlignmentVector = m_CameraLookAt - m_CameraPos;
	m_AlignmentVector.Normalize();

	//compute U & V vectors
	m_ProjectionScreenU = qbVector<double>::cross(m_AlignmentVector, m_CameraUp);
}