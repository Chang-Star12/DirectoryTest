#include <algorithm>
#include <vector>
#include <string>

struct Comparator {
    bool operator()(const std::string& a, const std::string& b) const {
        return a < b;
    }
};

int main() {
    std::vector<std::string> data = { "orange", "apple", "banana" };

    std::sort(data.begin(), data.end(), Comparator());

    return 0;
}
