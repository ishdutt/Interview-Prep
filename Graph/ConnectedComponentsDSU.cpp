#include<bits/stdc++.h>
using namespace std;

vector<int>parent(100001,0);
vector<int>sizeosSet(100001,0);

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
		if(sizeosSet[fpx]<sizeosSet[fpy])
			swap(fpx,fpy);
		parent[fpy]=fpx;
		sizeosSet[fpx]+=sizeosSet[fpy];
	}
}	

int main()
{
	int n,m;
	cin>>n>>m;

	for(int i=0;i<n;i++)
	{
		parent[i]=i;
		sizeosSet[i]=1;
	}
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		x--,y--;
		union_set(x,y);
	}
	
    //1. APPRAOCH-> MOST IMPORTANT.. MAKING THE ELEMENTS POINT TO THEIR ABSOLUTE PARENT AND THEN COUNT THE NUMBER  OF DISTINCT 
    //  ELEMENTS IN PARENT ARRAY

    //2. APPROACH: SIMPLY COUNT THE LEADER OF THE SETS(WHERE PARENT[I]==I) WHICH IS EASIER TO COUNT.

    //3. APPROACH: FOR COUNTING THE FREQUENCY OF THE SET OF EACH CONNCETED COMPONENT-> DON'T NEED TO USE THE 1ST APPROACH(MAKING)
    //             MAKING THEM POINT TO THEIR ABSOLUTE PARENT.. SINXE IT WILL INCRESE THE COMPLEXITY OF THE OVERALL CODE.
    //             INSTEAD MAKE USE OF THE SIZE ARRAY ;) IT SHOWS THE SIZE OF THAT SET IN WHICH THE LEADER IS THAT ELEMENT AND 
    //             AND IS INDEPENDENT OF CHANGE IN THE PARENT(SINCE IT IS ALSO MODIFIED AT THE SAME TIME)
	for(int i=0;i<n;i++)
	{
		int p=parent[i];
		//HERE PARENT'S PARENT MIGHT POINT TO A DIFFERENT PARENT WHICH IS NOT ABSOLUTE PARENT..
		//SO USE FIND_PARENT TO FIND THE ABSOLUTE PARENT OF THE PARENT OF THAT NODE 
        //AND MAKE IT POINT TO THAT NODE
		int absparent=find_parent(p);
		if(parent[i]!=absparent)	parent[i]=absparent;	
	}

	set<int>s(parent.begin(),parent.begin()+n);
	cout<<s.size()<<endl;
	//cout<<count<<endl;
}