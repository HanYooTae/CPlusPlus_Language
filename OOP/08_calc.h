#pragma once

//이 헤더 파일을 include하는 모든 파일에 포함되므로 주의해야 함
// 필요없는 헤더가 다른 파일에 포함될 수 있다. -> 컴파일 시간 증가
//#include <iostream>

//해당 파일을 포함하는 모든 파일 전역에 std가 using됨. -> 중복문제 발생 가능성 증가
//using namespace std;

//class는 다른 곳에서도 쓰이는 경우가 많기 때문에 보통 개별의 header파일로 정리되어있다.
//보통 함수의 프로토타입은 헤더에 두고 구현부는 cpp로 넘겨준다.

void Test();

//class Calc
//{
//public:
//	Calc(int value) : value(value) {}
//
//	Calc& Add(int value) { this->value += value; return *this; }		// 정의 위치 이동하면 아래 코드처럼 변경됨.
//	Calc& Sub(int value) { this->value -= value; return *this; }
//	Calc& Mul(int value) { this->value *= value; return *this; }
//	Calc& Div(int value) { this->value /= value; return *this; }
//	Calc& Mod(int value) { this->value %= value; return *this; }
//
//private:
//	int value;
//};

class Calc
{
public:
	Calc(int value) : value(value) {}

	//리팩토링 -> 정의 위치 이동
	//헤더파일에 구현한 함수를 정의 위치 이동을 해주면
	//inline이 붙어있다. -> header에 정의부까지 작성한 함수들은 기본적으로 inline이기 때문이다.
	//그렇기 때문에 코드가 짧은 함수는 헤더에 적어놓는 것도 하나의 최적화 방법이다.
	Calc& Add(int value);
	Calc& Sub(int value);
	Calc& Mul(int value);
	Calc& Div(int value);
	Calc& Mod(int value);

	void Print();

	void Test();	//구현부를 만들지 않고 넘기면 inline이 붙지 않는다.

private:
	int value;
};