#include <iostream>
#include <vector>
#include <algorithm>

// Functor 클래스 정의: 입력값에 특정 값을 곱해주는 기능 수행
class Multiply {
public:
    // 명시적 생성자: 곱할 값을 설정
    explicit Multiply(int factor) : factor_(factor) {}

    // Functor 연산자(): 입력받은 값에 factor를 곱한 결과 반환
    int operator()(int value) const {
        return value * factor_;
    }

private:
    int factor_;  // 곱할 값 저장
};

int main() {
    // 데이터 벡터 초기화
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    // 결과를 저장할 벡터 선언 및 크기 설정
    std::vector<int> result(data.size());

    // 곱할 값을 3으로 설정한 Multiply 객체 생성
    Multiply multiplyBy3(3);

    // std::transform을 이용해 data의 각 원소에 multiplyBy3 적용 후 결과 저장
    std::transform(data.begin(), data.end(), result.begin(), multiplyBy3);

    // 결과 출력
    std::cout << "결과: ";
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
