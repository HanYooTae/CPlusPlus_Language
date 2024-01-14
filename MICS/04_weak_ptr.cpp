/*
	strong reference vs weak reference
	- strong reference : �޸� ������ ������ ��ġ�� ���� -> shared_ptr�� ������ �� ����
	- weak reference : �޸� ������ ������ ���� �ʴ� ���� -> weak_ptr�� �����͸� ������ �� ����

	weak_ptr
		- �ٸ� �� ����Ʈ �����Ϳ� �޸� �ܵ����� ������� ���ϴ� ����Ʈ ������
		- shared_ptr�� ��ȯ ������ ������ �ذ��ϱ� ���� ����Ѵ�.
*/

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Person
{
public:
	Person(const string& name) : name(name)
	{
		cout << name << " Created" << endl;
	}

	~Person()
	{
		cout << name << " Destroyed" << endl;
	}

	const string& GetName() const { return name; }

	// �ܺ� �Լ�
	friend bool PartnerUp(std::shared_ptr<Person>& p1, std::shared_ptr<Person>& p2)
	{
		if (p1 == nullptr || p2 == nullptr)
			return false;

		p1->partner = p2;
		p2->partner = p1;

		cout << p1->name << " is partnered with " << p2->name << endl;
		return true;
	}

private:
	string name;
	// ���� �Ҵ�� ��ü�� ���ΰ� ���θ� shared_ptr ���·� ���� �� ��ȯ ������ ������ �߻�
	//std::shared_ptr<Person> partner;

	// weak_ptr ���·� �����Ͽ� ��ȯ ������ ���� �ذ� ����
	// -> ���ΰ� �����ϰ� �ִٴ� ���� ������, ���� �� ������ ���� �ʴ´�.
	std::weak_ptr<Person> partner;
};

class Test : public Person
{
public:
	Test(const std::string& name)
		: Person(name)
	{}
};

int main()
{
	/*
		circular dependency issues : ��ȯ ������ ����

		���ΰ� ���θ� �����ϴ� ��Ȳ���� ī������ ���ο��� �����־�
		���� �������� ��ٸ��� �ֱ� ������ ī������ ���� �ʰ� ������ ����ϰ� ��(�޸𸮰� �������� ����) -> �޸� ����
	*/
	{
		// �Ҵ�� Lucy�� ����Ʈ ������ lucy�� ����, ���� ���� -> ���� 0 -> 1
		auto lucy = std::make_shared<Person>("Lucy");

		// �Ҵ�� Ricky�� ����Ʈ ������ ricky�� ����, ���� ���� -> ���� 0 -> 1
		auto ricky = std::make_shared<Person>("Ricky");
		
		// ���� �Ҵ�� ��ü Lucy���� Ricky�� ����
		// ���� �Ҵ�� ��ü Ricky���� Lucy�� ����
		// ������ ī��Ʈ 1 -> 2 ����
		PartnerUp(lucy, ricky);

	}	/*
			����Ʈ ������ lucy, ricky �Ҹ�->������ ī��Ʈ ���� 2 -> 1
			������, ���� �Ҵ�� ��ü Lucy, Ricky�� ��� ������ ���θ� shared_ptr ���·� ������ ����.

			1. Lucy�� �Ҹ��ϱ� ���� Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ� ��
			2. Ricky�� ���� ����Ʈ �����Ͱ� �Ҹ�Ǳ� ���ؼ��� Ricky�� �Ҹ��ؾ� ��
			3. Ricky�� �Ҹ��ϱ� ���� Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ��ؾ� ��
			4. Lucy�� ���� ����Ʈ �����Ͱ� �Ҹ�Ǳ� ���ؼ��� Ricky�� �Ҹ��ؾ� ��
				-> ���� �ݺ�

			���ΰ� ���ѷ����� ������ �ִ��ؼ� ��ȯ ������ ������� �θ���.
			-> ���θ� ������ �� weak_ptr ���·� �����Ͽ� ���� �ذ� ����
		*/

	// weak_ptr
	{
		auto test = std::make_shared<Person>("Test");
		auto test1 = test;
		std::weak_ptr<Person> weak = test;

		cout << endl << "------------------------------------------------------------" << endl;

		test = nullptr;		// == test.reset();

		// expired() : weak_ptr�� ������ �������� �Ҹ� ���� Ȯ��, �Ҹ� �� true ��ȯ
		if (weak.expired() != true)
			cout << "��ȿ��" << endl;		// ������� ����
		else
			cout << "��ȿ���� ����" << endl;	// �����

		cout << endl << "------------------------------------------------------------" << endl;

		/*
			weak_ptr ���·δ� �ٷ� ������� ���ϰ� shared_ptr ���·� �ٲپ ����ؾ� �Ѵ�.
			-> ��Ƽ ������ ȯ�濡���� weak_ptr�� �����͸� ����� �� ���� shared_ptr�� ���� �����Ǿ�
			weak_ptr�� ������ �����Ͱ� �Ҹ��ϴ� ���� ���� ���� ��� ���� �ּ� 1�� ���� ���� Ƚ���� Ȯ���ϱ� �����̴�.
		*/

		// weak-> error		// ����Ϸ��� weak.lock()-> ���
		weak.lock()->GetName();	// ok	 // lock() : ���� ����(weak_ptr)�� ���� ����(shared_ptr)���·� �ٲپ��ش�.
	}

	cout << endl;

	// �߰����� ����Ʈ ������ ���� + ������
	{
		auto test1 = std::make_shared<Person>("Test1");
		auto test2 = std::make_shared<Person>("Test2");

		// 1. ����Ʈ �����ͳ��� ���� ����
		test1.swap(test2);

		// 2. �ش� ����Ʈ �������� ������ ���� (�Ʒ� �� �� �ϳ�)
		// ���� X, �ش� ����Ʈ �����͸� �����͸� �����ϴ� ��
		test1.reset();
		test1 = nullptr;

		// 3. ����Ʈ �������� ĳ����
		// ��ĳ������ �Ͻ��� ����ȯ ����
		std::shared_ptr<Person> parent = std::make_shared<Test>("Test");

		// �ٿ� ĳ������ ������ ����� ����ȯ�� ���־�� �Ѵ�.
		// ����Ʈ �������� ����ȯ�� _pointer ������ �� ����
		std::shared_ptr<Test> child = std::static_pointer_cast<Test>(parent);

		// 4. ����Ʈ �������� ������ ���� ���� Ȯ�ι�
		// dull ������ �����ϰ� �ּҰ� ���� ���� Ȯ�� ����
		if (test1 == nullptr);
		if (!test1 != false);
	}

	return 0;
}