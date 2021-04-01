#include<bits/stdc++.h>
using namespace std;


//IDEA IS TO USE 2 HEAPS ONE MIN HEAP FOR STORING BIGGER ELEMENTS AND ONE MAX HEAP FOR STORING THE 
// SMALLER ELEMENTS .. WHEN HEAPS SIZE ARE EVEN.. THEN TAKE ELEMENT FROM BOTH HEAPS AND DO THE 
// MEAN ELSE TAKE IT FROM THE MAX HEAP (IT'S LARGEST ELEMENT)
int main()
{
    int n;
    cin>>n;
    vector<int>a(n,0);

    priority_queue<int>maxheap;
    priority_queue<int,vector<int>,greater<int>>minheap;
    while (n--)
    {
        int temp;
        cin>>temp;
        a.push_back(temp);
        

        //maxheap.push(temp);
        if(maxheap.empty()|| maxheap.top()>temp)
            maxheap.push(temp);
        
        else
            minheap.push(temp);
        

        int maxheapsize=maxheap.size();
        int minheapsize=minheap.size();

        if(maxheapsize-minheapsize>1)
        {
            cout<<"MOSHI2\n";
            int transfer=maxheap.top();
            maxheap.pop();
            minheap.push(transfer);
        }
        
        else if(minheapsize-maxheapsize>1)
        {
            int transfer=minheap.top();
            minheap.pop();
            maxheap.push(transfer);
        }
        
        //TESTING
        // priority_queue<int>temp1=maxheap;

        // cout<<"MAX HEAP=";
        // while (!temp1.empty())
        // {
        //     cout<<temp1.top()<<" ";
        //     temp1.pop();
        // }
        // cout<<"\n";

        // priority_queue<int,vector<int>,greater<int>>temp2=minheap;

        // cout<<"MIN HEAP=";
        // while (!temp2.empty())
        // {
        //     cout<<temp2.top()<<" ";
        //     temp2.pop();
        // }
        // cout<<"\n";



        if((maxheap.size()+minheap.size())%2==0)
            cout<<"Median="<<double(maxheap.top()+minheap.top())/2<<endl;
        else
        {
            if(maxheapsize>minheapsize)
                cout<<"MEdian="<<maxheap.top()<<endl;
            else
            {
                cout<<"MEdian="<<minheap.top()<<endl;
            }
            
        }
        
    }
    
}