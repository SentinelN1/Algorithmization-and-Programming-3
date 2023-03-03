#pragma once

template <typename TNode>
class Node
{
private:
    TNode nodeData;

public:
    Node(const TNode &nodeData_)
    {
        nodeData = nodeData_;
    }

    ~Node() {}

    TNode NodeData()
    {
        return nodeData;
    }
};