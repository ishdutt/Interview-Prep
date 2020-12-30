#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a={2, 4, 3};
    vector<int> b = {5, 6, 1};
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    vector<int> ans;
    int i=0;
    int j=0;
    while(ans.size()<a.size())
    {
        if(a[i]>b[j])
            ans.push_back(a[i]),i++;
        else if(a[i]<=b[j])
            ans.push_back(b[j]),j++;
    }

    //ans
    for(int k=0;k<ans.size();k++)
        cout<<ans[k]<<" ";
    cout<<"\n";
}