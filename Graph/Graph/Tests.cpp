#include "Graph.h"

void searchArc1() {
    Graph graph;

    if (!graph.searchArc(3, 4)) {
        cout << "Test searchArc1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void searchArc2() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);

    if (!graph.searchArc(3, 4)) {
        cout << "Test searchArc2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void searchArc3() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(3,4);

    if (graph.searchArc(3, 4)) {
        cout << "Test searchArc3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void searchVertex1() {
    Graph graph;

    if (!graph.searchVertex(3)) {
        cout << "Test searchVertex1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void searchVertex2() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,4);

    if (!graph.searchVertex(3)) {
        cout << "Test searchVertex2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void searchVertex3() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(3,4);

    if (graph.searchVertex(3)) {
        cout << "Test searchVertex3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc1() {
    Graph graph;

    if (!graph.addArc(3,4)) {
        cout << "Test addArc1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc2() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (!graph.addArc(6,4)) {
        cout << "Test addArc2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc3() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (!graph.addArc(1,9)) {
        cout << "Test addArc3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc4() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (!graph.addArc(3,4)) {
        cout << "Test addArc4 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc5() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (!graph.addArc(1,1)) {
        cout << "Test addArc5 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void addArc6() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (graph.addArc(2,3)) {
        cout << "Test addArc6 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc1() {
    Graph graph;

    if (2 == graph.removeArc(3,4)) {
        cout << "Test removeArc1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc2() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (1 == graph.removeArc(6,4)) {
        cout << "Test removeArc2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc3() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);
    graph.addArc(1,9);

    if (!graph.removeArc(1,9)) {
        cout << "Test removeArc3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc4() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);
    graph.addArc(1,1);

    if (!graph.removeArc(1,1)) {
        cout << "Test removeArc4 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc5() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);
    graph.addArc(1,1);

    if (!graph.removeArc(2,3)) {
        cout << "Test removeArc5 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeArc6() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);
    graph.addArc(1,1);

    if (!graph.removeArc(5,3)) {
        cout << "Test removeArc6 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeVertex1() {
    Graph graph;

    if (2 == graph.removeVertex(3)) {
        cout << "Test removeVertex1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeVertex2() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);

    if (1 == graph.removeVertex(6)) {
        cout << "Test removeVertex2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void removeVertex3() {
    Graph graph;

    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(5,3);
    graph.addArc(1,9);

    if (!graph.removeVertex(1)) {
        cout << "Test removeVertex3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass1() {
    Graph graph;

    if (2 == graph.wideBypass(3)) {
        cout << "Test wideBypass1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass2() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,4);

    if (1 == graph.removeVertex(3)) {
        cout << "Test wideBypass2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass3() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(3,4);

    if (!graph.wideBypass(3)) {
        cout << "Test wideBypass3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass4() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(1,4);

    if (1 == graph.wideBypass(3)) {
        cout << "Test wideBypass4 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass5() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(1,9);
    graph.addArc(5,7);
    graph.addArc(5,10);
    graph.addArc(4,6);
    graph.addArc(7,8);


    if (!graph.wideBypass(1)) {
        cout << "Test wideBypass5 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass6() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(1,9);
    graph.addArc(5,7);
    graph.addArc(5,10);
    graph.addArc(4,6);
    graph.addArc(7,8);


    if (!graph.wideBypass(5)) {
        cout << "Test wideBypass6 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void wideBypass7() {
    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,4);
    graph.addArc(1,3);
    graph.addArc(1,9);
    graph.addArc(5,7);
    graph.addArc(5,10);
    graph.addArc(4,6);
    graph.addArc(7,8);

    for (int i = 0; i < 10; i += 2) {
        graph.removeVertex(i);
    }

    if (!graph.wideBypass(1)) {
        cout << "Test wideBypass7 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle1() {

    Graph graph;

    if (2 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle1 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle2() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,3);
    graph.addArc(3,4);
    graph.addArc(4,5);

    graph.print();

    if (!graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle2 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle3() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,3);
    graph.addArc(3,4);
    graph.addArc(4,5);
    graph.addArc(5,1);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle3 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle4() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,1);
    graph.addArc(2,3);
    graph.addArc(3,2);
    graph.addArc(3,4);
    graph.addArc(4,3);
    graph.addArc(4,5);
    graph.addArc(5,4);
    graph.addArc(5,1);
    graph.addArc(1,5);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle4 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle5() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,3);
    graph.addArc(3,4);
    graph.addArc(4,5);
    graph.addArc(5,1);
    graph.addArc(1,1);
    graph.addArc(2,2);
    graph.addArc(3,3);
    graph.addArc(4,4);
    graph.addArc(5,5);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle5 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}
void hamiltonCycle6() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(2,3);
    graph.addArc(3,4);
    graph.addArc(5,1);
    graph.addArc(1,1);
    graph.addArc(2,2);
    graph.addArc(3,3);
    graph.addArc(4,4);
    graph.addArc(5,5);

    graph.print();

    if (!graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle6 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}


void hamiltonCycle7() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,3);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(3,2);
    graph.addArc(3,4);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle7 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle8() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,3);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(3,2);
    graph.addArc(3,4);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);

    graph.removeVertex(3);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle8 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle9() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);

    graph.removeVertex(4);

    graph.print();

    if (!graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle9 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle10() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,3);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(3,2);
    graph.addArc(3,4);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);
    graph.addArc(5,5);

    graph.print();

    if (!graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle10 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle11() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,3);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(3,2);
    graph.addArc(3,4);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);

    for (int i = 0; i < 10; i += 2) {
        graph.removeVertex(i);
    }

    graph.print();

    if (!graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle11 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}

void hamiltonCycle12() {

    Graph graph;

    graph.addArc(1,2);
    graph.addArc(1,6);
    graph.addArc(1,10);
    graph.addArc(2,6);
    graph.addArc(4,1);
    graph.addArc(4,2);
    graph.addArc(10,4);
    graph.addArc(4,10);
    graph.addArc(6,8);
    graph.addArc(8,1);
    graph.addArc(8,9);
    graph.addArc(9,1);
    graph.addArc(9,10);
    graph.addArc(9,8);
    graph.addArc(3,2);
    graph.addArc(3,4);

    graph.addArc(1,3);

    graph.print();

    if (1 == graph.hamiltonCycle()) {
        cout << "Test hamiltonCycle12 passed"  << endl;
        cout << "----------------------"  << endl;
    }
}