#include <iostream>
using namespace std;
/*
	L-value & = 나중에 다시 접근이 가능한 값
	R-value && = 식이 끝나면 접근이 불가능한 값
*/

struct aa
{
	int a;	//멤버변수만 넣음
};

//구조체에 함수를 넣기 위해 새롭게 만들어진 것이 class
class A
{
	void test();

	int a;
};

//두 레퍼런스로 프로그래머의 의도를 알 수 있다.
int Test1(/*const*/int& a/*, int& b*/)	//a는 어딘가에 원본이 있음을 표시하고 복사의 필요성을 표시
{
	/*
		swap 함수

		int temp = a;
		a = b;
		b = temp;
	*/
	
	//const를 넣으면 a값을 수정할 수 없음
	//const가 없다면 a값을 수정할 수 있음.
	a = 10; 

	return a;
}

int Test2(int&& a)	//a는 밖에서 존재하지 않을 때 표시 -> 복사할 필요가 없다.
{
	//cout << a << endl;
	return a;
}

int main()
{
	int val = 5;

	int& r = val;	//자료형 옆에 붙은 & : L-value reference
					//역참조를 생각할 필요가 없음.
	/*
		val == r -> val과 r은 같은 것. val의 별명을 r로 붙인 것. 편하게 쓰기 위해서 등장
		- 내부적으로는 포인터임.
		- 변수처럼 사용하면 된다.
	*/
	r = 100;

	//int& a;		//error		//초기화 시 무조건 l-value값이 들어가야 한다.
	//별명을 붙이기 위해서는 대상이 필요하다.

	std::cout << val << std::endl;

	//int& r2 = 10;		//L-value만 가능
	const int& r2 = 10;	//상수화하면 다시 접근할 일이 없기 때문에 가능
	
	//r2 = 10;			//값을 변경하려는 시도이기 때문에 같은 숫자여도 안된다.

	int&& rr = 10;		//R-value reference
	//move semantic

	//int&& rr = val;

	Test1(val);
	//Test1(100);
	//Test2(val);
	Test2(100);
	Test2(101);

	return 0;
}