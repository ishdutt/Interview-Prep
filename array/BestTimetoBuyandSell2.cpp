#include<bits/stdc++.h>
using namespace std;

//4 VARIANTS: 1. ONLY ONE TIME BUY AND SELL
//            2. CAN SELL ANY NUMBER OF TIMES NO CONSTRAINTS
//            3. CAN BUY K NO. OF TIMES

//            TRICK: TRANSACTION BETWEEN CONSECUTIVE PAIRS: CHECK AND VERIFY THIS APPROACH SEE USING
//          GRAPH... :)

int main()
{
    vector<int> sp = { 100, 180 ,260, 310, 40 ,535, 695};
    int min_element = INT_MAX;
    int profit = 0;

    //JUST ADD THE STUFF
    for(int i=1;i<sp.size();i++)
        if(sp[i]>sp[i-1]) profit+= sp[i]-sp[i-1];
    

    cout<<profit<<endl;
}