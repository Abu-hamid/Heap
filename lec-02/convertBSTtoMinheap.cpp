#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {

        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(node *root, vector<int> &arr)
{

    // base case
    if (root == NULL)
        return;

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void BSTtoMinHeap(node *root, vector<int> arr, int index)
{

    // base case;
    if (root == NULL)
        return;

    root->data = arr[index++];
    BSTtoMinHeap(root->left, arr, index);
    BSTtoMinHeap(root->right, arr, index);
}

void convertToMinHeap(node *root)
{

    vector<int> arr;
    int index = -1;

    inorder(root, arr);

    // BST to Min heap convertion;
    BSTtoMinHeap(root, arr, index);
}

// ans is presnt in the pre order format;

int main()
{

    return 0;
}