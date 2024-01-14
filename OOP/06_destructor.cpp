#include <iostream>

using namespace std;

/*
	destructor - �Ҹ���
	- Ŭ������ �Ҹ�� �� ȣ��Ǵ� �Լ�
	- �Ҹ� �� �ʿ��� �۾��� ���ش�.
	- �����ε��� �ȵǱ� ������ �ϳ��� �����Ѵ�.
*/

class Test
{
public:
	int c = 1;
	Test()
	{
		cout << "Constructor!!, " << c << endl;
	}

	// ~ : tilde (not ������ �ǹ�)
	~Test()	//�Ҹ���
	{
		c--;
		cout << "Destructor!!, " << c << endl;		//���Ͱ� �׾��� �� �������� ���� �� ��� ����
	}
};

class IntArray
{
public:

	IntArray(const int& length)
		: length(length)
	{
		arr = new int[length];

		cout << "Constructor!!" << endl;
	}

	~IntArray()		//�Ҹ��ڰ� ȣ��Ǹ鼭 ���� ����
	{
		if (arr != nullptr)
		{
			delete[] arr;
			arr = nullptr;
		}
		cout << "Destructor!!" << endl;

	}

private:
	int* arr = nullptr;
	const int length;
};

int main()
{
	cout << "####################################################1" << endl;
	{
		cout << "####################################################2" << endl;
		Test test;
		cout << "####################################################3" << endl;
	}
	cout << "####################################################4" << endl;

	/*while (true)*/	//�޸� ������ �Ͼ �� �ִ�.
	{
		IntArray my_arr(1000);
		cout << "hi" << endl;
		//~IntArray()�� ����ϸ� delete�� ����� �ʿ䰡 ����
		//delete[] my_arr.arr;		//�� �ٻ��� �޸� ������ �Ͼ
	}
	return 0;
}