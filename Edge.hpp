#pragma once

#include "Node.hpp"

template<typename TNode, typename TWeight>
class Edge {
private:
    const Node<TNode> *fromNode;
    const Node<TNode> *toNode;
    TWeight edgeWeight;

public:
    Edge() {
        fromNode = nullptr;
        toNode = nullptr;
        edgeWeight = 0;
    }

    Edge(const Node<TNode> &from, const Node<TNode> &to, const TWeight &weight) {
        fromNode = &from;
        toNode = &to;
        edgeWeight = weight;
    }

    ~Edge() = default;

    TWeight GetWeight() const {
        return edgeWeight;
    }

    void SetWeight(const TWeight &weight) {
        edgeWeight = weight;
    }

    const Node<TNode> *FromNode() const {
        return fromNode;
    }

    const Node<TNode> *ToNode() const {
        return toNode;
    }
};