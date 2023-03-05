#include "Graph.hpp"

#define TNode string
#define TWeight double

int main() {
    Matrix<TWeight> matrix = {{0, 1, 0, 1},
                              {0, 0, 1, 0},
                              {1, 0, 0, 1},
                              {0, 0, 0, 0}};

    Node<TNode> node1("NodeA");
    Node<TNode> node2("NodeB");
    Node<TNode> node3("NodeC");
    Node<TNode> node4("NodeD");
    Node<TNode> node5("NodeE");
    Node<TNode> node6("NodeA");

    list<Node<TNode>> nodes = {node1, node2, node3, node4};

    Graph<TNode, TWeight> graph(nodes, matrix);

    graph.save_to_file("graphOut.txt");

    auto graph2(graph);
    graph2.load_from_file("graphIn.txt.txt");
    for (auto i: graph2.Nodes()) {
        std::cout << i.GetData() << std::endl;
    }
    std::cout << graph2.AdjacencyMatrix() << std::endl;

    return 0;
}
