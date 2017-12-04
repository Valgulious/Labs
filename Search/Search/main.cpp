#include <iostream>

using namespace std;

int BinarySearch (int[],int);
int InterpolatingSearch (int[], int);
int trueSort(int[]);

int const SIZE_OF_ARRAY = 10;

int main() {
    int result;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int array[SIZE_OF_ARRAY][SIZE_OF_ARRAY];
    int array_for_search[SIZE_OF_ARRAY];
    int key(0);

    for (int i=0;i<SIZE_OF_ARRAY;i++)
        for (int j=0;j<SIZE_OF_ARRAY;j++) array[i][j] = 10*i + j;

    for (int j=0;j<SIZE_OF_ARRAY;j++){
        for (int i=0;i<SIZE_OF_ARRAY;i++){
            array_for_search[i] = array[i][j];
            cout << array_for_search[i] << ' ';
        }
        cout << endl << "Введите искомое число" << endl;
        cin >> key;
        cout << "Результат бинарного поиска: ";
        try {
            cout << "Искомый элемент стоит на позиции: "
                 << BinarySearch(array_for_search,key) << endl;
        } catch (char const* message){
            cout << message << endl;
        }
        cout << "Результат интерполяционного поиска поиска: ";
        try {
            cout << "Искомый элемент стоит на позиции: "
                 << InterpolatingSearch(array_for_search,key) << endl;
        } catch (char const* message){
            cout << message << endl;
        }
    }

    return 0;
}

int BinarySearch (int array[], int key) {
    int left(0), right(SIZE_OF_ARRAY-1), mid(0);

    if (trueSort(array)){
        while (left <= right){
            mid = (left+right)/2;
            if (key == array[mid]) return mid+1;
            else if (key < array[mid]) right = mid - 1;
            else if (key > array[mid]) left = mid + 1;
        }

    } else throw "Массив не отсортирован";
    throw "Поиск не дал результатов";
}

int InterpolatingSearch (int array[], int key){
    int left(0), right(SIZE_OF_ARRAY-1), mid(0);

    if (trueSort(array)){
        while ((array[left] < key) && (array[right] >= key)){
            mid = left + (((key-array[left])*(right-left))/(array[right]-array[left]));
            if (array[mid] < key) left = mid + 1;
            else if (array[mid] > key) right = mid - 1;
            else return mid+1;
        }
        if (array[left] == key) return left+1;
        else throw "Поиск не дал результатов";
    } else throw "Массив не отсортирован";

}

int trueSort (int array[]){
    for (int i=1;i<SIZE_OF_ARRAY;i++) if (array[i-1]>array[i]) return 0;
}