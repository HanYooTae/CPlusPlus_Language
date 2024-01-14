//���� �Լ��� ���� �������̵�(������)
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

	//����� �θ� Ŭ������ ��ĳ�����Ͽ� �ڽ� Ŭ������ ���� �ϰ������� ó�� ����
	
	//Animal Ŭ������ ��ĳ����
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

	//1. ??�� ��µ� : �� ĳ���� �� ���� ����� ���� ���� ��� ��� Ŭ���� ������ �Լ��� ȣ���
	//2. virtual�� ����� �������̵�����, �ϳ��� Ŭ������ �پ��� �ڷ����� ǥ���� -> ������
	for (const auto& animal : animals)
		animal->Speak();				//virtual�� �Ⱥ��̸� ���о��� Animal Ŭ������ Speak�� ��µȴ�.

	return 0;
}

// ���� : SOLID ��ü���� 5�� ��Ģ �����ϱ�