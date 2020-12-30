#include<bits/stdc++.h>
using namespace std;

int flag=0;

//IN DIRECTED GRAPH...USE TOPOLOGICAL SORT.. AND MANTAIN A COUNT VARIABLE... INCREMENT IT...IF NOT EQUAL TO
//  N THEN CYCLE HAI USME

long long int cnt=0;
vector<int>order;
 
//TOPOLOGICAL SORT:
//1. CALCULATE INDEGREE... JISKA 0 INDEGREE HAI INSERT IT long long intO QUEUE
//2. JO TOP PE ELEMENT HAI..USKE ADJACENT EDGES KE INDEGREE KO -- KARO...AGAR ZERO HO TOH INSERT IT BACK long long intO QUEUE
//3. REPEAT TILL QUEUE IS EMPTY
void topological(vector<long long int>graph[],long long int n,vector<long long int>&indegree)
{
    set<long long int>s;
    for(long long int i=0;i<n;i++)
        if(indegree[i]==0)
            s.insert(i);
    //cout<<"TEST="<<s.size()<<endl;
    
    while (!s.empty())
    {
        long long int top=*(s.begin());
        s.erase(s.begin());
        // cout<<top+1<<" ";
        order.push_back(top+1);
        cnt++;
        for(long long int i=0;i<graph[top].size();i++)
        {
            indegree[graph[top][i]]--;
            //cout<<graph[top][i]<<" "<<indegree[graph[top][i]]<<endl;
            if(indegree[graph[top][i]]==0)
            {
                //cout<<"YO\n";
                s.insert(graph[top][i]);
            }       
        }
    }
    //cout<<endl;
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
    
    //dfs(graph,visited,0,stackcontent);

    topological(graph,n,indegree);
    if(cnt!=n)  cout<<"Sandro fails."<<endl;
    else
    {
        for(int i=0;i<order.size();i++)
            cout<<order[i]<<" ";

        cout<<endl;
    }
}