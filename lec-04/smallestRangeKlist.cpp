#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class node
{

public:
    int data;
    int row;
    int col;

    node(int data, int row, int col)
    {

        this->data = data;
        this->row = row;
        this->col = col;
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

int kthSmallestrange(vector<vector<int>> &a, int k, int n)
{

    int mini = INT_MAX, maxi = INT_MIN;

    priority_queue<node *, vector<node *, compare>> minheap;

    // step 1 create minheap for starting elelment of the list and tracking min/maxi value;
    for (int i = 0; i < n; i++)
    {

        int element = a[i][0];
        mini = min(mini, element);
        maxi = max(maxi, element);
        minheap.push(new node(element, i, 0));
    }

    int start = mini;
    int end = maxi;

    // process the range
    while (!minheap.empty())
    {
        // min fetch
        node *temp = minheap.top();
        minheap.pop();

        mini = temp->data;

        // range or answer update;
        if (maxi - mini < end - start)
        {

            start = mini;
            end = maxi;
        }

        // check next elemenet exist or not;
        if (temp->col + 1 < n)
        {

            maxi = max(maxi, a[temp->row][temp->col + 1]);
            minheap.push(new node(a[temp->row][temp->col + 1], temp->row, temp->col + 1));
        }

        else
        {
            break;
        }
    }

    return (end - start + 1);
}

int main()
{

    return 0;
}