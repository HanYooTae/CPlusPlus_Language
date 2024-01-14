#include <iostream>
using namespace std;

template<class T>
class A
{
public:
	A(const T& value)
		: value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}

private:
	T value;
};
//포인터로 들어왔을 때 특수화 진행
//template<class T>		//모든 포인터 타입에 대해 특수화를 해야하기 때문에 명시해야 함
//class A<T*>				//포인터에 대한 특수화
//{
//public:
//	A(T* value)
//		: value(value)
//	{}
//
//	void Print()
//	{
//		cout << *value << endl;
//	}
//
//private:
//	T* value;
//};

int main()
{
	A<int> a_int(123);
	a_int.Print();

	int temp = 456;

	A<int*> a_int_ptr(&temp);
	a_int_ptr.Print();

	return 0;
}