#include <iostream>
#include <vector>
#include <algorithm>
/*
================================================================================================
<Functor>

Operator�� �������� Ŭ�������� ���� ��ü�� �ǹ� 

��ü.Operator���� �������� ��ȯ���� ���ٴ� ���̴�.
���� ����: ��ü ��ü�� ��ȯ���̱� �����̴�.

================================================================================================//ㅁㄴㅇㄹㄴㅁㅇㄹ

<Vector>

���� ũ�� ���� ���� �迭

�ڵ����� �޸𸮸� �����ϹǷ�, ����ڴ� �޸� ������ ���� ������ �ʿ䰡 ����.

std::vector<int> data = { 1, 2, 3, 4, 5 };
std::transform

================================================================================================
*/



 
/*
���� ĸ��ȭ�� ���뼺
ȣ���� ���¿���, ���뼺 

Multiply multiplyBy3(3);
Multiply multiplyBy5(5);
int result = multiplyBy3.operator()(5); // 15
result = multiplyBy5.operator()(5); // 25

�Լ�ó�� �����ϴ� ��ü
�Ʒ� ����.
std::transform(data.begin(), data.end(), result.begin(), multiplyBy3);

�����Ϸ� ����ȭ�� ���ɼ�
�Լ� ��ü�� ����ϸ�, �����Ϸ��� �ζ��� ����ȭ�� ������ �� �ִ� ������ �þ�� �˴ϴ�. �̴� ���� �ð� ���� ��� �⿩�� �� ������, Ư�� ���� ȣ��Ǵ� ���꿡�� �����մϴ�.

//Multiply multiexample(3);
//multiexample  //multiexample.operator()()
//multiexample(5)  //multiexample.operator()(5) //15
*/


/*
<��� �Ұ��� �ڵ�>
std::transform(data.begin(), data.end(), result.begin(), multiplyBy3.operator()(data));
�Լ� ��ü�� ��ȯ���� ����:
std::transform�� �� ��° ���ڴ� �� ��ҿ� ���� ȣ��� �� �ִ� **�Լ� ��ü(ȣ�� ������ ��ü)**���� �մϴ�.

multiplyBy3�� �Լ� ��ü��, operator()�� �����ǵǾ� �����Ƿ� multiplyBy3(��_���)�� ���� ����� �� �ֽ��ϴ�.
�ݸ�, multiplyBy3.operator()(data)�� ���� ȣ���� �ǹ��ϸ�, �� �����(���� ���, data��� �����̳� ��ü�� ���� �� �� ȣ���� ���)�� ���޵˴ϴ�.
���� Ÿ���� ����ġ:
operator()�� ���� ���� ���(��: int)�� ���ڷ� �޾� ó���ϵ��� ����Ǿ��µ�, data�� std::vector<int>�� ���� �����̳� ��ü�� ��Ÿ���ϴ�.

��, multiplyBy3.operator()(data)�� ���� �ۼ��ϸ�, operator()�� �����̳� ��ü�� �����Ϸ��� �Ͽ� ������ ������ �߻��� ���ɼ��� �����ϴ�.
std::transform�� ���� ����:
std::transform�� �Է� ������ �� ��ҿ� ���� �ݺ������� �Լ� ��ü�� ȣ���մϴ�.

�ùٸ� ����� �ܼ��� �Լ� ��ü�� multiplyBy3�� �����ϴ� ������, ���������� �� ��ҿ� ���� multiplyBy3(���)�� ȣ��Ǿ� ����� result�� �����Ѵ�.
*/




// Multiply Ŭ������ functor�μ� ���ǵǾ� operator()�� �����������ν�,
// �� ��ҿ� ���� ������ ������� ���� ������ �����մϴ�.
class Multiply {
public:
    explicit Multiply(int factor) : factor_(factor) {}

    // ȣ�� �����ڸ� ���� ��ü�� �Լ�ó�� ����� �� �ֽ��ϴ�.
    int operator()(int value) const {
        return value * factor_;
    }
    //Multiply multiexample(3);
    //multiexample  //multiexample.operator()()
	//multiexample(5)  //multiexample.operator()(5) //15

private:
    int factor_;
};

int main() {
    // �ʱ� �����͸� ���� ����[���� ũ�� ���� ���� �迭] ����
    std::vector<int> data = { 1, 2, 3, 4, 5 };
    std::vector<int> result(data.size());

    // Multiply ��ü�� �����Ͽ� �� ��ҿ� ���� ������ �����ϵ��� �����մϴ�.
    Multiply multiplyBy3(3);

    // std::transform �˰����� functor�� �����Ͽ� data ������ ��� ���Ҹ� ó���մϴ�.
    //multiplyBy3.operator()(��_���)
    std::transform(data.begin(), data.end(), result.begin(), multiplyBy3);


    // ��� ���
    std::cout << "���: ";
    for (const auto& num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}




/****************************************************************************************

������ �����ڸ� ����Ͽ� �Ϲ��� ��ȯ �����ϱ�
C++11���ʹ� explicit Ű���带 ����Ͽ� �����ڸ� ������ �����ڷ� ������ �� �ֽ��ϴ�.
������ �����ڴ� �Ϲ��� ��ȯ�� �����ϹǷ�, ��ü ���� �ÿ� ���������� �����ڸ� ȣ���ؾ� �մϴ�.

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
    MyClass obj1(10);      // ������ ȣ��: ����
    // MyClass obj2 = 10;  // ������ ����: �Ϲ��� ��ȯ ����
    // func(20);           // ������ ����: �Ϲ��� ��ȯ ����
    func(MyClass(20));     // ������ ��ü ���� �� ����: ����
    return 0;
}
*/



