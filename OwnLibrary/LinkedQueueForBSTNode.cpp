# include "LinkedQueueForBSTNode.h"
LinkedQueueForBSTNode::LinkedQueueForBSTNode()
{
    front = nullptr;
    back = nullptr;
}
bool LinkedQueueForBSTNode::enqueue(BSTNode* tn)
{
    LinkedQueueNode* newNode = new LinkedQueueNode();
    newNode->data = tn;
    if (isEmpty())
    {
        front = newNode;
        back = newNode;
    }
    else
    {
        back->next = newNode;
        back = newNode;
    }
    return true;
}
bool LinkedQueueForBSTNode::dequeue(BSTNode*& tn)
{
    if (isEmpty())
    {
        return false;
    }
    LinkedQueueNode* temp = front;
    tn = temp->data;
    front = front->next;
    delete temp;
    if (front == nullptr)
    {
        back = nullptr;
    }
    return true;
}
bool LinkedQueueForBSTNode::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}