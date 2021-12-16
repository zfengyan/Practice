#include"Geometry.h"
#include<cmath>

namespace geo {
	double Vector3d::vector_length()const {
		return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
	}

	Vector3d Vector3d::normalized_vector()const {
		const double len(vector_length());
		return len ? Vector3d(v[0] / len, v[1] / len, v[2] / len) : Vector3d();
		// length can't be 0 otherwise return default value
	}

	void Vector3d::operator+=(const Vector3d& other) {
		v[0] += other.v[0];
		v[1] += other.v[1];
		v[2] += other.v[2];
	}

	Vector3d Vector3d::operator+(const Vector3d& other)const {
		return Vector3d(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
	}

	Vector3d Vector3d::operator-(const Vector3d& other) const {
		return Vector3d(v[0] - other.v[0], v[1] - other.v[1], v[2] - other.v[2]);
	}

	Vector3d Vector3d::operator*(const double& s) const {
		return Vector3d(v[0] * s, v[1] * s, v[2] * s);
	}

	Vector3d Vector3d::operator/(const double& s) const {
		return s ? Vector3d(v[0] / s, v[1] / s, v[2] / s) : Vector3d();
	}

	double Vector3d::dot_product(const Vector3d& other) const {
		return (v[0] * other.v[0] + v[1] * other.v[1] + v[2] * other.v[2]);
	}

	Vector3d Vector3d::cross_product(const Vector3d& other) const
	{
		return Vector3d(
			v[1] * other.v[2] - v[2] * other.v[1],
			v[2] * other.v[0] - v[0] * other.v[2],
			v[0] * other.v[1] - v[1] * other.v[0]
		);
	}

	Plane::Plane(const Point& p1, const Point& p2, const Point& p3)
	{
		// TODO
	}

	bool Plane::is_plane() const {
		return !(p[0] == 0 && p[1] == 0 && p[2] == 0);
	}

	bool Plane::point_in_plane(const Point& point) const {
		return is_plane() && (!(p[0] * point.x + p[1] * point.y + p[2] * point.z + p[3]));
	}

	// not class methods
	bool point_collinear(const Point& pa, const Point& pb, const Point& pc) {

	}
}
