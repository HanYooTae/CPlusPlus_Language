#include <iostream>
#include <string>

/*
	PP - Procedual Programming -> 프로시저(함수) -> 함수 단위로 실행
	OOP - Object Oriented Programming -> 객체지향(C++) -> 객체 단위로 실행
*/

/*
	객체(Object) => Class + Instance
	- Class
		ㅁ 무엇을 만들지에 대한 설계도, 혹은 상상 ex) dna, 붕어빵 틀, 자동차 설계도,...
		ㅁ 사물의 공통된 속성과 동작을 각각 멤버 변수(data) 멤버 함수(method)로 만들어 표현

	- Instance
		ㅁ class를 통해 만들어진 실체
		ㅁ class는 하나지만 하나의 class를 통해 다양한 instance가 존재한다.
		ex) 붕어빵 틀 하나에서 다양한 붕어빵을 만들 수 있다. (팥, 슈크림 등)
*/

/*
	객체지향 3요소		//4대 특징 (캡슐화, 정보은닉, 상속, 다형성)
	
	1.캡슐화(Encapsulation)
	- 객체의 속성(멤버 변수)와 동작(멤버 함수)를 클래스로 묶는 것
	- 접근 지정자를 통해 외부에 필요한 내용만 공개하고 나머지는 숨긴다. -> 정보은닉(Information hiding)
	- 필요한 정보만 공개해 사용하기 쉽게 한다. ex) 리모컨은 버튼만 조작하면 내부 회로를 몰라도 사용 가능

	2. 상속(Inheritence)
	- 상위 클래스의 속성과 기능을 물려받는 하위 클래스를 만들어 속성과 기능을 확장할 수 있다.
	- 부모 클래스, 자식 클래스라고도 부른다.

	3. 다형성(Polymorphism)
	- 하나의 객체가 여러 가지 형태의 자료형을 가질 수 있는 것
		-> 다양한 형태로 객체를 표현 가능
		ㅁ 오버라이딩
			ㄴ 상위 클래스가 가지고 있는 메소드를 하위 클래스가 재정의해서 사용하는 것
		ㅁ 오버로딩
			ㄴ 같은 이름을 가진 메소드를 인자 값의 형태나 개수를 다르게 하여 다른 기능을 수행하도록 정의하는 것
			ㄴ  호출 매개변수에 따라 매칭되어 함수를 실행시켜줌
*/

class Person	//상상, 설계도
//추상화
{	//캡슐화, {}로 데이터와 메소드를 묶음
//접근 지정자(access specifier) 접근 범위를 제어한다. (public, protected, private)
public:		//모두에게 공개
	void Work()
	{

	}

	void Sleep()
	{

	}

	//정보 은닉
protected:	//자신과 자식 클래스 내부에서만 사용 가능 (friend 키워드 사용 시 한정적으로 공개 가능 >> 일단 스킵)

private:	//자신만 사용 가능 (friend 키워드 사용 시 한정적으로 공개 가능 >> 일단 스킵)
	std::string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

class Animal		//오버라이딩
{
public:
	void Eat() { std::cout << "동물" << std::endl; }

	std::string name;
private:
};

class Dog : public Animal
{
public:
	void Eat() { std::cout << "개" << std::endl; }

	int age;
};

class Cat : public Animal
{
public:
	void Eat() { std::cout << "고양이" << std::endl; }

	int weight;
};


int main()
{
	Person person;		//person을 인스턴스라고 함(상상을 직접 실현시킨 것 = 실체)		//instance, object(객체)

	//person.age;			//error : 은닉된 정보 접근
	person.Sleep();			//공개된 내용만 접근 가능
	Dog d;
	d.Eat();

	Animal a;
	a.Eat();

	Cat c;
	c.Eat();


	return 0;
}