#include <iostream>
using namespace std;

class heap
{

public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
};

// it follow the 1 base indexing for the iteration;

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

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
int main()
{

    heap h;

    int arr[6] = {-1 , 53 ,54 ,55 ,50 ,51};
    int n = 5;

// creating heap;
    for(int i = n/2;i>0;i--){

        heapify(arr , n , i);
    }


    // for printing the value of the heapify;

    for(int i=1;i<=n;i++){

        cout<< arr[i]<<" ";
    }

    cout<<endl;
   


    return 0;
}