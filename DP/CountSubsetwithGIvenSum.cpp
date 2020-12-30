#include<bits/stdc++.h>
using namespace std;

// THIS IS A COUNTING PROBELM 
// COUNT NO. OF SUBSET WITH THE SUM AS THAT NUMBER... FUNCTION SHOULD RETURN THE NUMBER
// VARIATION OF KNSPSACK: WE HAVE TO CALCULATE THE SUM.. WHICH IS KNAPSACK... HERE WE HAVE TO GIVE THE 
// NUMBER...(important to see the approach) IT;S A COUNTING PROBLEM

int countSubset(vector<int>&a, int sum ,vector<vector<int>>&dp)
{
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //BASE CASES
            if(j==0)
                dp[i][j]=1;
        
            else if(i==0)
                dp[i][j]=0;
  
            else
            {
                //IF ELEMENT IS GREATER THAN THE SUM WE IGNORE IT :p
                if(a[i-1]>j)    dp[i][j]=dp[i-1][j];

                //IF IT'S SIZE IF LESS THEN WE HAVE TWO PATHS.. TAKE IT OR LEAVE IT.. WE HAVE TO CONSIDER
                // BOTH OPTIONS...JUST LIKE nCr
                else    dp[i][j] = dp[i-1][j] + dp[i-1][j-a[i-1]];
            }
        }
    }

        
    return dp[a.size()][sum];
}

int main()
{
    vector<int> a={1,6,5,11,3,2,8};
    int sum=10;

    vector<vector<int>>dp(a.size()+1, vector<int> (sum+1, -1));

    cout<<countSubset(a,sum,dp)<<endl;
}