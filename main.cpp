#include "Graph.hpp"

#define TNode string
#define TWeight double

int main() {
    Matrix<TWeight> matrix = {{0, 1, 0, 1},
                              {0, 0, 1, 0},
                              {1, 0, 0, 1},
                              {0, 0, 0, 0}};

    Node<TNode> nodeA("Node A");
    Node<TNode> nodeB("Node B");
    Node<TNode> nodeC("Node C");
    Node<TNode> nodeD("Node D");
    Node<TNode> nodeE("Node E");
    Node<TNode> nodeF("Node F");

    list<Node<TNode>> nodes = {nodeA, nodeB, nodeC, nodeD};

    Graph<TNode, TWeight> graph(nodes, matrix);

    return 0;
}
