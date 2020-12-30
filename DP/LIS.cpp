#include<bits/stdc++.h>
using namespace std;


//IF THE CURRENT ELEMENT IS DECREASING.. WE JUST IGNORE IT :)
// ELSE WE HAVE 2 OPTIONS.. TAKE IT OR LEAVE IT SUCH THAT WE GET THE MAX LENGTH.. 

//IN 2ND CASE.. WE ALREADY CONSIDERED THE CASE WHEN THE 1ST ELEEMTN IS STARTING OR THE SECOND ONE IS 
// STARTING..AND SO ON. SINCE IT GIVES US THE FREEDOM TO CHOOSE.. IT CAN TAKE ANY SEQUENCE OF 
// ELEMENTS POSSIBLE :)

int lis(vector<int>a,int n,int lastelement)
{
    //BASE CASE
    if(n==a.size()) return 0;

    //IF IT IS DECREASING ... WE JUST MOVE AHEAD IGNORING THE NUMBER
    if(a[n]<=lastelement)  return lis(a,n+1,lastelement);

    //IF IT IS INCREASING.. WE CAN EITHER TAKE IT OR LEAVE IT...THIS IS THE CASE WITH FIRST ELEMENT
    // TOO... WHICH ENSURES ANY INDEXED NUMBER CAN BE THE STARTING POINT IN THE SUBSEQUENCE :)
    // IF TAKEN.. UPDATE THE LAST_ELEMENT AND INCREMENT THE COUNTER... ELSE JUST INCREEMENT THE COUNTER
    else    return max(1+lis(a,n+1,a[n]),lis(a,n+1,lastelement));

}

int lismemo(vector<int>a,int n,int lastelement,vector<vector<int>>&dp)
{
    //MOVING FROM LAST ELEMENT :)
    //BASE CASE
    if(n==0) return dp[n][lastelement]=0;

    //DP IS NOT EMPTY
    if(dp[n][lastelement]!=-1)  return dp[n][lastelement];

    //MODIFICATION FOR ADJUSTING INTIAL LASTELEMENT IN DP TABLE
    //check FOR LAST ELEMENT :)  

    //IF IT IS DECREASING THEN.. WE CAN EITHER TAKE IT OR LEAVE IT...THIS IS THE CASE WITH FIRST ELEMENT
    // TOO... WHICH ENSURES ANY INDEXED NUMBER CAN BE THE STARTING POINT IN THE SUBSEQUENCE :)
    // IF TAKEN.. UPDATE THE LAST_ELEMENT AND INCREMENT THE COUNTER... ELSE JUST INCREEMENT THE COUNTER
    if(a[n-1]<=lastelement)   return dp[n][lastelement]= max(1+lismemo(a,n-1,a[n-1],dp),lismemo(a,n-1,lastelement,dp));

    else    return dp[n][lastelement]= lismemo(a,n-1,lastelement,dp);

}

//HERE ALSO TRANSITION VARIABLE WILL BE PRESENT... IT ENSURE FOR CHECKING THE DATA
// SO 2D VECTOR HOGA YAHA BHI :)

int lisit(vector<int>a,int maxelement)
{
    //FOR FASTER OPTION ;)

    //1d table ... DP[I]=LENGTH OF LIS FROM A0...Ai INLUDING Ai IN THE SEQUENCE AS LAST ELEMENT
    // THIS REDUCES THE NEED TO MODIFIY THE NEED TO KEEP TRACK OF LAST ELEMENT

    vector<int>dp(a.size()+1,1);
    

    //AND FINALLY TRAVERSE THROUGH ALL THE "T" AND RETURN THE MAX VALUE SINCE WE DON'T KNOW THE LAST 
    // ELEMENT

    // WHEN T[I]=1 IT MEANS THE NO. WILL BE ALONE IN THE SEQUENCE IF TAKEN IN THE LIS .
    // WHEN T[I]!=1 THEN IT MEANS THE NUMBER IS ALREADY IN ANY SEQUENCE SO WE WILL SEARCH FOR THE 
    // HIGHEST J(<I) AND MAKE T[I]=T[J]+1..(MAKING I THE NEXT ELEMENT IN  THE SEQUNCE CONTAINING J)

    for(int i=1;i<a.size();i++)
    {
        //J IS THE PRECEDING ELEMENT OF I IN THE LONGEST INCREASING SUBSEQUENCE
        for(int j=0;j<i;j++)
        {
            //if I IS IN A SEQUENCE THAT HAS LONGER LENGTH THEN NO NEED TO UPDATE THE DP ARRAY WITH 
            // LOWER POSSIBLE VALUE. 
            if(a[i]>a[j])
                dp[i]=max(dp[i],dp[j]+1);

            //OR 
            // for(a[i]>a[j] && dp[j]>dp[i])
            //     dp[i]=dp[j+1];
        }
    }

    //SEARCHING FOR THE MAXIMUM POSSIBLE VALUE IN DP TABLE ;)

    int ans=dp[0];
    for(int i=0;i<dp.size();i++)
    {
        // cout<<dp[i]<<" ";
        ans=max(ans,dp[i]);
    }
    //cout<<endl;
    return ans;
}

void lisprint(vector<int>a)
{
    //2D MATRIX... LEN WILL STORE AND DO THE WORK OF DP TABLE
    // 2ND DIMENSION WILL STORE THE LIS SEQUENCE
    vector<vector<int>>lis(a.size());

    lis[0].push_back(a[0]);
    
    for(int i=1;i<a.size();i++)
    {
        //J IS THE PRECEDING ELEMENT OF I IN THE LONGEST INCREASING SUBSEQUENCE
        for(int j=0;j<i;j++)
        {
            //if I IS IN A SEQUENCE THAT HAS LONGER LENGTH THEN NO NEED TO UPDATE THE DP ARRAY WITH 
            // LOWER POSSIBLE VALUE. 
            if(a[i]>a[j] && lis[i].size()<lis[j].size()+1)
                lis[i]=lis[j];

        }
        //PUSHING THE ARR[I]TH ELEMENT IN THE LIST
        lis[i].push_back(a[i]);
    }
    
    //SEARCHING FOR THE MAXIMUM POSSIBLE VALUE IN DP TABLE ;)
    int maxsize=lis[0].size();
    int maxindex=0;
    for(int i=0;i<a.size();i++)
    {
        if(maxsize<lis[i].size())
        {
            maxindex=i;
            maxsize=lis[i].size();
        }
    }

    for(int i=0;i<lis[maxindex].size();i++)
        cout<<lis[maxindex][i]<<" ";
    
    cout<<endl;

}


int main()
{
    vector<int>array = { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    
    int maxelement=INT_MIN;
    for(int i=0;i<array.size();i++)
        maxelement=max(maxelement,array[i]);
    
    //2ND DIMENSION IS MAX ELEMENT..WE ARE AT WORST CASE TAKE THAT MAX ELEMENT(NOT NECESSARY TO INCLUDE 
    // IT BUT IN CASE WE INCLUDE IT.. WE MAKE DIMENSION AS MAX ELEMENT)
    //HERE MAXELEMENT+2 KYUNKI I'LL USE MAX ELEMENT +1 TO STORE INT_MIN CONDITION (IN OPPOSITE SENSE)
    vector<vector<int>> dp(array.size()+1,vector<int>(maxelement+2,-1));

    //Current element and last element in increasing sequence
    //INITIALLY, last ELEMENT IS -INF SO THAT WE CAN TAKE ANY NUMBER AS STARTING :)
    cout<<lis(array,0,INT_MIN)<<endl;

    cout<<lismemo(array,array.size(),maxelement+1,dp)<<endl;

    cout<<lisit(array,maxelement)<<endl;

    lisprint(array);
    //vector<vector<int>> dp(array.size()+1,vector<int>(,-1))
}