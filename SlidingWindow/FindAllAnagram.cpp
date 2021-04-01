#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s="cbaebabacd";
    string pattern="abc";

    //OPTIMISED APPROACH HAI YE... O(26*N) HAI COMPLEXITY WHICH IS THE BEST
    vector<int>a(26,0);
    vector<int>b(26,0);
    for(int i=0;i<pattern.size();i++)
        b[pattern[i]-'a']++;
    int count=pattern.size();
    for(int i=0;i<s.size();i++)
    {
        a[s[i]-'a']++;

        if(i<=pattern.size())    a[s[i-pattern.size()]-'a']--;
        
        //O(26)=O(1) HENCE TIME COMPLEXITY IS BETTER HERE I.E 
        if(a==b)
        {
            cout<<"YES"<<endl;
            return true;
        }
    }

    //OPTIMISE IT USING COUNT VARIABLE DECREMENT IT WHEN BECOMES 0 THEN SIMPLY RETURN TRUE

    cout<<"false";
    cout<<endl;
    return 0;
}