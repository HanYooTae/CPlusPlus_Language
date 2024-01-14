/*
	RTTI : Run Time Type Information
	- ��Ÿ�� �߿� �ǽð����� ������ Ÿ�Կ� ���� ������ ��� ���
	- RTTI ����� �����־�� ��Ÿ�� �� �ڷ����� Ȯ�� ����
	- dynamic_cast�� ����� ���� �ʿ��ϴ�.
	- ��Ÿ�� �� �ڷ����� ����ؾ��ϱ� ������ ������.
	https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=kyed203&logNo=220164579551
*/

#include <iostream>
#include <typeinfo>		// RTTI ��� ���

using namespace std;

//int add(int a, int b) { return a + b; }
//int add(float a, int b) { return a + b; }

//�ڷ����� ������� ���α׷����� ���� �� �ִ� �� : �Ϲ�ȭ ���α׷���(���ø�) generic type
template<typename T>
T add(T a, T b)
{
	//cout << "a : " << a << endl;
	//cout << "b : " << b << endl;
	cout << "a : " << typeid(a).name() << endl;				//typeid(������).name() -> ������ �ڷ��� ���
	cout << "b : " << typeid(b).name() << endl;

	return a + b;
}

//template<typename T, typename T2>
//T add(T a, T2 b)
//{
//	cout << "a : " << a << endl;
//	cout << "b : " << b << endl;
//}


int main()
{
	//add(10, 20);
	//add(10.0f, 20);

	//add<int>(10, 20);
	//add<float>(10.0f, 20.0f);
	//add<float, int>(10.0f, 20);

	add(10, 20);
	add(10.0f, 20.0f);
	//add(10.0f, 20);

	return 0;
}