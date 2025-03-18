#include <iostream>
#include <memory>

class Repository {
public:
    Repository(const std::string& path) : path_(path) {
        std::cout << "Repository at " << path_ << " 생성됨.\n";
    }
    ~Repository() {
        std::cout << "Repository at " << path_ << " 소멸됨.\n";
    }
    void open() {
        std::cout << "Repository " << path_ << " 열림.\n";
    }
private:
    std::string path_;
};

int main() {
    // std::unique_ptr를 사용하여 Repository 객체의 소유권을 관리합니다.
    // std::make_unique 함수를 사용하여 동적 할당된 객체를 생성합니다.
    // std::unique_ptr<Repository> repoPtr(new Repository("/path/to/repo")); 와 동일
    // std::unique_ptr<Repository> repoPtr = std::unique_ptr<Repository>(new Repository("/path/to/repo"));
    // 
    std::unique_ptr<Repository> repoPtr = std::make_unique<Repository>("/path/to/repo");

    // 객체의 멤버 함수 호출
    repoPtr->open();

    // repoPtr은 범위를 벗어날 때 자동으로 소멸되며, 동적 할당된 메모리를 해제합니다.
    // repoPtr은 main 함수의 로컬 변수로 선언되어 있습니다.
    // main 함수가 종료될 때 repoPtr도 범위를 벗어나게 되며, 이 시점에서 std::unique_ptr의 소멸자가 호출됩니다.
    // 소멸자가 호출되어 "Repository at /path/to/repo 소멸됨."이 출력됩니다.
    // std::unique_ptr<Repository> repoPtr = nullptr; 와 동일
    // std::unique_ptr<Repository> repoPtr = std::unique_ptr<Repository>(nullptr); 와 동일

    // std::unique_ptr가 관리하는 포인터가 이미 유효한 객체를 가리키고 있을 경우, 
    // nullptr과 같이 새로운 값이 대입되면, 
    // 내부적으로 기존에 소유하던 객체의 소멸자를 호출하여 delete 연산자를 실행합니다.
    // 이는 스마트 포인터의 reset(nullptr) 호출과 동일한 효과를 나타냅니다. 

    return 0;
}