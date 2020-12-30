#include<bits/stdc++.h>
using namespace std;

//USING HEAP.. TWO APPRAOCH WHILE IMPLEMENTING-> USING PRIORITY QUEUE OR CONVERTING ARRAY TO HEAP
int main()
{
    vector<int> a={2,3,4,7,1,5,90};
    int k=3;

    priority_queue<int> q(a.begin(),a.end());
    while(--k)
        q.pop();
    
    cout<<q.top()<<endl;

    //CONVERTING TO HEAP : 2nd TYPE FOR IMPLEMENTATION
    make_heap(a.begin(),a.end());


    while(k--)
    {
        //remove element from heap
        pop_heap(a.begin(),a.end());
        a.pop_back();
    }
    cout<<a.front();
}