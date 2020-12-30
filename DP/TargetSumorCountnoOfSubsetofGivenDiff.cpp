#include<bits/stdc++.h>
using namespace std;

//THIS PROBLEM IS BASICALLY SAME AS COUNTING THE NO. OF SUBSET WITH A GIVEN SUM..HERE SUM VALUE CHANGES
// THESE ARE 2 DIFFERENT QUESTIONS WITH EXACTLY SAME CODE AND IDEA

int countValue(vector<int>a,int sum,vector<vector<int>>dp)
{
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)    dp[i][j]=1;
            else if(i==0)   dp[i][j]=0;

            else
            {
                if(a[i-1]>j)    dp[i][j]=dp[i-1][j];

                else    dp[i][j]=dp[i-1][j]+dp[i-1][j-a[i-1]];
            }
            
        }
    }
    return dp[a.size()][sum];
}

int main()
{
    vector<int>a={1, 1, 1, 1, 1};
    int  dif = 3;
    int sum=0;
    for(int i=0;i<a.size();i++)     sum+=a[i];

    vector<vector<int>>dp(a.size()+1,vector<int>(((sum-dif)/2)+1,-1));
    cout<<countValue(a,(sum-dif)/2,dp)<<endl;
}