/*
	pure virtual function - ���� ���� �Լ�
	- �Ļ� Ŭ�������� �ݵ�� �������ؾ� �ϴ� �Լ�
	- ������ �����ϴ� ��ü�� ����.
	- ���ǵ��� �ʴ� �Լ��̹Ƿ� ���� ���� �Լ��� ������ Ŭ������
	  �ν��Ͻ�ȭ�� �ȵǰ� ������θ� ����ؾ� �Ѵ�.
	  -> ������ Ÿ�� �ڷ����� ���� ����

	  abstract class - �߻� Ŭ����
	  - �ϳ� �̻��� ���� ���� �Լ��� ������ Ŭ����

	  interface - �������̽�
	  - ���� ���� �Լ��θ� �̷���� Ŭ����
	  - C++������ ���� �߻� Ŭ������ ������ �� ���� �ʾ�, �̸� �տ� I�� �ٿ� ǥ��

	  ���� - �������̽��� ����ϴ� ���� �����ϱ�
	  //TODO : ���� �� �����Ͽ� ����ϴ� ���� ����
*/

#include <iostream>
#include <string>
using namespace std;

#define ����_����_�Լ���_�߻�_Ŭ����

#ifdef ����_����_�Լ���_�߻�_Ŭ����

class Animal	//�߻� Ŭ����
{
public:
	Animal(const string& name) : name(name) {}

	auto GetName() const { return name; }

	//virtual void Speak() const { cout << "???" << endl; }
	virtual void Speak() const = 0;		//���� ���� �Լ�
	
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

	//���� ���� �Լ��� ������ Ŭ�����̹Ƿ� ��üȭ �Ұ���
	//Animal ani("lala");
	//ani.Speak();

	//��ӹ��� ���� ���� �Լ��� ���������� �ʾ� ����
	//Fox fox("RURU");
	//fox.Speak();

	return 0;
}
#endif // ����_����_�Լ���_�߻�_Ŭ����
