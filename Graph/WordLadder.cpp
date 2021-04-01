Problem: https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>diction(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        
        q.push(make_pair(beginWord,1));
        set<string>visited;
        visited.insert(beginWord);
        while(!q.empty())
        {
            string top=q.front().first;
            if(top==endWord)    return q.front().second;
            //ITERATOR FOR CHANGEING
            
            //cout<<"ME->"<<top<<endl;
            
            for(int i=0;i<beginWord.size();i++)
            {
                for(int j=1;j<26;j++)
                {
                    string newen=top;
                    
                    if((newen[i]+j)>int('z'))
                        newen[i]=char('a'+int(newen[i]+j-int('z')-1));
                    
                    else
                        newen[i]=char((newen[i]+j));
                    // cout<<top<<" "<<newen<<endl;
                    
                    if(visited.find(newen)==visited.end() && diction.find(newen)!=diction.end())
                    {
                        cout<<"TEST="<<top<<" "<<newen<<endl;
                        q.push(make_pair(newen,q.front().second+1));
                        visited.insert(newen);
                    }
                        
                }
            }
            q.pop();
        }
        return 0;
        
    }
};