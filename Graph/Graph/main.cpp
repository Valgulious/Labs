#include <iostream>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph;
    /*graph.addArc(4,2);
    graph.addArc(3,4);
    graph.addArc(2,2);
    graph.addArc(1,2);
    graph.addArc(1,2);
    graph.addArc(1,3);*/

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < i; ++j) {
            graph.addArc(i, j);
        }
    }

    graph.print();

    cout << graph.wideBypass(1) << endl;

    for (int i = -1; i < 12; i=i+2) {
                   graph.removeVertex(i);
    }

    graph.print();

    cout << graph.wideBypass(8) << endl;

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < i; ++j) {
            graph.addArc(10-i, j);
        }
    }

    graph.print();

    cout << graph.wideBypass(1) << endl;


    return 0;



}