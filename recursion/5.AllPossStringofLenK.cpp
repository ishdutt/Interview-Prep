#include<bits/stdc++.h>
using namespace std;


//COmplexity is O(K**n) or [k power n]

//Here k is for fixed size while i is an iterator for selecting element from the array
int com(vector<char>s,string ans,int k,int i)
{
    if(k==ans.size())
    {
        cout<<ans<<endl;
        ans="";
    }
    else
    {
        //THis is for making available all the combinations for all the positions
        //From one node-> Multiple nodes of next outcome which can be the same number or a different number
        for(int b=0;b<s.size();b++)
        {
            ans+=s[b];
            com(s,ans,k,b);
            //If that is not selected then we have to remove it too
            ans.pop_back();
        }
        //For Visualisation:
        //Remove the loop and write the set of statements n times-> and then think..
        //THis Self calling shows that K possible scenatios whereas pop_back is to ensure that 
        //Element is removed and tried it with other characters.
        //Obviously if we manage the ans vector properly then popback sentence can be eliminated
            
    }
    
}

int main()
{
    vector<char> s={'a','b'};
    int k=3;
    string ans="";
    com(s,ans,k,0);
}