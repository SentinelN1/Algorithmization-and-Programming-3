#pragma once

#include "Node.hpp"

template<typename TNode, typename TWeight>
class Edge {
private:
    Node<TNode> firstNode;
    Node<TNode> secondNode;
    TWeight edgeWeight;

public:
    Edge() = default;

    Edge(Node<TNode> first, Node<TNode> second, const TWeight &weight) {
        firstNode = first;
        secondNode = second;
        edgeWeight = weight;
    }

    ~Edge() = default;

    TNode FirstNodeData() const {
        return firstNode->NodeData();
    }

    TNode SecondNodeData() const {
        return secondNode->NodeData();
    }

    TWeight Weight() const {
        return edgeWeight;
    }
};