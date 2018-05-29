#include <iostream>
#include "String.h"

int main() {
    String s3("Hellow Worlld!!!", 3);
    String s5("ll");
    String s6("llll");

    s3.replace(s5, s6);
    cout << s3 << endl;
    return 0;
}