#include <iostream>
#include <memory>
#include <vector>

class Robot {
public:
    Robot(int id) : id_(id) {
        std::cout << "Robot " << id_ << " 생성됨.\n";
    }
    ~Robot() {
        std::cout << "Robot " << id_ << " 소멸됨.\n";
    }

    void doTask() {
        std::cout << "Robot " << id_ << "가 작업 수행 중...\n";
    }

private:
    int id_;
};

int main() {
    // shared_ptr로 로봇 객체를 생성 및 관리
    std::shared_ptr<Robot> robotPtr = std::make_shared<Robot>(1);
    robotPtr->doTask();

    {
        // 같은 객체를 공유하는 또 다른 shared_ptr 생성
        std::shared_ptr<Robot> robotPtr2 = robotPtr;
        robotPtr2->doTask();

        std::cout << "현재 참조 횟수: " << robotPtr.use_count() << "\n";
    } // robotPtr2가 범위를 벗어나면서 참조 카운트가 감소

    std::cout << "범위를 벗어난 후 참조 횟수: " << robotPtr.use_count() << "\n";

    // 컨테이너에 여러 shared_ptr 저장
    std::vector<std::shared_ptr<Robot>> robots;
    robots.push_back(std::make_shared<Robot>(2));
    robots.push_back(std::make_shared<Robot>(3));

    for (auto& r : robots) {
        r->doTask();
    }

    // 컨테이너 소멸 시 로봇 객체 자동 소멸됨
    return 0;
}
