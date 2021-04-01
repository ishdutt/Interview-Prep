Problems: https://leetcode.com/problems/reconstruct-itinerary/

class Solution {
public:
    vector<string>ans;
    map<string,priority_queue<string,vector<string>,greater<string>>>adj;
    void dfs(string src)
    {
        //KYUNKI ANS UNIQUE HOGA TOH ATMAX TICKET SIZE KE BARABAR HONA CHAHIYE
        if(adj.empty())    return ;

        //REMOVING ALL THE NODES AND HENCE ENSURING ALL THE EDGES ARE VISITED AND NOT VIVITED TWICE
        while(!adj[src].empty())
        {
            string temp=adj[src].top();
            cout<<"TEST="<<src<<" "<<temp<<endl;

            adj[src].pop();
            dfs(temp);
        }
        ans.push_back(src);
        
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
                
        for(int i=0;i<tickets.size();i++)
            adj[tickets[i][0]].push(tickets[i][1]);
        
        string src="JFK";
        
        dfs(src);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};