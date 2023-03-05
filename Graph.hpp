# pragma once

#include "Matrix.hpp"
#include "Edge.hpp"
#include <vector>

using std::vector;

template<typename TNode, typename TWeight>
class Graph {
private:
    vector<Node<TNode>> graphNodes;
    Matrix<TWeight> adjacencyMatrix;

public:
    size_t Nodes() const {
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

    Matrix<TWeight> AdjacencyMatrix() const {
        return adjacencyMatrix;
    }

    bool empty() const {
        return graphNodes.empty();
    }

    void clear() {
        graphNodes.clear();
        adjacencyMatrix.clear();
    }

    void swap(Graph &other) {
        Graph *tmp = this;
        this = &other;
        &other = tmp;
    }

    // Default Constructor
    Graph() = default;

    // Constructor
    Graph(const vector<Node<TNode>> &nodes, const Matrix<TWeight> &matrix) {
        if (matrix.square()) {
            graphNodes = nodes;
            adjacencyMatrix = matrix;
        }
    }

    // Destructor
    ~Graph() = default;

    // Copy Constructor
    Graph(const Graph &other) {
        if (this != other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
        }
    }

    // Move Constructor
    Graph(Graph &&other) {
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
    Graph &operator=(Graph &&other) {
        if (this != &other) {
            graphNodes = other.graphNodes;
            adjacencyMatrix = other.adjacencyMatrix;
            other.clear();
        }
        return *this;
    }

    size_t degree_in(const int &nodeIndex) {
        size_t count = 0;
        for (int i = 0; i < Nodes(); ++i) {
            if (adjacencyMatrix(nodeIndex, i) > 0) {
                count++;
            }
        }
        return count;
    }

    size_t degree_out(const int &nodeIndex) {
        size_t count = 0;
        for (int i = 0; i < Nodes(); ++i) {
            if (adjacencyMatrix(i, nodeIndex) > 0) {
                count++;
            }
        }
        return count;
    }

    bool loop(const int &nodeIndex) {
        return adjacencyMatrix(nodeIndex, nodeIndex) > 0;
    }

    void clear_edges() {
        adjacencyMatrix = Matrix<TWeight>(Nodes(), Nodes(), 0);
    }

    bool erase_edges_go_from(const int &nodeIndex) {
        for (int i = 0; i < Nodes(); ++i) {

        }
    }
};
