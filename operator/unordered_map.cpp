#include <unordered_map>
#include <string>
#include <utility>
#include <functional>

struct MyType {
    int id;
    std::string name;

    bool operator==(const MyType& other) const {
        return id == other.id && name == other.name;
    }
};

// 해시 함수 정의
struct CustomHash {
    size_t operator()(const MyType& obj) const {
        return std::hash<int>()(obj.id) ^ std::hash<std::string>()(obj.name);
    }
};

int main() {
    std::unordered_map<MyType, int, CustomHash> map;
    map[{1, "test"}] = 100;

    return 0;
}
