#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>graph,unordered_set<int>&visited,int currentnode)
{
    //cout<<"MOSHI\n";
    if(visited.size()==graph.size())    return;

    visited.insert(currentnode);
    cout<<currentnode<<endl;
    
    for(int i=0;i<graph[currentnode].size();i++)
    {
        //cout<<"TEST="<<graph[currentnode][i]<<endl;
        //VISIT THAT NODE WHICH IS CONNECTED TO THE CURRENTNODE
        if(visited.find(graph[currentnode][i])==visited.end())
        {
            dfs(graph,visited,graph[currentnode][i]);
        }
    }
}

void bfs(vector<vector<int>>graph,unordered_set<int>&visited,int currentnode)
{
    queue<int>q;
    q.push(currentnode);
    visited.insert(0);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        
        for(int i=0;i<graph[q.front()].size();i++)
        {
            if(visited.find(graph[q.front()][i])==visited.end())
            {
                q.push(graph[q.front()][i]);
                visited.insert(graph[q.front()][i]);
            }   
        }
        q.pop();
    }
    cout<<endl;
}

//FOR UNDIRECTED GRAPH: YOU WILL HAVE TO ADD THE CONJUGATE NODE TO THE GRAPH AS WELL...IT WON'T BE GIVEN AS EDGE PAIR IN GRAPH
//I.E (I,J) => (J,I)

//FOR DIRECTED... NO ISSUES...JUST ADD THE EDGE PAIR IN THE ADJACENTCY LIST

//FOREST TREES AND GRAPH DIFFERENCE: https://www.quora.com/What-is-the-difference-between-a-tree-and-a-forest-in-graph-theory?top_ans=5430863

int main()
{
    //adjacentcy list 
    vector<vector<int>>graph={{1,2,3},{3,4},{5},{0,1,5},{1,5},{4,5}};

    //MANTAINED SO THAT THE SAME NODE IS NOT VISITED TWICE
    unordered_set<int>visited;
    //dfs(graph,visited,0);

    bfs(graph,visited,0);

}

/* 
   1------4
  / \      \
 0---3------5
  \        /
   2-------
*/