#include <iostream>
#include <string>

/*
	PP - Procedual Programming -> ���ν���(�Լ�) -> �Լ� ������ ����
	OOP - Object Oriented Programming -> ��ü����(C++) -> ��ü ������ ����
*/

/*
	��ü(Object) => Class + Instance
	- Class
		�� ������ �������� ���� ���赵, Ȥ�� ��� ex) dna, �ؾ Ʋ, �ڵ��� ���赵,...
		�� �繰�� ����� �Ӽ��� ������ ���� ��� ����(data) ��� �Լ�(method)�� ����� ǥ��

	- Instance
		�� class�� ���� ������� ��ü
		�� class�� �ϳ����� �ϳ��� class�� ���� �پ��� instance�� �����Ѵ�.
		ex) �ؾ Ʋ �ϳ����� �پ��� �ؾ�� ���� �� �ִ�. (��, ��ũ�� ��)
*/

/*
	��ü���� 3���		//4�� Ư¡ (ĸ��ȭ, ��������, ���, ������)
	
	1.ĸ��ȭ(Encapsulation)
	- ��ü�� �Ӽ�(��� ����)�� ����(��� �Լ�)�� Ŭ������ ���� ��
	- ���� �����ڸ� ���� �ܺο� �ʿ��� ���븸 �����ϰ� �������� �����. -> ��������(Information hiding)
	- �ʿ��� ������ ������ ����ϱ� ���� �Ѵ�. ex) �������� ��ư�� �����ϸ� ���� ȸ�θ� ���� ��� ����

	2. ���(Inheritence)
	- ���� Ŭ������ �Ӽ��� ����� �����޴� ���� Ŭ������ ����� �Ӽ��� ����� Ȯ���� �� �ִ�.
	- �θ� Ŭ����, �ڽ� Ŭ������� �θ���.

	3. ������(Polymorphism)
	- �ϳ��� ��ü�� ���� ���� ������ �ڷ����� ���� �� �ִ� ��
		-> �پ��� ���·� ��ü�� ǥ�� ����
		�� �������̵�
			�� ���� Ŭ������ ������ �ִ� �޼ҵ带 ���� Ŭ������ �������ؼ� ����ϴ� ��
		�� �����ε�
			�� ���� �̸��� ���� �޼ҵ带 ���� ���� ���³� ������ �ٸ��� �Ͽ� �ٸ� ����� �����ϵ��� �����ϴ� ��
			��  ȣ�� �Ű������� ���� ��Ī�Ǿ� �Լ��� ���������
*/

class Person	//���, ���赵
//�߻�ȭ
{	//ĸ��ȭ, {}�� �����Ϳ� �޼ҵ带 ����
//���� ������(access specifier) ���� ������ �����Ѵ�. (public, protected, private)
public:		//��ο��� ����
	void Work()
	{

	}

	void Sleep()
	{

	}

	//���� ����
protected:	//�ڽŰ� �ڽ� Ŭ���� ���ο����� ��� ���� (friend Ű���� ��� �� ���������� ���� ���� >> �ϴ� ��ŵ)

private:	//�ڽŸ� ��� ���� (friend Ű���� ��� �� ���������� ���� ���� >> �ϴ� ��ŵ)
	std::string name;
	int age;
	float height;
	float weight;
	bool favorite;
};

class Animal		//�������̵�
{
public:
	void Eat() { std::cout << "����" << std::endl; }

	std::string name;
private:
};

class Dog : public Animal
{
public:
	void Eat() { std::cout << "��" << std::endl; }

	int age;
};

class Cat : public Animal
{
public:
	void Eat() { std::cout << "�����" << std::endl; }

	int weight;
};


int main()
{
	Person person;		//person�� �ν��Ͻ���� ��(����� ���� ������Ų �� = ��ü)		//instance, object(��ü)

	//person.age;			//error : ���е� ���� ����
	person.Sleep();			//������ ���븸 ���� ����
	Dog d;
	d.Eat();

	Animal a;
	a.Eat();

	Cat c;
	c.Eat();


	return 0;
}