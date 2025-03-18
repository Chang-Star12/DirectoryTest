template<typename T>  //typename == T   (int, double , class 등을 T로 치환(매개변수로)하겠다는 것)
//Class 선언부에서는 T를 사용할 수 있고 인스턴스 선언시에는 double, int, MyContainer 등으로 치환됨. 즉 MyContainer 또한 typename 이다.  
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
