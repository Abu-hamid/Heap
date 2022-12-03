#include <iostream>
using namespace std;


// time complexity is O(log n);

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

    void insertion(int val)
    {

        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            //  take a right position of the root element;

            int parent = index / 2;

            if (arr[parent] < arr[index])
            {

                swap(arr[parent], arr[index]);
                index = parent;
            }

            else
            {
                return;
            }
        }
    }


//  time complexity will be O(logn);

    void deleteFromHeap(){

        if(size == 0){
            return;
        }

        arr[1] = arr[size]; // root value give to the last node;
        size--;// remove last element;

        // take root node to the correct psition;

        int i =1;
        while(i < size){

            int leftIndex = 2*i;
            int rightIndex = 2*i + 1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){

                swap(arr[i] , arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i < arr[rightIndex]]){

                swap(arr[i] , arr[rightIndex]);
                i = rightIndex;
            }

            else{

                return;
            }



        }

    }


};

int main()
{

    heap h;
    h.insertion(55);
    h.insertion(10);
    h.insertion(20);
    h.insertion(50);
    h.insertion(52);

    return 0;
}