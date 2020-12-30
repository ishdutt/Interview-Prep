#include<bits/stdc++.h>
using namespace std;

/*                                                      DIJIKSTRA'S ALGORITHM WEIGHTED GRAPH KE LIYE MAINLY
    TIME COMPLEXITY IS O(E+ VlogV) WORSE THAN O(E+V) FOR BFS
    1. 

*/
int dijikstra(vector<pair<int,int>>graph[],int n,vector<bool>&visited,int source,int destination)
{   
    vector<int>dis(n,INT_MAX);
    dis[source]=0;
    visited[source]=0;
    cout<<"TEST"<<endl;
    //DISTANCE IS FIRST............SECOND IS NODE
    //HEAP SO THAT I CAN GET THE MINIMUM DISTANCE AND WE CAN SELECT THAT NODE TO MARK IT VISITED
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> >>pq;
    pq.push(make_pair(dis[source],source));
    while (!pq.empty())
    {
        //NOTE: THE HEAP WILL HAVE MULTIPLE NODE'S ENTRY.... WHICH ARE UPDATED WITH DISTANCE...SINCE WE ARE NOT REMOVING THOSE 
        //  ENTRY..BUT IT WILL NOT HARM ANYTHING...AND THE FINAL DISTANCE MATRIX WILL CONTAIN THE MIN VALUE ONLY!!!
        //cout<<pq.top().second<<" "<<pq.top().first<<endl;
        int u=pq.top().second;
        visited[u]=true;
        pq.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            //SELECT THE NODE WHICH IS ADJACENT TO u
            int v=graph[u][i].first;
            
            int distance=graph[u][i].second;
            //CHECK IF IT IS VISITED OR NOT AND DIS[V]>DIS[U]+GRAPH[U][V]
            if(visited[v]!=true && dis[v]>distance+dis[u])
            {
                dis[v]=distance+dis[u];
                
                pq.push(make_pair(dis[v],v));
            }
                
        }
    }
    cout<<"Distance"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<dis[i]<<endl;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>graph[n];
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
    }
    int source,desitination;
    cin>>source>>desitination;
    vector<bool>visited(n,false);
    dijikstra(graph,n,visited,source,desitination);
}

/* 
   1------4
  / \      \
 0---3------5
  \        /
   2-------
*/
