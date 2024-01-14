#include <iostream>

using namespace std;

/*
	const 멤버 함수
	- 해당 멤버 함수에서는 내부에서 멤버 변수가 상수화된다. -> 수정 불가능
	- mutable을 사용한 멤버 변수는 제외
*/

class Data
{

public:
	Data() : value1(0), value2(0) {}

	//const 멤버함수는 멤버 변수가 모두 상수화되어 수정 불가능
	//void SetValue1(int value) const { this->value1 = value; }		//error

	const void setValue2(int value) const { this->value2 = value; }		//mutable 키워드가 있는 멤버변수는 가능하다.

	int& GetValue() { cout << "not const" << endl; return value1; }
	
	//const 함수에서 멤버변수의 참조를 리턴할 경우 에러 -> 우회적으로 값을 수정할 수 있기 때문에
	//int& GetValue1() const { cout << "const" << endl; return value1; }
	//멤버 변수의 참조를 반환할 경우 const를 붙여 수정못하는 형태로 만들어주어야 한다.
	const int& GetValue1() const { cout << "const" << endl; return value1; }
	const int& GetValue2() const { cout << "mutable" << endl; return value2; }
	int& GetValue3() const { cout << "Mutable" << endl; return value2; }

	int test() { return 0; }

private:
	int value1;
	mutable int value2;		//mutable : const 멤버함수 내부에서도 변경이 가능해진다.

	/*
		https://modoocode.com/253
		explicit(명시적 변환 <> 암시적 변환(implicit))도 구글링할 것!
	*/
};

//void Print(Data& data)
//{
//	data.test();
//	data.GetValue();
//}

void Print(const Data& data)
{
	/*
		외부에서 받은 인자값이 일반 객체 형태여도
		현재 받는 매개변수의 자료형은 상수이기 때문에
		const 멤버함수만 호출이 가능하다.
		그렇기 때문에 멤버 변수에 대한 수정이 없는 멤버 함수들은 모두 const를 붙여주어
		const 객체에서도 호출이 가능하도록 만드는게 좋다.
	*/
	data.GetValue1();
}

int main()
{
	Data data1;
	const Data data2;		//상수 객체는 const 멤버 함수만 호출 가능

	data1.GetValue() = 10;
	//data2.GetValue() = 10;	//수정 가능성이 있는 일반 멤버 함수는 호출하지 못함
	//data2.test();			//수정될 가능성이 있기 때문에 호출하지 못함

	data1.GetValue1();
	data2.GetValue1();

	return 0;
}