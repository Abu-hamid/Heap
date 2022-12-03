#include <iostream>
#include <vector>
using namespace std;

// it follow the 1 base indexing for the iteration;

void heapify(vector<int> &arr, int n, int i)
{

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[largest] < arr[left])
    {

        largest = left;
    }

    if (right < n && arr[largest] < arr[right])
    {

        largest = right;
    }

    if (largest != 1)
    {

        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

vector<int> mergeHeaps(vector<int> & a, vector<int> & b, int n, int m)
    {

        // step 1 merge the bothe array into one array;

        vector<int> ans;        
        for (auto i : a)
            ans.push_back(i);
        for (auto i : b)
            ans.push_back(i);

        // step 2 build heap using heapify;
        int size = ans.size();
        for (int i = size / 2 - 1; i >=0; i--)
        {
            heapify(ans, size, i);
        }
    }

    int main()
    {

        return 0;
    }