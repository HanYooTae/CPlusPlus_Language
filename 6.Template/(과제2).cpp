// 과제 2
/*
   아래의 클래스는 들어온 템플릿 인자에 따라 데이터를 8개 생성해주는 클래스이다.

   여기서 문제가 생기는데 bool형을 만들 시 공간을 낭비하게 된다.
   -> bool형은 1바이트 크기만으로도 8가지를 표현할 수 있지만 아래와
   같이 생성될 경우 1바이트 * 8의 크기를 가진다.

   아래의 클래스를 템플릿 특수화로 bool형일시
   1바이트를 가지고 8개의 불값을 처리할 수 있게 만들자

   template <class T>
class Storage8
{
public:
    void Set(int index, const T& value)
    {
        arr[index] = value;
    }

    const T& Get(int index) { return arr[index]; }

private:
    T arr[8];
};
*/

#include <iostream>
using namespace std;

template <class T>
class Storage8
{
public:
    void Set(int index, const T& value)
    {
        arr[index] = value;
    }

    const T& Get(int index) { return arr[index]; }

private:
    T arr[8];
};


template <>
class Storage8<bool>
{
public:
    void Set(int index, const bool& value) {
        if (value == true) {
            arr = arr | (1 << index);
        }
        else {
            arr = arr & (255 - (1 << index));
        }
    }

    const bool& Get(int index) {
        return arr & (1 << index);
    }

private:
    char arr;
};

int main()
{
    Storage8<bool> str;

    cout << boolalpha;
    cout << str.Get(5) << endl;

    str.Set(5, true);

    cout << str.Get(5) << endl;

    return 0;
}