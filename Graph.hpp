#pragma once
#include "Matrix.hpp"
#include "Edge.hpp"

template <typename TNode, typename TWeight>
class Graph
{
private:
    list<Node<TNode>> graphNodes;
    list<Edge<TNode, TWeight>> graphEdges;

public:
    Graph() {}

    Graph(const Matrix<TWeight> &matrix)
    {
        
    }

    ~Graph()
    {
        graphNodes.clear();
        graphEdges.clear();
    }

    int Nodes()
    {
        return graphNodes.size();
    }

    int Edges()
    {
        return graphEdges.size();
    }

    bool empty()
    {
        return graphNodes.empty();
    }

    size_t size()
    {
        return graphNodes.size();
    }

    void clear()
    {
        graphNodes.clear();
        graphEdges.clear();
    }
};