#include <iostream>

/*
	function overloading
	- �Լ��� �̸��� ����(�ߺ�)�ؼ� ����ϴ� ��
	- �Ű�����(parameter)�θ� ������ �����ϴ�.
*/

using namespace std;

int add(int a, int b) { return a + b; }
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
//int add(int aa, int bb) { return aa + bb; }			//���� Ÿ���� �Ű������� �޴� add�� ������ �ȵȴ�.
//void add(int a, int b) { return a + b; }				//��ȯ�����δ� ������ �ȵȴ�.

using integer = int;
//int add(integer a, integer b) { return a + b; }			//�굵 �ȵ�.		//�����Ϸ��� ���⿡ ���� int�̱� ����
float add(float a, float b) { return a + b; }

using d = double;

d add(d a, d b) { return a + b; }

//void output(unsigned int value){}
//void output(int value){}
void output(float value){}



int main()
{
	auto result1 = add(10, 20);
	auto result2 = add(10.1f, 20.0f);
	auto result3 = add(10.1, 20.0);
	cout << result1 << endl;
	cout << result2 << endl;
	cout << result3 << endl;

	output(1);		//ambiguous		// int �ڷ����� �ִٸ� 1�� int�̱� ������ Ȯ���ϰ� 1�� ��Ī�ϴ� �Ķ���Ͱ� �־ �Ͻ������� ��������
	//output(1.0);		//ambiguous
	//output('c');		//ambiguous
	output((unsigned int)1);		//typecasting����� ��

	return 0;
}