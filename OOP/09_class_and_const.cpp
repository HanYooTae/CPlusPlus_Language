#include <iostream>

using namespace std;

/*
	const ��� �Լ�
	- �ش� ��� �Լ������� ���ο��� ��� ������ ���ȭ�ȴ�. -> ���� �Ұ���
	- mutable�� ����� ��� ������ ����
*/

class Data
{

public:
	Data() : value1(0), value2(0) {}

	//const ����Լ��� ��� ������ ��� ���ȭ�Ǿ� ���� �Ұ���
	//void SetValue1(int value) const { this->value1 = value; }		//error

	const void setValue2(int value) const { this->value2 = value; }		//mutable Ű���尡 �ִ� ��������� �����ϴ�.

	int& GetValue() { cout << "not const" << endl; return value1; }
	
	//const �Լ����� ��������� ������ ������ ��� ���� -> ��ȸ������ ���� ������ �� �ֱ� ������
	//int& GetValue1() const { cout << "const" << endl; return value1; }
	//��� ������ ������ ��ȯ�� ��� const�� �ٿ� �������ϴ� ���·� ������־�� �Ѵ�.
	const int& GetValue1() const { cout << "const" << endl; return value1; }
	const int& GetValue2() const { cout << "mutable" << endl; return value2; }
	int& GetValue3() const { cout << "Mutable" << endl; return value2; }

	int test() { return 0; }

private:
	int value1;
	mutable int value2;		//mutable : const ����Լ� ���ο����� ������ ����������.

	/*
		https://modoocode.com/253
		explicit(����� ��ȯ <> �Ͻ��� ��ȯ(implicit))�� ���۸��� ��!
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
		�ܺο��� ���� ���ڰ��� �Ϲ� ��ü ���¿���
		���� �޴� �Ű������� �ڷ����� ����̱� ������
		const ����Լ��� ȣ���� �����ϴ�.
		�׷��� ������ ��� ������ ���� ������ ���� ��� �Լ����� ��� const�� �ٿ��־�
		const ��ü������ ȣ���� �����ϵ��� ����°� ����.
	*/
	data.GetValue1();
}

int main()
{
	Data data1;
	const Data data2;		//��� ��ü�� const ��� �Լ��� ȣ�� ����

	data1.GetValue() = 10;
	//data2.GetValue() = 10;	//���� ���ɼ��� �ִ� �Ϲ� ��� �Լ��� ȣ������ ����
	//data2.test();			//������ ���ɼ��� �ֱ� ������ ȣ������ ����

	data1.GetValue1();
	data2.GetValue1();

	return 0;
}