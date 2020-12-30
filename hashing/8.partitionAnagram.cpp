#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s={"eat","tea","tan","ate","nat","bat"};

    //HERE customised nested ds
    //map of vectors of string
    map<string,vector<string>> m;
    //traverse and add the sorted atring as key and other string of vectors as value
    for(int i=0;i<s.size();i++)
    {
        string temp = s[i];
        sort(s[i].begin(),s[i].end());
        m[s[i]].push_back(temp);
    }
    //print the string
    for(auto i : m)
    {
        //print the vector
        //cout<<i.first<<endl;
        for(auto j : i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
}