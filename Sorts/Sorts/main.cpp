#include <iostream>
#include <chrono>

using namespace std;
/* ВНИМАНИЕ!!!! Сколько времнени занимает работа сортировки?*/
void NonRecursiveQuickSort (int[]);
void TooWayInsertion (int[]);

const int SIZE_OF_ARRAY = 100000;

long int swapCount(0), ifCount(0);

int main() {
    setlocale(LC_ALL, "rus");

    clock_t clock1;
    double seconds;

    int array_for_QuickSort[SIZE_OF_ARRAY], array_for_InsSort[SIZE_OF_ARRAY];
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++) {
        array_for_QuickSort[i] = -50000 + rand()%100000;
        array_for_InsSort[i] = array_for_QuickSort[i];
        cout << array_for_QuickSort[i] << ' ';
    }

    cout << endl << "Результат Быстрой сортировки: ";
    clock1 = clock();
    NonRecursiveQuickSort(array_for_QuickSort);
    clock1 = clock() - clock1;
    seconds = (double)clock1 / CLOCKS_PER_SEC;
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array_for_QuickSort[i] << ' ';
    cout << endl << "Колличество обменов: " << swapCount;
    cout << endl << "Колличество сравнений: " << ifCount;
    cout << endl << "Время выполнения сортировки: " << seconds << 's';

    ifCount = 0;
    swapCount = 0;
    cout << endl << "Результат сортировки Двухпутевыми вставками: ";
    clock1 = clock();
    TooWayInsertion(array_for_InsSort);
    clock1 = clock() - clock1;
    seconds = (double)clock1 / CLOCKS_PER_SEC;
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array_for_InsSort[i] << ' ';
    cout << endl << "Колличество обменов: " << swapCount;
    cout << endl << "Колличество сравнений: " << ifCount;
    cout << endl << "Время выполнения сортировки: " << seconds << 's';
    cout << endl;
    return 0;
}

void NonRecursiveQuickSort (int array[]){
    int i(0), j(0), L(0), R(0), s(0), x(0);
    int low[SIZE_OF_ARRAY], high[SIZE_OF_ARRAY];

    low[0] = 0; high[0] = SIZE_OF_ARRAY-1;
    do {
        ifCount++;
        L = low[s]; R = high[s]; s--;
        do {
            ifCount++;
            i = L; j = R; x = array[(L+R)/2];
            do {
                ifCount++;
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
                if (i <= j) {
                    swap(array[i], array[j]);
                    swapCount++;
                    i++; j--;
                }
                ifCount++;
            } while (i<=j);
            if (i < R) {
                s++; low[s]=i; high[s]=R;
            }
            ifCount++;
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
            ifCount+=2;
        }
        ifCount+=2;
        while ((k+left != k) && (array[i] < array_for_sort[k])){
            k--; left--; right++;
            ifCount+=2;
        }
        ifCount+=2;
        if (array[i] > array_for_sort[k]){

            if (left < right) {
                for (int j=k-left-1;j<k;j++){
                    swap(array_for_sort[j],array_for_sort[j+1]);
                    swapCount++;
                }
                array_for_sort[k] = array[i];
                left++;
            } else {
                for (int j=k+right+1;j>k+1;j--){
                    swap(array_for_sort[j],array_for_sort[j-1]);
                    swapCount++;
                }
                array_for_sort[k+1] = array[i];
                right++;
            }
            ifCount++;
        } else {
            if (left < right) {
                for (int j=k-left-1;j<k-1;j++){
                    swap(array_for_sort[j],array_for_sort[j+1]);
                    swapCount++;
                }
                array_for_sort[k-1] = array[i];
                left++;
            } else {
                for (int j=k+right+1;j>k;j--){
                    swap(array_for_sort[j],array_for_sort[j-1]);
                    swapCount++;
                }
                array_for_sort[k] = array[i];
                right++;
            }
            ifCount++;
        }
        ifCount++;
    }
    for (int i=k-left;i<SIZE_OF_ARRAY+(k-left);i++){
        array[j] = array_for_sort[i];
        j++;
    }
}