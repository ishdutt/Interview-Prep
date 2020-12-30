#include<bits/stdc++.h>
using namespace std;

//THIS IS FIBONACCI VARIENT ;)
int ways(int n,int curr)
{
    if(curr>n) return 0;

    if(curr==n) return 1;

    //HE HAS THREE OPTIONS... 
    else
    {
        return ways(n,curr+1)+ways(n,curr+2)+ways(n,curr+3);
    }
    
}

int solve(int n)
{
    vector<int>dp(n+1,0);
    //TO REACH 0->1 OPTION .. TO REACH 1->1 OPTION...TO REACH 2-> 2 OPTIONS
    dp[0]=1,dp[1]=1,dp[2];
    for(int i=2;i<n+1;i++)
    {
        //PERSON HAS 3 OPTIONS.. MOVE 1,2,3 STEPS.. NO EFFECT OF HOW WE REACHED THERE.. SO NO 2D DP ;)x
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }
    return dp[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<ways(n,0)<<endl;
    cout<<solve(n)<<endl;
}