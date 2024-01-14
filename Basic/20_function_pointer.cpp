#include <iostream>
#include <functional>		//함수 포인터를 쉽게 쓸 수 있게 해주는 라이브러리
using namespace std;

bool func(const int& x)
{
	cout << x << endl;
	return x > 0;
}

//함수의 이름 부분이 타입 부분이 된다.  func_ptr
typedef bool(*func_ptr)(const int&);

//위와 동일함
using func_type = bool(*)(const int&);

int main()
{
	//이렇게 사용하면 불편함
	bool (*pf)(const int&) = func;

	//1.
	func_ptr f = func;

	//2.
	func_type f2 = func;

	//#include <fucntional>을 사용해서 사용할 수 있는 기능
	//반환값과 매개변수만 적어주면 된다.
	//직접적으로 주소에 접근하지 못한다?
	function<bool(const int&)> f3 = func;
	f3(10);

	return 0;
}