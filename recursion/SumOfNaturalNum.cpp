#include<bits/stdc++.h>
using namespace std;

int sum(int i,int n)
{
    if(i==n+1)
        return 0;
    else
    {
        return i+sum(i+1,n);
    }
    
}

int main()
{
    int n=10;
    cout<<sum(0,n)<<"\n";
}