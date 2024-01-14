#pragma once

//�� ��� ������ include�ϴ� ��� ���Ͽ� ���ԵǹǷ� �����ؾ� ��
// �ʿ���� ����� �ٸ� ���Ͽ� ���Ե� �� �ִ�. -> ������ �ð� ����
//#include <iostream>

//�ش� ������ �����ϴ� ��� ���� ������ std�� using��. -> �ߺ����� �߻� ���ɼ� ����
//using namespace std;

//class�� �ٸ� �������� ���̴� ��찡 ���� ������ ���� ������ header���Ϸ� �����Ǿ��ִ�.
//���� �Լ��� ������Ÿ���� ����� �ΰ� �����δ� cpp�� �Ѱ��ش�.

void Test();

//class Calc
//{
//public:
//	Calc(int value) : value(value) {}
//
//	Calc& Add(int value) { this->value += value; return *this; }		// ���� ��ġ �̵��ϸ� �Ʒ� �ڵ�ó�� �����.
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

	//�����丵 -> ���� ��ġ �̵�
	//������Ͽ� ������ �Լ��� ���� ��ġ �̵��� ���ָ�
	//inline�� �پ��ִ�. -> header�� ���Ǻα��� �ۼ��� �Լ����� �⺻������ inline�̱� �����̴�.
	//�׷��� ������ �ڵ尡 ª�� �Լ��� ����� ������� �͵� �ϳ��� ����ȭ ����̴�.
	Calc& Add(int value);
	Calc& Sub(int value);
	Calc& Mul(int value);
	Calc& Div(int value);
	Calc& Mod(int value);

	void Print();

	void Test();	//�����θ� ������ �ʰ� �ѱ�� inline�� ���� �ʴ´�.

private:
	int value;
};