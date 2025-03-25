#include <algorithm>
#include <vector>
#include <iostream>

struct IntrinsicInst {
    unsigned id;
    // 기타 멤버...
};

struct isTargetIntrinsic {
    unsigned ID;

    isTargetIntrinsic(unsigned id) : ID(id) {}

    bool operator()(const IntrinsicInst& II) const {
        return II.id == ID;
    }
};

int main() {
    std::vector<IntrinsicInst> intrinsics = { {10}, {42}, {23} };
    unsigned targetID = 42;

    auto it = std::find_if(intrinsics.begin(), intrinsics.end(), isTargetIntrinsic(targetID));

    if (it != intrinsics.end()) {
        std::cout << "Found ID: " << it->id << std::endl;
    }
    else {
        std::cout << "Not found." << std::endl;
    }

    return 0;
}
