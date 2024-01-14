#include <iostream>
using namespace std;

template<class T>
class A
{
public:
	A(const T& input) {}

	void DoSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

//클래스 자체도 특수화 가능
template<>
class A<char>
{
public:
	A(const char& input) {}

	void DoSomething()
	{
		cout << "char type specialization" << endl;
	}
};

int main()
{
	A<int> a_int(10);
	A<float> a_float(10.0f);
	A<char> a_char('a');

	a_int.DoSomething();
	a_float.DoSomething();
	a_char.DoSomething();

	a_int.Test();
	a_float.Test();
	//템플릿 클래스는 특수화할 경우, 멤버도 서로 다르게 가지고 있다.
	//a_char.Test();	//error	//특수화한 char형에는 Test함수가 없음
	
	cout << endl;

	return 0;
}

/*
   과제 : 
   2진수와, bool대수 문제, 비트연산
   1.
   int a = 123;

	  a= 2345;
	  ....

	  a = 0;
	  a = a ? a -> ?에 무슨 연산자가 들어가야 위 코드보다 빠르게 될까?

   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp를 사용하지 않고 바꾸는법 찾기

   3.
	  짝수/홀수 판별 -> %사용하지 않고

   4.
	  음수/양수 판별 -> 관계연산자 사용 x


   5.
	  2의 승수인지 아닌지 판별 -> 반복문 사용하지 않고
	  연산 두번만 하면 알 수 있음

   6.
	  대문자/소문자 변환 -> +, - 안쓰고
	  아스키 코드의 대소문자는 여섯번째 비트가 모두 0이고
	  소문자는 모두 1 이다.
*/

// 과제 
/*
   아래의 클래스는 들어온 템플릿 인자에 따라 데이터를 8개 생성해주는 클래스이다.

   여기서 문제가 생기는데 bool형을 만들 시 공간을 낭비하게 된다.
   -> bool형은 1바이트 크기만으로도 8가지를 표현할 수 있지만 아래와
   같이 생성될 경우 1바이트 * 8의 크기를 가진다.

   아래의 클래스를 템플릿 특수화로 bool형일시
   1바이트를 가지고 8개의 불값을 처리할 수 있게 만들자

   template <class T>
class Storage8
{
public:
   void Set(int index, const T& value)
   {
	  arr[index] = value;
   }

   const T& Get(int index) { return arr[index]; }

private:
   T arr[8];
};

*/