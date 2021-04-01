#include<bits/stdc++.h>
using namespace std;

//NUMBER OF WAYS TO EVALUEATE THE BOOLEAN OPERATION SUCH THAT THE O/P IS TRUE..FIND NUMBER OF 
//SUCH WAYS

int dp[1001][1001][2];

int solve(string s,int i,int j,bool istrue)
{
    //cout<<i<<" "<<j<<endl;
    if(i>j) return 0;

    else if(i==j)
    {
        // if(s[i]=='T' && istrue==1)  return 1;
        // else if(s[i]=='F' && istrue==0)  return 1;
        // else return 0;
        if (istrue == 1)
			return s[i] == 'T';
		else
			return s[i] == 'F';
    }

    if(dp[i][j][int(istrue)]!=-1)    return dp[i][j][int(istrue)];

    //PARTITIION THE STRING
    int ans=0;
    for(int k=i+1;k<j;k=k+2)
    {
        int ltrue = solve(s,i,k-1,true);
        int lfalse = solve(s,i,k-1,false);
        int rtrue = solve(s,k+1,j,true);
        int rfalse = solve(s,k+1,j,false);

        //CONDITIONS BASED ON THE BOOLEAN OPERATOR
        if(s[k]=='&')
        {
            //CONDITION FOR TRUE TOTAL
            //NUMBER OF WAYS = NUMBER OF WAYS FOR TRUE FOR RIGHT * NUMBER OF WAYS FOR TRUE ON RIGHT
            //MULTIPLICATION RULE P&C
            if(istrue)
                ans+= ltrue*rtrue; 
            else
                ans+= ltrue*rfalse + lfalse*rtrue + lfalse*rfalse;
        }
        else if(s[k]=='^')
        {
            if(istrue)
                ans+= ltrue*rfalse + lfalse*rtrue;
            else
                ans+= ltrue*rtrue + lfalse*rfalse;
        }
        else 
         {
            if(istrue)
                ans+= ltrue*rfalse + lfalse*rtrue + ltrue*rtrue; 
            else
                ans+= lfalse*rfalse;
        }
    }
    return dp[i][j][int(istrue)] = ans;
}

int main()      
{
    //string s="T|T&F^T";
    string s="T^T^T^F|F&F^F|T^F^T";
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,s.size()-1,true);
}