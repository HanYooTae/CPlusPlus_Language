#include <iostream>
#include "HashMap.h"

using namespace std;

int main() {

    HashMap<string, int>* hashmap = new HashMap<string, int>();

    hashmap->put("abc", 213);
    hashmap->put("bcd", 1234345);

    cout << hashmap->get("abc") << endl;
    cout << hashmap->get("bcd") << endl;

    hashmap->put("abc", 41235);
    hashmap->put("bcd", 12323455);

    cout << hashmap->get("abc") << endl;
    cout << hashmap->get("bcd") << endl;

    cout << endl;
    hashmap->remove("abc");
    cout << hashmap->get("abc") << endl; // 키를 찾을 수 없습니다.

    cout << endl;
    hashmap->put("abcc", 123);
    hashmap->put("abcd", 123);
    hashmap->put("abcf", 156);
    hashmap->put("abcg", 1243);
    hashmap->put("abcq", 123);
    hashmap->remove("abcd");
    cout << hashmap->get("abcd") << endl; // 키를 찾을 수 없습니다.
    cout << hashmap->get("abcg") << endl;

    return 0;
}