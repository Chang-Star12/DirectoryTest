#include <iostream>
#include <memory>

/*

"클래스는 데이터(상태)와 그 데이터를 다루는 로직(행위)을 하나로 묶어 캡슐화(encapsulation)한 사용자 정의 자료형이다."

*/


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
    // std::unique_ptr를 사용하여 Repository 객체의 소유권을 관리 : std::unique_ptr<Repository> repoPtr(new Repository("/path/to/repo")); 와 동일
    std::unique_ptr<Repository> repoPtr = std::make_unique<Repository>("/path/to/repo");

    // 객체의 멤버 함수 호출
    repoPtr->open();
    //repoPtr은 범위를 벗어날 때 자동으로 소멸되며, 동적 할당된 메모리를 해제합니다.

     
    return 0;
}
