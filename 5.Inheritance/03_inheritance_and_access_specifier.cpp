/*
	��� ���� ������
	- ��� Ŭ������ �Ļ� Ŭ������ ��ӽ����� �� ����ϴ� ������
	- ��� ���� �����ڰ� ��� Ŭ���� ����� ���� �����ں��� ���� ���ѵ� ���� ������ ���,
	  ��� ���� �����ڷ� ����ȴ�.
	- private����� ����� ������ ���, �Ļ� Ŭ�������� ���� ������ �Ұ����ϴ�.

   ��� ���� ������      ��� Ŭ����         �Ļ�Ŭ����
   public		          public	         public
						  protected          protected
						  private            ���� �Ұ�

   protected			  public             protected
						  protected          protected
						  private            ���� �Ұ�

   private				  public             private
						  protected          private
						  private            ���� �Ұ�
*/

#include <iostream>
using namespace std;

class Base
{
public:
	int Test() {};
	int public_data;

protected:
	int protected_data;

private:
	int private_data;
};

//��� Ŭ������ ����� ���� �����ڸ� private����
class Derived : private Base
{
public:
	Derived()
	{
		//�ش� ������� ��� ��� ���� �����ڿ� ���� private���� �ٲ�
		Test();
		public_data;
		protected_data;
		//private_data;		//private����� ��ӹ޾� ���� X
	}
	/*
	private:
		Test();
		public_data;
		protected_data;
		//private_data;		//private����� ��ӹ޾� ���� X
	*/
};

//Derived�� Base�� ����� private���� �޾ұ� ������
//��� ���� �����ڸ� public���� �����Ͽ��� �ǹ̰� ����.
//-> ��� ���� �����ڰ� �� ������ ���ѵ� ��쿡�� ������ �Ǳ� ����
class A : public Derived
{
public:
	A()
	{
		//private ����� ��ӹ޾� ������ �Ұ���
		/*Test();
		public_data;
		protected_data;
		private_data;*/
	}

};

int main()
{
	Base base;

	//�ܺο��� ���� ������ public
	base.Test();
	base.public_data;

	//private���·� ��ӹ޾� ���� �Ұ���
	Derived d;
	//d.Test();
	//d.public_data;



	return 0;
}