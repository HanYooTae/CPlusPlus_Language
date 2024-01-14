#include <iostream>

/*
	function overloading
	- 함수의 이름을 적재(중복)해서 사용하는 것
	- 매개변수(parameter)로만 구분이 가능하다.
*/

using namespace std;

int add(int a, int b) { return a + b; }
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
//int add(int aa, int bb) { return aa + bb; }			//같은 타입의 매개변수를 받는 add가 있으면 안된다.
//void add(int a, int b) { return a + b; }				//반환값으로는 구분이 안된다.

using integer = int;
//int add(integer a, integer b) { return a + b; }			//얘도 안됨.		//컴파일러가 보기에 같은 int이기 때문
float add(float a, float b) { return a + b; }

using d = double;

d add(d a, d b) { return a + b; }

//void output(unsigned int value){}
//void output(int value){}
void output(float value){}



int main()
{
	auto result1 = add(10, 20);
	auto result2 = add(10.1f, 20.0f);
	auto result3 = add(10.1, 20.0);
	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;

	output(1);		//ambiguous		// int 자료형이 있다면 1이 int이기 때문에 확실하게 1을 지칭하는 파라미터가 있어서 암시적으로 인정해줌
	//output(1.0);		//ambiguous
	//output('c');		//ambiguous
	output((unsigned int)1);		//typecasting해줘야 함

	return 0;
}