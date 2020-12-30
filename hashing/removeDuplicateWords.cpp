#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Geeks for Geeks A Computer Science portal for Geeks";
    //SPlit the space
    string temp="";
    unordered_set<string> ans;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]==' ')
        {
            ans.insert(temp);
            temp="";
        }
        else
            temp+=s[i];
    }
    for(auto i : ans)
    cout<<i<<" ";
    cout<<"\n";
}