#include <iostream>

using namespace std;

int BinarySearch (int*,int);
void BubbleSort (int*);

int const SIZE_OF_ARRAY = 10;
int array[SIZE_OF_ARRAY];
int key(0);

int main() {
    int result;
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    for (int i=0;i<SIZE_OF_ARRAY;i++) array[i] = rand()%100;
    BubbleSort(array);
    for (int i=0;i<SIZE_OF_ARRAY;i++) cout << array[i] << ' ';
    cout << endl << "Введите искомое число" << endl;
    cin >> key;
    result = BinarySearch(array,key);
    if (result) cout << "Искомое число стоит под номером: " << result << endl;
    else cout << "Поиск не дал результатов" << endl;
    return 0;
}

int BinarySearch (int *array, int key) {
    int left(0), right(SIZE_OF_ARRAY), mid(0);

    while (left <= right){
        mid = (left+right)/2;
        if (key == array[mid]) return mid+1;
        else if (key < array[mid]) right = mid - 1;
        else if (key > array[mid]) left = mid + 1;
    }
    return 0;
}

void BubbleSort (int *array){
    for (int i=0;i<SIZE_OF_ARRAY-1;i++) {
        for (int j = 0; j < SIZE_OF_ARRAY - i; j++)
            if (array[j-1] > array[j]) swap(array[j-1], array[j]);
    }
}