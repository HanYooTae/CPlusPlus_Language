#include <iostream>
using namespace std;

template<class T, int size>
class StaticArray
{
public:
	T* GetArray() { return arr; }
	T& operator[](int index)
	{
		return arr[index];
	}

	void Print1()
	{
		for (int i = 0; i < size; i++)
			cout << (*this)[i] << ' ';
		cout << endl;
	}

public:
	T arr[size];
};

template<typename T, int size>
void Print2(StaticArray<T, size>& arr)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
	cout << endl;
}

template<int size>
void Print2(StaticArray<char, size>& arr)
{
	for (int i = 0; i < size; i++)
		cout << arr[i];
	cout << endl;
}

int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.Print1();
	Print2(int4);


	StaticArray<char, 6> char6;
	char6[0] = 'H';
	char6[1] = 'E';
	char6[2] = 'L';
	char6[3] = 'L';
	char6[4] = 'O';
	char6[5] = '\0';

	char6.Print1();
	//cout.clear();
	Print2(char6);

	return 0;
}