#include<bits/stdc++.h>
using namespace std;

int sum(int m,int n)
{
    if(n==0)
        return 1;
    else
    {
        return m*sum(m,n-1);
    }
    
}

int main()
{
    int n=10;
    int m=2;
    cout<<sum(m,n)<<"\n";
}