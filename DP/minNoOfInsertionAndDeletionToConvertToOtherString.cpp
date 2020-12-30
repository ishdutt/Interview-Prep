#include<bits/stdc++.h>
using namespace std;

//WHEN MOVING FROM STRING 1 TO STRING 2 WE HAVE TO GO VIA LCS STATE...SO FIRST REMOVE THE STRINGS 
// TO LEAVE ONLY LCS IN THE 1ST STRING AND THEN ADD ALL THE ELEMENTS WHICH ARE XTRA INTO THE STRING 1 
// TO CONVERT IT INTO STIRNG 2

//LCS VARIANT

// WHEN REPLACE.. THEN EDIT DISTANCE... JUST ADD ONE MORE STEP OF EDIT.. SO INSTEAD OF 2 CHOICES..
// THREE CHOICCES WILL BE THERE

//LCS KA CODE HAI.. BAS O/P MODIFY KIYA HAI MAINE
int solve(string s,string t)
{
    vector<vector<int>>dp(s.size()+1,vector<int>(t.size()+1,0));

    for(int i=0;i<s.size()+1;i++)
    {
        for(int j=0;j<t.size()+1;j++)
        {
            //IF ONE STRING IS 0 THEN WE HAVE TO MAKE THE OTHER STRING 0 TOO ;)
            if(i==0||j==0)    dp[i][j]=0;  

            else if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+1;

            else
            {
                
                dp[i][j]=max(dp[i-1][j] ,  dp[i][j-1]);
            }
            
        }
    }
    // CONVERT STRING S1 TO LCS BY DELETING ELEMETNS.. THEN ADD THE REMAINING ELEMENTS TO MAKE IT 
    // TO STRING 2
    return s.size()+t.size()-2*dp[s.size()][t.size()];

}


int main()
{
    string s="abc";
    string t="bcd";

    cout<<solve(s,t)<<endl;
}