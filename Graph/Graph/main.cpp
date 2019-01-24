#include <iostream>
#include "Graph.h"
#include "Tests.cpp"

using namespace std;

int main() {
    Graph graph;
//    /*graph.addArc(4,2);
//    graph.addArc(3,4);
//    graph.addArc(2,2);
//    graph.addArc(1,2);
//    graph.addArc(1,2);
//    graph.addArc(1,3);*/
//
//    /*for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < i; ++j) {
//            graph.addArc(i, j);
//        }
//    }
//
//    graph.print();
//
//    cout << graph.wideBypass(1) << endl;
//
//    for (int i = -1; i < 12; i=i+2) {
//                   graph.removeVertex(i);
//    }
//
//    graph.print();
//
//    cout << graph.wideBypass(8) << endl;
//
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < i; ++j) {
//            graph.addArc(10-i, j);
//        }
//    }
//
//    graph.print();
//
//    cout << graph.wideBypass(1) << endl;*/
//
//
//    graph.addArc(1,2);
//    graph.addArc(2,3);
//    graph.addArc(3,4);
//    graph.addArc(1,3);
//    graph.addArc(2,4);
//    graph.addArc(4,1);

//    graph.addArc(1,2);
//    graph.addArc(1,1);
//    graph.addArc(1,3);
//    graph.addArc(1,6);
//    graph.addArc(1,10);
//    graph.addArc(2,6);
//    graph.addArc(2,2);
//    graph.addArc(3,2);
//    graph.addArc(3,4);
//    graph.addArc(3,3);
//    graph.addArc(4,1);
//    graph.addArc(4,2);
//    graph.addArc(4,4);
//    graph.addArc(10,4);
//    graph.addArc(10,10);
//    graph.addArc(4,10);
//    graph.addArc(6,8);
//    graph.addArc(6,6);
//    graph.addArc(8,1);
//    graph.addArc(8,8);
//    graph.addArc(8,9);
//    graph.addArc(9,9);
//    graph.addArc(9,1);
//    graph.addArc(9,10);
//    graph.addArc(9,8);
//    graph.addArc(10,10);
//    graph.addArc(1,1);
//    graph.addArc(4,4);
//    graph.addArc(2,2);
//
//    graph.print();
//
//    cout << graph.hamiltonCycle() << endl;

    hamiltonCycle1();
    hamiltonCycle2();
    hamiltonCycle3();
    hamiltonCycle4();
    hamiltonCycle5();
    hamiltonCycle6();
    hamiltonCycle7();
    hamiltonCycle8();
    hamiltonCycle9();
    hamiltonCycle10();
    return 0;
}