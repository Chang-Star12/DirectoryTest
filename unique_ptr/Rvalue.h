
class Temp_Memory
{
	int a = 10;    // lvalue
	int& b = a;    // lvalue reference, 기존 변수(a)를 참조
	int&& c = 20;  // rvalue reference, 임시 객체(20)를 참조
};

