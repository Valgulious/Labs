#include <iostream>
#include <cstring>
#include "String.h"

int main() {
//    char* c = "stringstringstring";
//    int a[5] = {2,4,2,1,5};
//    cout << strlen(c) << endl;
//    cout << sizeof(a)/sizeof(int) << endl;

    String s("Hellow World!!!", 7);
    String s1("string", 10);
    String s2 ("strinn", 5);

    cout << s << endl;
    cout << s.length() << endl;

    s = s + s1;

    cout << "s = " << s << endl;
    String s3 (s);
    cout << "s3 = " << s3 << endl;
    cout << s + s1 << endl;

    if (s1 == s2) cout << "Yes" << endl;

    return 0;
}