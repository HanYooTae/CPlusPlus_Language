/*
	RTTI : Run Time Type Information
	- 런타임 중에 실시간으로 데이터 타입에 대한 정보를 얻는 기능
	- RTTI 기능이 켜져있어야 런타임 때 자료형을 확인 가능
	- dynamic_cast를 사용할 때도 필요하다.
	- 런타임 때 자료형을 계산해야하기 때문에 느리다.
	https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kyed203&logNo=220164579551
*/

#include <iostream>
#include <typeinfo>		// RTTI 사용 헤더

using namespace std;

//int add(int a, int b) { return a + b; }
//int add(float a, int b) { return a + b; }

//자료형에 상관없이 프로그래밍을 해줄 수 있는 것 : 일반화 프로그래밍(템플릿) generic type
template<typename T>
T add(T a, T b)
{
	//cout << "a : " << a << endl;
	//cout << "b : " << b << endl;
	cout << "a : " << typeid(a).name() << endl;				//typeid(변수명).name() -> 변수의 자료형 출력
	cout << "b : " << typeid(b).name() << endl;

	return a + b;
}

//template<typename T, typename T2>
//T add(T a, T2 b)
//{
//	cout << "a : " << a << endl;
//	cout << "b : " << b << endl;
//}


int main()
{
	//add(10, 20);
	//add(10.0f, 20);

	//add<int>(10, 20);
	//add<float>(10.0f, 20.0f);
	//add<float, int>(10.0f, 20);

	add(10, 20);
	add(10.0f, 20.0f);
	//add(10.0f, 20);

	return 0;
}