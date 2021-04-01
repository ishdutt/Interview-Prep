#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int solve(vector<int>mat,int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    //BASE CONDITION.. ALWAYS MIN OF 2 NUMBERS ARE NEEDED
    if(i>=j)    return 0;

    if(dp[i][j]!=-1)    return dp[i][j]; 

    int ans=INT_MAX;
    //DIVIDING IT INTO K POSISTIONS WHERE WE CAN APLLY BRACKATS FOR GIVING PREFERENCE TO MULTIPLICATION
    // K FROM 1 TO J-1 
    for(int k=i;k<j;k++)
    {
        //COMBINING THE PROBLEMS AND THE ADDITION FACTOR
        int temp    =   solve(mat,i,k)  +    solve(mat,k+1,j)   +  (mat[i-1]*mat[k]*mat[j]);
        ans=min(ans,temp);
    }
    return dp[i][j]=ans;
}

int main()
{
    vector<int>mat={ 1, 2, 3, 4, 3 };
    //vector<vector<int>>dp(10001,vector<int>(10001));
    memset(dp,-1,sizeof(dp));
    cout<<solve(mat,1,mat.size()-1)<<endl;
}