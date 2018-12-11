#include "Graph.h"

int Graph::addArc(int _startVertex, int _endVertex) {
    GraphNode* node = searchStartVertexInNodes(_startVertex);
    auto insertNode = new GraphNode;
    insertNode->startVertex = _startVertex;
    insertNode->endVertex = _endVertex;

    if (!this->listOfNOdes) {
        this->listOfNOdes = insertNode;
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
        return 0;
    }
    return 1;
}

int Graph::removeArc(int _startVertex, int _endVertex) {

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
        return 0;
    }

    return 1;
}

int Graph::searchArc(int _startVertex, int _endVertex) {
    GraphNode * node = this->listOfNOdes;
    int result = 0;
    if (node) {
        result = searchArcInNodes(node, _startVertex, _endVertex);
    }

    return result;
}

int Graph::searchArcInNodes(Graph::GraphNode *_graphNode, int _startVertex, int _endVertex) {
    if (_graphNode) {
        return (_startVertex == _graphNode->startVertex && _endVertex == _graphNode->endVertex) ? 1 : searchArcInNodes(_graphNode->next, _startVertex, _endVertex);
    }
    return 0;
}

Graph::GraphNode* Graph::searchStartVertexInNodes(int _vertex) {
    GraphNode *node = this->listOfNOdes;

    while (node) {
        if (_vertex == node->startVertex) return node; else node = node->next;
    }
    return node;
}

Graph::GraphNode* Graph::searchVertexInNodes(int _vertex) {

    GraphNode* node = this->listOfNOdes;

    while (node) {
        if (_vertex == node->startVertex || _vertex == node->endVertex) return node; else node = node->next;
    }

    return node;
}

void Graph::print() {
    GraphNode *node = this->listOfNOdes;

    if (node) {
        while (node) {
            printNode(node);
            node = node->next;
        }
        cout << endl;
    }
}

void Graph::printNode(GraphNode* _node) {
    cout << "(" << _node->startVertex << "," << _node->endVertex << ") ";
}

int Graph::searchVertex(int _vertex) {
    return (searchVertexInNodes(_vertex)) ? 1 : 0;
}

int Graph::removeVertex(int _vertex) {

    if (this->listOfNOdes) {
        GraphNode* searchNode = searchVertexInNodes(_vertex);
        if (searchNode) {
            while (searchNode) {
                removeArc(searchNode->startVertex, searchNode->endVertex);
                searchNode = searchVertexInNodes(_vertex);
            }
            return 0;
        }
        return 1;
    }

    return 2;
}
