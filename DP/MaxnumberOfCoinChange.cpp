#include<bits/stdc++.h>
using namespace std;

//COUNT SUBSET WITH GIVEN SUM PROBLEM WITH UNBOUNDED VERSION OF KS


int noOfWays(vector<int>coins,int n)
{
    vector<vector<int>>dp(coins.size()+1,vector<int>(n+1,-1));
    for(int i=0;i<coins.size()+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            //cout<<i<<" "<<j<<endl;
            if(j==0)    dp[i][j]=1;

            else if(i==0) dp[i][j]=0;

            else if(coins[i-1]>j)   dp[i][j]=dp[i-1][j];

            //IF INCLUDE.. WE CAN INCLUDE IT MANY TIMES.. IF LEAVE.. THEN I-1
            else    dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
        }
    }
    return dp[coins.size()][n];
}

int main()
{
    int n=5;
    vector<int>coins={1,2,3};
    cout<<noOfWays(coins,n)<<endl;
}