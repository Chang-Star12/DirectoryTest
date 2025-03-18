#include <iostream>
#include <cstring> // strlen, strcpy 사용
#include <Windows.h>
/*

"클래스는 데이터(상태)와 그 데이터를 다루는 로직(행위)을 하나로 묶어 캡슐화(encapsulation)한 사용자 정의 자료형이다."

*/
class Repositor {
public:
    // 생성자: LPSTR 형식의 문자열(경로)을 받아 내부적으로 복사합니다.
    Repositor(LPSTR path) {
        // 입력된 문자열의 길이를 측정하여 동적 메모리 할당 (null 문자 포함)
        size_t len = strlen(path);
        path_ = new char[len + 1];
        strcpy_s(path_, len + 1, path);
        std::cout << "Repository at " << path_ << " 생성됨.\n";
    }

    // 소멸자: 동적으로 할당된 메모리를 해제합니다.
    ~Repositor() {
        std::cout << "Repository at " << path_ << " 소멸됨.\n";
        delete[] path_;
    }

    // Repository를 여는 기능을 수행하는 메서드
    void open() {
        std::cout << "Repository " << path_ << " 열림.\n";
    }

private:
    LPSTR path_; // 내부적으로 관리되는 문자열
};
/*
int main() {
    // LPSTR 변수에 문자열을 동적 할당하여 초기화
    LPSTR repoPath = new char[256];
    strcpy_s(repoPath, strlen("/path/to/repo"), "/path/to/repo");

    // Repository 객체 생성 (LPSTR을 인자로 전달)
    Repositor* repo = new Repositor(repoPath);
    repo->open();


    // 동적 할당된 Repository 객체와 문자열 메모리를 수동으로 해제
    delete repo;
    delete[] repoPath;

    return 0;
    }
 */
