#include<bits/stdc++.h>
using namespace std;

//FIXME:
bool solve(string s,set<string> dic,int n,string currentstring, vector<int>&dp)
{
    
    bool ifpresent=dic.find(currentstring)!=dic.end();

    //cout<<n<<" "<<s[n]<<" currentstring="<<currentstring<<" "<<ifpresent<<endl;;

    if(n==s.size()&& !ifpresent)  return dp[n]=0;

    else if(n==s.size()&&ifpresent)  return dp[n]=1;

    
    if(dic.find(currentstring)==dic.end())
    {
        currentstring.push_back(s[n]);
        return dp[n]=solve(s,dic,n+1,currentstring,dp);
    }
    //IF CURRENTSTRING IS AVAILABLE IN DICTIONARY
    else
    {
        currentstring.push_back(s[n]);
        //WHEN STRING IS MADE ZERO.. THEN WE DON'T HAVE TO INCREMENT THE POINTER 
        return dp[n]=solve(s,dic,n,"",dp) || solve(s,dic,n+1,currentstring,dp);
    }
    
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;

        vector<string> a={"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
        set<string>dic(a.begin(),a.end());


        vector<int>dp(s.size()+1,-1);
        cout<<solve(s,dic,0,"",dp)<<endl;
    }
}