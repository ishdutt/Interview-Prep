#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {9,9,9,2, 5};
    int k=2;

    //USING HASHMAP (SAME METHOD IN SORT BY FREQ)
    //KEY: value and VALUE: frequency
    map<int,int>m;
    for(int i=0;i<nums.size();i++)
        m[nums[i]]++;

    vector<int>v;
    //K is for top max element
    while(k>0)
    {
        //SImply finding the max element by traversing the Map
        int max=0;
        int maxnum=0;
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(max<i->second)
            {
                max=i->second;
                maxnum=i->first;
            }
        }            
        m[maxnum]=0;
        v.push_back(maxnum);
        k--;
    }
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
}