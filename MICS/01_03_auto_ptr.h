#pragma once

/*
	std::auto_ptr<T>
	- C++ 98�� ó�� �߰�
	- C++ 11���� �ֱ� ������ ��������� �ǰ���
	- C++ 17���� ������
*/

// auto_ptr�� ������ ������ �ִ� �����͸� �ּҸ� �ٸ� �����Ͱ� �������� ���ϵ��� ����
// ���� ���� �����Ͱ� ���� �ּҸ� ����Ű�� �ִٸ� ��� ������ �߻�

template<typename T>
class AutoPtr final
{
public:
	AutoPtr(T* ptr = nullptr)
		:ptr(ptr)
	{}

	// �Ҹ� �� �ڵ����� �����ϵ��� ����
	~AutoPtr()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	};

	// auto_ptr�� �ϳ��� �ּҸ� ���� ���� auto_ptr�� ������ ���ϰ� �����.
	// unique point - ������ �������� �ϳ��� ���� ��
	// ���� �õ�
	AutoPtr(const AutoPtr& other)
	// ������ ������ �� �ٸ� Ŭ������ �޾Ƽ� ����
	{
		ptr = other.ptr;		// other�� �ִ� �����͸� �Ѱ���		// other�� ������ �������� �Ѱ���
		other.ptr = nullptr;	// other�� ������ �ִ� �����͸� nullptr�� �ٲ���		// other���� ���̻� �����Ϳ� �������� ���ϵ��� �Ѵ�.
	}

	// ����
	AutoPtr& operator = (AutoPtr& other)
	{
		// �ڱ� �ڽ��� ��� ���
		if (other == *this)
			return *this;

		//�����ϴ� �����Ͱ� �ִٸ� ����
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}

		ptr = other.ptr;
		other.ptr = nullptr;

		return *this;		// ü�̴��� ���ؼ� ������ ������ ����
	}

	void Test() {}

	//������ó�� ����� �� �ֵ��� ������ ������(operator overloading)
	T& operator * () const { return *ptr; }
	T* operator -> () const { return ptr; }


private:
	T* ptr = nullptr;
};