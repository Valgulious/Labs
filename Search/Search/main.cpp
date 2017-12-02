#include <iostream>

using namespace std;

int BinarySearch (int*,int);
int trueSort(int*);

int const SIZE_OF_ARRAY = 10;
int array[SIZE_OF_ARRAY];
int key(0);

int main() {
    int result;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++){
        array[i] = rand()%100;
        cout << array[i] << ' ';
    }
    cout << endl << "Введите искомое число" << endl;
    cin >> key;
    try {
        cout << "Искомый элемент стоит на позиции: " << BinarySearch(array,key);
    } catch (char const* message) {
        cout << message;
    }
    return 0;
}

int BinarySearch (int *array, int key) {
    int left(0), right(SIZE_OF_ARRAY), mid(0);

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

int trueSort (int *array){
    for (int i=1;i<SIZE_OF_ARRAY;i++) if (array[i-1]>array[i]) return 0;
}