#include<bits/stdc++.h>
using namespace std;

//THIS FUNCTION RETURNS PROFIT MAXIMISED VALUE :)

//NOW MEMOIZATION
int ks(vector<int>val,vector<int>wt,int N,int W,vector<vector<int>>dp)
{
    //BASE CASE
    if(N==0||W==0)    return 0;

    //IF ALREADY COMPUTED THEN TAKE IT FROM THERE
    if(dp[N-1][W]!=-1)    return dp[N-1][W];

    //IF WEIGHT IS GREATER THEN WE DON"T CONSIDER THIS ITEM ADN STORE THAT IN TABLE AS WELL
    if(wt[N-1]>W) return dp[N][W]= ks(val,wt,N-1,W,dp);

    //IF WITHIN RANGE, WE HAVE 2 OPTIONS... INCLUDE IT OR EXCLUDE IT ... STORE THAT IN TABLE AS WELL
    else
        return dp[N][W] = max(val[N-1]+ks(val,wt,N-1,W-wt[N-1],dp) , ks(val,wt,N-1,W,dp));

    
}


int ksIterative(vector<int>val,vector<int>wt,int N,int W,int dp[4][51])
{
    for(int i=0;i<N+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)    dp[i][j]=0;

            //IF WEIGHT IS GREATER THEN WE IGNORE IT  :-)
            else if(wt[i-1]>j) dp[i][j] = dp[i-1][j];

            // ELSE WE HAVE OPTION TO WHETHER TAKE IT OR LEAVE IT...I DENOTES THE POINTER WHILE J DENOTES THE 
            // WEIGHT OF THE KNAPSACK IN THE SUBPROBLEM

            //HERE i-1 will give the ith value pointer and i-1 passsed is decrementing the i value moving to
            // a new subproblem :)
            else  dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);


        }
    }
    return dp[N][W];
}

//                                         ==CAUTION===
// BHAI COUNTER YAHA PE COUNTER VALUE START N-1 NAI PASS KARTE HAI... n PASS KARTE HAI PAGAL!!
// STANDARD YAHI HAI... ISILIYE N-1 SE ACESS KARTE HAI MAIN CODE ME... TU PASS HI N-1 KARTA HAI SAALE!!

int main()
{
    vector<int> val{60,100,120};
    vector<int> wt{10,20,30};

    int W = 50;
    //SINCE 2 VALUES ARE CHANGING AND IT DOES MATTER HOW WE REACHED AT THAT STATE HENCE 2 VARIABLES

    //DP TABLE WITH -1 AS DEFAULT ENTRY
    //cout<<val.size()<<endl;
    vector<vector<int>>dp(val.size()+1, vector<int> (W+1, -1));
    //int dp[4][51]={-1};

    cout<<ks(val,wt,3,W,dp)<<endl;
}