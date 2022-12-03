#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    int i; // row
    int j; // colomn;

    node(int data, int row, int col)
    {
        this->data = data;
        i = row;
        j = col;
    }
};
class compare
{

public:
    bool operator()(node *a, node *b)
    {

        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arr, int k)
{

    priority_queue<node *, vector<node *>, compare> minheap;

    // step 1 put the arrays first elelemnt  into the minheap;

    for (int i = 0; i < arr.size(); i++)
    {

        node *temp = new node(arr[i][0], i, 0);
        minheap.push(temp);
    }

    // step 2

    vector<int> ans;
    while(minheap.size() > 1){

        node*temp = minheap.top();

        ans.push_back(temp->data);
        minheap.pop();

        int i = temp->i;
        int j = temp->j;

        if(j+1 < arr[i].size()){// check the next index  in the range of the array length;

            node*next = new node(arr[i][j+1] , i , j+1);
            minheap.push(next);
        }

    }

    return ans;
}

int main()
{

    return 0;
}