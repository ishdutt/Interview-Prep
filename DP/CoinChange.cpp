#include<bits/stdc++.h>
using namespace std;

//INFINITE SUPPLY OF COIN.. GET THE DENOIMINATION OF M (UNBOUNDED KNAPSACK)
//MINIUM NUMBER OF COINS TO GET THE DESIRED SUM :)

int coincount(vector<int>a,int k,int n)
{
    //BASE CASE
    if(k<=0)    return 0;
    else if(n<=0)
    {
        if(k>0) return INT_MAX;

        else    return 0;
    }

    //IF COIN IS GREATER THAN AMOUNT THEN IT IS NOT TAKEN
    if(a[n-1]>k)    return coincount(a,k,n-1);

    else    return min(1+coincount(a,k-a[n-1],n),coincount(a,k,n-1));
}

int coinit(vector<int>a,int k,int n)
{
    vector<vector<int>>dp(n+1,vector<int>(k+1,0));
    //I IS THE ITERATOR TO THE DENOMINATIONS
    for(int i=0;i<n+1;i++)
    {
        //J IS THE SUM VALUE WE NEED
        for(int j=0;j<k;j++)
        {
            if(i==0)
            {
                //IF NO DENOMINATION AND J IS GREATER.. THEN NOT POSSIBLE(I.E WE WILL HAVE ONLY ONE 
                // TRIANGLE HALF)
                if(j>0)     dp[i][j]=INT_MAX;
                //IF  0 THEN POSIBLE WAYS=0
                else    dp[i][j]=0;
            }
            
            else if(j==0)    dp[i][j]=0;

            
            //IF IT IS GREATER THAN THE ELEMENT.. SIMPLY IGNORE IT :)
            else if(a[i-1]>j)   dp[i][j]=dp[i-1][j];

            else
            {
                // WE CAN TAKE IT OR LEAVE IT..2 OPTTIONS CHOOSING THE MAX OUT OF THEM  
                dp[i][j]=max(dp[i-1][j],1+dp[i-1][j-a[i-1]]);
            }
            
        }
    }
}

int main()
{
    vector<int>a= {1,2,5};
    int k=11;
    
    vector<int> coins;
    cout<<coincount(a,k,a.size())<<endl;
}