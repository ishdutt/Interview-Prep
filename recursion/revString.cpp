#include<bits/stdc++.h>
using namespace std;


void rev(string s,int l,int h)
{
    if(l>=h)
    {
        cout<<"Ye hai "<<s<<endl;
        return;
    }
    swap(s[l],s[h]);
    rev(s,l+1,h-1);
}

int main()
{
    string s="abnc";
    rev(s,0,s.size()-1);
}