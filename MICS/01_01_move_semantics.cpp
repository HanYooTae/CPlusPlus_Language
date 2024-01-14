/*
	����Ʈ ������
	- ������ó�� �����ϴ� Ŭ���� ���ø�.
	- ��� ������, �޸� ������ �����ϱ� ���� ����
	- memory ����� ���ԵǾ�����

	����Ʈ �������� ����
	- auto_ptr
	- unique_ptr
	- shared_ptr
	- weak_ptr
*/

#include<iostream>
#include<memory>
#include"01_02_resource.h"
#include"01_03_auto_ptr.h"
using namespace std;

/*
	RAII : Resource Acquisition is initialization
	- ������ �������� �����ϴ� ��
	- RAII ��Ģ�� ����Ʈ �����Ϳ� ����Ǿ��ִ�.
*/

// RAII ��Ģ�� �������� �ʾ��� ��
void DoSomething1()
{
	Resource* resource = new Resource;
	// *resource : new Resource(���Ҵ��� ������)�� �޸�/�ּҿ� ����

	// ...
	// early return -> �޸� ���� �߻�
	//if (true) return;		// Resource*�� ��������� �����Ҵ��� �����ʹ� ������� ����
	// ...

	// �ذ��1 : �����ϴ� ������ ����
	// ���� : ���� �ڵ带 �߰����� �ʴ� �Ǽ��� �� �� �ִ�.
	// -> �ش� ������ ��� �� �ڵ����� �����ǰ� �ϰ� �ʹ�. -> ����Ʈ ������
	if (true)
	{
		delete resource;
		return;
	}

	delete resource;
}

// �ذ�� 2 : �Ҹ��ڿ��� �����ϱ�
// ��ü�� �Ҹ��ϸ鼭 �Ҹ��ڰ� ȣ��ȴ�.
// �׷��Ƿ� �Ҹ��ڿ� ���������� �����ִ� �ڵ带 �߰��Ͽ�
// ���� �����͸� ������ �Ҹ��� �� �ڵ����� �����ϵ��� ��
// -> ����Ʈ �������� ����
void DoSomething2()
{
	AutoPtr<Resource> resource(new Resource);

	// ���� resource ��ü ��ü�� ���� �����̱� ������
	// �Լ��� ����� �� �ڵ����� �Ҹ��ڰ� ȣ��ȴ�.
	if (true) return;
}

void DoSomething3(AutoPtr<Resource> temp)
{

}

int main()
{
	// ������ ��� �� �ڵ����� �Ҹ��Ų��.

	cout << "{" << endl;
	AutoPtr<Resource> res = new Resource;
	cout << "}" << endl;

	// ����Ʈ ������ ������
	AutoPtr<Resource> res1 = new Resource;

	// .�����ڸ� ���� ������ ���� ����Ʈ ������ Ŭ������ ���
	//res1.Test();

	// ������ �������� ����� �����ϱ� ���ؼ��� -> �����ڸ� ���� �����ؾ� ��
	//res1->~Resource();


	// AutoPtr�� ������
	AutoPtr<Resource> res2 = new Resource;

	// 1 : auto_ptr�� ���� �������� �������� �Ѿ������.
	DoSomething3(res2);

	//res2->;		// res2�� ������ �ִ� �ּҰ� nullptr�� �Ǿ� ���� �߻�

	// 2 : autoptr�� �迭 ������ ����, ������ �������� ����.
	// delete�� �ְ� delete[]�� ����
	

	return 0;
}