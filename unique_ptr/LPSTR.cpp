#include <iostream>
#include <cstring> // strlen, strcpy 사용

// Windows 환경에서 LPSTR은 char*와 동일하게 정의됩니다.
typedef char* LPSTR;

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

    /*
    객체 생성과 역할 분리:
    Repository 클래스는 단순한 문자열 데이터 이상으로,
    저장소와 관련된 여러 기능(예: open 메서드 등)을 캡슐화합니다.
    따라서 단순히 repoPath 변수에 저장된 문자열을 사용하는 것이 아니라,
    Repository 객체를 생성하여 해당 경로와 관련된 로직을 처리하도록 하는 것입니다.
    */


    /*
        // 동적 할당된 Repository 객체와 문자열 메모리를 수동으로 해제
        delete repo;
        delete[] repoPath;

        return 0;
    }
    */
