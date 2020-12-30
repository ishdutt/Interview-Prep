#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {9,2,5,1,1};
    
    int counts[256] = {0};
    for (int ch : s)
        ++counts[ch];

    // for(int i=0;i<s.size();i++)
    //     cout<<counts[s[i]]<<" ";
    
    //THis is an example of lambda function remember the syntax
    sort(s.begin(), s.end(), [&](int a, int b) { 
        // Second condition is for when freq is same then whichever i greater is returned
        return counts[a] > counts[b] || (counts[a] == counts[b] && a > b); 

        //NAIVE Implementation think that a is superior
        if(counts[a]==counts[b] && a>b)
            return true;
        if(counts[a]>counts[b])
            return true;
        else
            return false;
        
    });
    for(int i=0;i<s.size();i++)
        cout<<s[i]<<endl;
}