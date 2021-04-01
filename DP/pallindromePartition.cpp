#include<bits/stdc++.h>
using namespace std;

//PALLINDROME PARTITION : Given a string, a partitioning of the string is a palindrome partitioning 
//                        if every substring of the partition is a palindrome
//      HERE WE NEED TO FIND MIN NUMBER OF OPERATIONS TO DO SO ;)

int dp[1001][1001];

bool ispal(string s,int i,int j)
{
    //cout<<s[i]<<" "<<s[j]<<endl;
    while(i<=j)
    {
        if(s[i]!=s[j])  return false;
        i++,j--;
    }

    return true;
}


int solve(string s,int i,int j)
{
    //AGAR 1 KA HUA TOH HOGA HI PALLINDROME AND NO NEED TO CUT FURTHER
    if(i>=j) return 0;

    //cout<<i<<" "<<j<<endl;

    //AGAR YE PALLINDROME HAI THEN NO NEED TO CHECK FURTHER AND WON'T BE CUT FURTHER
    if(ispal(s,i,j))    
        return 0;
    
    if(dp[i][j]!=-1)    return dp[i][j];

    int ans=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=solve(s,i,k)+solve(s,k+1,j)+1;
        ans=min(ans,temp);
    }
    return dp[i][j]= ans;
}

int main()
{
    string s="ababbbabbababa";
    memset(dp,-1,sizeof(dp));
    cout<<solve(s,0,s.size()-1)<<endl;
}