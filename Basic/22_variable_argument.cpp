#include <iostream>
#include <cstdarg>		//가변인자관련 헤더
#include <string>

#define ARG_1
//#define ARG_2
//#define ARG_3

#ifdef ARG_1

using namespace std;


//=======================================================================================
// [가변인자 함수 사용해보기]
//=======================================================================================

void print_number(int arg_count, ...)
{
    va_list arg_list;	//가변 인자를 다루는 포인터
   
    /*
        va_start(가변인자 포인터, 마지막 고정인수)
            - 가변 인자의 포인터 설정 매크로
            - 마지막 고정 인수를 기준으로 위치를 찾아준다.

        ---------------------------------------------------
        |  arg_count  | arg_list1 | arg_list2 | arg_list3 |
        ---------------------------------------------------
                      ↑
                  arg_list
       마지막 고정 인수를 기준으로 가변 인자의 시작 위치를 찾아준다.
    */

    va_start(arg_list, arg_count);

    //가변 인자의 개수만큼 출력해준다.
    for (int i = 0; i < arg_count; i++)
    {
        //va_arg(arg_list, int) : arg_list에서 4바이트(int크기)만큼 역참조하여 데이터를 가져온 뒤
        //                        arg_list를 4바이트(int크기)만큼 이동시킨다. -> 다음 가변 인자의 시작 위치를 가리킨다.
        int num = va_arg(arg_list, int);

        printf("%d ", num);
    }
    printf("\n");
    //va_end() : 해당 가변 인자 포인터를 NULL로 초기화한다.
    va_end(arg_list);
}

int main()
{
    //범위 값을 잘 작성해야 함. 범위를 적게 했다면 전부 나오지 않음 print_number(2, 1, 2, 3, 4);

    print_number(1, 1);
    print_number(2, 1, 2);
    print_number(3, 1, 2, 3);
    print_number(4, 1, 2, 3, 4);

    return 0;
}
#endif


#ifdef ARG_2
using namespace std;


//=======================================================================================
// [다양한 자료형을 가변 인자로 받아 출력해보자]
//=======================================================================================
//arg_format : 뒤에 들어올 가변 인자의 타입을 받는다.

void print_value(const char* const arg_format, ...)
{
    va_list arg_list;
    va_start(arg_list, arg_format);

    int i = 0;
    arg_format[i];
    while (arg_format[i] != '\0')
    {
        //받은 형식에 맞게 처리해준다
        switch (arg_format[i++])
        {
        case 'i': printf("%d ", va_arg(arg_list, int)); break;
        case 'd': printf("%lf ", va_arg(arg_list, double)); break;
        case 'c': printf("%c ", va_arg(arg_list, char)); break;
        case 's': printf("%s ", va_arg(arg_list, char*)); break;
        }
    }
    printf("\n");

    va_end(arg_list);
}

int main()
{
    print_value("i", 10);
    print_value("di", 3.141592, 10);
    print_value("cdi", 'A', 3.141592, 10);
    print_value("scdi", "arg_list", 'A', 3.141592, 10);

    //printf("count : %d", 10);

    return 0;
}
#endif

#ifdef ARG_3
using namespace std;


//=======================================================================================
// [더 쉽게 다양한 자료형을 가변 인자로 받아 출력해보자]
//=======================================================================================

void print_string(const std::string arg_format, ...)
{
    va_list arg_list;
    int i = 0;

    va_start(arg_list, arg_format);
    {
        // _vscprintf -> 형식과 인자가 합쳐서 만들어질 총 문자열의 길이를 알려준다.
        // -> '\0'의 길이는 따로 넣어주어야 한다.
        int size = _vscprintf(arg_format.c_str(), arg_list) + sizeof('\0');

        //만들어질 크기만큼 동적할당을 받는다.
        char* string = new char[size];

        // vsprint_s() : string에 size만큼 arg_format(형식)과 arg_list(인자)를 합쳐 문자열을 만들어준다.
        vsprintf_s(string, size, arg_format.c_str(), arg_list);

        // 완성된 문자열을 출력한다.
        printf("%s", string);

        //사용 후 해제해준다.
        delete[] string;
    }
    va_end(arg_list);
    printf("\n");
}

int main()
{
    print_string("문자열 출력 가능 : %s, 숫자도 가능 : %d, Escape sequence도 가능 : \tTest", "Hello World", 123);

    //__FUNCTION__
    //__LINE__

    return 0;
}
#endif