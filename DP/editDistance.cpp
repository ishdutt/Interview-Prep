#include<bits/stdc++.h>
using namespace std;


//LONGEST COMMON SUBSEQUENCE
int lcs(string s1,string s2,int n1,int n2,vector<vector<int>>dp)
{
    //cout<<"TEST "<<n1<<" "<<n2<<endl;
    // //BASE CONDITION
    // if(n1==0 || n2==0)  return 0;

    // if(dp[n1-1][n2-1]!=-1)  return dp[n1-1][n2-1];

    // //MAIN PARTx
    // if(s1[n1-1]==s2[n2-1]) return dp[n1-1][n2-1]= 1+lcs(s1,s2,n1-1,n2-1,dp);

    // //IF CHAR NOT MATCHES THEN W HAVE TO MOVE ON AND CHECK WHICH IS GIVING MAX RESULTS, IF WE MOVED WRT
    // // STRING S1 OR WRT TO STRING S2 :)
    // else if(s1[n1-1]!=s2[n2-1])  return   dp[n1-1][n2-1]= max(lcs(s1,s2,n1-1,n2,dp),lcs(s1,s2,n1,n2-1,dp));

    for(int i=0;i<n1+1;i++)
    {
        for(int j=0;j<n2+1;j++)
        {
            // WHEN ONE OF THE STRING IS ZERO... WE JUST HAVE TO MAKE THE OTHER STRING AS 0 AS WELL
            // I.E IT'S SIZE NUMBER OF OPERATIONS
            if(i==0)    dp[i][j]=j;

            else if(j==0)    dp[i][j]=i;

            else if(s1[i-1]==s2[j-1])   dp[i][j]= dp[i-1][j-1];

            else
            {
                //WHEN MISMATCH 3 OPTIONS EITHER SKIP STRING 1'S ELEMENT(I.E DELETE IT) SKIPS STRING 2'S
                // ELEMENT (I.E DELETE IT) (BOTH SAME AS LCS) OR FOR REPLACE JUST REPLACE , NOW IT BECAME 
                // EQUAL.. MOVE TO I-1 AND J-1
                dp[i][j]= min(1+dp[i-1][j],min(1+dp[i][j-1],dp[i-1][j-1]+1));   
            }
            
        }
    }
    return dp[n1][n2];

}

int main()
{
    string s1="gesek";
    string s2="geek";
    
    //WE ARE HERE TOO MVING FROM BACK N-1th ELEMENT to 0th ELEMENT.
    
    //HERE 2 VARIABLES ARE DECREASING ...SO 2D MATRIX
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    int ans=lcs(s1,s2,s1.size(),s2.size(),dp);

    cout<<"TEST="<<ans<<"\n";
    
}