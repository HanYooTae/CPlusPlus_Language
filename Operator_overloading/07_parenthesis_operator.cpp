//��ȣ ������

#include <iostream>
using namespace std;

class Counter
{
public:
	int operator()(int i) { return count += i; }

private:
	int count = 0;
};

int main()
{
	Counter ct;

	cout << ct(30) << endl;		//Function object - Functor
	cout << ct(300) << endl;	//��ü�� �Լ�ó�� ���

	return 0;
}