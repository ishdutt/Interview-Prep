#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 4, 4, 5, 3};
    
    //HERE set can't be used since we have to mantain a certain order instead of vector a
    // WE can use set playing the same role as maps
    
    unordered_map<int,int>m;
    int maximum;
    for(int i=0;i<a.size();i++)
        maximum=max(maximum,a[i]);

    for(int i=0;i<a.size();i++)
    {
        if(m[a[i]]!=0)
        {
            a[i]=maximum+1;
            maximum++;
            m[maximum]++;
        }
        else
            m[a[i]]++;
        
    }
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<endl;
}