#include <iostream>
using namespace std;
/*
	L-value & = ���߿� �ٽ� ������ ������ ��
	R-value && = ���� ������ ������ �Ұ����� ��
*/

struct aa
{
	int a;	//��������� ����
};

//����ü�� �Լ��� �ֱ� ���� ���Ӱ� ������� ���� class
class A
{
	void test();

	int a;
};

//�� ���۷����� ���α׷����� �ǵ��� �� �� �ִ�.
int Test1(/*const*/int& a/*, int& b*/)	//a�� ��򰡿� ������ ������ ǥ���ϰ� ������ �ʿ伺�� ǥ��
{
	/*
		swap �Լ�

		int temp = a;
		a = b;
		b = temp;
	*/
	
	//const�� ������ a���� ������ �� ����
	//const�� ���ٸ� a���� ������ �� ����.
	a = 10; 

	return a;
}

int Test2(int&& a)	//a�� �ۿ��� �������� ���� �� ǥ�� -> ������ �ʿ䰡 ����.
{
	//cout << a << endl;
	return a;
}

int main()
{
	int val = 5;

	int& r = val;	//�ڷ��� ���� ���� & : L-value reference
					//�������� ������ �ʿ䰡 ����.
	/*
		val == r -> val�� r�� ���� ��. val�� ������ r�� ���� ��. ���ϰ� ���� ���ؼ� ����
		- ���������δ� ��������.
		- ����ó�� ����ϸ� �ȴ�.
	*/
	r = 100;

	//int& a;		//error		//�ʱ�ȭ �� ������ l-value���� ���� �Ѵ�.
	//������ ���̱� ���ؼ��� ����� �ʿ��ϴ�.

	std::cout << val << std::endl;

	//int& r2 = 10;		//L-value�� ����
	const int& r2 = 10;	//���ȭ�ϸ� �ٽ� ������ ���� ���� ������ ����
	
	//r2 = 10;			//���� �����Ϸ��� �õ��̱� ������ ���� ���ڿ��� �ȵȴ�.

	int&& rr = 10;		//R-value reference
	//move semantic

	//int&& rr = val;

	Test1(val);
	//Test1(100);
	//Test2(val);
	Test2(100);
	Test2(101);

	return 0;
}