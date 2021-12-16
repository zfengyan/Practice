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
		Vector3d(const double& vx, const double& vy, const double& vz) {
			v[0] = vx; v[1] = vy; v[2] = vz;
		}
		Vector3d(const Point& pa, const Point& pb) {
			v[0] = pb.x - pa.x; v[1] = pb.y - pa.y; v[2] = pb.z - pa.z;
		} // vector: ab(point to b)
		
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


	class Triangle {
	public:
		Point pa;
		Point pb;
		Point pc;
	public:
		Triangle() = default;
	};


	class Plane {
	public:
		double p[4]{}; // p[0]:a, p[1]: b, p[2]: c, p[3]: d

	public:
		Plane(const double& a, const double& b, const double& c, const double& d) {
			p[0] = a; p[1] = b; p[2] = c; p[3] = d;
		}
		Plane(const Point& p1, const Point& p2, const Point& p3);
		Plane(const Triangle& t);

		bool is_plane()const; // a,b,c not all equal to 0 can form a plane
		bool point_in_plane(const Point& p)const;



	};
}

#endif