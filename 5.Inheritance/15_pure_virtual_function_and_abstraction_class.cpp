/*
	pure virtual function - 순수 가상 함수
	- 파생 클래스에서 반드시 재정의해야 하는 함수
	- 동작을 정의하는 몸체가 없다.
	- 정의되지 않는 함수이므로 순수 가상 함수를 포함한 클래스는
	  인스턴스화가 안되고 상속으로만 사용해야 한다.
	  -> 포인터 타입 자료형은 선언 가능

	  abstract class - 추상 클래스
	  - 하나 이상의 순수 가상 함수를 포함한 클래스

	  interface - 인터페이스
	  - 순수 가상 함수로만 이루어진 클래스
	  - C++에서는 보통 추상 클래스와 구분이 잘 가지 않아, 이름 앞에 I를 붙여 표시

	  과제 - 인터페이스를 사용하는 이유 조사하기
	  //TODO : 다음 주 월요일에 사용하는 이유 설명
*/

#include <iostream>
#include <string>
using namespace std;

#define 순수_가상_함수와_추상_클래스

#ifdef 순수_가상_함수와_추상_클래스

class Animal	//추상 클래스
{
public:
	Animal(const string& name) : name(name) {}

	auto GetName() const { return name; }

	//virtual void Speak() const { cout << "???" << endl; }
	virtual void Speak() const = 0;		//순수 가상 함수
	
private:
	string name;
};

class Cat : public Animal
{
public:
	Cat(string name) : Animal(name) {}
	void Speak() const { cout << "Meow" << endl; }
};

class Dog : public Animal
{
public:
	Dog(string name) : Animal(name) {}
	void Speak() const { cout << "Woof" << endl; }
};


class Fox : public Animal
{
public:
	Fox(string name) : Animal(name) {}
};

int main()
{
	Cat cat("DiDi");
	Dog dog("Corgi");

	cat.Speak();
	dog.Speak();

	//순수 가상 함수를 가지는 클래스이므로 실체화 불가능
	//Animal ani("lala");
	//ani.Speak();

	//상속받은 순수 가상 함수를 재정의하지 않아 에러
	//Fox fox("RURU");
	//fox.Speak();

	return 0;
}
#endif // 순수_가상_함수와_추상_클래스
