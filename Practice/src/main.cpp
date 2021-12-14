#include<iostream>
#include<vector>

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


int main(int argc, const char** argv) {

    std::ios::sync_with_stdio(false); // speed up for cin and std::std::cout

    std::vector<double> vec;
    vec.emplace_back(1.0);
    vec.emplace_back(-2.0);
    vec.emplace_back(3.0);
    std::cout << sum(vec);

	return 0;
}