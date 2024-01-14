/*
	상속 접근 지정자
	- 기반 클래스를 파생 클래스에 상속시켜줄 때 사용하는 지정자
	- 상속 접근 지정자가 기반 클래스 멤버의 접근 지정자보다 더욱 제한된 접근 권한일 경우,
	  상속 접근 지정자로 변경된다.
	- private멤버는 상속을 시켜줄 경우, 파생 클래스에서 직접 접근이 불가능하다.

   상속 접근 지정자      기반 클래스         파생클래스
   public		          public	         public
						  protected          protected
						  private            접근 불가

   protected			  public             protected
						  protected          protected
						  private            접근 불가

   private				  public             private
						  protected          private
						  private            접근 불가
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

//기반 클래스의 멤버의 접근 지정자를 private으로
class Derived : private Base
{
public:
	Derived()
	{
		//해당 멤버들이 모두 상속 접근 지정자에 의해 private으로 바뀜
		Test();
		public_data;
		protected_data;
		//private_data;		//private멤버를 상속받아 접근 X
	}
	/*
	private:
		Test();
		public_data;
		protected_data;
		//private_data;		//private멤버를 상속받아 접근 X
	*/
};

//Derived가 Base의 멤버를 private으로 받았기 때문에
//상속 접근 지정자를 public으로 지정하여도 의미가 없다.
//-> 상속 접근 지정자가 더 접근이 제한된 경우에만 변경이 되기 때문
class A : public Derived
{
public:
	A()
	{
		//private 멤버를 상속받아 접근이 불가능
		/*Test();
		public_data;
		protected_data;
		private_data;*/
	}

};

int main()
{
	Base base;

	//외부에서 접근 가능한 public
	base.Test();
	base.public_data;

	//private형태로 상속받아 접근 불가능
	Derived d;
	//d.Test();
	//d.public_data;



	return 0;
}