#include<bits/stdc++.h>
using namespace std;


vector<int>p(1000,0);
//FOR STORING THE SIZE OF THE SUBTREE(OR GROUP)
vector<int>size(1000,0);
//FOR STROING THE rankOfnode OF EACH SET
vector<int>rankOfnode(1000,0);

int answer=0;

//FINDING THE PARENT OF THE GROUP OR SET.. 
int find_parent(int x)
{
    if(p[x]==x) return x;
    //STORING THE ABSOLUTE PARENT SO THAT OVERALL HEIGTH OF TREE IS REDUCED FOR FASTER ACCESS(DP;))
    else    p[x]=find_parent(p[x]);
}

void union_group(int x,int y)
{
    int fpx=find_parent(x);
    int fpy=find_parent(y);
    //IF THE LEADER OF BOTH THE SETS ARE EQUAL .. WE DON'T DO ANYTHING...(
    //  (HELPFUL FOR CYCLE DETECTION)...IF TRUE THEN CYCLE IS PRESENT
    if(fpx==fpy)    return;
    else
    {
        //union by size:   THE GROUP WHICH HAS GREATER SIZE WILL HAVE THE LEADER..
        if (size[fpx] < size[fpy])
            swap(fpx, fpy);
        p[fpy] = fpx;
        size[fpx] += size[fpy];
    }   
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a[n];
    //make the parent array(or leader array)
    vector<pair<int,pair<int,int>>>edges;

    for(int i=0;i<n;i++)
    {
        p[i]=i;
        size[i] = 1;
        rankOfnode[i]=0;
    }
    //INPUT
    for(int i=0;i<m;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        edges.push_back(make_pair(w,make_pair(x,y)));
    }
    //SORT THE ARRAYS based on THE WEIGHTS ;)
    sort(edges.begin(),edges.end());

    // NOW TRAVERSE ALL THE EDGES AND FORM GROUPS..IF CYCLE IS DETECTED(I.E SAME PARENT) SKIP THAT EDGE

    //STORE THE EDGES.. OR JUST THE FINAL WEIGHT OF THE SPANNING TREE
    for(int i=0;i<m;i++)
    {
        //FORMING UNION 
        int x=edges[i].second.second;
        int y=edges[i].second.first;
        if (find_parent(x)!=find_parent(y))
        {
            //cout<<"TEST="<<x<<" "<<y<<endl;
            answer+=edges[i].first;
            //STORING THE EDGES
            //result.push_back(a[i].second);
            union_group(edges[i].second.second,edges[i].second.first);
        }
        
    }
    cout<<answer<<endl;
}