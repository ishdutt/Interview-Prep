#include<bits/stdc++.h>
using namespace std;

bool solve(string s,string regexp,int n1,int n2,vector<vector<int>>&dp)
{
    //cout<<n1<<"="<<s[n1]<<" n2"<<n2<<"="<<regexp[n2]<<endl; 
    //IF BOTH REACHED TO END THEN TRUE 
    if(n1==s.size()&&n2==regexp.size())    return dp[n1][n2]=1;

    //IF N2 REACHES END... THEN 0
    // IF N1 REACHES END.. WAIT AND CHECK IF THE STRING HAS '*' PART
    if(n2==regexp.size())    return dp[n1][n2]=0;

    if(dp[n1][n2]!=-1)  return dp[n1][n2];

    //ADDED N1!+ END KYUNKI AGAR NAI DAALA TOH .* PE YE INFINITE LOOP BAN JAYEGA..BUT IT MUST GO TO ELSE PART IF STRING S IS FINISHED
    else if(s[n1]==regexp[n2] || regexp[n2]=='.' && n1!=s.size())
    {
        //agar match kiya aur NEXT CHAR IS '*' THEN WE WILL STAY ON THE SAME STATE FOR S AND MOVE THE
        // POINTER FOR STRING S.
        // IF THE "*" KA KAAM HO GAYA THEN GOTO ELSE 1ST CASE
        // cout<<n2<<" "<<
        if(n2!=regexp.size()-1 && regexp[n2+1]=='*')
        {
            //cout<<"YOYO\n";
            //SECOND CASE IS FOR HANDLING THE SCENARIO OF AA*A.. IN THIS.. YOU WILL HAVE THE OPTION TO CHOOSE WHETHER TO STAY
            // IN THE * PART OR SKIP IT(MATLAB ZERO OCCURENCES LE IS CHARACTER KE) .. 
            //WE WILL TAKE THE ONE WHICH GIVES US + RESULT.. THAT'S WHY ||
            return dp[n1][n2]=solve(s,regexp,n1+1,n2,dp)|| solve(s,regexp,n1,n2+2,dp);

        }
            
        else
            return dp[n1][n2]= solve(s,regexp,n1+1,n2+1,dp);
    }  

    else 
    {
        //IF THE CURRENT POS CHAR DOESN'T MATCH AND THE NEXT CHAR IS '*' IN REGEXP THEN IT WILL OCCUR 0 
        // NUMBER OF TIMES AND WE WILL SKIP THE STUFF ;).. MOVE THE POINTER FOR REGULAR EXPRESSION ONLY
        //cout<<"NAI MIla re\n";
        if(n2!=regexp.size()-1 && regexp[n2+1]=='*')
            return dp[n1][n2] = solve(s,regexp,n1,n2+2,dp);

        else
        {
            return dp[n1][n2]=0;   
        }
        
    }      
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s,regexp;
        cin>>s>>regexp;

        vector<vector<int>>dp(s.size()+1,vector<int>(regexp.size()+1,-1));
        cout<<solve(s,regexp,0,0,dp)<<endl;
    }
}