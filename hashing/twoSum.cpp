#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    vector<int> a = {1,2,2,6,7};
    int x =4;
    //=======================BRUTE FORCE
    // for(int i=0;i<a.size();i++)
    // {
    //     for(int j=0;j<a.size();j++)
    //     {
    //         if(a[i]+a[j]==x)
    //         {
    //             cout<<"TRUE";
    //             return 0;
    //         }
    //     }
    // }
    //cout<<"False";
    //return 0;
    

    //================================SORT+2 POINTER
    // sort(a.begin(),a.end());
    // int l=a[0];
    // int r=a.back();
    // while (l<r)
    // {
    //     if(l+r==x)
    //     {
    //         cout<<"TRUE\n";
    //         return 0;
    //     }
    //     else if(l+r>x)
    //         r--;
    //     else
    //         l++;
        
    // }
    // cout<<"FALSE\n";
    
    //TODO ================================SET,MAP +FIND METHOD
    unordered_multiset<int> s(a.begin(),a.end());
    for(int i=0;i<s.size();i++)
    {
        //a[i] is the element
        auto it = s.find(x-a[i]);
        //Casing since the x can be double of a[i] in that case find will output the same number    
        if(s.find(x-a[i])!=s.end())
        {
            if(*it==a[i])
            {
                if(s.count(*it)>1)
                {
                    cout<<"TRUE\n";
                    return 0;
                }
                    
            }
            else
            {
                cout<<"TRUE\n";
                return 0;
            }
               
        }
            
    }
    cout<<"FALSE\n";
}