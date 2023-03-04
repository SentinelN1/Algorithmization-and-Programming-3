#pragma once

template<typename TNode>
class Node {
private:
    TNode nodeData;

public:
    Node() = default;

    Node(const TNode &data) {
        nodeData = data;
    }

    ~Node() = default;

    TNode NodeData() const {
        return nodeData;
    }
};