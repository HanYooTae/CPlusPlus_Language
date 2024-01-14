#include <iostream>

using namespace std;

struct person		//C에서는 구조체 안에 기본값을 넣어주지 못함	//C++에서 기본값을 넣어주면 넣어준 값으로 바뀐다.
{
	/*
		- 구조체 안에 있는 함수는 메모리 텍스트(코드) 영역에
		  미리 할당되어 크기를 차지하지 않는다.
		- 미리 잡혀있기 때문에 변수를 통해 호출하지 않아도 사용할 순 있지만
		  클래스 멤버 함수는 __thiscall형식이기 때문에
		  ()안에 아무것도 없어보이지만 해당하는 객체의 포인터가 들어가기 때문에
		  person::Print();로 따로 호출할 수 없다.
	*/

	//멤버함수
	//구조체 안에 작성한 함수는 사이즈에 포함되지 않는다
	void /*__thiscall*/ Print(/*person this*/)
	{
		//this;
		cout << /*this->*/age << endl;
	}

	//void /*__thiscall*/ Print(/*person* this*/int age)		// 매개변수에 동일한 이름의 변수가 선언되어있다면 this로 구분해주어야 함
	//{
	//	this->age;
	//	age;
	//	cout << age << endl;
	//}

	/*
		과제 : C++ 함수호출규약 (funtion calling convension) 조사
	*/

	//C와 다르게 기본값 예약이 가능
	//멤버변수
	int age;
	float weight = 40.0f;
	std::string name = "diDi";
};

int main()
{
	person p1{ 10, 50.0f, "DIDI" };

	cout << p1.age << endl;
	cout << p1.weight << endl;
	cout << p1.name << endl;
	cout << endl;

	person p2;
	cout << p2.age << endl;		//age가 초기화되지 않았으니 값이 없음. 쓰레기값 출력
	cout << p2.weight << endl;
	cout << p2.name << endl;


	cout << endl;
	p1.Print(/*&p1*/);
	

	return 0;
}