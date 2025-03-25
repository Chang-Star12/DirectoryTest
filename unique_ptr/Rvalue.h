
class Temp_Memory
{
	int a = 10;    // lvalue
	int& b = a;    // lvalue reference, 기존 변수(a)를 참조
	int&& c = 20;  // rvalue reference, 임시 객체(20)를 참조

	//임시객체?
	/*
	생성할때는 최적화를 시키지 않지만 옮길 때 주소값을 옮김으로써 최적화를 시킴
	*/
};

