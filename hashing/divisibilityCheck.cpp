#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {2, 3, 8, 6, 9, 10};
    sort(a.begin(),a.end());
    //get the max element
    //MAP IS to find whether the element is there in the array or not in const time 
    int maxelement = INT_MIN;
    map<int,int>mp;
    for(int i=0;i<a.size();i++)
    {
        mp[a[i]]++;
        maxelement = max(maxelement,a[i]);
    }
    cout<<"MAX ELEMENT"<<maxelement<<endl;
    set<int> s;
    //TRaversing the array element
    for(int i=0;i<a.size();i++)
    {
        //Getting the multiple of elements
        for(int j=2;j<maxelement/a[i]+1;j++)
        {
            cout<<"ELEMENT OBTAINED ARE "<<j*a[i]<<endl;
            //If their multiple is present or not
            if(mp[j*a[i]]!=0)
                s.insert(j*a[i]);
        }
    }

    for(auto it : s)
        cout<<it<<" ";
    cout<<endl;
}