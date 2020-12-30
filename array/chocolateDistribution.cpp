#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    int m = 5;    
    vector<int>a = { 3, 4, 1, 9, 56, 7, 9, 12};
    
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    
    int mina = INT_MAX;
    for(int i=0;i<n-m+1;i++)
    {
        //cout<<a[i]
        cout<<"TEST "<<a[i+m-1]<<" "<<a[i]<<endl;
        mina = min(mina,a[i+m-1]-a[i]);
    }
        

    cout<<mina<<endl;
}