#include <iostream>

// ClassC: 캡슐화를 적용한 클래스
class ClassC {
private:
    int point;  // private 멤버 변수
public:
    // 생성자: point를 초기화
    ClassC(int p = 0) : point(p) {}

    // setter 함수: point 값을 수정
    void setPoint(int p) {
        point = p;
    }

    // getter 함수: point 값을 반환
    int getPoint() const {
        return point;
    }
};

// ClassB: ClassC 인스턴스에 대한 포인터를 보유
class ClassB {
private:
    ClassC* ptrClassC;  // ClassC 인스턴스에 대한 포인터
public:
    // 생성자: 외부에서 생성한 ClassC 인스턴스의 주소를 받아 저장
    ClassB(ClassC* c) : ptrClassC(c) {}

    // ClassC 인스턴스의 point 값을 수정하는 메서드
    void updatePoint(int p) {
        if (ptrClassC) {
            ptrClassC->setPoint(p);
        }
    }

    // ClassC 인스턴스의 point 값을 반환하는 메서드
    int retrievePoint() const {
        if (ptrClassC) {
            return ptrClassC->getPoint();
        }
        return -1;
    }
};

int main() {
    // main 함수에서 ClassC의 인스턴스를 생성
    ClassC sharedInstance(10);
    std::cout << "초기 값 (main에서): " << sharedInstance.getPoint() << std::endl;

    // ClassB가 main에서 생성한 동일한 ClassC 인스턴스를 공유하도록 생성
    ClassB objB(&sharedInstance);

    // ClassB를 통해 sharedInstance의 point 값을 수정
    objB.updatePoint(50);
    std::cout << "ClassB를 통한 수정 후 값 (main에서): " << sharedInstance.getPoint() << std::endl;

    // main에서 직접 set 함수를 호출하여 값을 수정
    sharedInstance.setPoint(100);
    std::cout << "main에서 직접 수정 후 값 (ClassB를 통해 확인): " << objB.retrievePoint() << std::endl;

    return 1;
}
