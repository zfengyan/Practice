#ifndef _GEOMETRY_H_
#define _GEOMETRY_H_

#include<cmath>

namespace geo {
	struct Point {
		double x;
		double y;
		double z;

		Point() :x(0), y(0), z(0) {}
		Point(const double& px, const double& py, const double& pz) :
			x(px), y(py), z(pz) {}

	};


	class Vector3d {
	public:
		double v[3]{}; // the length is known, use the normal array(faster than vector)
	public:
		Vector3d() = default;
		Vector3d(const double& px, const double& py, const double& pz) {
			v[0] = px; v[1] = py; v[2] = pz;
		}
		
		double vector_length()const;
		Vector3d normalized_vector()const;
		
		void operator+=(const Vector3d& other);// NB: this operator would change the original vector
		Vector3d operator+(const Vector3d& other)const; 
		Vector3d operator-(const Vector3d& other)const;
		Vector3d operator*(const double& s)const;
		Vector3d operator/(const double& s)const;

		double dot_product(const Vector3d& other)const;
		Vector3d cross_product(const Vector3d& other)const;
	};
}

#endif