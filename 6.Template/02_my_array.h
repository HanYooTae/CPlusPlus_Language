#pragma once

template<class T>

class MyArray
{
public:
	MyArray(int length)
		: length(length)
	{
		arr = new T[length];
	}

	~MyArray()
	{
		delete[] arr;
	}

	void Print();

private:
	T* arr = nullptr;
	int length = 0;
};

//1. .h에 구현부를 같이 정의
//template<class T>
//inline void MyArray<T>::Print()
//{
//}

//2. 인라인 파일을 만들어 분리
#include "02_my_array.inl"
