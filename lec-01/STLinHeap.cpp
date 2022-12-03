#include<iostream>
#include<queue>
using namespace std;
int main(){


// max heap;

priority_queue<int>pq;

pq.push(2);

cout<<pq.top();
cout<<pq.size();


// min Heap;
priority_queue<int ,vector<int>,greater<int>>minheap;

minheap.push(2);

cout<<minheap.top();
cout<<minheap.size();

if(minheap.empty()){

    cout<<"queue is empty"<<endl;
}

else{

    cout<<"queue is not empty"<<endl;
}
return 0;
}