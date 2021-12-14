#include<iostream>
#include<vector>
#include<limits>

// https://en.wikipedia.org/wiki/Kahan_summation_algorithm
// https://github.com/delfrrr/delaunator-cpp/tree/master/include

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


int main(int argc, const char** argv) {

    std::ios::sync_with_stdio(false); // speed up for cin and std::std::cout

    std::vector<double> vec;
    vec.emplace_back(1.0);
    vec.emplace_back(-2.0);
    vec.emplace_back(3.0);
    std::cout << sum(vec) << '\n';
    //std::cout << std::numeric_limits<double>::max;

    std::cout << orient(2, 0, 1, 1, 0, 0);
	return 0;
}