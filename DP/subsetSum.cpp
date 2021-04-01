#include<bits/stdc++.h>
using namespace std;

//THIS PROBLEM IS A LITTLE DIFFERENT FROM NOTMAL ONE .. HERE WE HAVE TO PRINT IF POSSIBLE THEN YES
//  ELSE NO.... YES/NO TYPE PROBLEM :)

//  PROBLEM: GIVEN A SUM.. CHECK WHETHER THERE EXISTS A SUBSET WITH GIVEN SUM ...YES/NO
//  BOOLEAN VALUE WILL BE STORED IN DP TABLE IN THIS CASE
//VARIENT OF KNAPSACK PROBLEM...HERE ITMES = ARAY ELEMENTS, SUM = K LIMIT. OOPTIONS WE CQN TAKE IT OR LEAVE IT


int check(vector<int>&a, int sum, vector<vector<int>>dp)
{
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //BASE CASE... WHAT HAPPENS WHEN 0?---> IF SUM IS ZERO..POSSIBLE..IF A IS 0 IMPOSSIBLE
            if(j==0)    dp[i][j]=1;

            else if(i==0)   dp[i][j]=0;
            
            else
            {
                 // SAME CASE... WHEN NUMBER IS GREATER THAN SUM..WE IGNORE IT :)
                if(a[i-1]>j)    dp[i][j]=dp[i-1][j];

                //HERE BOOLEAN VALUE SO.. WE TAKE OR INSTEAD OF MAX... IE. IF EITHER ONE IS TRUE WE TAKE THAT
                else    dp[i][j]=dp[i-1][j] || dp[i-1][j-a[i-1]];
            }
        }
    }

    return dp[a.size()][sum];
}

int main()
{
    vector<int> a={1,6,5,11,3,2,8};
    int sum=14;

    vector<vector<int>>dp(a.size()+1, vector<int> (sum+1, -1));

    cout<<check(a,sum,dp)<<endl;
}