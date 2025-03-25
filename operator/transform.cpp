#include <algorithm>
#include <vector>

struct StatisticFunctor {
    double mean;

    StatisticFunctor(double m) : mean(m) {}

    double operator()(double value) const {
        return (value - mean) * (value - mean);
    }
};

int main() {
    std::vector<double> data = { 1.0, 2.0, 3.0 };
    double mean = 2.0;

    std::transform(data.begin(), data.end(), data.begin(), StatisticFunctor(mean));

    return 0;
}
