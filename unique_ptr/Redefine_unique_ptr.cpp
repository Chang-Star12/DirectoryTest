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
    unique_ptr(unique_ptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // 이동 할당 연산자
    unique_ptr& operator=(unique_ptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

    // 객체 접근 연산자 (->, *)
    T* operator->() const { return ptr; }
    T& operator*() const { return *ptr; }

    // 소유권 해제
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }
};
