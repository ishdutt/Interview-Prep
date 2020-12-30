#include<bits/stdc++.h>
using namespace std;
//O(nlog(n)) complexity 

vector<int>parent(100001,0);
vector<int>sizeosSet(100001,0);
set<pair<int,int>>leaders;

int find_parent(int x)
{
	if(parent[x]==x)	return x;

	else	return parent[x]=find_parent(parent[x]);
}

void union_set(int x,int y)
{
	int fpx=find_parent(x);
	int fpy=find_parent(y);
	if(fpx==fpy)	return;

	else
	{
        //INSERT AND REMOVE THE PAIR OF SIZEOFSET AND THE  LEADER
		leaders.erase(make_pair(sizeosSet[fpx],fpx));
		leaders.erase(make_pair(sizeosSet[fpy],fpy));
		if(sizeosSet[fpx]<sizeosSet[fpy])
			swap(fpx,fpy);
		parent[fpy]=fpx;
		sizeosSet[fpx]+=sizeosSet[fpy];
		leaders.insert(make_pair(sizeosSet[fpx],fpx));
	}
}	

int main()
{
	int n,q;
	cin>>n>>q;

	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		leaders.insert(make_pair(1,i));
		sizeosSet[i]=1;
	}
	for(int i=0;i<q;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		union_set(x,y);
        //PRINT MAX AND MIN DIFF FROM THE SET
		auto maxi=(leaders.end());
		maxi--;
		auto mini=leaders.begin();
		cout<< ((*maxi).first)-((*mini).first)<<endl;
	}
	
}