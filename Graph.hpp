# pragma once

#include "Matrix.hpp"
#include "Edge.hpp"
#include <vector>
#include <list>
#include <map>
#include <set>

using std::vector, std::list, std::pair, std::map, std::set;

template<typename TNode, typename TWeight>
class Graph {
private:
    map<Node<TNode>, size_t, NodeCompare<TNode>> graphNodes;
    Matrix<TWeight> adjacencyMatrix;

public:
    size_t size() const {
        return graphNodes.size();
    }

    size_t Edges() const {
        size_t count = 0;
        for (auto i: adjacencyMatrix) {
            if (i > 0) {
                count++;
            }
        }
        return count;
    }

    set<Node<TNode>, NodeCompare<TNode>> Nodes() {
        set<Node<TNode>, NodeCompare<TNode>> s;
        for (auto i: graphNodes) {
            s.insert(i.first);
        }
        return s;
    }

    Matrix<TWeight> AdjacencyMatrix() const {
        return adjacencyMatrix;
    }


    // 3. Основной интрефейс -- начало
    bool empty() const {
        return graphNodes.empty();
    }

    void clear() {
        graphNodes.clear();
        adjacencyMatrix.clear();
    }

    void swap(Graph &other) {
        Graph tmp = *this;
        *this = other;
        other = tmp;
    }
    // 3. Основной интрефейс -- конец

    // 2. Конструкторы и операторы присваивания класса Graph -- начало
    // Default Constructor
    Graph() = default;

    // Constructor
    Graph(const vector<Node<TNode>> &nodes, const Matrix<TWeight> &matrix) {
        if (matrix.square()) {
            for (size_t i = 0; i < nodes.size(); ++i) {
                graphNodes[nodes[i]] = i;
            }
            adjacencyMatrix = matrix;
        }
    }

    // Destructor
    ~Graph() = default;

    // Copy Constructor
    Graph(Graph<TNode, TWeight> &other) {
        if (this != &other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
        }
    }

    // Move Constructor
    Graph(Graph &&other) noexcept {
        if (this != other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
            other.clear();
        }
    }

    // Copy Assignment Operator
    Graph &operator=(const Graph &other) {
        if (this != &other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
        }
        return *this;
    }

    // Move Assignment Operator
    Graph &operator=(Graph &&other) noexcept {
        if (this != &other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
            other.clear();
        }
        return *this;
    }
    // 2. Конструкторы и операторы присваивания класса Graph -- начало

    // 4. Итерирование по графу -- начало
    auto begin() {
        return graphNodes.begin();
    }

    auto end() {
        return graphNodes.end();
    }

    auto cbegin() const {
        return graphNodes.cbegin();
    }

    auto cend() const {
        return graphNodes.cend();
    }
    // 4. Итерирование по графу -- конец

    // 5. Работа с графом через ключ -- начало
    size_t degree_in(const Node<TNode> &node) {
        size_t count = 0;
        for (int i = 0; i < size(); ++i) {
            if (adjacencyMatrix(graphNodes[node], i) > 0) {
                count++;
            }
        }
        return count;
    }

    size_t degree_out(const Node<TNode> &node) {
        size_t count = 0;
        for (int i = 0; i < size(); ++i) {
            if (adjacencyMatrix(i, graphNodes[node]) > 0) {
                count++;
            }
        }
        return count;
    }

    bool loop(const Node<TNode> &node) {
        return adjacencyMatrix(graphNodes[node], graphNodes[node]) > 0;
    }
    // 5. Работа с графом через ключ -- конец

    // 6. Вставка узлов и рёбер в граф -- начало
//    pair<auto, bool> insert_node(const Node<TNode> &node) {
//
//    }
    // 6. Вставка узлов и рёбер в граф -- конец

    void clear_edges() {
        adjacencyMatrix = Matrix<TWeight>(Nodes(), Nodes(), 0);
    }

    bool erase_edges_go_from(const int &nodeIndex) {
        for (int i = 0; i < Nodes(); ++i) {

        }
    }

    //

};

template<typename TNode, typename TWeight>
void swap(Graph<TNode, TWeight> &graph1, Graph<TNode, TWeight> &graph2) {
    Graph<TNode, TWeight> tmp = graph1;
    graph1 = graph2;
    graph2 = tmp;
}
