#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
	using my_int = int;
	int name;
};

//���ø� �Ű������� typename�� class�� ���� �ǹ� -> ���̰� ����
template<typename T>
//template<class T>
class B
{
public:
	//T::my_int�� Ÿ������ �ƴϸ� ���� ��� �������� ������ �ȵ�
	//-> �����Ϸ��� ���� ��� ������ �ν��Ѵ�.
	//T::my_int i;	//error

	/*
	  ���ø� ���ο��� ��ø ���� Ÿ�� �̸��� ����� ��, typename�� ����ؾ� �Ѵ�.

	  dependent - ���� �̸�
	  - ���� typename Tó�� Ÿ���� ���ڷ� �޾� ����� ��,
	  T�� �����̸��̶�� �θ���.

	  nested dependent type name - ��ø ���� Ÿ�� �̸�
	  - ���� �̸��ӿ� �ٸ� Ÿ���� ���� �� ���,
	  ��ø ���� Ÿ�� �̸��̶�� �θ���.

	  - ex) T::my_int
   */

	//typename Ű���带 ����� T::my_int�� Ÿ�� �̸����� ����Ͽ� �ذ� ����
	typename T::my_int i;
	T::name;

private:

};

int main()
{
	A::my_int a = 10;

	return 0;
}