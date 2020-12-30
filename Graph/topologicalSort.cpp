#include<bits/stdc++.h>
using namespace std;

void dfs(vector<long long int>graph[], vector<long long int>&visited ,long long int currentnode,vector<bool>&stackcontent)
{
    if(stackcontent[currentnode])
    {
        cout<<"Sandro fails.\n";
        return;
    }   
    visited[currentnode]=1;
    stackcontent[currentnode]=true;
    //cout<<currentnode<<endl;

    for(long long int i=0;i<graph[currentnode].size();i++)
    {
        if(visited[graph[currentnode][i]]==0)
        {
            dfs(graph,visited,graph[currentnode][i],stackcontent);
        }
        //AGAR VISITED HAI... DUSRI BAAR BHI AANA CHAAA RHA HAI STACK ME... THEN NODE HAI..ELSE NO ;)
        else if(stackcontent[graph[currentnode][i]])
        {
            cout<<"Sandro fails.\n";
            return;
        }  
    }
    // for(long long int i=0;i<3;i++)
    //     cout<<stackcontent[i]<<" ";
    // cout<<endl;
    stackcontent[currentnode]=false;
}
 
//TOPOLOGICAL SORT:
//1. CALCULATE INDEGREE... JISKA 0 INDEGREE HAI INSERT IT long long intO QUEUE
//2. JO TOP PE ELEMENT HAI..USKE ADJACENT EDGES KE INDEGREE KO -- KARO...AGAR ZERO HO TOH INSERT IT BACK long long intO QUEUE
//3. REPEAT TILL QUEUE IS EMPTY
void topological(vector<long long int>graph[],long long int n,vector<long long int>&indegree)
{
    queue<long long int>q;
    for(long long int i=0;i<n;i++)
        if(indegree[i]==0)  q.push(i);
    
    while (!q.empty())
    {
        cout<<q.front()+1<<" ";
        for(long long int i=0;i<graph[q.front()].size();i++)
        {
            indegree[graph[q.front()][i]]--;
            if(indegree[graph[q.front()][i]]==0)
                q.push(graph[q.front()][i]);
        }
        q.pop();
    }
    cout<<endl;
}

 int main()
{
    //n->NODES m VERTICES
    long long int n,m;
    cin>>n>>m;
    vector<long long int>graph[n];
    vector<long long int>indegree(n,0);
    for(long long int i=0;i<m;i++)
    {
        long long int x,y;
        cin>>x>>y;
        x--;
        y--;
        graph[x].push_back(y);
        //INDEGREE FOR EACH NODE... KONSE KONSE VERTEX USSE CONNECTED HAI..UNKI INDEGREE ++
        indegree[y]++;
    }
    vector<long long int>visited(n,0);
    vector<bool>stackcontent(n,false);
    
    dfs(graph,visited,0,stackcontent);
    
    
    topological(graph,n,indegree);
}