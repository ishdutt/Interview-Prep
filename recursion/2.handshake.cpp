#include<bits/stdc++.h>
using namespace std;

int hs(int ans,int n)
{
    if(n==1)
        return ans;
    else
    {
        //SEE how tp get the cumulative sum in Recursion
        ans=(n-1)+hs(ans,n-1);
    }
    return ans;
}

int main()
{
    int n=10;
    int ans=0;
    cout<<hs(ans,10);
}