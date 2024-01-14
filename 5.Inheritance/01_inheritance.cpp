/*
	Inheritance - ���
	- �ٸ� Ŭ������ ������ �״�� ������ �� �ִ� ���
	- ����� ������ ���ȭ�Ͽ� �ڵ带 �����ϱ⿡ �����ϴ�.
	- �ϻ� Ŭ������ ����� ��� Ŭ������ ����� ����/Ȯ���ϱ⿡ ����
	- �ڵ��� �ߺ��� �ٿ� ����ȭ�� �� �ִ�.
*/
#include <iostream>
using namespace std;

//Base class - ��� Ŭ����
class Mother
{
public:
	int GetA() const
	{
		cout << "mother" << endl;
		return a;
	}

	void SetA(const int& a) { this->a = a; }

private:
	int a;

protected:
	int b;

public:
	int c;
};

//Derived class - �Ļ� Ŭ����, ��� Ŭ������ ������ �״�� ��������
class Daughter : public Mother
{
public:
	//��� Ŭ������ private����� ��ӵǾ ���� �Ұ���
	//�ڽĿ����� protected�� public�� ���� ����
	//int GetA() const { return a; }	//error

	int GetA() const
	{
		//�θ��� ����� �״�� ��밡�� -> ���� ��� �ÿ��� ��ȣ�� �� ����
		//���߻�� - �� Ŭ������ �� ���� �� �� �̻��� Ŭ������ ��ӹ޴� ��
		c;			//Mother::c

		//���/�Ļ� Ŭ������ ����� ��ĥ ���, �Ļ� Ŭ������ ����� �켱�õȴ�.
		b;			//Daughter::b
		//���ӽ����̽��� ����Ͽ� ���а���
		Mother::b;

		cout << "Daughter" << endl;

		return Mother::GetA();
	}

	//__super�� �θ� Ŭ���� ǥ�� ����, VC���� Ű����
	int GetAA() const { return __super::GetA(); }

private:
	int b;
};

int main()
{
	//�ν��Ͻ�ȭ�� �� ��ӹ��� Ŭ������ �����Ѵٸ�
	//�ֻ��� Ŭ�����κк��� ������	(�켱�õǴ� �Ŷ� ȣ��Ǵ� ���� �ٸ� ��)
	//Mother ���� -> Daughter ����
	Daughter d;

	//��� Ŭ���� Mother�κ��� ��ӹ��� ��� �Լ� SetA ȣ��
	d.SetA(10);

	//��� Ŭ������ �Ļ� Ŭ������ ���� �̸��� ��ġ�� ����� ���� ���,
	//������°� �ƴ϶� �ڽ��� ���� �켱�̴�.
	d.GetA();

	cout << "1####################" << endl;

	//������ ��� Ŭ������ ����� ����ϰ� �ʹٸ�
	d.Mother::GetA();

	return 0;
}