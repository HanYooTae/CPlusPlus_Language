#include <iostream>
using namespace std;

#define 과제1

#ifdef 과제1

int main()
{
	/*
   과제 :
   2진수와, bool대수 문제, 비트연산
   1.
   int a = 123;

	  a= 2345;
	  ....

	  a = 0;
	  a = a ? a -> ?에 무슨 연산자가 들어가야 위 코드보다 빠르게 될까?
*/

	//a를 0으로 바꾸기
	int a1 = 12345;
	a1 = a1 ^ a1;
	cout << a1 << endl;
	cout << endl;
	

/*
   2.
   int a = 123;
   int b = 456;

   a = a ? b
   b = a ? b
   a = a ? b

   temp를 사용하지 않고 바꾸는법 찾기
*/

	int a = 1;		//01
	int b = 2;		//10

	//^연산자(XOR) : 두 비트가 다르면 1, 같으면 0
	a = a ^ b;		//11
	b = a ^ b;		//01
	a = a ^ b;		//10

	cout << a << endl;
	cout << b << endl;
	cout << endl << endl;
	//a = (a + b) - (b = a);


/*
   3.
	  짝수/홀수 판별 -> %사용하지 않고
*/
	int c = 1;
	int d = 2;

	int c1 = c & 1;
	int d1 = d & 1;

	if (c1 == 1)
		cout << "홀수" << endl;
	else if (c1 == 0)
		cout << "짝수" << endl;

	if (d1 == 1)
		cout << "홀수" << endl;
	else if (d1 == 0)
		cout << "짝수" << endl;



	/*
	   4.
		  음수/양수 판별 -> 관계연산자 사용 x
	*/
	cout << endl;

	int y = 1;
	y >>= 31;

	int z = -1;
	z >>= 31;

	if (y == 0)
		cout << "양수" << endl;
	else if (y == -1)
		cout << "음수" << endl;

	if (z == 0)
		cout << "양수" << endl;
	else if (z == -1)
		cout << "음수" << endl;

	/*
	   5.
		  2의 승수인지 아닌지 판별 -> 반복문 사용하지 않고
		  연산 두번만 하면 알 수 있음
	*/

	int e = 4;

	if ((e & (e - 1)) == 0)
		cout << "2의 승수가 맞습니다." << endl;

	else
		cout << "2의 승수가 아닙니다." << endl;

	/*
	   6.
		  대문자/소문자 변환 -> +, - 안쓰고
		  아스키 코드의 대소문자는 여섯번째 비트가 모두 0이고
		  소문자는 모두 1 이다.
	*/

	string str = "ABC";

	for (char& ch : str)
	{
		if ('A' <= ch && 'Z' >= ch)
		{
			ch |= 32;
		}
		cout << ch << endl;
	}
	cout << str << endl;

	return 0;
}

#endif // 과제1

// 과제 2
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

template<>
class Storage8<bool>
{
public:
	Storage8(const char& input) {}

	void Set(int index, const bool& value)
	{
		arr[index] = value;
	}

	const bool& Get(int index) { return arr[index]; }

private:
	bool arr[8];
};