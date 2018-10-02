#include <iostream>

using namespace std;

int const T = 2; // Степень B-дерева

struct BNode {

    int keys[2*T-1]; // Ключи узла
    BNode * parent = nullptr; // Родитель
    BNode * childs[2*T]; // Потомки
public:
    int search(int element) {
        for (int i = 0; i < 2*T - 1; i++) if (this->keys[i] == -1) return i;
        return -1;

    }

    int searchChild(int element) {
        int i = 0;
        while ((i < 2*T - 1) and (element <= this->keys[i])) i++;
        return i;
    }
};

/*Функция создания B-дерева
 * root - корень дерева*/
BNode createBTree(BNode root);

/*Функция удаления B-дерева
 * root - корень дерева*/
void deleteBTree(BNode root);

/*Функция добавления елемента в B-дерево
 * root - корень B-дерева, element - элемент, который надо добавить в B-дерево*/
int addElement(BNode root, int element);

/*Функция удаления елемента из B-дерева
 * root - корень B-дерева, element - элемент, который надо удалить из B-дерева*/
int deleteElement(BNode root, int element);

/*Функция поиска элемента в B-дереве
 * root - корень B-дерева, element - элемент, который надо найти в B-дереве*/
int searchELement(BNode root, int element);

/*Функция печати B-дерева
 * root - корень B-дерева*/
void printBtTree(BNode root);

/*Функция определяющая, являутся ли узел B-дерева корнем или нет
 * node - узел B-дерева*/
bool isRoot(BNode node);

int main() {
    BNode BTree;
    addElement(BTree, 5);
    cout << BTree.keys[0];
//    if (isRoot(BTree)) cout << "yes";
    return 0;
}

bool isRoot(BNode node) {
    if (!node.parent) return true;
    return false;
}

int addElement(BNode root, int element) {
    for (int i = 0; i < 2*T; i++) {
        int search = root.search(element);
        if (search != -1) root.keys[search] = element;
        else {
            BNode node = *root.childs[root.searchChild(element)];
            addElement(node, element);
        }}
}