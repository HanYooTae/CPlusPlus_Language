/*
	이름 공간 (namespace)
	- 정의된 객체에 대해 소속을 정해주는 것
	- std::cout, std::cin 여기서 std가 cout, cin의 이름 공간
	- 객체의 이름이 같아도 이름공간이 다르면 다른 객체로 인식한다.
	- 변수나 함수의 이름이 겹치는 경우를 해결할 수 있다.


	선언

	namespace 공간 이름
	{
		멤버
	}


	접근법

	공간이름::멤버

	ex) namespace a
	{
		int b;
	}

	a::b = 10;
	- 이름 공간 a에 있는 변수 b에 접근하여 10을 대입
*/

#include <iostream>

namespace my_namespace_1
{
	int a;	//my_namespace_1::a

	void do_something(){}	//my_namespace_1::do_somthing()

	namespace DIDI
	{
		namespace TITI
		{
			namespace RURU
			{
				int c;	//my_namespace_1::DIDI::TITI::RURU::c;
			}
		}
	}
}

namespace my_namespace_1	//분래해서 사용해도 같은 이름공간에 들어간다.
{
	int hello;	//my_namespace::hello
}

//C++17에서 가능
//namespace my_namespace_1::DIDI::TITI
//{
//	int test;
//}

namespace my_namespace_2
{
	int a;
	void do_something(){}
}


int main()
{
	/*
		using namespace 이름공간
		- 해당 이름 공간을 선언한 영역 내에서 사용하지 않고도 접근이 가능하다.
	*/
	using namespace my_namespace_1;
	using namespace std;	//전역에 사용하면 문제가 발생할 수도 있음. 쓸 공간에서만 사용
	
	//a;	//error, 선언되어 있지 않음

	// 이름공간이 달라 같은 이름의 변수 사용가능 -> 중복을 피할 수 있다.
	my_namespace_1::a = 5;
	my_namespace_2::a = 10;

	my_namespace_1::DIDI::TITI::RURU::c;

	std::cout << 10 << std::endl;
	// 사용할 때마다 이름 공간을 쓰기 불편함 -> using namespace 사용
	cout << 10 << endl;

	{
		using namespace my_namespace_1;
		using namespace my_namespace_2;
		//a = 10; ambigous : 모호성

		my_namespace_2::a = 20;

		hello;
	}

	{
		using namespace my_namespace_2;
		
		my_namespace_1::a = 20;
		a = 110;
	}

	

	return 0;
}