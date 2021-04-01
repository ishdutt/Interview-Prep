#include<bits/stdc++.h>
using namespace std;

class trie{
    public:
    bool end;
    unordered_map<char,trie*>mp;
    
    trie()
    {
        end=false;
    }
};
//FOR CREATING DYNAIMC SIZE NODES( NOT LIKE ARRAY) HENCE USING POINTER TO TRIE NODE
//FOR OBJECT CREATION "NEW" IS USED
trie *root=new trie();
void insert(string s)
{
    trie *cur=root;
    for(auto ch:s)
    {
        if(cur->mp[ch]==NULL) 
            cur->mp[ch]=new trie();
        cur=cur->mp[ch];
    }
    cur->end=true;
}

void traverse()
{
    trie *cur=root;
    while(cur!=NULL)
    {
        for(auto m:cur->mp)
        {
            cout<<m.first<<endl;
            cur=cur->mp;
        }
            
    }
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string>s;
        for(int i=0;i<words.size();i++)
            insert(words[i]);
        
        traverse();

        return  s; 
    }
};

int main()
{
    vector<vector<char>>board={{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};

    vector<string>words={"oath","pea","eat","rain"};

    Solution s;

    vector<string>ans=s.findWords(board,words);

    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
    cout<<endl;

}