#include<bits/stdc++.h>
using namespace std;

//FOR adding data to the combin. of ds, store the inner ds first (temp) and then push it to the 
//hybrid ds eg. just like how it works for vector of vectors i.e 2d array

int main()
{
    vector<int> s={1,2,45,8,7,36};
    //1. MAP of VEctors(IMP)

    map<int,vector<int>>m;
    for(int i=0;i<s.size();i++)
    {
        //ADDING VALUE To THE MAP OF VECTORS
        vector<int>temp(s.begin(),s.begin()+i);
        m[s[i]] = temp;
    }
    // for(auto i : m)
    // {
    //     //TO PRINT WE NEED 2 FOR LOOPS SINCE THE VALUE IS ALSO A VECTOR AND NEEDS TRAVERSAL
    //     cout<<i.first<<"->";
    //     for(auto d : i.second)
    //         cout<<d<<" ";
    //     cout<<"\n";
    // }

    //2. MAP OF MAPS FOR STORING 2 VALUES AS KEYS
    map<int,map<int,int>>mp;
    for(int i=0;i<s.size();i++)
    {
        map<int,int>temp;
    }

    //3. SET OF VECTORS
    sort(s.begin(),s.end());
    set<vector<int>> sete;
    for(int i=0;i<s.size();i++)
    {
        next_permutation(s.begin(),s.end());
        sete.insert(s);
    }

    auto it = sete.begin();
    it++;

    //DELETING STE OF VECTORS
    //sete.erase({1,2,7,36,45,8});
    sete.erase(it);

    //PRINTING
    for(auto it: sete)
    {
        //THis is how to print the nested ds ---> USE FOR FOR nested to access
        for(auto d : it)
        cout<<d<<" ";
        cout<<"\n";
    }
}