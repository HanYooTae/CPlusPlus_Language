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

//1. .h�� �����θ� ���� ����
//template<class T>
//inline void MyArray<T>::Print()
//{
//}

//2. �ζ��� ������ ����� �и�
#include "02_my_array.inl"
