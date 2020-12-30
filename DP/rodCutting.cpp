#include<bits/stdc++.h>
using namespace std;
//SAME AS UNBOUNDED KS .. HERE WE HAVE TO DIVIDE THE ROD INSTEAD OF CONSTRUCTING IT.. BOTH ARE 
//BIJECTIVE IN NATURE :)

// PROFIT ARRAY IS SAME AS KS's VALUE MATRIX
// LENGTH ARRAY IS SAME AS WT ARRAY(I CREATED IT :)

//IT IS EXACT OPPOSITE OF THE KS.. HERE WE DIVIDE INSTEAD OF ACCUMULATE :)

int main()
{
    //THIS PROFIT IS CORRESPODING TO THE SIZE EG.->8 SIZE KA PRICE 20, 7 KA 17 
    vector<int>profit{1, 5, 8, 9, 10, 17, 17, 20};
    
    vector<int>length{1,2,3,4,5,6,7,8};


    vector<vector<int>>dp(profit.size()+1,vector<int>(length.size()+1,-1));
    
    // IT IS LENGHT OF ROD.. TRAVERSING THE POSSIBLE LENGTHS 
    for(int i=0;i<profit.size()+1;i++)
    {
        // IT IS THE AVAILABLE SIZE LEFT
        for(int j=0;j<length.size()+1;j++)
        {
            if(i==0 || j==0)    dp[i][j]=0;

            // IF LENGTH IS MORE THAN MAX LEN THEN IGNORE IT 
            else if(length[i-1]>j)   dp[i][j]=dp[i-1][j];

            else
                    dp[i][j] = max(profit[i-1]+dp[i][j-length[i-1]],dp[i-1][j]);
            
        }
    }

    cout<<dp[profit.size()][length.size()]<<endl;
}