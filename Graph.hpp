#pragma once

#include "Matrix.hpp"
#include "Edge.hpp"
#include <vector>

using std::vector;

template<typename TNode, typename TWeight>
class Graph {
private:
//    vector<TNode> nodes;
    Matrix<TWeight> adjacencyMatrix;

public:
    Graph() = default;

    Graph(const Matrix<TWeight> &matrix) {
        if (matrix.square()) {
//            nodes = vector<TNode>(matrix.Rows());
            adjacencyMatrix = matrix;
        }
    }

    Matrix<TWeight> AdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    ~Graph() {
    }

    int Nodes() const {
    }


    int Edges() const {
    }

    bool empty() const {
    }

    void clear() {
    }

//    void AddNode(const Node<TNode> &node) {
//    }
};
