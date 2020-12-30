#include<bits/stdc++.h>
using namespace std;


void pal(string s,int l,int h)
{
    if(l>=h)
    {
        cout<<"Ye hai\n";
        return;
    }
    if(s[l]!=s[h])
    {
        cout<<"Nai hai\n";
        return;
    }
    else
        pal(s,l+1,h-1);
}

int main()
{
    string s="a";
    pal(s,0,s.size()-1);
}