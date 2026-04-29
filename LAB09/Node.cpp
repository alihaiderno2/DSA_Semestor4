# include "Node.h"
Node::Node(){
    data = 0;
    next = nullptr;
}
Node::Node(int val)
{
    data = val;
    next = nullptr;
}
int Node::getData()
{
    return data;
}
Node* Node::getNext()
{
    return next;
}
void Node::setNext(Node* nextNode)
{
    next = nextNode;
}