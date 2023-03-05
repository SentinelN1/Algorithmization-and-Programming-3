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

    TNode GetData() const {
        return nodeData;
    }

    void SetData(const TNode &data) {
        nodeData = data;
    }
};

template<typename TNode>
struct NodeCompare {
    bool operator()(const Node<TNode> &lhs, const Node<TNode> &rhs) const {
        return &lhs < &rhs;
    }
};