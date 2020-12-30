#include<bits/stdc++.h>
using namespace std;

//LONGEST COMMON SUBSEQUENCE
int lcs(string s1,string s2,int n1,int n2,vector<vector<int>>dp)
{
    //cout<<"TEST "<<n1<<" "<<n2<<endl;
    //BASE CONDITION
    if(n1==0 || n2==0)  return 0;

    if(dp[n1-1][n2-1]!=-1)  return dp[n1-1][n2-1];

    //MAIN PARTx
    // IF MATCHES.. MOVE AHEAD .. DECREASE THE POINTERS(KYUNKI ONCE THAT CHAR IS MATCHED.. 
    //IT DOESN'T MATTER WHETHER IT MATCHES WITH OTHER CHAR OF OTHER SEQUENCE(WASTAGE OF TIME TO RECOMPUTE))
    
    // WE IGNORE THAT STRING IN THE HOPE THAT IT WILL MATCH WITH OTHER CHAR AT SOME TIME
    if(s1[n1-1]==s2[n2-1]) return dp[n1-1][n2-1]= 1+lcs(s1,s2,n1-1,n2-1,dp);

    //IF CHAR NOT MATCHES THEN W HAVE TO MOVE ON AND CHECK WHICH IS GIVING MAX RESULTS, IF WE MOVED WRT
    // STRING S1 OR WRT TO STRING S2 :)
    //i.e TAKE THE S1 STRING AS IT IS AND REDUCE S2 BY ONE.. OR DECREASE S1 BY ONE AND KEEP S1 AS 
    // SAME.. THEN TAKE THE MAXIMUM OF THESE TWO
    else if(s1[n1-1]!=s2[n2-1])  return   dp[n1-1][n2-1]= max(lcs(s1,s2,n1-1,n2,dp),lcs(s1,s2,n1,n2-1,dp));

}

int lcs2(string s1,string s2,int n1,int n2,vector<vector<int>>dp)
{
    string s="";
    for(int i=0;i<n1+1;i++)
    {
        for(int j=0;j<n2+1;j++)
        {
            if(i==0 || j==0)    dp[i][j]=0;

            else if(s1[i-1]==s2[j-1])
            {
                dp[i][j]= 1+dp[i-1][j-1];
            }   

            else
            {
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);   
            }
            
        }
    }

    //WE HAVE TO TRAVERSE SEPARATELY SINCE WE IF DONE IN MAIN LOOP.. IT WILL HAVE MANY REPITATIONS..
    //HERE IF S1[I]==S2[J] THEN ADD THAT STRING AND DECRESE BOTH THE I AND J (JUST AS IN ABOVE DP CODE)
    // WHEN UNEQUAL.. WHICHVER IS GIVING MORE VALUE WILL BE TAKEN FOR THE PATH I.E WHEN I IS DECREASED AND WHEN J IS DECREASED..
    // JISKE BHI KAM KARNE PE MAX VALUE MIL  RHA HAI WAHI PATH OPT KARENGE....FROM REVERSING THE ABOVE LOGIC ONLY..
    int i=n1;
    int j=n2;
    while(i>0&&j>0)
    {
        if(i==0||j==0)  break;

        else if(s1[i-1]==s2[j-1])
        {
            s+=s1[i-1];
            // cout<<"TETS="<<s1[i]<<endl;
            i--;
            j--;
        }  
        else
        {
            if(dp[i-1][j]>dp[i][j-1])
                i--;
            
            else
            {
                j--;
            }   
        }
    }


    cout<<s<<endl;
    return dp[n1][n2];

}

int main()
{
    string s1="aacabdkacaa";
    string s2="dbbc";
    
    cout<<s1.size()<<" "<<s2.size()<<endl;
    //WE ARE HERE TOO MVING FROM BACK N-1th ELEMENT to 0th ELEMENT.
    
    //HERE 2 VARIABLES ARE DECREASING ...SO 2D MATRIX
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    cout<<lcs2(s1,s2,s1.size(),s2.size(),dp)<<endl;
}