#include<bits/stdc++.h>
using namespace std;

//It is called Subsequence of a string not substring

//This apporoach is very similar to the Either take the element or not but implemented in a different way.

//This approach can be understood as selection of 1,2..n elements from a string of n elements..nCr
//Their permutation is not included here

//K here shows the element to be included or not
void sub(string ans,string s,int k)
{
    //Base Condition
    if(k==s.length())
    {
        //print the substring
        cout<<ans<<"\n";
        ans="";
    }
    else
    {
        //pUsh to the vector /string
        ans+=s[k];
        //First take it and do the stuff
        sub(ans,s,k+1);
        //THen remove it and do the stuff
        ans.pop_back();
        sub(ans,s,k+1);
    }
    
}

int main()
{
    string s="abc";
    string ans="";
    
    sub(ans,s,0);
}