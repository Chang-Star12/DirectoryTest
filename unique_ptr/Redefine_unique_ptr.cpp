/*
unique_ptr 클래스 재정의

1: 복사생성자, 복사할당연산자 삭제: double delete 방지
2: 이동생성자, 이동할당연산자 추가: 소유권 이전
*/


template <typename T>
class unique_ptr {
private:
    T* ptr; // 실제 객체를 가리키는 포인터

public:
    // 생성자: 초기화
    explicit unique_ptr(T* p = nullptr) : ptr(p) {}

    // 소멸자: 자동으로 메모리 해제
    ~unique_ptr() { delete ptr; }

    // 복사 금지 (copy constructor 삭제)
    unique_ptr(const unique_ptr&) = delete;
    unique_ptr& operator=(const unique_ptr&) = delete;

    // 이동 생성자 (move constructor)
    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr)  //int& b = a;    // lvalue reference, 기존 변수(a)를 참조
                                                              //int&& c = 20;  // rvalue reference, 임시 객체(20)를 참조
    {
		other.ptr = nullptr; // other.ptr 소유권이전 이후 nullptr로 초기화
    }

    // 이동 할당 연산자 (다른객체의 소유권을 '가져오는' 행위)
    unique_ptr& operator=(unique_ptr&& other) noexcept 
    {
        if (this != &other) 
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
	// 소유권 해제 (자신이 관리하는 포인터를 '외부에' 넘겨주는 행위)
    T* release()
    {
        T* temp = ptr;
        ptr = nullptr;
        return temp;   //release() 함수는 단순히 포인터를 nullptr로 만드는 것뿐만 아니라, 기존에 관리하던 자원의 소유권을 외부로 이전시키는 목적을 가지고 있음.
    }

    // 객체 접근 연산자 (->, *)
	T* operator->() const { return ptr; } //ptr.operator->()와 동일 ex) ptr->open(); // ptr의 주소가 가리키는 객체의 open() 함수 호출
	T& operator*() const { return *ptr; } // *ptr.operator*()와 동일 ex) (*ptr).open(); // ptr의 주소가 가리키는 객체의 open() 함수 호출

};
