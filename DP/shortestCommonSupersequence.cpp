#include<bits/stdc++.h>
using namespace std;
//MERGE TWO STRINGS INTO A SINGLE STRING SUCH THAT THEY WILL FORM A SINGLE STRING AND THAT STRING
// WILL HAVE THE FORMER SEQUENCES AS IT'S SUBSEQUENCE

//LCS VARIENT
//FORMULA: LEN(S1)+LEN(S2)-LCS(kyunki ye part dono me common hoga isiliye ek baar nikal denge)
int solve(string s,string t)
{
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));

    for(int i=0;i<s.size()+1;i++)
    {
        for(int j=0;j<t.size()+1;j++)
        {
            if(i==0||j==0)  dp[i][j]=0;

            else if(s[i-1]==t[i-1]) dp[i][j]=dp[i-1][j-1]+1;

            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            
        }
    }

    return s.size()+ t.size()-dp[s.size()][t.size()];
}

int main()
{
    string s="abs";

    string d="sfdmsf";
    cout<<solve(s,d)<<endl;
}