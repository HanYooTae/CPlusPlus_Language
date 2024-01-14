#include <iostream>

using namespace std;

/*
	destructor - 소멸자
	- 클래스가 소멸될 때 호출되는 함수
	- 소멸 시 필요한 작업을 해준다.
	- 오버로딩이 안되기 때문에 하나만 존재한다.
*/

class Test
{
public:
	int c = 1;
	Test()
	{
		cout << "Constructor!!, " << c << endl;
	}

	// ~ : tilde (not 부정의 의미)
	~Test()	//소멸자
	{
		c--;
		cout << "Destructor!!, " << c << endl;		//몬스터가 죽었을 때 아이템을 떨굴 때 사용 가능
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

	~IntArray()		//소멸자가 호출되면서 동적 해제
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

	/*while (true)*/	//메모리 누수가 일어날 수 있다.
	{
		IntArray my_arr(1000);
		cout << "hi" << endl;
		//~IntArray()를 사용하면 delete를 사용할 필요가 없음
		//delete[] my_arr.arr;		//이 줄빼면 메모리 누수가 일어남
	}
	return 0;
}