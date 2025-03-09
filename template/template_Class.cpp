
//template<class T> 는 template<typename T>와 같은 의미이다.
//template<class T> 는 T라는 타입 매개변수를 선언하는 것이다.
//T는 실제 사용 시 구체적인 데이터 타입으로 대체된다. 
//예를 들어, MyContainer<int> intContainer(5); 라고 선언하면 T는 int로 대체된다.
//MyContainer<double> doubleContainer(5); 라고 선언하면 T는 double로 대체된다.

template<class T>
class MyContainer {
public:
    MyContainer(int size) : size_(size), data_(new T[size]) {}
    ~MyContainer() { delete[] data_; }

    void set(int index, const T& value) {
        if (index >= 0 && index < size_) {
            data_[index] = value;
        }
    }

    T get(int index) const {
        if (index >= 0 && index < size_) {
            return data_[index];
        }
        return T();  // 기본값 반환
    }

private:
    int size_;
    T* data_;
};

// 사용 예:
#include <iostream>

int main() {
    MyContainer<int> intContainer(5);
    intContainer.set(0, 10);
    std::cout << "Element at index 0: " << intContainer.get(0) << std::endl;

    MyContainer<double> doubleContainer(5);
    doubleContainer.set(0, 3.14);
    std::cout << "Element at index 0: " << doubleContainer.get(0) << std::endl;
    return 0;
}
