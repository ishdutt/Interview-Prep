class Solution {
public:
    bool out(int i,int j,vector<vector<char>>& b)
    {
        if(i>=0 && j>=0 && i<b.size() && j<b[i].size()) return true;
        
        return false;
    }
    bool dfs(vector<vector<char>>& b, string word,int i,int j,int it)
    {
        
        if(it==word.size()) return true;
        if(!out(i,j,b))  return false;
        //cout<<"MOS"<<word[it]<<" "<<b[i][j]<<endl;
        
        if(b[i][j]==word[it]) 
        {
            cout<<word[it]<<endl;
            b[i][j]='*';
            if(dfs(b,word,i+1,j,it+1))  return true;
            if(dfs(b,word,i,j+1,it+1))  return true;
            if(dfs(b,word,i-1,j,it+1))  return true;
            if(dfs(b,word,i,j-1,it+1))  return true;
            b[i][j]=word[it];
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& b, string word) {
        
        for(int i=0;i<b.size();i++)
        {
            for(int j=0;j<b[i].size();j++)
            {
                if(b[i][j]==word[0])
                {
                    //cout<<"Xo" << i<<" "<<j<<endl;
                    if(dfs(b,word,i,j,0))
                        return true;
                }
            }
        }
        return false;
    }
};