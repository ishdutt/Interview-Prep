#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

vector<int>adj[100005];

//NUMBER OF CONNECTED COMPONENTS->BFS APPLICATION(IMP)

void bfs(ll source, vector<ll>&visited)
{
    queue<ll>q;
    q.push(source);
    visited[source]=1;
    while (!q.empty())
    {
        for(ll i=0;i<adj[q.front()].size();i++)
        {
            //cout<<" Nodes"<<adj[q.front()][i]<<endl;
            if(visited[adj[q.front()][i]]==0)
            {
                q.push(adj[q.front()][i]);
                visited[adj[q.front()][i]]=1;
            }
        }
        q.pop();

    }
    
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    //cout<<"MOSHI"<<endl;
    while (t--)
    {
        for(ll i=0;i<100005;i++){adj[i].clear();}
        ll n,m;
        cin>>n>>m;
        
        memset(adj, 0, sizeof(adj)); 

        //ARRAY
        for(int i=0;i<m;i++)
        {
            //EDGE FROM A TO B
            ll a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // //BFS... CONNECTED COMPONENTS BASED QUESTION

        
        vector<ll>visited(n,0);
        ll count=0;
        
        for(ll i=0;i<n;i++)
        {
            //cout<<"HELLO\n";
            if(visited[i]==0)
            {
                //cout<<"Componoment="<<i<<endl;
                bfs(i,visited);
                count++;
            }
        }
        cout<<count<<endl;

        
    }
    return 0;        
}
    
