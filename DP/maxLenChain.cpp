#include<bits/stdc++.h>
using namespace std;

//FOR INCREASING ORDER STUFFF....START POINNTER FROM 0 TILL N..OTHERWISE CONFUSING

int len(vector<pair<int,int>>chain,int n,pair<int,int>currentpair)
{
    if(n==chain.size())    return 0;

    //IF CONDITION (FRST ELEMENT IS GREATER THAN THE SECOND ELEMENT OF CURRENT ELEMENT)
    //IS NOT SATISFIED THEN IGNORE
    if(currentpair.second> chain[n].first)  return len(chain,n+1,currentpair);

    //IF CONDITION SATISFIED THEN WE CAN EITHER TAKE IT OR LEAVE IT
    return max(len(chain,n+1,currentpair),1+len(chain,n+1,chain[n]));
}

int main()
{
    vector<pair<int,int>>chain = { {70, 80}, {39, 60},{15, 28}, {27, 40}, {50, 90} };

    // sort(chain.begin(),chain.end(),[&](pair<int,int> a,pair<int,int> b){
    //     return a.first<b.first;
    // });
    // for(int i=0;i<chain.size();i++)
    //     cout<<chain[i].first<<" "<<chain[i].second<<endl;

    pair<int,int>temp(INT_MIN,INT_MIN);
    cout<<len(chain,0,temp)<<endl;
}