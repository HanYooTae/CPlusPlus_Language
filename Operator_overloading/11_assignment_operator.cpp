/*
	deep copy vs shallow copy -> ���� ���� vs ���� ����
	move�� ���� ���縦 ���
*/

#include <iostream>
#include <cassert>
using namespace std;

class Mystring
{
public:
	Mystring(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1;		//�ι��ڱ��� �������ֱ� ���ؼ� +1
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';		//�� length - 1�� �ι������� Ȯ���غ���
	}

	~Mystring()
	{
		if (data != nullptr)
		{
			//��������� ����
			delete[] data;		//Hello ��ü�� �迭�̱� ������ �迭�� �޾ƾ� ��
			data = nullptr;
		}
	}

	//copy constructor
	Mystring(const Mystring& other)
	{
		cout << "copy constructor" << endl;

		//shallow copy
		//������ �ִ� ���� �״�� �����ϴ� ��
		//���� : �����Ͱ� ����� �� �ּҰ� �Ѿ��.
		//������ ������ �ּҿ� ��������. -> �Ҹ��� �� ������ ���� �� �ִ�.
		//length = other.length;
		//data = other.data;

		//deep copy
		//���ο� ������ ���� ���� -> ��������� ���� ���ɼ� X
		//���� �Ҵ��� �ؼ� ����
		//��Ȳ�� ���� �ΰ��� copy�� ������ �������
		//copy = str�� �ּ�ó���ؼ� ���� �ذ�
		/*this->*/length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;
	}

	//copy assignment operator
	// �ܺο� �����ϴ� �����͸� �������� ��. ������ ũ�⸸ŭ �����Ҵ��� �� �Ŀ� ������
	Mystring& operator = (const Mystring& other)		
	{
		//������ �ڵ带 ����� ���� ������

		//1.
		//prevent self_assignment -> �ڽ��� �Ҵ��ϴ� �� ����
		if (this == &other) return *this;

		//2. �̹� �����Ҵ�� �����Ͱ� ���� ��� �޸� ������ �Ͼ �� �ִ�.
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		cout << "copy assignment operator" << endl;
		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;

		return *this;		//ü�̴��� ���Ͽ� �ڱ��ڽ� ��ȯ
	}

	//move constructor
	//���� ��ü�� �������� ���� -> �ܺο� other�� ���̻� �������� ���� ���̶�� ��
	Mystring(Mystring&& other) noexcept	//���� ���� �� or �״�� ����� ���̱� ������ ���� const�� �Ⱥٿ��� ��.
	{
		cout << "move constructor" << endl;

		//move : Lvalue�� Rvalue�� �ٲ��ִ� ��
		this->	data = move(other.data);
		this->length = move(other.length);

		//���� other�� ���̻� �������� �ʴ´ٰ� ������
		//-> �ܺο� ������ ��� �����Ҵ�� �����͸� �����ϸ�
		//������ ���� �� �ֱ� ������ �ּҸ� nullptr�� �ʱ�ȭ���־�� ����
		// �������� �����ִ� ��
		other.data = nullptr;
	}

	//move assignment operator
	// �������� �Ѱ��ִ� ��
	Mystring& operator = (Mystring&& other) noexcept		//throw�� ����?
	{
		cout << "move assignment operator" << endl;

		//1.
			//prevent self_assignment -> �ڽ��� �Ҵ��ϴ� �� ����
		if (this == &other) return *this;

		//2. �̹� �����Ҵ�� �����Ͱ� ���� ��� �޸� ������ �Ͼ �� �ִ�.
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		this->length = std::move(other.length);
		this->data = std::move(other.data);

		other.data = nullptr;
		return *this;
	}

public:
	char* data = nullptr;
	int length = 0;
};

//���糪 �̵��� �Ǵ� ���� ��õ������ ���� Ŭ����
class Test
{
private:
	//������� �ʰ� �Ϸ��� delete�� �߰��ص� ��
	Test(const Test&)/* = delete*/;
	Test(Test&&)/* = delete*/;
	Test& operator = (const Test&);
	Test& operator = (Test&&);
};

int main()
{
	cout << "1#######################################" << endl;
	Mystring str("Hello");
	cout << (void*)str.data << endl;		//�ʿ����� ���� ����� ������� �ʱ� ���Ͽ� int*�� �ƴ϶� void*�� ����ϴ� ���� ���� ����
	cout << str.data << endl;

	cout << "2#######################################" << endl;
	{
		Mystring copy(str);		// ���������� ���� ��� ���� ����� ���ǵȴ�.
		//copy = str;			
		copy = str;				// ���������� ���� ��� ���� ����� ���ǵȴ�.
		cout << (void*)copy.data << endl;
		cout << copy.data << endl;
	}

	{
		Mystring move(std::move(str));
		//move = str;
		
		cout << (void*)move.data << endl;
		cout << move.data << endl;
	
	}

	return 0;
}