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

    int topsCount;
    GraphNode *listOfNOdes = nullptr; //Начальный узел

    void sortTops();
    GraphNode* searchVertexInNodes(int _vertex);
    int searchArcInNodes(GraphNode* _graphNode, int _startVertex, int _endVertex);
    void printNode(GraphNode* _node);

public:
    Graph() = default;

    int searchVertex(int _vertex);
    int removeVertex(int _vertex);

    int addArc(int _startVertex, int _endVertex);
    int searchArc(int _startVertex, int _endVertex);
    int removeArc(int _startVertex, int _endVertex);

    void print();
//    void printTops();
};


#endif //GRAPH_GRAPH_H
