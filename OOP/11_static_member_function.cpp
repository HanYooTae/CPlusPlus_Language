#include <iostream>
#include <functional>

using namespace std;

/*
	static_member_function
	- Ŭ������ ��ü�� �������� �ʰ� Ŭ������ �̸������� ȣ���� ������ �Լ�
	- ��ü�� �����Ƿ� this ������ ����� �ȵǰ� ���� ��� ������ ��� �����ϴ�.
	- const �Լ��� ���� �� ����.
*/

class Test
{
public:
	void Temp1() { this->value1; }				//__this call�����̱� ������ ����
	
	//__this call ����� �ƴ�. __standard call��.
	//�׳� Ŭ���� ī�װ��� ���Ե� ���� �Լ��� ����ϴ�.
	//static void Temp2() { this->value1; }		//error, this ��� �Ұ���
	//static void Temp2() const { this->value1; }		//error, ���ȭ��ų ��������� ����
	static void Temp2() { value2; }
	int temp1(int value) { this->value1 = value; }
	//mutable������ ���� ����
	//int temp2(int value) const { this->value1 = value; }
	static int temp3(int value) { value2 = value; }

private:
	/*mutable*/ int value1;
	static int value2;

public:
	int test;
};

int main()
{
	//Test::Temp1();		//__this call����̱� ������ �ν��Ͻ��� ���� ȣ���ؾ� �Ѵ�.
	Test t1;
	t1.Temp1();
	
	t1.Temp2();
	Test::Temp2();		//__this call�� �ƴϱ� ������ �ν��Ͻ����� ȣ���� ����

	//�Ϲ� �Լ��� ���� ����
	void (*ptr1)() = Test::Temp2;

	//__this call����� �Լ��� �Ϲ����� ������ �Լ������Ϳ� ���� �� ����.
	//void (*ptr1)() = Test::Temp1;

	/*
		��� ������
		- Ư�� Ŭ������ ���� ����� ����Ű�� ������
		- ��� �����͸� ����� ��� �Լ��� ���� �� �ִ�.
		- Ư�� �ν��Ͻ�ȭ�� ����� ��ġ�� �ƴ� ����� Ŭ������
		  �����ϴ� ������� ��ġ�� ������ ������ ����ϱ� ���ؼ� ��ü�� �־���� �Ѵ�.
		- �ּҿ� ������ �� (.*) �����ڸ� ����Ѵ�.
		- �⺻ ������ ���Ŀ��� ���ӽ����̽��� �߰����ָ� �ȴ�.

		������� ������
		�ڷ��� Ŭ�����̸�::*�������̸� = &Ŭ�����̸�::�����̸�

		����Լ� ������
		��ȯ�� (Ŭ�����̸�::*�Լ��������̸�) = &Ŭ�����̸�::�Լ��̸�;
	*/

	//������� ������
	int Test::*ptr3 = &Test::test;
	t1.*ptr3 = 10;		//��� �����ʹ� ���� �ν��Ͻ��� �ʿ�

	//����Լ� ������
	void (Test::*ptr4)() = &Test::Temp1;
	(t1.*ptr4)();

	//functional�� ����� ����Լ� ������
	std::function<void(Test)> fp = &Test::Temp1;
	fp(t1);
	std::function<void()> fp1 = Test::Temp2;
	fp1();
	
	return 0;
}