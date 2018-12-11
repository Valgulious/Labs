#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    cout << "" << endl;
    Graph graph;
    graph.addArc(4,2);
    graph.addArc(3,4);
    graph.addArc(2,2);
    graph.addArc(1,2);
    graph.addArc(1,2);
    graph.addArc(1,3);

    graph.print();
    cout << graph.wideBypass() << endl;
    return 0;
}