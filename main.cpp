#include "Graph.hpp"
#include <set>

using std::cin, std::cout, std::endl, std::string;

#define TNode int
#define TWeight int

int main() {
    Matrix<TWeight> matrix1 = {{0, 1, 0, 1},
                               {0, 0, 1, 0},
                               {1, 0, 0, 1},
                               {0, 0, 0, 0}};

    Matrix<TWeight> matrix2 = {{1, 1, 0, 0, 1, 0},
                               {1, 0, 1, 0, 1, 0},
                               {0, 1, 0, 1, 0, 0},
                               {0, 0, 1, 0, 1, 1},
                               {1, 1, 0, 1, 0, 0},
                               {0, 0, 0, 1, 0, 0}};

    Node<TNode> nodeA(0);
    Node<TNode> nodeB(1);
    Node<TNode> nodeC(2);
    Node<TNode> nodeD(3);
    Node<TNode> nodeE(4);
    Node<TNode> nodeF(5);

    vector<Node<TNode>> nodes1 = {nodeA, nodeB, nodeC, nodeD};
    vector<Node<TNode>> nodes2 = {nodeA, nodeB, nodeC, nodeD, nodeE, nodeF};

//    Edge<TNode, TWeight> edgeAB(nodeA, nodeB, 0.4490);
//
//    Edge<TNode, TWeight> edgeBC(nodeB, nodeC, 0.2500);
//
//    Edge<TNode, TWeight> edgeCA(nodeC, nodeA, 0.5392);
//    Edge<TNode, TWeight> edgeCE(nodeC, nodeE, 0.2500);
//
//    Edge<TNode, TWeight> edgeDA(nodeD, nodeA, 0.5392);
//    Edge<TNode, TWeight> edgeDC(nodeD, nodeC, 0.3923);
//
//    Edge<TNode, TWeight> edgeDE(nodeD, nodeE, 0.4735);
//
//    Edge<TNode, TWeight> edgeEB(nodeE, nodeB, 0.2500);

    Graph<TNode, TWeight> graph1(nodes1, matrix1);
    Graph<TNode, TWeight> graph2(nodes2, matrix2);

    swap(graph1, graph2);

    for (auto i: graph1.Nodes()) {
        cout << "( " << graph1.degree_out(i) << " : " << graph1.degree_in(i) << " )" << endl;
    }
    return 0;
}
