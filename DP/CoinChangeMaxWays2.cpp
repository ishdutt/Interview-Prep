#include<bits/stdc++.h>
using namespace std;

//INFINITE SUPPLY OF COIN.. GET THE DENOIMINATION OF M (UNBOUNDED KNAPSACK)
//MINIMUM NUMBER OF WAYS TO ACHIVE THE DESIRED SUM :)

//UNBOUNDED VERSION OF COUNT NUMBER OF SUBSET WITH GIVEN SUM

int coinways(vector<int>coins,int k,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    //FOR ITERATING OVER COINS:)
    for(int i=0;i<n+1;i++)
    {
        //FOR DESIRED SUM VALUE :)
        for(int j=0;j<k+1;j++)
        {
            if(j==0)    dp[i][j]=1;

            else if(i==0)     dp[i][j]=0;

            else if(coins[i-1]>j)   dp[i][j]=dp[i-1][j];

            else    dp[i][j]= dp[i-1][j] + dp[i][j-coins[i-1]];
        }
    }
    return dp[n][k];
}

int main()
{
    vector<int>a= {1,2,3};
    int k=4;
    
    vector<int> coins;
    cout<<coinways(a,k,a.size())<<endl;
}