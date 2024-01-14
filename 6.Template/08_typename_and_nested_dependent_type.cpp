#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	using my_int = int;
	int name;
};

//템플릿 매개변수의 typename과 class는 같은 의미 -> 차이가 없다
template<typename T>
//template<class T>
class B
{
public:
	//T::my_int가 타입인지 아니면 정적 멤버 변수인지 구분이 안됨
	//-> 컴파일러는 정적 멤버 변수로 인식한다.
	//T::my_int i;	//error

	/*
	  템플릿 내부에서 중첩 의존 타입 이름을 사용할 때, typename을 사용해야 한다.

	  dependent - 의존 이름
	  - 위의 typename T처럼 타입을 인자로 받아 사용할 때,
	  T를 의존이름이라고 부른다.

	  nested dependent type name - 중첩 의존 타입 이름
	  - 의존 이름속에 다른 타입이 정의 된 경우,
	  중첩 의존 타입 이름이라고 부른다.

	  - ex) T::my_int
   */

	//typename 키워드를 사용해 T::my_int가 타입 이름임을 명시하여 해결 가능
	typename T::my_int i;
	T::name;

private:

};

int main()
{
	A::my_int a = 10;

	return 0;
}