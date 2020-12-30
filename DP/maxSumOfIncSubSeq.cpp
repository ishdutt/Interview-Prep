#include<bits/stdc++.h>
using namespace std;

int maxsum(vector<int>&a,int n,int prev)
{
    cout<<"TEST "<<n<<" "<<a[n]<<"\n";
    if(n==a.size())     return 0;

    else if(a[n]<=prev)  maxsum(a,n+1,prev);

    else    max(maxsum(a,n+1,prev),a[n]+maxsum(a,n+1,a[n]));
}

int main()
{
    vector<int> a={10, 12, 32, 4, 4, 6, 7, 5, 6, 1, 2, 3};
    int prev = INT_MIN;
    cout<<maxsum(a,0,prev)<<endl;
}