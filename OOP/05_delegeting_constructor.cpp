#include <iostream>
#include <string>

using namespace std;

/*
	delegeting constructor - ���� ������
	- ���� Ŭ�������� �����ڰ� �ٸ� �����ڸ� ȣ���ϴ� ��
*/

//������ �� id�� 0���� ����� name�� �ʱ�ȭ���ְ� ���� ��
class Student1
{
public:
	Student1(const int& id, const std::string& name)
		:id(id), name(name)
	{
		//...
		//...
		//...
	}

	//�̿� ���� �پ��� ������� �ʱ�ȭ�� �� ������ �ʱ�ȭ ����� �ϳ��� �ִ� ���� ���������ϱ⿡ ����.
	Student1(const std::string& name)
		//:id(0), name(name)
		: Student1(0, name)
	{
		//...
		//...
		//...
	}

	int getStu1()
	{
		return id;
	}

private:
	int id;
	std::string name;
};

//��� ����� �ʱ�ȭ���ִ� �Լ��� �����
//�����ڸ��� �ٸ��� ȣ��
//Student1�� Student2�� ���� ����� �����
class Student2
{
public:
	Student2(const int& id, const std::string& name)
		//:id(id), name(name)
	{
		Initilaize(id, name);
	}
	
	Student2(const std::string& name)
		//:id(0), name(name)
		//: Student2(0, name)
	{
		Initilaize(0, name);
	}
	
	void Initilaize(const int& id, const std::string& name)
	{
		
	}

	/*int getStu2()
	{
		return id;
	}*/

private:
	int id;
	std::string name;
};


int main()
{


	return 0;
}