#include<bits/stdc++.h>
using namespace std;

//HERE NO OPTION EXECPT USING STRING
map<string,bool>dp;

int solve(string s,string t)
{
    if(s.size()!=t.size())  return false;
    if(s==t)    return true;

    string temp=s;
    temp.push_back(' ');
    temp+=t;
    cout<<s<<" "<<t<<" "<<temp<<endl;
    if(dp.find(temp)!=dp.end()) return dp[temp];

    int n=s.size();
    for(int i=1;i<n;i++)
    {
        //MATCHING THE 1ST AND SECOND PART AS IT IS(NO SWAPPING) AND THEY ARE EQUAL
        if(solve(s.substr(0,i),t.substr(0,i)) && solve(s.substr(i,n-i),t.substr(i,n-i)))    return dp[temp]= true;
         //MATCHING THE 1ST AND SECOND PART AS IT IS(SWAPPING) AND THEY ARE EQUAL
        else if(solve(s.substr(0,i),t.substr(n-i,i)) && solve(s.substr(i,n-i),t.substr(0,n-i)))   return dp[temp]= true;
    }
    return dp[temp]=false;
}

int main()
{
    string s="coder";
    string t="ocred" ;
    //memset(dp,-1,sizeof(dp));
    cout<<solve(s,t)<<endl;
}