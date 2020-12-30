#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s="chibihc";
    map<char,int> m;
    int count = 0;
    for(int i=0;i<s.size();i++)
        m[s[i]]++;
    for(auto i: m)
    {
        if(count>1)
        {
            cout<<"NOT possible\n";
            return 0;
        }
        if(i.second%2!=0 && count<2)
            count++;
    }
    cout<<"Possible\n";

}