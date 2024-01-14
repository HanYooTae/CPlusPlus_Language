#include <iostream>
#include <string>

using namespace std;

/*
	delegeting constructor - 위임 생성자
	- 같은 클래스에서 생성자가 다른 생성자를 호출하는 것
*/

//생성할 때 id는 0으로 만들고 name만 초기화해주고 싶을 때
class Student1
{
public:
	Student1(const int& id, const std::string& name)
		:id(id), name(name)
	{
		//...
		//...
		//...
	}

	//이와 같이 다양한 방식으로 초기화할 수 있지만 초기화 방식은 하나만 있는 것이 유지보수하기에 좋다.
	Student1(const std::string& name)
		//:id(0), name(name)
		: Student1(0, name)
	{
		//...
		//...
		//...
	}

	int getStu1()
	{
		return id;
	}

private:
	int id;
	std::string name;
};

//모든 멤버를 초기화해주는 함수를 만들어
//생성자마다 다르게 호출
//Student1과 Student2는 같은 결과를 출력함
class Student2
{
public:
	Student2(const int& id, const std::string& name)
		//:id(id), name(name)
	{
		Initilaize(id, name);
	}
	
	Student2(const std::string& name)
		//:id(0), name(name)
		//: Student2(0, name)
	{
		Initilaize(0, name);
	}
	
	void Initilaize(const int& id, const std::string& name)
	{
		
	}

	/*int getStu2()
	{
		return id;
	}*/

private:
	int id;
	std::string name;
};


int main()
{


	return 0;
}