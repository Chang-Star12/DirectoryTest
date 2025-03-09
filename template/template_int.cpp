
/*
타입 매개의 변수

    정의: 
    template<class T> 또는 template<typename T>와 같이 선언된 매개변수는 타입 매개변수로, 
    실제 사용 시 구체적인 데이터 타입(예 : int, double, std::string 등)으로 대체됩니다.

*/




/*
비타입 매개변수

    정의: 
    template<int N>와 같이 선언된 매개변수는 비타입 매개변수로, 컴파일 타임에 결정되는 상수값을 전달받습니다. 
    이러한 매개변수는 주로 배열의 크기, 정적 크기, 혹은 컴파일 타임 상수 값 등을 지정할 때 사용됩니다.

*/


/*

template<int N>
class FixedArray {
public:
    FixedArray() : data_{} {}

    int& operator[](int index) { return data_[index]; }
    const int& operator[](int index) const { return data_[index]; }

    int size() const { return N; }

private:
    int data_[N];
};

// 사용 예:
int main() {
    FixedArray<10> arr;  // N은 10으로 고정됨
    arr[0] = 5;
    return 0;
}

*/

