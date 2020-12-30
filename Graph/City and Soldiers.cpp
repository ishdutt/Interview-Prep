#include<bits/stdc++.h>
using namespace std;

vector<long long int>parent(100005,0);
vector<long long int>sizeofSet(100005,1);

long long int find_parent(long long int x)
{
	if(parent[x]==x)	return x;
	else
		return parent[x]=find_parent(parent[x]);	
}

void make_parent(long long int x)
{
	long long int fpx=find_parent(x);
	parent[x]=x;
	parent[fpx]=x;
	swap(sizeofSet[fpx],sizeofSet[x]);
}

void union_set(long long int x,long long int y)
{
	long long int fpx=find_parent(x);
	long long int fpy=find_parent(y);

	if(fpx==fpy)	return ;
	else
	{
		// if(sizeofSet[fpx]<sizeofSet[fpy])
		// 	swap(fpx,fpy);
		parent[fpx]=fpy;
		sizeofSet[fpy]+=sizeofSet[fpx];
	}
}
int main()
{
	long long int n,q;
	cin>>n>>q;
	for(long long int i=0;i<n;i++)
	{
		parent[i]=i;
		sizeofSet[i]=1;
	}
	while(q--)
	{
		long long int qtype,a,b;
		cin>>qtype;
		if(qtype==3)
		{
			cin>>a;
			a--;
			long long int papa=find_parent(a);
			cout<<sizeofSet[papa]<<endl;
		}
		else
		{
			if(qtype==2)
			{
				cin>>a;
				a--;
				make_parent(a);
			}
			
			else
			{
				cin>>a>>b;
				a--;
				b--;
				union_set(a,b);
			}
				
		}
		// cout<<"test"<<endl;	
		// for(long long int i=0;i<n;i++)
		// 	cout<<parent[i]<<" ";
		// cout<<endl;
	}
}