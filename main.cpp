#include "Graph.hpp"

using std::cin, std::cout, std::endl, std::string;

#define TNode string
#define TWeight double

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

    Node<TNode> nodeA("A");
    Node<TNode> nodeB("B");
    Node<TNode> nodeC("C");
    Node<TNode> nodeD("D");
    Node<TNode> nodeE("E");
    Node<TNode> nodeF("F");

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

    cout << graph1.AdjacencyMatrix() << endl;

    matrix2 = Matrix<TWeight>();

//    for (int i = 0; i < graph1.Nodes(); ++i) {
//        cout << "( " << graph1.degree_out(i) << " : " << graph1.degree_in(i) << " )" << endl;
//    }

    return 0;
}
