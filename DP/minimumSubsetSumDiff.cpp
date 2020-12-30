#include<bits/stdc++.h>
using namespace std;

//                                  CONCEPT WISE IMPORTANT :)
//PROBLEM: CALCULATE MIN SUM DIFFERENCE BETWEEN 2 PARTITIONS 
//  HERE WE ARE DEPENDENT ON THE POSSIBLE SUM OF THE SUBSET AND CACULATE THE POSSIBLE DIFFERENCE BETWEEN
//  THEM... HENCE PRINTING THE MIN DIFFERNCE. :p

int check(vector<int>&a,int sum,vector<vector<int>>&dp)
{
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)    dp[i][j]=1;

            else if(i==0)   dp[i][j]=0;

            else
            {
                if(a[i-1]>j)   dp[i][j]= dp[i-1][j];

                else    dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
            
        }
    }
    // NOW WE CHECK ALL POSSIBLE SUM.. AND CHECK THE DIFF FOR THE CORRESPONDING SUM VALUE
    int ans=INT_MAX;
    for(int i=0;i<(sum/2)+1;i++)
    {
        if(dp[a.size()][i]==1)
        {   
            //IF ABOVE CONDITION IS TRUE THEN THAT SUM IS POSSIBLE..i.e i IS POOSIBLE
            ans=min(ans,abs(sum-2*i));
        }
    }
    return ans;
}

int main()
{
    vector<int> a={1,4,9,16};
    
    int sum=0;
    for(int i=0;i<a.size();i++)     sum+=a[i];

    vector<vector<int>>dp(a.size()+1, vector<int> (sum+1, -1));
    //HERE WE ARE PASSING SUM+1 AS UPPERBOUND SO THAT WE GET ALL POSSIBLE INTERMEDIATE VALUES
    cout<<check(a,sum,dp)<<endl;
}