#pragma once

/*
	std::auto_ptr<T>
	- C++ 98에 처음 추가
	- C++ 11에서 있긴 하지만 쓰지말라고 권고함
	- C++ 17에서 삭제됨
*/

// auto_ptr은 본인이 가지고 있는 포인터를 주소를 다른 포인터가 공유하지 못하도록 막음
// 여러 개의 포인터가 같은 주소를 가리키고 있다면 허상 포인터 발생

template<typename T>
class AutoPtr final
{
public:
	AutoPtr(T* ptr = nullptr)
		:ptr(ptr)
	{}

	// 소멸 시 자동으로 해제하도록 만듬
	~AutoPtr()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	};

	// auto_ptr은 하나의 주소를 여러 개의 auto_ptr이 가지지 못하게 만든다.
	// unique point - 무조건 소유권을 하나만 갖는 것
	// 복사 시도
	AutoPtr(const AutoPtr& other)
	// 본인을 생성할 때 다른 클래스를 받아서 생성
	{
		ptr = other.ptr;		// other에 있는 포인터를 넘겨줌		// other의 데이터 소유권을 넘겨줌
		other.ptr = nullptr;	// other가 가지고 있는 포인터를 nullptr로 바꿔줌		// other에서 더이상 데이터에 접근하지 못하도록 한다.
	}

	// 대입
	AutoPtr& operator = (AutoPtr& other)
	{
		// 자기 자신일 경우 취소
		if (other == *this)
			return *this;

		//존재하는 데이터가 있다면 삭제
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}

		ptr = other.ptr;
		other.ptr = nullptr;

		return *this;		// 체이닝을 위해서 본인의 참조를 리턴
	}

	void Test() {}

	//포인터처럼 사용할 수 있도록 연산자 재정의(operator overloading)
	T& operator * () const { return *ptr; }
	T* operator -> () const { return ptr; }


private:
	T* ptr = nullptr;
};