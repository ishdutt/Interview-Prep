#include<bits/stdc++.h>
using namespace std;

//METHODS: BFS, DIJIKSTRA...ETC(TBU)
//WHY NOT DFS? SINCE IN DFS.. WE CAN END UP CHOOSING THE LONGER PATH AC TO RECURION CALLS IT IT'S NOT A GURANTEE THAT THE PATH WILL
// BE SHORTEST..BUT WE CAN DEFINATELY VISIT THAT NODE.


//HOW BFS-> WE ARE DOING LEVEL ORDER TRAVERSAL HERE.. SO WE WILL DEFINATELY GET THE SHORTEST PATH (WHICH IS THE HEIGHT OF THAT TREE)


//For a general graph, the concept of a 'level' may not be well-formed (JUST USE YOUR VISUAL IMAGINATION)
// (although you could just define it as the (shortest) distance from the source node, I suppose),
// thus a level-order traversal may not be well-defined, but a breadth-first search still makes perfect sense.


//NOTE: YE UNWEIGHTED GRAPH KE LIYE THA IDEA ;)...ONLY WITH A TRICK YOU CAN USE (YE BHI NAMUMKIN HAI ALMOST) TO USE IT IN WEIGHTED 
//GRAPH

//      MULTISOURCE BFS(IMP)    -> MAKES THE QUESTION A BIT TRICKY
int shortestpathusingBFS(vector<vector<int>>graph,vector<bool>&visited,int source,int destination)
{
    //cout<<"MOSHI\n";
    int dis=0;
    //FOR MANTAINING THE DISTANCE..EITHER KEEP A DISTANCE MATRIX FOR EACH ELEMENT OR MAKE A PAIR IN QUEUE ;)
    queue<int>q;
    vector<int>distance(graph.size(),INT_MAX);

    //SOURCE KE LIYE CONFIG
    q.push(source);
    distance[source]=0;
    visited[source]=1;

    while (!q.empty())
    {
        for(int i=0;i<graph[q.front()].size();i++)
        {
            
            if(visited[graph[q.front()][i]]==0)
            {
                //cout<<"TEST "<<q.front()<<" "<<graph[q.front()][i]<<endl;
                //q.fornt WILL BE THE PARENT FOR EACH NODE HERE ADDED
                q.push(graph[q.front()][i]);
                visited[graph[q.front()][i]]=1;
                distance[graph[q.front()][i]] = distance[q.front()]+1;
            }     
        }
        q.pop();
    }
    
    return distance[destination];
}



int main()
{
    //adjacentcy list 
    vector<vector<int>>graph={{1,2,3},{3,4},{5},{0,1,5},{1,5},{4,5}};

    //MANTAINED SO THAT THE SAME NODE IS NOT VISITED TWICE
    vector<bool>visited(graph.size(),0);
    //dfs(graph,visited,0);

    cout<<shortestpathusingBFS(graph,visited,0,0)<<endl;

}

/* 
   1------4
  / \      \
 0---3------5
  \        /
   2-------
*/