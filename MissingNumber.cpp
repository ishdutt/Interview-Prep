#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    vector<int> a;
    for(int i=1;i<=n-1;i++)
    {
        long long int input;
        cin>>input;
        a.push_back(input);
    }
    //Print
    // for(int i=0;i<a.size();i++)
    //     cout<<a[i]<<" ";

    //Logic
    map<int,int> m;
    for(int i=0;i<a.size();i++)
        m[a[i]]++;
    
    for(int i=0;i<a.size();i++)
    {
        //cout<<m[a[i]]<<" ";
        if(m[a[i]]==0)
        {
            cout<<a[i]<<endl;
            break;
        }
    }
        
}   