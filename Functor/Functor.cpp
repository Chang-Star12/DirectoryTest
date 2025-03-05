#include <iostream>
#include <vector>
#include <algorithm>

/*

<Functor>

Operator를 재정의한 클래스에서 나온 객체를 의미 

객체.Operator와의 차이점은 반환값이 없다는 것이다.
없는 이유: 객체 자체가 반환값이기 때문이다.

*/



/*
상태 캡슐화와 재사용성
호출자 상태연계, 재사용성 


함수처럼 동작하는 객체
Functor는 호출 연산자(operator())를 오버로딩하여 객체를 함수처럼 사용할 수 있게 합니다. 이는 std::transform과 같은 알고리즘에서 함수 객체를 인자로 전달하여, 각 요소에 대해 동일한 연산을 반복적으로 적용할 수 있도록 합니다.

즉, std::transform은 multiplyBy3(각_요소)를 내부적으로 호출함으로써 각 요소에 상수 3을 곱한 결과를 도출합니다.
컴파일러 최적화의 가능성
함수 객체를 사용하면, 컴파일러가 인라인 최적화를 수행할 수 있는 여지가 늘어나게 됩니다. 이는 실행 시간 성능 향상에 기여할 수 있으며, 특히 고빈도 호출되는 연산에서 유리합니다.

코드의 명료성과 유지보수성
Functor를 사용하면, 연산의 목적과 동작이 명시적으로 클래스 내에 정의되므로, 코드의 가독성이 향상됩니다. 또한, 객체의 상태와 연산 로직이 하나의 단위로 묶여 있어, 유지보수 및 확장이 용이합니다.

*/


/*
<사용 불가능 코드>
std::transform(data.begin(), data.end(), result.begin(), multiplyBy3.operator()(data));
함수 객체와 반환값의 차이:
std::transform의 네 번째 인자는 각 요소에 대해 호출될 수 있는 **함수 객체(호출 가능한 객체)**여야 합니다.

multiplyBy3는 함수 객체로, operator()가 재정의되어 있으므로 multiplyBy3(각_요소)와 같이 사용할 수 있습니다.
반면, multiplyBy3.operator()(data)는 단일 호출을 의미하며, 이 결과값(예를 들어, data라는 컨테이너 전체에 대해 한 번 호출한 결과)이 전달됩니다.
인자 타입의 불일치:
operator()는 보통 단일 요소(예: int)를 인자로 받아 처리하도록 설계되었는데, data는 std::vector<int>와 같이 컨테이너 전체를 나타냅니다.

즉, multiplyBy3.operator()(data)와 같이 작성하면, operator()에 컨테이너 전체를 전달하려고 하여 컴파일 에러가 발생할 가능성이 높습니다.
std::transform의 내부 동작:
std::transform은 입력 범위의 각 요소에 대해 반복적으로 함수 객체를 호출합니다.

올바른 방식은 단순히 함수 객체인 multiplyBy3를 전달하는 것으로, 내부적으로 각 요소에 대해 multiplyBy3(요소)가 호출되어 결과를 result에 저장한다.
*/




// Multiply 클래스는 functor로서 정의되어 operator()를 재정의함으로써,
// 각 요소에 대해 지정된 상수와의 곱셈 연산을 수행합니다.
class Multiply {
public:
    explicit Multiply(int factor) : factor_(factor) {}

    // 호출 연산자를 통해 객체를 함수처럼 사용할 수 있습니다.
    int operator()(int value) const {
        return value * factor_;
    }

private:
    int factor_;
};

int main() {
    // 초기 데이터를 가진 벡터[동적 크기 조정 가능 배열] 생성
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    std::vector<int> result(data.size());

    // Multiply 객체를 생성하여 각 요소에 곱셈 연산을 수행하도록 설정합니다.
    Multiply multiplyBy3(3);

    // std::transform 알고리즘에 functor를 전달하여 data 벡터의 모든 원소를 처리합니다.
    //multiplyBy3.operator()(각_요소)
    std::transform(data.begin(), data.end(), result.begin(), multiplyBy3);


    // 결과 출력
    std::cout << "결과: ";
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}




/****************************************************************************************

명시적 생성자를 사용하여 암묵적 변환 금지하기
C++11부터는 explicit 키워드를 사용하여 생성자를 명시적 생성자로 선언할 수 있습니다.
명시적 생성자는 암묵적 변환을 금지하므로, 객체 생성 시에 명시적으로 생성자를 호출해야 합니다.

****************************************************************************************/
/*
class MyClass {
public:
    explicit MyClass(int value) : value_(value) {}
private:
    int value_;
};

void func(MyClass obj) {
    // ...
}

int main() {
    MyClass obj1(10);      // 명시적 호출: 정상
    // MyClass obj2 = 10;  // 컴파일 에러: 암묵적 변환 금지
    // func(20);           // 컴파일 에러: 암묵적 변환 금지
    func(MyClass(20));     // 명시적 객체 생성 후 전달: 정상
    return 0;
}
*/



