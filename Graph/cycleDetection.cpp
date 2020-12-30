#include<bits/stdc++.h>
using namespace std;

//APPROACH: 1.MARK THE NODES VISITED WHEN THEY REACH THE TOP OF QUEUE
//          2.IF ANY ELEMENT WHICH IS ALREADY VISITED IS FOUND AT THE TOP AGAIN.. CYCLE HAI(IN CYCLE...SAME NODE WILL BE PUSHED TO 
//             STACK TWICE)
//FOR UNDIRECTED ONLY!!!!!!!!!!!!!!!!
void BFS(vector<vector<int>>graph, unordered_set<int>&visited ,int currentnode)
{
    queue<int>q;
    q.push(currentnode);
    while (!q.empty())
    {
        if(visited.find(q.front())!=visited.end())
        {
            cout<<"Cycle hai \n";
            return ;
        }
        visited.insert(q.front());
        for(int i=0;i<graph[q.front()].size();i++)
        {
            if(visited.find(graph[q.front()][i])==visited.end())
            {

                q.push(graph[q.front()][i]);
            }
        }
        q.pop();
    }
    
}
 

//IN DFS ALSO... VIVSITED NODE WILL BE VISITED TWICE
// IF ELEMENT OCCURS IN STACK TWICE THEN THERE IS A CYCLE IN THE GRAPH...
// TO KEEP A STACK CONTENT WE WILL MANTAIN A STACK ARRAY SHOWING THE CONTENT IN PRESENT IN STACK  

//FOR UNDIRECTED GRAPH..JUST MAKE SURE THAT IF I TO J NODE EXIST.. THEN J TO I ALSO EXIST...BUT HERE.. WE ALSO NEED TO KEEP TRACK 
// OF THE PARENT...OTHERWISE I->J AND J->I KO WO EK CYCLE MAAN LEGA... SO JUST KEEP ONE PARENT AND ENSURE THAT THE CYCLE PART IS 
// NOT PARENT OF THAT NODE
void dfs(vector<vector<int>>graph, vector<int>&visited ,int currentnode,vector<bool>&stackcontent)
{
    if(stackcontent[currentnode])
    {
        cout<<"CYCLE HAI BE\n";
        return;
    }   
    visited[currentnode]=1;
    stackcontent[currentnode]=true;
    cout<<currentnode<<endl;

    for(int i=0;i<graph[currentnode].size();i++)
    {
        if(visited[graph[currentnode][i]]==0)
        {
            dfs(graph,visited,graph[currentnode][i],stackcontent);
        }
        //AGAR VISITED HAI... DUSRI BAAR BHI AANA CHAAA RHA HAI STACK ME... THEN NODE HAI..ELSE NO ;)
        else if(stackcontent[graph[currentnode][i]])
        {
            cout<<"CYCLE HAI BE\n";
            return;
        }  
    }
    // for(int i=0;i<3;i++)
    //     cout<<stackcontent[i]<<" ";
    // cout<<endl;
    stackcontent[currentnode]=false;
}


int main()
{
    //adjacentcy list 
    //vector<vector<int>>graph={{1},{2},{0}};
    vector<vector<int>>graph={{1,2,3},{},{},{}};

    //MANTAINED SO THAT THE SAME NODE IS NOT VISITED TWICE
    vector<int>visited(graph.size(),0);
    //dfs(graph,visited,0);

    //BFS(graph,visited,0);
    vector<bool>stackcontent(graph.size(),false);


    //FOR DIRECTED GRAPH AND DISCONNECTED GRAPH
    for(int i=0;i<graph.size();i++)
        if(visited[i]==0)
        {
            dfs(graph,visited,i,stackcontent);
        }
            
    cout<<"Cycle Nai Hai\n";

}

/* 
   1------4
  / \      \
 0---3------5
  \        /
   2-------
*/