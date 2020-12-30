#include<bits/stdc++.h>
using namespace std;

void search(int n,int k,vector<int> sub)
{
    if(k==n+1)
    {
        //Print
        for(int i=0;i<sub.size();i++)
        cout<<sub[i]<<" ";
        cout<<"\n";
    }
    else
    {
        //include k in subset
        sub.push_back(k);
        search(n,k+1)
    }

}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    vector<int> sub;
    for(int k=0;k<n;k++)
        search(a[n-1],k,sub);
}