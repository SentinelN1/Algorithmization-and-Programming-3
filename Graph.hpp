#pragma once

#include "Matrix.hpp"
#include "Edge.hpp"
#include <vector>
#include <list>

using std::vector;
using std::list;

template<typename TNode, typename TWeight>
class Graph {
private:
    vector<Node<TNode>> graphNodes;
    list<Edge<TNode, TWeight>> graphEdges;

public:
    Graph() = default;

    Graph(const Matrix<TWeight> &matrix) {
        if (matrix.square()) {
            graphNodes.assign(matrix.Rows(), Node<TNode>());

            for (int i = 0; i < matrix.Columns(); ++i) {
                for (int j = 0; j < matrix.Rows(); ++j) {
                    TWeight weight = matrix[i * matrix.Columns() + j];
                    if (weight > 0) {
                        graphEdges.push_back(Edge<TNode, TWeight>(graphNodes[i], graphNodes[j], weight));
                    }
                }
            }
        }
    }

    ~Graph() {
        graphNodes.clear();
        graphEdges.clear();
    }

    int Nodes() const {
        return graphNodes.size();
    }

    vector<Node<TNode>> NodesData() const {
        return graphNodes;
    }

    int Edges() const {
        return graphEdges.size();
    }

    list<Edge<TNode, TWeight>> EdgesWeights() const {
        return graphEdges;
    }

    bool empty() const {
        return graphNodes.empty();
    }

    size_t size() const {
        return graphNodes.size();
    }

    void clear() {
        graphNodes.clear();
        graphEdges.clear();
    }
};
