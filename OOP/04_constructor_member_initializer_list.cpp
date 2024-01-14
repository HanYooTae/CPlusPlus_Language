#include <iostream>

using namespace std;

class Data
{
public:
	Data(const int a, int b, int c/*, int& d*/)

		//������ ���ÿ� �ʱ�ȭ�ϴ� �Ͱ� �����ϴ�.
		//�ʱ�ȭ ����Ʈ���� ���� �־��ָ� ������ ���� ���õ�
		: a(a)	//a(a)   a -> �������, (a) -> ��������
		, b(b)
		, c(c)

	{	//������ ����
		
		//�̹� a, b, c �޸𸮰� ������� ���·� ����Ǿ� const�� ������ ������ �ȵ�
		//this->a = a;
		//this->b = b;
		//this->c = c;

	
	}
	

	int GetA() { return a; }

private:
	const int a;
	const int b;
	const int c;
	//int& d;	//�̷� ������ ����
};

int main()
{
	Data test(20, 10, 10);

	cout << test.GetA() << endl;

	//�ʱ�ȭ ����Ʈ���� ���� �־��ָ� ������ ���� ���õǰ�, �Ʒ� �Է��� ��� ������ �������
	Data data(30, 20, 20);
	
	cout << data.GetA() << endl;

	return 0;
}