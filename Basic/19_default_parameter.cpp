#include <iostream>
using namespace std;

//void print(int x)
//{
//	cout << x << endl;
//}

void print(int x = 7)		//�ƹ��͵� �Է����� ���� �� x�� �⺻ ������ 7�� �ְ� �ʹ�. -> default parameter
{
	cout << x << endl;
}

//������ ��1 : �׻� ���� ���� �־�� �Ѵ�
void print(int x = 7, int y = 7)
//void print(int x = 7, int y)			//�ȵ�
{
	cout << x << endl;
}

//������ ��2 : ������ ���� �ڿ� �ִٸ�, ���� ���� �־���� �Ѵ�.
void test(int x = 10, int y = 10, int z = 10)
{
	cout << x << ", " << y << ", " << z << endl;
}

int main()
{
	//print();		//7
	//print(10);	//10
	//print();		//7

	//������ �� 3 : default parameter�� overload�� ���ÿ� ���� �ʴ´�.
	//print(1);	//ambiguous

	//������ ��2 : ������ ���� �ڿ� �ִٸ�, ���� ���� �־���� �Ѵ�.
	test(10, 10, 15);

	return 0;
}