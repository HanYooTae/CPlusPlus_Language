#include <iostream>

using namespace std;

/*
	friend
	- �ܺο��� Ŭ������ private, protected ����� ������ �� �ְ� ���ִ� Ű����
	- ������ �����ϰ� ���� �ʿ��� �����Ѵ�. -> �ܹ���
	- friend�� ��ӵ��� �ʴ´�.
*/

/*
	A(B�� ���ٰ���)

	B(A�� ���ٺҰ���)
*/

//#define friend_global_function
//#define friend_member_class
#define friend_class

#ifdef friend_global_function
/*
	���� �Լ����� Ŭ������ �����ϴ� ���
*/

class A
{
private:
	//1.
	//friendŰ���带 ����ϸ� �����Լ����� private�� ���� ����� ���ٰ����ϴ�.
	friend void do_something1(A& a);		//Ŭ���� ���ο� ��𿡵� �ִٸ� �������

	//2.
	//�ٷ� �Լ��� ���Ǻθ� ���� �ȴ�. (�ۿ� ���� �ȿ� ���� ����.)
	//���ο� �����ص� �����Լ� ���
	friend void do_something2(A& a)
	{
		cout << a.value << endl;
	}

	//friend int main();					main�� ����

private:
	int value = 1;
};

void do_something1(A& a)
{
	cout << a.value << endl;
}

int main()
{
	A a;
	do_something1(a);
	do_something2(a);

	return 0;
}

#endif

#ifdef friend_member_class
/*
	Ÿ���� �ٸ� Ŭ������ Ư�� ��� �Լ��� �����ϴ� ���
*/

//���� ����
//�ڿ� �ۼ��� �ڵ带 ���� �ڵ忡�� ������Ű�� ���� �� ���
//���� ������ ���־�� class A���� class B�� ���縦 �ν��� �� �ִ�.
class B;

//���� ������ ���� ���� B�� ���������� �� �� ���δ� �𸥴�.
//-> B�� ���� �޸𸮸� ���� �� ��� error
//B b;

//B* b1;						//�����ʹ� �� -> ���� B�ν��Ͻ��� �����ϴ°� �ƴϱ� ������ ����

//class B* b2;					//���� ����� ���ÿ� ��� ����

class A
{
public:
	void attack(B& b);		//B�� ���漱������� class B�� ������ ��
	//���漱������ class�� ���������� �˰� ���� ��, ���� ���δ� �� �� ����. -> error
	//������Ÿ�԰� ���Ǻθ� �и��� �ذ� -> �ش� �Լ��� ���Ǻθ� class B�� ������ �κ� �Ʒ��� �ξ�� ��
	/*{
		cout << "b�� hp : " << b.hp << endl;

		cout << "����!" << endl;
		b.hp -= 10;

		cout << "b�� hp : " << b.hp << endl;
	}*/
};

class B
{
	//class B���� class A�� ��� �Լ� attack���� �ڽ��� ��� ����� ���� �����ϵ��� ���
	friend void A::attack(B& b);
private:
	int hp = 100;
};




int main()
{
	A a;
	B b;

	a.attack(b);

	return 0;
}

void A::attack(B& b)
{
	cout << "b�� hp : " << b.hp << endl;

	cout << "����!" << endl;
	b.hp -= 10;

	cout << "b�� hp : " << b.hp << endl;
}

#endif // friend_member_class

#ifdef friend_class
/*
   Ÿ���� �ٸ� Ŭ������ ��� ������ ���� �Ϸ����Ҷ�
*/

class A
{
public:
	void Print_B_value1(class B& b);		//�Ķ���Ϳ� class B& b�� �ۼ��ϸ�, �Ʒ����� ����Ǵ� �Լ����� �Ķ���ʹ�
											//class�� ������ B& b�� �ۼ��ص� ���漱������ ���Ͽ� �������� �����.
	void Print_B_value2(class B& b);
};

class B
{
public:
	// class A���� B�� ��� ����� ���� ����
	// B���� A�� ������ �ȵ� -> �ܓ���
	friend class A;

private:
	int value1;
	int value2;
};
void A::Print_B_value1(B& b)
{
	b.value1 = 1;
	cout << "value1 : " << b.value1 << endl;
}

void A::Print_B_value2(B& b)
{
	b.value2 = 2;
	cout << "value2 : " << b.value2 << endl;
}

int main()
{
	A a;
	B b;
	a.Print_B_value1(b);
	a.Print_B_value2(b);

	return 0;
}

#endif // friend_class
