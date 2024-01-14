#include<iostream>
using namespace std;

/*
   anonymous object
   - 클래스를 인스턴스화 안하고 멤버 함수만 사용하려고 할 때 사용.
*/
class A
{
public:
    void print()
    {
        cout << "print" << endl;
    }

    //destructor는 모든 함수가 끝나고 난 후에 일괄적으로 종료된다.
    ~A()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    // 사용을 한번만 할것이지만 객체를 만들어 사용한다. -> 번거롭다.
    A a;
    a.print();

    // 익명 객체를 사용하면 좀더 편하게 사용가능
    A().print(); // 생성되고 함수 실행후 사라짐

    return 0;
}