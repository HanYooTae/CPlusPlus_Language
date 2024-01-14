//가상 함수를 통한 오버라이딩(다형성)
#include <iostream>
#include <string>
using namespace std;

class Animal
{
public:
	Animal(string name) : name(name) {}

	//1.
	//void Speak() const { cout << "??" << endl; }

	//2.
	virtual void Speak() const { cout << "??" << endl; }

protected:
	string name;
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	virtual void Speak() const { cout << "Meow" << endl; }

protected:
	string name;
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	virtual void Speak() const { cout << "Woof" << endl; }

protected:
	string name;
};

int main()
{
	Cat cats[]{ Cat("cat1"),Cat("cat2"),Cat("cat3"),Cat("cat4"),Cat("cat5") };
	Dog dogs[]{ Dog("dog1"),Dog("dog2"),Dog("dog3"),Dog("dog4"),Dog("dog5") };

	for (const auto& cat : cats)
		cat.Speak();

	for (const auto& dog : dogs)
		dog.Speak();


	cout << endl;

	//공통된 부모 클래스로 업캐스팅하여 자식 클래스를 묶어 일괄적으로 처리 가능
	
	//Animal 클래스로 업캐스팅
	Animal* animals[]
	{
		&cats[0],
		&cats[1],
		&cats[2],
		&cats[3],
		&cats[4],
		&dogs[0],
		&dogs[1],
		&dogs[2],
		&dogs[3],
		&dogs[4]
	};

	//1. ??만 출력됨 : 업 캐스팅 시 가장 상속을 하지 않을 경우 기반 클래스 기준의 함수가 호출됨
	//2. virtual을 사용한 오버라이딩으로, 하나의 클래스로 다양한 자료형을 표현함 -> 다형성
	for (const auto& animal : animals)
		animal->Speak();				//virtual을 안붙이면 구분없이 Animal 클래스의 Speak가 출력된다.

	return 0;
}

// 과제 : SOLID 객체지향 5대 원칙 조사하기