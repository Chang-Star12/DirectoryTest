#include <iostream>
#include <future>

struct AsyncCallback {
    void operator()(std::future<int>& resultFuture) {
        try {
            int result = resultFuture.get();
            std::cout << "Result: " << result << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

int compute() {
    return 42;
}

int main() {
    std::future<int> fut = std::async(std::launch::async, compute);
    AsyncCallback callback;

    callback(fut);

    return 0;
}
