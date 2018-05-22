#include <iostream>
#include "String.h"

int main() {
//    char* c = "stringstringstring";
//    int a[5] = {2,4,2,1,5};
//    cout << strlen(c) << endl;
//    cout << sizeof(a)/sizeof(int) << endl;

    String s("Hellow World!!!", 7);
    String s1("string", 10);
    String s2 ("stringa", 5);

    cout << s << endl;
    cout << s.length() << endl;
    cout << s + s1 << endl;
    s = s + s1;

    cout << "s1 = " << s1 << endl;
    cout << "s = " << s << endl;
    cout << s.length() << endl;
    String s3 (s);
    String s4("a", 5);

    StringIter stringIter(&s3);
    s3 = s3 + s4;
    cout << "s3 = " << s3 << endl;
    cout << s + s1 << endl;

    if (s1 == s2) cout << "Yes" << endl;

    cout << "s3 = " << s3 << endl;
    cout << "s2 = " << s2 << endl;
    cout << s2.find(&s3) << endl;

    for (int i = 0; i < s3.length(); i++) {
        cout << stringIter.curentItem();
        stringIter.next();
    }
    cout << endl;

    cout << s3.length() << endl;
    return 0;
}