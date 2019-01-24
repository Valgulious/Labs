#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H

#include <iostream>
#include <vector>

using namespace std;

class Graph {

private:
    struct GraphNode {
        int startVertex;
        int endVertex;
        GraphNode *next = nullptr;
        GraphNode *prev = nullptr;
        bool passed;
    };

    struct Chain {
        int vertex;
        Chain *next = nullptr;
        Chain *prev = nullptr;
    };

    int countMarkedTops = 0;
    int lengthOfQueue = 0;
    int countOfVertexes = 0;

    int* markedTops = new int[countMarkedTops];
    int* queueOfTops = new int[lengthOfQueue];
    int* vertexes = new int[countOfVertexes];
    vector<Chain*> chains;


    GraphNode *listOfNOdes = nullptr; //Начальный узел

    GraphNode* searchStartVertexInNodes(int _vertex);
    GraphNode* searchVertexInNodes(int _vertex);
    GraphNode* searchLastVertexInNodes(int _vertex);

    int searchArcInNodes(GraphNode* _graphNode, int _startVertex, int _endVertex);

    void printNode(GraphNode* _node);

    GraphNode* firstArc(int _vertex);
    void markVertex(int _vertex);
    void passArc(GraphNode *_node);
    bool unlabeled(int _vertex);
    GraphNode* nextArc(GraphNode* _node, int _startVertex);
    void addToQueue(int _vertex);
    int removeFromQueue();

    Graph ham(Graph _graph);
    int call(int _vertex);
    int exodus(int _vertex);
    void addVertex(int _vertex);
    void removeVertexFromArray(int _vertex);
    bool zeroDeg();
    vector<int> oneDeg();
    vector<int> nextVertexes(int _vertex);
    Chain* addVertexToChain(Chain* _chain, int _vertex);
    Chain* addVertexInBeginOfChain(Chain* _chain, int _vertex);
    int lastVertex(Chain* _chain);
    bool isLastVertex(int _vertex);
    bool isFirstVertex(int _vertex);
    int sizeOfChain(Chain * _chain);
    void printHamCycle(Graph _graph);
    void deleteCycles();

    Graph step1(Graph _graph, int _vertex);
    Graph step2(Graph _graph);
    Graph mergeChains(Graph _graph);
    bool isHam();
    bool isHam(Graph _graph);
    void remArc(int _startVertex, int _endVertex);
//    void step3(Graph _graph);

    void printVertexes(); //Печать вершин дерева

public:
    Graph() = default;
    Graph(const Graph & _graph);
    ~Graph();

    int searchVertex(int _vertex);//Поиск вершины
    int removeVertex(int _vertex);//Удаление вершины

    int addArc(int _startVertex, int _endVertex); //Добавление дуги
    int searchArc(int _startVertex, int _endVertex); //Поиск дуги
    int removeArc(int _startVertex, int _endVertex);//Удаление дуги

    void print(); //Печать дерева

    int wideBypass(int _vertex); // Обход в ширину с посещением всех вершин

    int hamiltonCycles();
};


#endif //GRAPH_GRAPH_H
