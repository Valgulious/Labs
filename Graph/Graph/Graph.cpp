#include "Graph.h"

int Graph::searchVertex(int _vertex)
{
    return (searchVertexInNodes(_vertex)) ? 1 : 0;
}

int Graph::removeVertex(int _vertex)
{

    if (this->listOfNOdes) {
        GraphNode* searchNode = searchVertexInNodes(_vertex);
        if (searchNode) {
            while (searchNode) {
                removeArc(searchNode->startVertex, searchNode->endVertex);
                searchNode = searchVertexInNodes(_vertex);
            }
//            removeVertexFromArray(_vertex);
            return 0;
        }
        return 1;
    }

    return 2;
}

int Graph::addArc(int _startVertex, int _endVertex)
{
    GraphNode* node = searchStartVertexInNodes(_startVertex);
    auto insertNode = new GraphNode;
    insertNode->startVertex = _startVertex;
    insertNode->endVertex = _endVertex;

    if (!this->listOfNOdes) {
        this->listOfNOdes = insertNode;
        addVertex(_startVertex);
        addVertex(_endVertex);
        return 0;
    }

    if (!searchArcInNodes(this->listOfNOdes, _startVertex, _endVertex)) {
        if(node) {
            if (node->prev) {
                node->prev->next = insertNode;
                insertNode->prev = node->prev;
                node->prev = insertNode;
                insertNode->next = node;
            } else {
                node->prev = insertNode;
                insertNode->next = node;
            }
        } else {
            node = this->listOfNOdes;
            while (node->next && node->startVertex < insertNode->startVertex) node = node->next;
            if (node->startVertex > insertNode->startVertex) node = node->prev;
            if (!node) {
                node = insertNode;
                insertNode->next = this->listOfNOdes;
                this->listOfNOdes->prev = node;
            } else if (node->next) {
                node->next->prev = insertNode;
                insertNode->next = node->next;
                node->next = insertNode;
                insertNode->prev = node;
            } else {
                node->next = insertNode;
                insertNode->prev = node;
            }
        }
        while(node->prev) node = node->prev;
        this->listOfNOdes = node;
        addVertex(_startVertex);
        addVertex(_endVertex);
        return 0;
    }
    return 1;
}

int Graph::searchArc(int _startVertex, int _endVertex)
{
    GraphNode * node = this->listOfNOdes;
    int result = 0;
    if (node) {
        result = searchArcInNodes(node, _startVertex, _endVertex);
    }

    return result;
}

int Graph::removeArc(int _startVertex, int _endVertex)
{

    if (!this->listOfNOdes) return 2;

    if (searchArcInNodes(this->listOfNOdes, _startVertex, _endVertex)) {
        GraphNode* node = this->listOfNOdes;
        while (_startVertex != node->startVertex) node = node->next;
        while (_endVertex != node->endVertex) node = node->next;
        if (node->prev) {
            GraphNode* prevNode = node->prev;
            prevNode->next = node->next;
            if (node->next) node->next->prev = prevNode;
            while (prevNode->prev) prevNode = prevNode->prev;
            this->listOfNOdes = prevNode;
        } else {
            if (node->next) {
                node->next->prev = nullptr;
                this->listOfNOdes = node->next;
            } else this->listOfNOdes = nullptr;
        }
        delete node;
        if (!searchVertexInNodes(_startVertex)) removeVertexFromArray(_startVertex);
        if (!searchVertexInNodes(_endVertex)) removeVertexFromArray(_endVertex);
        return 0;
    }

    return 1;
}

void Graph::print()
{
    GraphNode *node = this->listOfNOdes;

    if (node) {
        while (node) {
            printNode(node);
            node = node->next;
        }
        cout << endl;
    } else cout << "Graph is empty" << endl;
}

int Graph::wideBypass()
{
    if (!this->listOfNOdes) return 1;

    GraphNode* node = this->listOfNOdes;

    addToQueue(node->startVertex);
    markVertex(node->startVertex);
    while (lengthOfQueue) {
        int q = removeFromQueue();
        GraphNode* arc = firstArc(q);
        while (arc) {
            passArc(arc);
            int p = arc->endVertex;
            if (unlabeled(p)) {
                markVertex(p);
                addToQueue(p);
            }
            arc = nextArc(arc, q);
        }
        cout << q << " ";
    }

    countMarkedTops = 0;
    lengthOfQueue = 0;
    while(node) {
        node->passed = false;
        node = node->next;
    }
    cout << endl;
    return 0;
}

Graph::GraphNode* Graph::searchStartVertexInNodes(int _vertex)
{
    GraphNode *node = this->listOfNOdes;

    while (node) {
        if (_vertex == node->startVertex) return node; else node = node->next;
    }
    return node;
}

Graph::GraphNode* Graph::searchVertexInNodes(int _vertex)
{

    GraphNode* node = this->listOfNOdes;

    while (node) {
        if (_vertex == node->startVertex || _vertex == node->endVertex) return node; else node = node->next;
    }

    return node;
}

int Graph::searchArcInNodes(Graph::GraphNode *_graphNode, int _startVertex, int _endVertex)
{
    if (_graphNode) {
        return (_startVertex == _graphNode->startVertex && _endVertex == _graphNode->endVertex) ? 1 : searchArcInNodes(_graphNode->next, _startVertex, _endVertex);
    }
    return 0;
}

void Graph::printNode(GraphNode* _node)
{
    cout << "(" << _node->startVertex << "," << _node->endVertex << ") ";
}

Graph::GraphNode* Graph::firstArc(int _vertex)
{
    GraphNode* node = this->listOfNOdes;

    while (node) if (_vertex == node->startVertex) return node; else node = node->next;

    return nullptr;
}

void Graph::markVertex(int _vertex)
{
    int* newArray = new int[countMarkedTops+1];

    for (int i = 0; i < countMarkedTops; i++) {
        newArray[i] = markedTops[i];
    }
    newArray[countMarkedTops] = _vertex;
    ++countMarkedTops;
    int* deleteArray = markedTops;
    markedTops = newArray;
    delete [] deleteArray;
}

void Graph::passArc(Graph::GraphNode *_node)
{
    _node->passed = true;
}

bool Graph::unlabeled(int _vertex)
{
    for (int i = 0; i < countMarkedTops; ++i) {
        if (_vertex == markedTops[i]) return false;
    }

    return true;
}

Graph::GraphNode* Graph::nextArc(Graph::GraphNode *_node, int _startVertex)
{
    GraphNode* nextNode = _node->next;
    return (nextNode && _startVertex == nextNode->startVertex && !nextNode->passed) ? nextNode : nullptr;
}

void Graph::addToQueue(int _vertex)
{
    int* newArray = new int[lengthOfQueue+1];

    for (int i = 0; i < lengthOfQueue; i++) {
        newArray[i] = queueOfTops[i];
    }
    newArray[lengthOfQueue] = _vertex;
    ++lengthOfQueue;
    int* deleteArray = this->queueOfTops;
    this->queueOfTops = newArray;
    delete [] deleteArray;
}

int Graph::removeFromQueue()
{
    int* newArray = new int[lengthOfQueue-1];
    int result = queueOfTops[0];

    for (int i = 1; i < lengthOfQueue; i++) {
        newArray[i-1] = queueOfTops[i];
    }

    --lengthOfQueue;
    int* deleteArray = queueOfTops;
    queueOfTops = newArray;

    delete [] deleteArray;

    return result;
}

int Graph::hamiltonCycles()
{
    GraphNode *node = this->listOfNOdes;

    if (!node) return 2;

    return ham();
}

int Graph::ham()
{

    return 0;
}

int Graph::call(int _vertex)
{
    GraphNode *node = this->listOfNOdes;
    int result = 0;

    while (node) {
        if (_vertex == node->endVertex) ++result;
        node = node->next;
    }

    return result;
}

int Graph::exodus(int _vertex)
{
    GraphNode *node = this->listOfNOdes;
    int result = 0;

    while (node) {
        if (_vertex == node->startVertex) ++result;
        node = node->next;
    }

    return result;
}

void Graph::addVertex(int _vertex)
{
    for (int i = 0; i < countOfVertexes; ++i) if (_vertex == vertexes[i]) return;

    int* newArray = new int[countOfVertexes+1];
    int* deleteArray = vertexes;

    for (int i = 0; i < countOfVertexes; ++i) newArray[i] = vertexes[i];

    newArray[countOfVertexes] = _vertex;
    ++countOfVertexes;

    vertexes = newArray;
    delete [] deleteArray;
}

void Graph::removeVertexFromArray(int _vertex)
{
    if (!countOfVertexes) return;

    int count = 0;
    int* newArray = new int[countOfVertexes-1];
    int* deleteArray = vertexes;

    while (count < countOfVertexes-1 && _vertex != vertexes[count]) {
        newArray[count] = vertexes[count];
        ++count;
    }

    if (count != countOfVertexes) {
        for (int i = count + 1; i < countOfVertexes; ++i) {
            newArray[count] = vertexes[i];
            ++count;
        }
    } else if (_vertex != vertexes[count]) {
        delete [] newArray;
        return;
    }

    --countOfVertexes;
    vertexes = newArray;
    delete [] deleteArray;
}

void Graph::printVertexes()
{
    if (countOfVertexes) {
        for (int i = 0; i < countOfVertexes; ++i) cout << vertexes[i] << " ";
        cout << endl;
    } else cout << "Vertexes are no peaks" << endl;
}