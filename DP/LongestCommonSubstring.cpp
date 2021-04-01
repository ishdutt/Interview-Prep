#include<bits/stdc++.h>
using namespace std;


//FIXME:
int lcs(string s1,string s2,int n1,int n2,vector<vector<int>>dp)
{
    
    //BASE CONDITION
    if(n1<=0 || n2<=0)  return 0;

    //MAIN PART.. IF THEY ARE EQUAL.. WE WILL CHECK THE COMMON PART AND AGAIN RECURSE THROUGH THE REMAINING 
    // PART... CHOOSING MAXIMUM VALUE BETWEEN THE CURRENT VALUE AND UPCOMING COMMON SUBSTRING

    //IDEA: YA TOH JO STRING MILI HAI WO NAI TOH AAGE JO MILEGI WO... UNME SE JO MAX HUA WO ANSWER :)
    if(s1[n1-1]==s2[n2-1])
    {
        int count=0;
        while (s1[n1--]==s2[n2--] && n1>=0 &&n2>=0)     count++;
           

        return  max(count,lcs(s1,s2,n1-1,n2-1,dp));  
    } 

    //IF CHAR NOT MATCHES THEN W HAVE TO MOVE ON AND CHECK WHICH IS GIVING MAX RESULTS, IF WE MOVED WRT
    // STRING S1 OR WRT TO STRING S2 :)
    else if(s1[n1-1]!=s2[n2-1])  return  max(lcs(s1,s2,n1-1,n2,dp),lcs(s1,s2,n1,n2-1,dp));

}

int longestCommonSubstring(string s1,string s2,int n,int m,vector<vector<int>>&dp)
{
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)  dp[i][j]=0;

            //HERE WE DID'T USE WHILE LOOP SINCE WE ARE MANTAINING THE TABLE SO BETTER GO WITH THE 
            // FLOW AND ADD THE LENGTH OF SUBSTRING UPTO LENGTH I,J...
            else if(s1[i-1]==s2[j-1])   dp[i][j]=1+dp[i-1][j-1];

            //when discontinuity then simply make the complete length as 0... THIS IS DONE AS AGAR I AND J ME LENGTH 5 HAI TOH
            // I+K,J+L ME (AGAR NON MATCHING HAI TOH) SAME AS I AND J HI HOGA.. JO PEHLE HI STORED HAI.. ISILIYE TABLE ME US LENGTH 
            // KO NAI STORE KAR RHE... IF STORED.. IT WILL HAVE THE SOME OF DISCONTINOUS PART TOO.. 
            //EG. ABCDXVBV      ABCDZVKK ISME ANSWER 4 AAYGEA BUT AGAR HAM VALUE 0 NAI KARENGE TOH 'V' BHI COUNT KAR LEGA FINAL ARRAY
            // ME..
            else
            {
                dp[i][j]=0;
            }
            
        }
    }
    //cout<<"MOSHI\n";
    int ans=0;
    //GETTING THAT INDEX VALUE WHERE WE GOT THE MAX LENGTH..
    for(int i=0;i<m+1;i++)
        ans=max(ans,dp[n][i]);

    return ans;
}

int main()
{
    string s1="KXCGMTMVVGFQQWSPD";
    string s2="JXZADDUKVLQPKUZJZHWSUTPCAFSYAIBJHAMMEGWBTPQELRNKBLDXGUZGCSEC";
    
    //WE ARE HERE TOO MVING FROM BACK N-1th ELEMENT to 0th ELEMENT.
    
    //HERE 2 VARIABLES ARE DECREASING ...SO 2D MATRIX
    vector<vector<int>>dp(s1.size()+1,vector<int>(s2.size()+1,-1));
    cout<<longestCommonSubstring(s1,s2,s1.size(),s2.size(),dp)<<endl;
}