#include <iostream>
#include <chrono>

using namespace std;
void NonRecursiveQuickSort (int[]);
void TooWayInsertion (short int[]);

const int SIZE_OF_ARRAY = 900000;

long int swapCount(0), ifCount(0);

int main() {
    setlocale(LC_ALL, "rus");

    clock_t clock1;
    double seconds;

    short int  array_for_InsSort[SIZE_OF_ARRAY];
    int *array_for_QuickSort = new int[SIZE_OF_ARRAY];
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++) {
        array_for_QuickSort[i] = 10-i%4; //rand()%10000;
        array_for_InsSort[i] = array_for_QuickSort[i];
 //       cout << array_for_QuickSort[i] << ' ';
    }

    cout << endl << "Результат Быстрой сортировки: ";
    clock1 = clock();
    NonRecursiveQuickSort(array_for_QuickSort);
    clock1 = clock() - clock1;
    seconds = (double)clock1 / CLOCKS_PER_SEC;
 //   for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array_for_QuickSort[i] << ' ';
    cout << endl << "Количество обменов: " << swapCount;
    cout << endl << "Количество сравнений: " << ifCount;
    cout << endl << "Время выполнения сортировки: " << seconds << 's';

    ifCount = 0;
    swapCount = 0;
    cout << endl << "Результат сортировки Двухпутевыми вставками: ";
    clock1 = clock();
    TooWayInsertion(array_for_InsSort);
    clock1 = clock() - clock1;
    seconds = (double)clock1 / CLOCKS_PER_SEC;
  //  for (int i = 0; i < SIZE_OF_ARRAY; i++) cout << array_for_InsSort[i] << ' ';
    cout << endl << "Количество перестановок: " << swapCount;
    cout << endl << "Количество сравнений: " << ifCount;
    cout << endl << "Время выполнения сортировки: " << seconds << 's';
    cout << endl;
    return 0;
}

void NonRecursiveQuickSort (int array[]){
    int i(0), j(0), L(0), R(0), s(0), x(0);
    int *high = new int[SIZE_OF_ARRAY];
    int *low = new int[SIZE_OF_ARRAY];

    low[0] = 0; high[0] = SIZE_OF_ARRAY-1;
    do {
        L = low[s]; R = high[s]; s--;
        do {
            i = L; j = R; x = array[(L+R)/2];
            do {
                while (array[i] < x) {
                    i++;
                    ifCount++;
                }
                ifCount++;
                while (x < array[j]) {
                    j--;
                    ifCount++;
                }
                ifCount++;
                if (i < j) {
                    swap(array[i], array[j]);
                    swapCount++;
                    i++; j--;
                } else if (i == j) {
                    i++;j--;
                }
            } while (i<=j);
            if (i < R) {
                s++; low[s]=i; high[s]=R;
            }
            R=j;
        } while (L < R);
    } while (s >= 0);
}

void TooWayInsertion (short int array[]){
    short int array_for_sort[2*SIZE_OF_ARRAY+1];
    int k((2*SIZE_OF_ARRAY+1)/2), j;
    int left(k), right(k);

    for (int i=0;i<2*SIZE_OF_ARRAY+1;i++) array_for_sort[i] = 0;

    array_for_sort[k] = array[0];
    swapCount++;
    for (int i=1;i<SIZE_OF_ARRAY;i++){
        if (array[i] <= array_for_sort[left]) {
            left--;
            array_for_sort[left] = array[i];
            swapCount++;
            ifCount++;
        } else if (array[i] >= array_for_sort[right]) {
            right++;
            array_for_sort[right] = array[i];
            swapCount++;
            ifCount++;
        } else if (array[i] >= array_for_sort[k]) {
            ifCount++;
            j = k;
            while (array[i] >= array_for_sort[j]) {
                ifCount++;
                j++;
            }
            ifCount++;
            if ((right-j) > (j-left)){
                left--;
                for (int u = left;u < j;u++) {
                    swap(array_for_sort[u],array_for_sort[u+1]);
                    swapCount++;
                }
                array_for_sort[j] = array[i];
                swapCount++;
            } else {
                right++;
                for (int u = right;u > j;u--) {
                    swap(array_for_sort[u],array_for_sort[u-1]);
                    swapCount++;
                }
                array_for_sort[j] = array[i];
                swapCount++;
            }
        } else {
            ifCount++;
            j = k;
            while (array[i] < array_for_sort[j]) {
                j--;
                ifCount++;
            }
            ifCount++;
            if ((right-j) > (j-left)){
                left--;
                for (int u = left;u < j;u++) {
                    swap(array_for_sort[u],array_for_sort[u+1]);
                    swapCount++;
                }
                array_for_sort[j] = array[i];
                swapCount++;
            } else {
                right++;
                for (int u = right;u > j;u--) {
                    swap(array_for_sort[u],array_for_sort[u-1]);
                    swapCount++;
                }
                array_for_sort[j] = array[i];
                swapCount++;
            }
        }
//        for (int h = 0; h < 2*SIZE_OF_ARRAY+1; h++) {
//            cout << array_for_sort[h] << ' ';
//        }
//        cout << endl;
//        while ((k+right != k) && (array[i] > array_for_sort[k])){
//            k++; left++; right--;
//            ifCount++;
//        }
//        ifCount++;
//        while ((k+left != k) && (array[i] < array_for_sort[k])){
//            k--; left--; right++;
//            ifCount++;
//        }
//        ifCount++;
//        if (array[i] > array_for_sort[k]){
//
//            if (left < right) {
//                for (int j=k-left-1;j<k;j++){
//                    swap(array_for_sort[j],array_for_sort[j+1]);
//                    swapCount++;
//                }
//                array_for_sort[k] = array[i];
//                swapCount++;
//                left++;
//            } else {
//                for (int j=k+right+1;j>k+1;j--){
//                    swap(array_for_sort[j],array_for_sort[j-1]);
//                    swapCount++;
//                }
//                array_for_sort[k+1] = array[i];
//                swapCount++;
//                right++;
//            }
//        } else {
//            if (left < right) {
//                for (int j=k-left-1;j<k-1;j++){
//                    swap(array_for_sort[j],array_for_sort[j+1]);
//                    swapCount++;
//                }
//                array_for_sort[k-1] = array[i];
//                swapCount++;
//                left++;
//            } else {
//                for (int j=k+right+1;j>k;j--){
//                    swap(array_for_sort[j],array_for_sort[j-1]);
//                    swapCount++;
//                }
//                array_for_sort[k] = array[i];
//                swapCount++;
//                right++;
//            }
//        }
//        ifCount++;
    }
//    for (int i=0;i<SIZE_OF_ARRAY*2+1;i++) cout << array_for_sort[i] << ' ';
//    cout << endl;
//    for (int i=k-left;i<SIZE_OF_ARRAY+(k-left);i++){
//        array[j] = array_for_sort[i];
//        j++;
//    }
    j = 0;
    for (int i = left; i <= left+10; i++) {
        array[j] = array_for_sort[i];
        j++;
    }
}