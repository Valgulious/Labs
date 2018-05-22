#include <iostream>
#include "String.h"

//int replace(String string, String subString)
//{
//    if (subString.length() <= string.length()) {
//        while (string.find(subString) >= 0) {
//            StringIter stringIter(&string);
//
//            stringIter.goToIndex(string.find(subString));
//            String string1(string.subStr(0, stringIter.getIndex() - 1));
//            String string2(string.subStr(stringIter.getIndex() + subString.length(), string.length() - 1));
//            string = string1 + string2;
//        }
//    } else return -2;
//}

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
    stringIter.resetIter(&s3);
    cout << "s3 = " << s3 << endl;
    cout << s + s1 << endl;

    if (s1 == s2) cout << "Yes" << endl;

    cout << "s3 = " << s3 << endl;
    cout << "s2 = " << s2 << endl;
    cout << s3.find(s2) << endl;

    for (int i = 0; i < s3.length(); i++) {
        cout << stringIter.currentItem();
        stringIter.next();
    }
    cout << endl;

    cout << s3.length() << endl;

    cout << s3 << endl;
    cout << "subStr = " << s3.subStr(4,10) << endl;
    s3.deleteSubStr(4,10);
    cout << s3 <<endl;

    String s5("str");
    String s6("777");
    s3.repalce(s5,s6);
    cout << s3 << endl;
    return 0;
}