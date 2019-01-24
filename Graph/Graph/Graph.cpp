#include "Graph.h"

Graph::Graph(const Graph & _graph)
{
    GraphNode* node = _graph.listOfNOdes;
//    this->chains = _graph.chains;

    for (auto chain : _graph.chains) {
        auto newChain = new Chain;
        newChain->vertex = chain->vertex;
        chain = chain->next;
        while (chain) {
            addVertexToChain(newChain, chain->vertex);
            chain = chain->next;
        }
        this->chains.push_back(newChain);
    }

    while (node) {
        this->addArc(node->startVertex, node->endVertex);
        node = node->next;
    }
}

Graph::~Graph(){
    this->chains.clear();
}

int Graph::searchVertex(int _vertex)
{
    return searchVertexInNodes(_vertex) ? 1 : 0;
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

int Graph::wideBypass(int _vertex)
{
    if (!this->listOfNOdes) return 2;

    GraphNode* node = searchStartVertexInNodes(_vertex);

    if (!node) return 1;

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

bool Graph::zeroDeg()
{
    for (int i = 0; i < countOfVertexes; ++i) if (!exodus(vertexes[i]) || !call(vertexes[i])) return true;

    return false;
}

vector<int> Graph::oneDeg() {
    vector<int> arr;
    for (int i = 0; i < countOfVertexes; ++i) {
        if (1 == exodus(vertexes[i]) || 1 == call(vertexes[i])) arr.push_back(vertexes[i]);
    }

    return arr;
}

int Graph::hamiltonCycle()
{
    GraphNode *node = this->listOfNOdes;

    if (!node) return 2;

   /* auto ch = new Chain;

    addVertexToChain(ch, node->startVertex);

    chains.push_back(ch);

    auto graph = new Graph(*this);
    bool flag = true;

    while (flag) {
        graph = ham(*graph);
        if (graph) flag = false;
    }*/

   for (int i = 0; i < countOfVertexes; ++i) {
       Graph graph(*this);
       Chain* chain = nullptr;

       chain = addVertexToChain(chain, vertexes[i]);
       graph.chains.push_back(chain);
       Graph newGraph(ham(graph));
       if (newGraph.isHam(*this)) {
           printHamCycle(newGraph);
           return 1;
       }
   }

    return 0;
}

Graph Graph::ham(Graph _graph)
{
    vector<int> eVertexes(_graph.nextVertexes(lastVertex(_graph.chains[0])));

    for (int i = 0; i < countOfVertexes; ++i) {
        _graph.remArc(vertexes[i], vertexes[i]);;
    }

    while (!eVertexes.empty()) {
        Graph newGraph(step1(_graph, eVertexes.back()));
//        newGraph = step2(_graph);
        if (!newGraph.zeroDeg()) {
            newGraph.addVertexToChain(newGraph.chains[0], eVertexes.back());
            Graph test(step2(newGraph));
            newGraph = test;
            if (newGraph.isHam()) {
                return newGraph;
            } else if (newGraph.zeroDeg()) {
                eVertexes.pop_back();
            } else {
                newGraph = ham(newGraph);
                if (newGraph.isHam()) return newGraph; else eVertexes.pop_back();
            }
        } else {
            eVertexes.pop_back();
        }
    }

    return _graph;
}

Graph Graph::step1(Graph _graph, int _vertex)
{
    for (int i = 0; i < _graph.countOfVertexes; ++i) {
        if (_vertex != _graph.vertexes[i])
            _graph.remArc(lastVertex(_graph.chains[0]), _graph.vertexes[i]);
        if (lastVertex(_graph.chains[0]) != _graph.vertexes[i])
            _graph.remArc(_graph.vertexes[i], _vertex);
    }

    for (auto chain : _graph.chains) {
        if (_vertex == chain->vertex)
            _graph.remArc(lastVertex(chain), _graph.chains[0]->vertex);
    }

    return _graph;
}

Graph Graph::step2(Graph _graph)
{
    vector<int> oneDegVertexes = _graph.oneDeg();

    while (!oneDegVertexes.empty()) {
        for (auto vertex : oneDegVertexes) {
            if (!_graph.isLastVertex(vertex) && 1 == _graph.call(vertex)) {
                int startVertex = _graph.searchLastVertexInNodes(vertex)->startVertex;
                for (int i = 0; i < _graph.countOfVertexes; ++i) {
                    if (vertex != _graph.vertexes[i])
                        _graph.remArc(startVertex, _graph.vertexes[i]);
                }
                if (_graph.zeroDeg()) return _graph;
                if (_graph.isLastVertex(_graph.searchVertexInNodes(vertex)->startVertex)) {
                    for (auto chain : _graph.chains) {
                        if (_graph.searchVertexInNodes(vertex)->startVertex == _graph.lastVertex(chain))
                            _graph.addVertexToChain(chain, vertex);
                    }
                } else /*if (!_graph.isFirstVertex(vertex))*/ {
                    auto newChain = new Chain;
                    newChain->vertex = _graph.searchLastVertexInNodes(vertex)->startVertex;
                    _graph.addVertexToChain(newChain, vertex);
                    _graph.chains.push_back(newChain);
                }
                _graph = mergeChains(_graph);
            } else if (!_graph.isFirstVertex(vertex) && 1 == _graph.exodus(vertex)) {
                for (int i = 0; i < _graph.countOfVertexes; ++i) {
                    if (_graph.searchStartVertexInNodes(vertex)->startVertex != _graph.vertexes[i])
                        _graph.remArc(_graph.vertexes[i], _graph.searchStartVertexInNodes(vertex)->endVertex);
                }
                if (_graph.zeroDeg()) return _graph;
                if (_graph.isFirstVertex(_graph.searchStartVertexInNodes(vertex)->endVertex)) {
                    for (auto chain : _graph.chains)
                        if (_graph.searchStartVertexInNodes(vertex)->endVertex == chain->vertex) {
                            _graph.addVertexInBeginOfChain(chain, vertex);
                            chain = chain->prev;
                        }

                } else {
                    auto newChain = new Chain;
                    newChain->vertex = vertex;
                    addVertexToChain(newChain, _graph.searchStartVertexInNodes(vertex)->endVertex);
                    _graph.chains.push_back(newChain);
                }
                _graph = mergeChains(_graph);
            }
            if (_graph.isHam()) return _graph;
        }
        _graph.deleteCycles();
//        if (_graph.zeroDeg()) {
//            return _graph;
//        }
        if (_graph.zeroDeg()) {
            const Graph &graph(_graph);
            return graph;
        }

        oneDegVertexes = _graph.oneDeg();
    }

    return _graph;
}

vector<int> Graph::nextVertexes(int _vertex)
{
    vector<int> arr;
    GraphNode* node = this->searchVertexInNodes(_vertex);

    while (node && _vertex == node->startVertex) {
        arr.push_back(node->endVertex);
        node = node->next;
    }

    return arr;
}

Graph::Chain* Graph::addVertexToChain(Chain* _chain, int _vertex)
{

    auto newChain = new Chain;
    newChain->vertex = _vertex;
    newChain->next = nullptr;
    newChain->prev = nullptr;

    if (!_chain) {
        _chain = newChain;
        return _chain;
    }

    Chain* chain = _chain;

    while(chain->next) chain = chain->next;
    newChain->prev = chain;
    chain->next = newChain;
}

Graph::Chain * Graph::addVertexInBeginOfChain(Graph::Chain *_chain, int _vertex)
{
    Chain* chain = _chain;
    int insertVertex = _vertex;
    int oldVertex;

//    auto newChain = new Chain;
//    newChain->vertex = _vertex;
//    newChain->next = chain;
//    chain->prev = newChain;
//    _chain = newChain;

    while (chain) {
        oldVertex = chain->vertex;
        chain->vertex = insertVertex;
        chain = chain->next;
        insertVertex = oldVertex;
    }

    this->addVertexToChain(_chain, insertVertex);
    return _chain;
}

int Graph::lastVertex(Graph::Chain* _chain)
{
    Chain* chain = _chain;

    while (chain->next) chain = chain->next;

    return chain->vertex;
}

bool Graph::isLastVertex(int _vertex)
{
    for (auto chain : chains) if (_vertex == lastVertex(chain)) return true;

    return false;
}

bool Graph::isFirstVertex(int _vertex)
{
    for (auto chain : chains) if (_vertex == chain->vertex) return true;

    return false;
}

Graph Graph::mergeChains(Graph _graph)
{
    auto chainsIterI = _graph.chains.begin();
    auto chainsIterJ = _graph.chains.begin();

//    for (auto chain : chains) {
//        int last = _graph->lastVertex(*chainsIter);
//        if (lastVertex(chain) == )
//    }

    for (int i = 0; i < _graph.chains.size(); ++i) {
        for (int j = 0; j < _graph.chains.size(); ++j) {
            if (_graph.chains[j]->vertex == _graph.lastVertex(_graph.chains[i]) && j) {
                Chain* chain = _graph.chains[j]->next;
                while (chain) {
                    _graph.addVertexToChain(_graph.chains[i], chain->vertex);
                    chain = chain->next;
                }
                _graph.chains.erase(chainsIterJ);
            } else if (_graph.chains[j]->vertex == _graph.lastVertex(_graph.chains[i]) && !j) {
                Chain* chain = _graph.chains[i];
                while (chain->next->next) {
                    chain = chain->next;
                }
                while (chain) {
                    _graph.addVertexInBeginOfChain(_graph.chains[j], chain->vertex);
                    chain = chain->prev;
                }
                _graph.chains.erase(chainsIterI);
            }
            chainsIterJ++;
        }
        chainsIterJ = _graph.chains.begin();
        chainsIterI++;
    }

//    while (chainsIterI != chains.end()-1) {
//        int last = _graph->lastVertex(*chainsIterI);
//        chainsIterI++;
//        if (last == *chainsIterI->vertex)
//    }
//    for (auto chainsIter = chains.begin(); chainsIter != chains.end(); chainsIter++) {
//
//    }
    return _graph;
}

int Graph::sizeOfChain(Graph::Chain *_chain)
{
    auto chain = _chain;

    if (!chain) return 0;

    int count = 0;

    while (chain) {
        ++count;
        chain = chain->next;
    }

    return count;
}

void Graph::printHamCycle(Graph _graph)
{
    auto chain = _graph.chains[0];

    while (chain) {
        cout << chain->vertex << " -> ";
        chain = chain->next;
    }
    cout << _graph.chains[0]->vertex;
    cout << endl;
}

bool Graph::isHam()
{
    Chain* chain = this->chains[0];
    return (sizeOfChain(chain) == countOfVertexes);
}

bool Graph::isHam(Graph _graph)
{
    Chain* chain = this->chains[0];
    return (sizeOfChain(chain) == _graph.countOfVertexes);
}

void Graph::deleteCycles()
{
    for (auto chain : this->chains) {
        if (searchArc(lastVertex(chain), chain->vertex)) this->removeArc(lastVertex(chain), chain->vertex);
    }
}

Graph::GraphNode* Graph::searchLastVertexInNodes(int _vertex)
{
    GraphNode* node = listOfNOdes;

    while (node) {
        if (_vertex == node->endVertex) return node;
        node = node->next;
    }

    return nullptr;
}

void Graph::remArc(int _startVertex, int _endVertex)
{
    if (!this->listOfNOdes) return;

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
        return;
    }

}