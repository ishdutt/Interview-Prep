#include<bits/stdc++.h>
using namespace std;

//UNLIKE IT'S INEFFICIENT BACKTRACKING APPROACH, HERE WE JUST HAVE TO PRINT IF SUCH CASE EXISTS.
// OUTPUT IS YES / NO
// SAME AS SUBSET SUM PROBLEM , HERE SUM =TOTAL_SUM/2
// KNAPSACK APPRAOCH : WE HAVE TO PUT ALL THOE STUFF INSIDE THE SET (BAG), SUCH THAT K(SUM) IS NOT 
// EXCEEDED

int check(vector<int>&a, int sum ,vector<vector<int>>&dp)
{
    for(int i=0;i<a.size()+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            //BASE CASE
            if(j==0)    dp[i][j]=1;     //sum is 0 hence {} is present everywhere

            else if(i==0)   dp[i][j]=0;

            else 
            {
                // SAME CASE... WHEN NUMBER IS GREATER THAN SUM..WE IGNORE IT :)
                if(a[i-1]>j)  dp[i][j]=dp[i-1][j];

                //HERE BOOLEAN VALUE SO.. WE TAKE OR INSTEAD OF MAX... IE. IF EITHER ONE IS TRUE WE TAKE THAT
                else     dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
            }
        }
    }
    return dp[a.size()][sum];
}

int main()
{
    vector<int> a={1,6,5,11,3,2,8};
    
    int sum=0;
    for(int i=0;i<a.size();i++)     sum+=a[i];

    if(sum%2!=0)
    {
        cout<<"0\n";
        return 0;
    }    
    sum=sum/2;

    vector<vector<int>>dp(a.size()+1, vector<int> (sum+1, -1));

    cout<<check(a,sum,dp)<<endl;
}
