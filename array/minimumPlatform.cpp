#include<bits/stdc++.h>
using namespace std;

//IN THIS WE JUST NEED TO TREAT ARRIVAL AS + AND DEPARTURE AS -
//NO NEED TO TRACK ALL TRAINS INDIVIDUALY AND MARK THEIR PRESENCE LIKE THE GANT CHART

int main()
{
    int n = 6;
    //IGNORING THE PREFIX 0
    vector<int> arrival = { 900, 910, 950, 1100, 1500, 1800 };
    vector<int> dep = { 910, 1200, 1120, 1130, 1900, 2000 };
    int curr =0;
    int maxa = 0;
    
    map<int,int> time;
    //DEPARTURE IS MARKED AS 1 ARRIVAL AS 0
    for(int i=0;i<n;i++)
        time[dep[i]] = 1;
    
    for(int i=0;i<n;i++)
        time[arrival[i]] = 0;
    
    for(auto x : time)
    {
        if(x.second==0)
            curr++;
        else if(x.second==1)
            curr--;
        maxa = max(maxa,curr);
    }
    cout<<maxa<<endl;
    
}