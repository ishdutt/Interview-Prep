#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        set<int>d(days.begin(),days.end());
            
        //NuBER OF DAYS  
        vector<int>dp(396,0);
        int h=days[n-1];
        for(int i=1;i<h+1;i++)
        {
            int t1 = max(0,i-1);
            int t2 = max(0,i-7);
            int t3 = max(0,i-30);
            
            //IGNORING TP BUY TICKET IF ON THAT DAY WE ARE NOT TRAVELLING AND TAKING THE VALUE FROM THE PREVIOUS DAY
            if(d.find(i)==d.end())  dp[i]=dp[i-1];
            
            //MAIN CODE => TAKING INPUT FROM PREVOUS DAYS + CURRENT DAYS
            else
                dp[i]=min(dp[t1]+costs[0],min(dp[t2]+costs[1], dp[t3]+costs[2]));
            cout<<dp[i]<<endl;
        }
        return  dp[h];
    }
};

int main()
{
    Solution s;
    vector<int>days={1,2,3,4,5,6,7,8,9,10,30,31};
    vector<int>costs = {2,7,15};
    cout<<s.mincostTickets(days,costs)<<endl;
}