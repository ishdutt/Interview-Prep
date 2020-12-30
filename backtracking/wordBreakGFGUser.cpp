#include<bits/stdc++.h>
using namespace std;

void wordBreak(const string& s,int idx,const unordered_set<string>& dict,vector<string>& ans,string curr)
{
    if(idx==s.size())
    {
        ans.push_back(curr);
        return;
    }
    for(int i=idx;i<s.size();i++)
    {
        string temp=s.substr(idx,i-idx+1);
        //cout<<idx<<" "<<temp<<endl;
        if(dict.find(temp)!=dict.end())
        {
            cout<<"Ye current hai "<<curr<<endl;
            if(curr!="")
                wordBreak(s,i+1,dict,ans,curr+" "+temp);  
            else
                wordBreak(s,i+1,dict,ans,temp);
        }
    }
}


int main()
{
    string s="iloveicecreamcatsanddog";
    vector<string> words={"cat","cats","and","sand","dog","i","love","ice","cream","icecream"};

    vector<string> ans;   
    unordered_set<string> dict(words.begin(),words.end()); 

    // S = INPUT STRING, INDEX, DICTIONARY, ANSWER VECTOR, CURRENT STRING
    wordBreak(s,0,dict,ans,"");

    for(auto X: ans)
         cout<<X<<"\n";
}