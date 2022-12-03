#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    int left;
    int right;int next;

    node(int data)
    {

        this->data = data;
        left = NULL;
        right = NULL;
        next  = NULL;

    }
};

class compare
{

public:
    bool operator()(node *a, node *b) //(node<int> *a, node<int> *b)
    {

        return a->data > b->data;
    }
};

node *mergeklist(vector<node >&listArr) //vector<node<int> *> &listArr
{

    // priority_queue<node<int> *, vector<node<int> *>, compare> minheap;
    priority_queue<node, vector<node, compare>> minheap;
    int k = listArr.size();

    // step 1;

    if (k == 0)
        return NULL;
    for (int i = 0; i < k; i++)
    {

        if (listArr[i] != NULL)
        {
            minheap.push(listArr[i]);
        }
    }

    node*head = NULL;
    node*tail  =NULL;
    while(minheap.size() > 0){

        node*top  = minheap.top();  //node<int>*top = minheap.top();
        minheap.pop();

        if(top->next != NULL){

            minheap.push(top->next);
        }

        if(head == NULL){

            // answer ll is empty;
            head = top;
            tail = top;

            
        }

        else{

            // insert at tail;

            tail->next = top;
            tail = top;
        }

    }

    return head;
}

int main()
{

    return 0;
}