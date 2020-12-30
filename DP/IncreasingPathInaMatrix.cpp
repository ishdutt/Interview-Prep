#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&mat,vector<vector<int>>&dp,int i,int j)
{
    //cout<<i<<" "<<j<<endl;
    //IF I J REACHES MORE THAN N-1 OR LESS THAN 1 THEN RETURN 0 SIMPLY
    if(i>=mat.size()|| j>=mat[0].size() || i<0 || j<0)
        return dp[i][j]=0;
    
    if(dp[i][j]!=-1)    return dp[i][j];

    //MOVE IN HORIZONTAL DIRECTION
    //IF THE CONDITION DIDN'T RUN THEN X,Y,Z,W WILL HAVE GARBAGE VALUE..HENCE INTIALISATION IS MUST
    int x=0,y=0,z=0,w=0;
    //HERE WE CHECK J<MAT.SIZE()-1 SINCE WE HAVE J+1 IN THE CHECKING CONDITION WHCIH CAN CAUSE 
    //SEGMENTAION FAULT FAULT
    if(j<mat[0].size()-1 && mat[i][j]<mat[i][j+1])
    {
        cout<<"MOSHI\n";
        x=1+solve(mat,dp,i,j+1);
    }
        

    if(j>0 && mat[i][j]<mat[i][j-1])
    {
        cout<<"MOSHO\n";
        y=1+solve(mat,dp,i,j-1);
        //cout<<"MOSHO\n";
    }
        

    if(i>0 && mat[i][j]<mat[i-1][j])
    {
        //cout<<"MOSHI\n";
        z=1+solve(mat,dp,i-1,j);
    }
        
    
    if(i<mat.size()-1 && mat[i][j]<mat[i+1][j])
    {
        w=1+solve(mat,dp,i+1,j);
        //cout<<"MOSHI\n";
    }
        
    
    //IT CAN BE MIN 1.. WE DIDN'T USE IT IN TABLE AS IT WILL CREATE CONFUSTION OF VISITED AND NON 
    // VISITED
    return dp[i][j]=max(x,max(y,max(z,max(w,1))));
    
}

int main()
{
    // vector<vector<int>>mat=  {{9, 9, 4},
    //                           {6,6,8},
    //                           {2,1,1}};
    vector<vector<int>>mat={{1,2}};
    
    //FOR  EVERY CELL WE CALCULATE THE LIS KEEPING THEM AS THE STARTING CHARACTER
    vector<vector<int>>dp(mat.size()+1,vector<int>(mat[0].size()+1,-1));

    int n=mat.size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            //cout<<"YOYO\n";
            solve(mat,dp,i,j);
        }
            
    }
    //NOW TRAVERSE THE WHOLE DP MATRIX TO SEARCH FOR THE MAX LEN
    int ans=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<mat[0].size();j++)
        {
            cout<<dp[i][j]<<" "; 
            ans=max(ans,dp[i][j]);
        }
        cout<<"\n";
    }
    cout<<ans<<"\n";
}