#include <iostream>
#include <cstring>
#include "String.h"

int main() {
//    char* c = "stringstringstring";
//    int a[5] = {2,4,2,1,5};
//    cout << strlen(c) << endl;
//    cout << sizeof(a)/sizeof(int) << endl;

    String s(5, "string");

    for (int i = 0; i < 5; i++) {
        cout << s.list -> symbols[i];
    }
    for (int i = 0; i < 5; i++) {
        cout << s.list -> next -> symbols[i];
    }
    cout << endl;
    cout << s.list -> lastSymbol << endl;
    cout << s.list -> next -> lastSymbol << endl;

    return 0;
}