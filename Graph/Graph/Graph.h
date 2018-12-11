#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>

using namespace std;

class Graph {

private:
    struct GraphNode{
        int startVertex;
        int endVertex;
        GraphNode *next = nullptr;
        GraphNode *prev = nullptr;
    };

    GraphNode *listOfNOdes = nullptr; //Начальный узел

    GraphNode* searchStartVertexInNodes(int _vertex);
    GraphNode* searchVertexInNodes(int _vertex);
    int searchArcInNodes(GraphNode* _graphNode, int _startVertex, int _endVertex);
    void printNode(GraphNode* _node);

public:
    Graph() = default;

    int searchVertex(int _vertex);//Поиск вершины
    int removeVertex(int _vertex);//Удаление вершины

    int addArc(int _startVertex, int _endVertex); //Добавление дуги
    int searchArc(int _startVertex, int _endVertex); //Поиск дуги
    int removeArc(int _startVertex, int _endVertex);//Удаление дуги

    void print(); //Печать дерева
};


#endif //GRAPH_GRAPH_H
