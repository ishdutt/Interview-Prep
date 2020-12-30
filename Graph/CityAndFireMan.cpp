#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007;

vector<int>parent(100001,0);
vector<int>sizeVec(100001,1);

int find_parent(int x)
{
    // cout<<"TEST"<<endl;
    if(parent[x]==x)    return x;

    else
        return parent[x]=find_parent(parent[x]);
}

void union_set(int x,int y)
{
    // cout<<"UNION"<<endl;
   
    int fpx=find_parent(x);
    int fpy=find_parent(y);
    cout<<x<<" "<<fpx<<" "<<y<<" "<<fpy<<endl;
    if(fpx==fpy)    return ;

    else
    {
        if(sizeVec[fpx]<sizeVec[fpy])
            swap(fpx,fpy);

        parent[fpy]=fpx;
        sizeVec[fpx]+=sizeVec[fpy];
    }
}

int main()
{
	int n,m;
    cin>>n;
    vector<int>cost(n,0);
    for(int i=0;i<n;i++)
        cin>>cost[i];
    cin>>m;
    
    //parent matrix initialisation
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        sizeVec[i]=1;
    }
    
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        x--,y--;
        union_set(x,y);
    }
    cout<<"BEFORE KAAND"<<endl;
    for(int i=0;i<n;i++)    
        cout<<parent[i]<<" ";
    cout<<endl;
    //MAKING ALL THE PARENTS AS ABSOLUTE PARENT :/
    for(int i=0;i<n;i++)
    {
        int p=parent[i];
		int absparent=find_parent(p);

        cout<<"CHECK:"<<i<<" "<<p<<" "<<absparent<<endl;
		if(parent[i]!=absparent)	parent[i]=absparent;
        // parent[i]=find_parent(parent[i]);	
    }
    cout<<"TEST"<<endl;
    for(int i=0;i<n;i++)    
        cout<<parent[i]<<" ";
    cout<<endl;
    
    //map for parent->mincost,count;
    unordered_map<int,vector<int>>costForEachComponent;
    for(int i=0;i<n;i++)
    {
        costForEachComponent[parent[i]].push_back(cost[i]);
    }
    long long int ans=1;
    for(auto it:costForEachComponent)
    {
        int count=0;
        int minimum=*min_element(it.second.begin(),it.second.end());    
        //cout<<"TEST="<<minimum<<endl;
        for(int i=0;i<it.second.size();i++)
        {
            if(it.second[i]==minimum)  count++;
        }
        ans=ans*count%mod;
    }
    cout<<ans<<endl;
}