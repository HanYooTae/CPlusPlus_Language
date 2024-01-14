/*
	deep copy vs shallow copy -> 깊은 복사 vs 얕은 복사
	move는 얕은 복사를 사용
*/

#include <iostream>
#include <cassert>
using namespace std;

class Mystring
{
public:
	Mystring(const char* const src = "")
	{
		assert(src);

		length = strlen(src) + 1;		//널문자까지 포함해주기 위해서 +1
		data = new char[length];

		for (int i = 0; i < length; i++)
			data[i] = src[i];

		data[length - 1] = '\0';		//왜 length - 1이 널문자인지 확인해보기
	}

	~Mystring()
	{
		if (data != nullptr)
		{
			//허상포인터 문제
			delete[] data;		//Hello 자체가 배열이기 때문에 배열로 받아야 함
			data = nullptr;
		}
	}

	//copy constructor
	Mystring(const Mystring& other)
	{
		cout << "copy constructor" << endl;

		//shallow copy
		//가지고 있는 값을 그대로 전달하는 것
		//문제 : 포인터가 복사될 때 주소가 넘어간다.
		//원본의 데이터 주소와 같아진다. -> 소멸할 때 문제가 생길 수 있다.
		//length = other.length;
		//data = other.data;

		//deep copy
		//새로운 공간을 만들어서 복사 -> 허상포인터 생성 가능성 X
		//동적 할당을 해서 느림
		//상황에 따라 두개의 copy를 적절히 사용하자
		//copy = str을 주석처리해서 문제 해결
		/*this->*/length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;
	}

	//copy assignment operator
	// 외부에 존재하는 데이터를 가져오는 것. 가져올 크기만큼 동적할당을 한 후에 가져옴
	Mystring& operator = (const Mystring& other)		
	{
		//안전한 코드를 만들기 위한 주의점

		//1.
		//prevent self_assignment -> 자신을 할당하는 것 방지
		if (this == &other) return *this;

		//2. 이미 동적할당된 데이터가 있을 경우 메모리 누수가 일어날 수 있다.
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		cout << "copy assignment operator" << endl;
		length = other.length;
		if (other.data != nullptr)
		{
			data = new char[length];
			for (int i = 0; i < length; i++)
				data[i] = other.data[i];
		}
		else
			data = nullptr;

		return *this;		//체이닝을 위하여 자기자신 반환
	}

	//move constructor
	//원본 자체를 가져오는 개념 -> 외부에 other가 더이상 존재하지 않을 것이라는 뜻
	Mystring(Mystring&& other) noexcept	//쓰고 버릴 값 or 그대로 사용할 값이기 때문에 굳이 const를 안붙여도 됨.
	{
		cout << "move constructor" << endl;

		//move : Lvalue를 Rvalue로 바꿔주는 것
		this->	data = move(other.data);
		this->length = move(other.length);

		//받은 other는 더이상 존재하지 않는다고 가정함
		//-> 외부에 존재할 경우 동적할당된 데이터를 공유하면
		//문제가 생길 수 있기 때문에 주소를 nullptr로 초기화해주어야 한전
		// 소유권일 뺏어주는 것
		other.data = nullptr;
	}

	//move assignment operator
	// 소유권을 넘겨주는 것
	Mystring& operator = (Mystring&& other) noexcept		//throw가 뭐지?
	{
		cout << "move assignment operator" << endl;

		//1.
			//prevent self_assignment -> 자신을 할당하는 것 방지
		if (this == &other) return *this;

		//2. 이미 동적할당된 데이터가 있을 경우 메모리 누수가 일어날 수 있다.
		if (this->data != nullptr)
		{
			delete[] this->data;
			this->data = nullptr;
		}

		this->length = std::move(other.length);
		this->data = std::move(other.data);

		other.data = nullptr;
		return *this;
	}

public:
	char* data = nullptr;
	int length = 0;
};

//복사나 이동이 되는 것을 원천적으로 막는 클래스
class Test
{
private:
	//사용하지 않게 하려면 delete를 추가해도 됨
	Test(const Test&)/* = delete*/;
	Test(Test&&)/* = delete*/;
	Test& operator = (const Test&);
	Test& operator = (Test&&);
};

int main()
{
	cout << "1#######################################" << endl;
	Mystring str("Hello");
	cout << (void*)str.data << endl;		//필요하지 않은 기능을 사용하지 않기 위하여 int*가 아니라 void*로 사용하는 것이 좀더 안전
	cout << str.data << endl;

	cout << "2#######################################" << endl;
	{
		Mystring copy(str);		// 재정의하지 않을 경우 얕은 복사로 정의된다.
		//copy = str;			
		copy = str;				// 재정의하지 않을 경우 얕은 복사로 정의된다.
		cout << (void*)copy.data << endl;
		cout << copy.data << endl;
	}

	{
		Mystring move(std::move(str));
		//move = str;
		
		cout << (void*)move.data << endl;
		cout << move.data << endl;
	
	}

	return 0;
}