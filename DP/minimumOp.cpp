#include<bits/stdc++.h>
using namespace std;

int noWays(int n)
{
    cout<<"TEST "<<n<<endl;
    if(n==0)    return 0;
    if(n==1)    return 1;

    if(n%2==0)  return min(1+noWays(n-1),1+noWays(n/2));
    
    
    else    return 1+noWays(n-1);
}


int main()
{
    int n=7;
    int count=0;
    cout<<noWays(n)<<endl;
}