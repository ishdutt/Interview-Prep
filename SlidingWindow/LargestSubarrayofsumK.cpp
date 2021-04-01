#include<bits/stdc++.h>
using namespace std;

int main()
{
    //vector<int>a={1,4,5,3,-1,-100,800,1,1,1,1,1,1,1,1,1,1};
    vector<int>a={10, 5, 2, 7, 1, 9}; 
    int k=15;
    int i=0,j=0;
    int cursum=0;
    int curlen=0,maxlen=0;

    while(j<a.size())
    {
        //  ADDING THE ELEMENT
        if(cursum<k) cursum+=a[j++];
        //REMOVINF THE ELEMENT
        if(cursum>k)    cursum-=a[i++];

        //CONDITION SATISFIED
        if(cursum==k)
        {           
            curlen=max(curlen,j-i);
            cursum+=a[j++];
        }
        
    }
    cout<<"TEST="<<curlen<<endl;
}