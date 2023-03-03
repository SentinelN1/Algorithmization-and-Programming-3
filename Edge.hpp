#pragma once
#include "Node.hpp"
#include <list>

using std::list;

template <typename TNode, typename TWeight>
class Edge
{
private:
    Node<TNode> *firstNode;
    Node<TNode> *secondNode;
    TWeight edgeWeight;

public:
    Edge() {}
    Edge(Node<TNode> *first, Node<TNode> *second, const TWeight &weight)
    {
        firstNode = first;
        secondNode = second;
        edgeWeight = weight;
    }

    ~Edge() {}

    TNode FirstNodeData()
    {
        return firstNode->NodeData();
    }

    TNode SecondNodeData()
    {
        return secondNode->NodeData();
    }

    TWeight Weight()
    {
        return edgeWeight;
    }
};