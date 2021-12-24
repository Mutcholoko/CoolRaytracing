#pragma once

#ifndef CAMERA_H
#define CAMERA_H

#include "qbVector.h"
#include "ray.h"

namespace RT {
	class Camera {
	public:
		//default constructor
		Camera();

		//set camera parameters
		void SetPos(const qbVector<double> &newPosition);
		void LookAt(const qbVector<double>&newLookAt);
		void SetUpVect(const qbVector<double>&upVector);
		void setLength(double newLength);
		void setHorSize(double newSize);
		void setAspect(double newAspect);

		//return camera parameters
		qbVector<double> GetPosition();
		qbVector<double> GetLookAt();
		qbVector<double> GetUp();
		qbVector<double> GetU();
		qbVector<double> GetV();
		qbVector<double> GetScreenCenter();
		double GetLength();
		double GetHorSize();
		double GetAspect();

		//generate a ray
		Ray GenerateRay(float projecScreenX, float projecScreenY);

		//update camera geometry
		void UpdateCameraGeometry();

	private:
		qbVector<double> m_CameraPos(3);
		qbVector<double> m_CameraLookAt(3);
		qbVector<double> m_CameraUp(3);
		double m_CameraLength;
		double m_CameraHorSize;
		double m_CameraAspectRatio;

		qbVector<double> m_AlignmentVector(3);
		qbVector<double> m_ProjectionScreenU(3);
		qbVector<double> m_ProjectionScreenV(3);
		qbVector<double> m_ProjectionScreenCenter(3);
	};
}

#endif // !CAMERA_H
