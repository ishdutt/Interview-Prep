    #include<bits/stdc++.h>
using namespace std;

int unboundedks(vector<int>&val,vector<int>&wt,int n,int W)
{
    if(n==0 || W==0) return 0;
    
    //IF WEIGHT IS MORE
    if(wt[n-1]>W)   return unboundedks(val,wt,n-1,W);

    else if(wt[n-1]<=W)
    {
        //AGAR LIYA TOH WE CAN TAKE IT AGAIN AND AGAIN.. AGAR IGNORE KIYA TOH MOVE THE ITERATOR :p
        return max(val[n-1]+unboundedks(val,wt,n,W-wt[n-1]),unboundedks(val,wt,n-1,W));
    }
}

int ks(vector<int>&val,vector<int>&wt,int n,int W,vector<vector<int>>dp)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<W+1;j++)
        {
            if(i==0 || j==0)    dp[i][j]=0;

            else if(wt[i-1]>j)   dp[i][j]=dp[i-1][j];

            else
            {
                dp[i][j]=max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
            }
            
        }
    }
    return dp[n][W];
}

int main()
{
    vector<int> val{10, 30, 20}; ;
    vector<int> wt{5, 10, 15};

    int W = 100;
    //SINCE 2 VALUES ARE CHANGING AND IT DOES MATTER HOW WE REACHED AT THAT STATE HENCE 2 VARIABLES

    //DP TABLE WITH -1 AS DEFAULT ENTRY
    vector<vector<int>>dp(val.size()+1, vector<int> (W+1, -1));

    //cout<<unboundedks(val,wt,3,W)<<endl;
    cout<<ks(val,wt,3,W,dp)<<endl;   
}