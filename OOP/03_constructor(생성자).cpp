// https://min-zero.tistory.com/47
#include <iostream>
#include <utility>		//std::move()
using namespace std;

class Fraction	//분수
{
public:
	/*
		constructor - 생성자
		- 객체를 인스턴스화할 때 호출된다.
		- 다른 함수와 구분하기 위해 반환 값이 없다.
	*/

	Fraction(int a, int b)
	{
		numerator = a;
		denominator = b;
		cout << "Constructor2!!" << endl;
	}

	//Fraction(int a = 10, int b = 10)		//모호성 문제
	//{
	//	numerator = a;
	//	denominator = b;
	//	cout << "Constructor2!!" << endl;
	//}


	/*
		기본적으로 오버로딩된 생성자 3가지
		- default constructor - 기본 생성자
			ㅁ 생성자를 하나도 선언하지 않을 경우 기본적으로 제공되는 생성자.
			ㅁ 하나라도 생성자를 정의했을 경우 포함하지 않음

		- copy constructor - 복사 생성자
			ㅁ 자신과 같은 타입의 클래스를 & 형태로 받는 경우 호출된다.
			ㅁ 재정의할 경우 외부에 존재하는 원본의 값을 복사하여 초기화하려고 할 때 사용한다.
			ㅁ 얕은 복사와 깊은 복사가 있다.

		- move constructor - 이동 생성자
			ㅁ 자신과 같은 타입의 클래스를 &&형태로 받는 경우 호출된다.
			ㅁ 재정의할 경우 원본 자체의 값을 대입하여 초기화하려고 할 때 사용한다.
	*/

	//Fraction();					//default constructor		// 생성자가 하나라도 있으면 포함 X
	//Fraction(const Fraction&);	//copy constructor		//외부에 원본이 있으므로 const 사용 권장
	//Fraction(Fraction&&);			//move constructor		//원본 자체를 가져왔으므로 const 사용 x


	Fraction()	//default constructor		//기본 생성자가 없다면 Fraction frac;을 선언할 수 없다.
	{
		cout << "Constructor1!!" << endl;
	}

	Fraction(const Fraction& data)
	{
		cout << "Constructor3!!" << endl;
	}

	//https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=mug896&logNo=140167721658
	Fraction(Fraction&& data) noexcept
	{
		cout << "Constructor4!!" << endl;
	}

private:
	int numerator = 10;		//분자
	int denominator = 10;	//분모
};

int main()
{
	Fraction frac;

	Fraction frac1(1.0, 2);
	
	//L-value 형태로 바꿔줌
	Fraction frac2(frac1);				//복사 생성자 호출

	//move() : 들어온 데이터를 R-value 형태로 바꿔준다.
	Fraction frac3(std::move(frac1));	//이동 생성자 호출

	return 0;
}