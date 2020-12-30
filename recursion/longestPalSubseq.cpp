#include<bits/stdc++.h>
using namespace std;
//TODO:
//It is called Subsequence of a string not substring

//This apporoach is very similar to the Either take the element or not but implemented in a different way.

//This approach can be understood as selection of 1,2..n elements from a string of n elements..nCr
//Their permutation is not included here

bool pal(string s)
{
    //Check for pallindrome
    for(int i=0;2*i<s.length();i++)
    {
        if(s[i]!=s[s.length()-1])
            return false;
    }
    return true;
}

vector<string> palList;

bool compare(string &s1,string &s2) 
{ 
    return s1.size() > s2.size(); 
} 

//K here shows the element to be included or not
void sub(string ans,string s,int k)
{
    //Base Condition
    if(k==s.length())
    {
        //Check if pallindrome
        if(pal(ans))
        {
            //cout<<ans<<endl;
            palList.push_back(ans);
            sort(palList.begin(), palList.end(), compare);
            cout<<palList[0]<<endl;
        }
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
    string s="abccbk";
    string ans="";
    
    sub(ans,s,0);
}