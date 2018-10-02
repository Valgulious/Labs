#include <iostream>
#include <vector>

using namespace std;

int const T = 2; // Степень B-дерева

struct BNode {
    bool isLeaf = true;
    vector<int> keys; // Ключи узла
    BNode * parent = nullptr; // Родитель
    vector<BNode*> children;// Потомки
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

    vector<int> a;
    vector<int>::iterator iter;

    a.push_back(5);
    a.push_back(6);
    iter = a.begin();
    iter++;
    a.insert(iter, 7);
    iter = a.begin();
    a.erase(iter);
//    a.erase(iter);
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    cout << a[6] << endl;
//    if (isRoot(BTree)) cout << "yes";
    return 0;
}

bool isRoot(BNode node) {
    if (!node.parent) return true;
    return false;
}

BNode restructuring(BNode node) {
    BNode leftNode, rightNode;
    vector<int>::iterator iter = node.keys.begin();
    for (int i = 0; i < 2*T-1; i++) {
        if (i < T-1) {
            leftNode.keys.push_back(node.keys[0]);
            node.keys.erase(iter);
        } else if (i > T-1) {
            rightNode.keys.push_back(node.keys[0]);
            node.keys.erase(iter);
        } else {
            iter++;
        }
    }
    if (node.parent) {
        addElement(*node.parent, node.keys[0]);
    } else {
        leftNode.parent = &node;
        rightNode.parent = &node;
        node.children[0] = &leftNode;
        node.children[1] = &rightNode;
    }
}

int addElement(BNode root, int element) {
    if (root.isLeaf) {
        if (root.keys.size() == 2*T-1) {

        }
    }
}
