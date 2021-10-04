//Vivek Arora

#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class binaryTreeNode
{
public:
    T data;
    binaryTreeNode *left;
    binaryTreeNode *right;

    binaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~binaryTreeNode()
    {
        delete left;
        delete right;
    }
};

binaryTreeNode<int> *takeInputLevelWise()
{

    int rootData;
    cout << "Enter root data" << endl;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }

    binaryTreeNode<int> *root = new binaryTreeNode<int>(rootData);

    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        binaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            binaryTreeNode<int> *child = new binaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}


void printLevelWise(binaryTreeNode<int> *root)
{

    if (root == NULL)
    {
        return;
    }

    queue<binaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {

        binaryTreeNode<int> *front = pendingNodes.front();

        cout << front->data << " ";
        pendingNodes.pop();

        if (front->left != NULL)
        {
            pendingNodes.push(front->left);
        }

        if (front->right != NULL)
        {
            pendingNodes.push(front->right);
        }
    }
}




int main()
{
    binaryTreeNode<int> *root = takeInputLevelWise();
  
    cout << "\nLevel Wise Tree Traversal:  "<< "\n";
    printLevelWise(root);
    delete root;
    return 0;
}
