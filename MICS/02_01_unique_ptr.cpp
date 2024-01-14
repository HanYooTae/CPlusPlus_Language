/*
	unique_ptr
		- Ư�� ��ü�� �ϳ��� ����Ʈ �����͸� �������� ������ �ϴ� ����Ʈ ������
		- auto_ptr�� �������� ������
		- unique_ptr�� �Ҹ��� ��, �ڽ��� ������ dull �����͸� �����Ѵ�.
			�� dull pointer : ����Ʈ �����Ͱ� ������ ���� ������
*/

#include <iostream>
#include <memory>
#include "02_02_resource.h"
using namespace std;

std::unique_ptr<Resource> DoSomething(std::unique_ptr<Resource> res)
{
	res->SetAll(10);
	res->Print();

	return res;
}

int main()
{
	// 1
	{
		// �̵� ����, �̵� ������ ��� ����
		// res1�� ������ �����Ǿ����� new Resource(5)(���� �Ҵ�)�� �ʰ� �����Ǵ� ���� ������ ���� �ʾ� ����ġ ���� ���� �߻� ����
		// ����Ʈ ������ ��ü�� ������ ��������µ� ������ ���� �����ʹ� ������ ������ ���� �Ҵ��� �� ���� make_�Լ��� ���
		std::unique_ptr<Resource> res1(new Resource(5));		// ���̷�Ʈ �ʱ�ȭ

		// �ϳ��� �����ؾ� �ϱ� ������ ���簡 �Ǹ� �ȵ�
		//std::unique_ptr<Resource> res2 = new Resource(5);		// ���� �ʱ�ȭ



		// make_����Ʈ ������ : �����ϰ� ��ü�� �Ҵ����ֵ��� �ϴ� �Լ�, ���������� ���� �Ҵ��� ���ش�.
		// ���� ������ �˾Ƽ� ������
		std::unique_ptr<Resource> res3 = std::make_unique<Resource>(5);

		res3->SetAll(5);
		res3->Print();

		//res3 = res1;	// ���� ���� X
		res3 = std::move(res1);		// r-value ���·� �ٲ� �̵� �����ڸ� ȣ�����־�� �Ѵ�.

		// res1�� res3�� �������� �Ű�� ������ ������ ���. �� �Ŀ� ���� �õ��ϸ� ���� �߻�
		res1->Print();
	}

	// 2
	{
		auto res1 = std::make_unique<Resource>(5);
		res1->SetAll(5);
		res1->Print();

		// ���۷����� �ѱ��� ���� ��� ���簡 �Ǳ� ������ ����
		//DoSomething(res1);		// copy

		// r-value ���·� �ѱ�� ����
		// �̵� ������(�������� ������ٰ� �ٽ� ������ �޴� ����
		// ��ȯ ������ �ٽ� �������� �޾��־�� �����Ͱ� �������� ����
		res1 = DoSomething(std::move(res1));

		// 2.
		// dull pointer ���·� �����͸� ���� r-value���·� ����� ����
		DoSomething(make_unique<Resource>(res1.get()));

		// get() : ����Ʈ �����Ͱ� ������ �ִ� �������� dull pointer�� ��ȯ
	}

	// 3
	{
		// dull pointer�� ����Ʈ �����͸� ��� ����ϸ� �߻��ϴ� ������
		Resource* res = new Resource(5);

		// res�� ������ �ּҸ� �Ѱ��ش�. res�� ����Ʈ �����Ͱ� �ƴϱ� ������ �������� ������� �ʴ´�.
		// -> unique_ptr�� �� ��ü�� ���Ͽ� �ϳ��� �����͸� �����ؾ� �ϴµ�, 2�� �̻��� �����Ͱ� �����ϰ� ��
		std::unique_ptr<Resource> res1(res);
		
		// �߰���
		// res1 = nullptr;	// �̰� �־��� ���, nullptr�� �ʱ�ȭ ���ֱ� ������ ������ �߻����� ����

		// res1�� res2�� ���� �ּҸ� �����ϰ� �ȴ�.
		std::unique_ptr<Resource> res2(res1.get());		// res1.get() = res

		/*
			�ش� ������ ����� res1�� res2 �Ҹ� -> �� �� �ڱⰡ ������ res�� �ּҸ� ����
			���� �ּҸ� 2�� �����Ϸ��� �õ��� -> ��� ������ ���� �߻�
			�׷��� ������ dull �����Ϳ� ����Ʈ �����͸� ����� ���� ���� ����
		*/
	}


//class a
//{
//public:
//	a(int* data) : data(data) {}
//	a(const a& data) {}
//public:
//	int* data;
//};
//
//int* data = new int;
//
//a test(data);
//a test2(test);
//a test3(test.data);

	return 0;
}