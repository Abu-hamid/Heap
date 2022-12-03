#include <iostream>
#include <queue>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{

    priority_queue<int> pq;

    // step 1;
    for (int i = 0; i < k; i++)
    {

        pq.push(arr[i]);
    }

    // step 2;

    for (int i = k; i <= r; i++)
    { // les than r becz in the ques. given index value ;

        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    // step 3 ans = pq.top();

    int ans = pq.top();
    return ans;
}
int main()
{

    return 0;
}