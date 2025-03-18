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
    // std::unique_ptr를 사용하여 Repository 객체의 소유권을 관리합니다.
    // std::make_unique 함수를 사용하여 동적 할당된 객체를 생성합니다.
    // std::unique_ptr<Repository> repoPtr(new Repository("/path/to/repo")); 와 동일
    std::unique_ptr<Repository> repoPtr = std::make_unique<Repository>("/path/to/repo");

    // 객체의 멤버 함수 호출
    repoPtr->open();
    /*
        repoPtr은 범위를 벗어날 때 자동으로 소멸되며, 동적 할당된 메모리를 해제합니다.
        repoPtr은 main 함수의 로컬 변수로 선언되어 있습니다.
        main 함수가 종료될 때 repoPtr도 범위를 벗어나게 되며, 이 시점에서 std::unique_ptr의 소멸자가 호출됩니다.
		소멸자가 호출되어 "Repository at /path/to/repo 소멸됨." 출력 후 동적 메모리를 해제합니다.
    */
     
    return 0;
}