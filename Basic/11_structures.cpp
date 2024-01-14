#include <iostream>

using namespace std;

struct person		//C������ ����ü �ȿ� �⺻���� �־����� ����	//C++���� �⺻���� �־��ָ� �־��� ������ �ٲ��.
{
	/*
		- ����ü �ȿ� �ִ� �Լ��� �޸� �ؽ�Ʈ(�ڵ�) ������
		  �̸� �Ҵ�Ǿ� ũ�⸦ �������� �ʴ´�.
		- �̸� �����ֱ� ������ ������ ���� ȣ������ �ʾƵ� ����� �� ������
		  Ŭ���� ��� �Լ��� __thiscall�����̱� ������
		  ()�ȿ� �ƹ��͵� ��������� �ش��ϴ� ��ü�� �����Ͱ� ���� ������
		  person::Print();�� ���� ȣ���� �� ����.
	*/

	//����Լ�
	//����ü �ȿ� �ۼ��� �Լ��� ����� ���Ե��� �ʴ´�
	void /*__thiscall*/ Print(/*person this*/)
	{
		//this;
		cout << /*this->*/age << endl;
	}

	//void /*__thiscall*/ Print(/*person* this*/int age)		// �Ű������� ������ �̸��� ������ ����Ǿ��ִٸ� this�� �������־�� ��
	//{
	//	this->age;
	//	age;
	//	cout << age << endl;
	//}

	/*
		���� : C++ �Լ�ȣ��Ծ� (funtion calling convension) ����
	*/

	//C�� �ٸ��� �⺻�� ������ ����
	//�������
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
	cout << p2.age << endl;		//age�� �ʱ�ȭ���� �ʾ����� ���� ����. �����Ⱚ ���
	cout << p2.weight << endl;
	cout << p2.name << endl;


	cout << endl;
	p1.Print(/*&p1*/);
	

	return 0;
}