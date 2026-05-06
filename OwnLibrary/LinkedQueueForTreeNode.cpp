# include "LinkedQueueForTreeNode.h"
LinkedQueueForTreeNode::LinkedQueueForTreeNode()
{
    front = nullptr;
    back = nullptr;
}
bool LinkedQueueForTreeNode::enqueue(TreeNode* tn)
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
bool LinkedQueueForTreeNode::dequeue(TreeNode*& tn)
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
bool LinkedQueueForTreeNode::isEmpty()
{
    if (front == nullptr)
    {
        return true;
    }
    return false;
}