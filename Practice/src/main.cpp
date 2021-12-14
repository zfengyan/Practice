#include<iostream>
#include<vector>
#include<limits>
#include<Eigen/Dense>
#include<Eigen/Core>

// https://en.wikipedia.org/wiki/Kahan_summation_algorithm
// https://github.com/delfrrr/delaunator-cpp/tree/master/include
// @brief: calculate the sum of all items in a vector

double sum(const std::vector<double>& x) {
    double sum = x[0];
    double err = 0.0;

    for (std::size_t i = 1; i < x.size(); ++i) {
        const double k = x[i];
        const double m = sum + k;
        err += std::fabs(sum) >= std::fabs(k) ? sum - m + k : k - m + sum;
        sum = m;
    }
    return sum + err;
}


// orient:
// @brief: if CW return 0 else(CCW) return 1
bool orient(
    const double px,
    const double py,
    const double qx,
    const double qy,
    const double rx,
    const double ry) {
    return (qy - py) * (rx - qx) - (qx - px) * (ry - qy) < 0.0;
}


std::pair<double, double> circumcenter(
    const double ax,
    const double ay,
    const double bx,
    const double by,
    const double cx,
    const double cy) {
    const double dx = bx - ax;
    const double dy = by - ay;
    const double ex = cx - ax;
    const double ey = cy - ay;

    const double bl = dx * dx + dy * dy;
    const double cl = ex * ex + ey * ey;
    const double d = dx * ey - dy * ex;

    const double x = ax + (ey * bl - dy * cl) * 0.5 / d;
    const double y = ay + (dx * cl - ex * bl) * 0.5 / d;

    return std::make_pair(x, y);
}


int main(int argc, const char** argv) {

    std::ios::sync_with_stdio(false); // speed up for cin and std::std::cout

    std::vector<double> vec;
    vec.emplace_back(1.0);
    vec.emplace_back(-2.0);
    vec.emplace_back(3.0);
    std::cout << sum(vec) << '\n';
    //std::cout << std::numeric_limits<double>::max;

    std::cout << orient(2, 0, 1, 1, 0, 0) << '\n';
    std::cout << circumcenter(0, 0, 1, 1, 2, 0).first << ' ' << circumcenter(0, 0, 1, 1, 2, 0).second << '\n';
	
    Eigen::VectorXd test_eigen(3);
    test_eigen(0) = 1;
    test_eigen(1) = 2;
    test_eigen(2) = 3;
    std::cout << test_eigen;
    return 0;
}