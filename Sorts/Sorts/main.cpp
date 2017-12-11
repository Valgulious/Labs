#include <iostream>

using namespace std;

void NonRecursiveQuickSort (int[]);
void TooWayInsertion (int[]);

const int SIZE_OF_ARRAY = 10;

int main() {
    setlocale(LC_ALL, "rus");

    int array_for_QuickSort[SIZE_OF_ARRAY], array_for_InsSort[SIZE_OF_ARRAY];
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++) {
        array_for_QuickSort[i] = -50 + rand()%100;
        array_for_InsSort[i] = array_for_QuickSort[i];
        cout << array_for_QuickSort[i] << ' ';
    }

    cout << endl << "Результат Быстрой сортировки: ";
    NonRecursiveQuickSort(array_for_QuickSort);
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array_for_QuickSort[i] << ' ';
    cout << endl << "Результат сортировки Вставками: ";
    TooWayInsertion(array_for_InsSort);
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array_for_InsSort[i] << ' ';
    cout << endl;
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

void TooWayInsertion (int array[]){
    int array_for_sort[2*SIZE_OF_ARRAY+1];
    int left(0), right(0), k((2*SIZE_OF_ARRAY+1)/2), j(0);

    for (int i=0;i<2*SIZE_OF_ARRAY+1;i++) array_for_sort[i] = 0;

    array_for_sort[k] = array[0];
    for (int i=1;i<SIZE_OF_ARRAY;i++){
        while ((k+right != k) && (array[i] > array_for_sort[k])){
            k++; left++; right--;
        }
        while ((k+left != k) && (array[i] < array_for_sort[k])){
            k--; left--; right++;
        }
        if (array[i] > array_for_sort[k]){

            if (left < right) {
                for (int j=k-left-1;j<k;j++){
                    swap(array_for_sort[j],array_for_sort[j+1]);
                }
                array_for_sort[k] = array[i];
                left++;
            } else {
                for (int j=k+right+1;j>k+1;j--){
                    swap(array_for_sort[j],array_for_sort[j-1]);
                }
                array_for_sort[k+1] = array[i];
                right++;
            }
        } else {
            if (left < right) {
                for (int j=k-left-1;j<k-1;j++){
                    swap(array_for_sort[j],array_for_sort[j+1]);
                }
                array_for_sort[k-1] = array[i];
                left++;
            } else {
                for (int j=k+right+1;j>k;j--){
                    swap(array_for_sort[j],array_for_sort[j-1]);
                }
                array_for_sort[k] = array[i];
                right++;
            }
        }
    }
    for (int i=k-left;i<SIZE_OF_ARRAY+(k-left);i++){
        array[j] = array_for_sort[i];
        j++;
    }
}