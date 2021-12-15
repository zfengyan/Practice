#include"Geometry.h"
#include<cmath>

double geo::Vector3d::vector_length()const {
	return sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
}

geo::Vector3d geo::Vector3d::normalized_vector(){
	const double len(geo::Vector3d::vector_length());
	return len ? geo::Vector3d(v[0] / len, v[1] / len, v[2] / len)
		: geo::Vector3d(); // length can't be 0 otherwise return default value
}

void geo::Vector3d::operator+=(const Vector3d& other){
	v[0] += other.v[0];
	v[1] += other.v[1];
	v[2] += other.v[2];
}

geo::Vector3d geo::Vector3d::operator+(const Vector3d& other)const{
	return geo::Vector3d(v[0] + other.v[0], v[1] + other.v[1], v[2] + other.v[2]);
}
