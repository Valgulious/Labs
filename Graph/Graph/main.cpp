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
    graph.printVertexes();

    cout << "e = " << graph.exodus(3) << endl;
    cout << "c = " << graph.call(3) << endl;

//    cout << graph.wideBypass() << endl;
    return 0;
}