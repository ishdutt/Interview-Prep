#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n,k;
    cin>>m>>n>>k;
    vector<vector<int>>a(m,vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    }
        //cout<<"MO11"<<endl;
    map<int,int>mp;
    for(int i=0;i<m;i++)
    {
        set<int>temp(a[i].begin(),a[i].end());
        //cout<<"MOShi"<<endl;
        for(auto it: temp)
        {
            mp[it]++;
            //cout<<"GAYA BC AAJ";
        }
            
    }
    //cout<<"MO"<<endl;
    for(auto it : mp)
    {
        if(it.second>=k)
            cout<<it.first<<" "; 
    }
    cout<<endl;
}