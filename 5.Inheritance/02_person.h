#pragma once
#include <string>

//서로 중복된 멤버를 가지는 student와 teacher가 있다.
//코드에 중복이 생겨 유지보수가 어려워짐 -> 수정하기 위해선 둘다 변경해야함
//공통된 멤버를 상위 클래스로 만들어 상속시켜주기

//아래와 같은 두 클래스를 상속을 통해 줄여보자

class EX_Student
{
public:
	EX_Student() = default;
	EX_Student(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) /*const*/ { this->name = name; }		//const넣으면 수정이 안됨

	void Study(){}

private:
	std::string name;
};

class EX_Teacher
{
public:
	EX_Teacher() = default;		//생성자는 왠만하면 1개만 생성해두는 것이 좋다.
	EX_Teacher(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) /*const*/ { this->name = name; }		//const넣으면 수정이 안됨

	void Teach() {}

private:
	std::string name;
};

//중복되는 멤버를 상위 클래스에 작성
class Person
{
public:		//접근 지정자
	Person() = default;
	Person(const std::string& name) :name(name) {}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

protected:
	std::string name;
};