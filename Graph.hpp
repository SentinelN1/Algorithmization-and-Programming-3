# pragma once

#include "Matrix.hpp"
#include "Edge.hpp"
#include <list>
#include <map>

using std::list, std::map;

template<typename TNode, typename TWeight>
class Graph {
private:
    list<Node<TNode>> graphNodes;
    map<Node<TNode>, list<Edge<TNode, TWeight>>, NodeCompare<TNode>> mapping;
    Matrix<TWeight> adjacencyMatrix;

public:
    // Constructor
    Graph() = default;

    // Constructor
    Graph(const list<Node<TNode>> &nodes, const Matrix<TWeight> &matrix) {
        if (matrix.square()) {
//            nodes = vector<TNode>(matrix.Rows());
            adjacencyMatrix = matrix;
        }
    }

    Matrix<TWeight> AdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    // Destructor
    ~Graph() {
    }

    // Copy Constructor
    Graph(const Graph &other) {

    }

    // Move Constructor
    Graph(Graph &&other) {

    }

    // Copy Assignment Operator
    Graph &operator=(const Graph &other) {
        if (this != &other) {

        }
        return *this;
    }

    // Move Assignment Operator
    Graph &operator=(Graph &&other) {
        if (this != &other) {

        }
        return *this;
    }


    int Nodes() const {
        mapping.size();
    }

    int Edges() const {
        return 0;
    }

    bool empty() const {
        return mapping.empty();
    }

    void clear() {
        for (auto i: mapping) {
            i.second.clear();
        }
        mapping.clear();
    }
};
