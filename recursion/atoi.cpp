#include<bits/stdc++.h>
using namespace std;

void atoi(string s,int ans,int n)
{
    //Extra 10 is mupltiplied even tough number is acheived
    if(n==s.length())
    {
        cout<<ans/10<<endl;
        //return ans;
    }
        
    else
    {
        //cout<<ans<<endl;
        atoi(s,(ans+(s[n]-'0'))*10,n+1);
    }
    
}

int main()
{
    string s="112";
    int ans=0;
    atoi(s,ans,0);
    
}