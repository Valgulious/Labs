#include <iostream>

using namespace std;

void NonRecursiveQuickSort (int[]);

const int SIZE_OF_ARRAY = 10;

int main() {
    int a[SIZE_OF_ARRAY];
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++) {
        a[i] = 0;
        cout << a[i] << ' ';
    }
    cout << endl;
    NonRecursiveQuickSort(a);
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << a[i] << ' ';
    return 0;
}

void NonRecursiveQuickSort (int array[]){
    int i(0),j(0),L(0),R(0),s(0),x(0);
    int low[SIZE_OF_ARRAY], high[SIZE_OF_ARRAY];

    low[0] = 0; high[0] = SIZE_OF_ARRAY-1;
    do {
        L = low[s]; R = high[s]; s--;
        do {
            i = L; j = R; x = array[(L+R)/2];
            do {
                while (array[i] < x) i++;
                while (x < array[j]) j--;
                if (i <= j) {
                    swap(array[i], array[j]);
                    i++; j--;
                }
            } while (i<=j);
            if (i < R) {
                s++; low[s]=i; high[s]=R;
            }
            R=j;
        } while (L < R);
    } while (s >= 0);
}