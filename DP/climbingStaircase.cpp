
#include<bits/stdc++.h>
using namespace std;

//THIS QUESTION IS SAME AS FIBONACCI SERIES
//THIS IS RECURSIVE APPROACH... IT WILL GIVE TLE FOR LARGE INPUTS :) SO NOW DO MEMOIZATION

// MEMOIZED SOLUTION :)
int countWays(vector<int>&dp,int n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return 1;
    
    //N STEPS SO CAN USE EITHER 1 STEP.. N-1 LEFT OR 2 STEPS .. N-2 LEFT
    if(dp[n]>0)
        return dp[n];
    dp[n]= countWays(dp,n-1)+countWays(dp,n-2);
    return dp[n];
}

int main()
{
    int n=3;
    vector<int>dp(n+1,0);
    cout<<countWays(dp,n)<<endl;
}