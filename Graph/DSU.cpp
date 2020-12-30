#include<bits/stdc++.h>
using namespace std;

//DSU FORMATION(UNION)... THEN FINDING LEADER..FINDING COMPONENTS

vector<int>p(1000,0);
//FOR STORING THE SIZE OF THE SUBTREE(OR GROUP)
vector<int>size(1000,0);
//FOR STROING THE rankOfnode OF EACH SET
vector<int>rankOfnode(1000,0);


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
        //NORMAL IMPLEMENTATION...BUT THIS WILL LEAD TO SCEWED TREE...SO OPTIMISE IT USING 
        // p[fpx]=fpy;

        //union by size:   THE GROUP WHICH HAS GREATER SIZE WILL HAVE THE LEADER..
        if (size[fpx] < size[fpy])
            swap(fpx, fpy);
        p[fpy] = fpx;
        size[fpx] += size[fpy];

        //2. APPROACH FOR OPTIMISAITON: UNION BY rankOfnode OPTIMISATION BASED ON DEPTH OF THE TREE
        // if (rankOfnode[fpx] < rankOfnode[fpy])
        //     swap(fpx, fpy);
        // p[fpy] = fpx;

        // if(rankOfnode[fpx]==rankOfnode[fpy])
        //     rankOfnode[fpx] ++;
    }   
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>a[n];
    //make the parent array(or leader array)
    for(int i=0;i<n;i++)
    {
        p[i]=i;
        size[i] = 1;
        rankOfnode[i]=0;
    }
    //INPUT
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        union_group(x,y);
    }
    //FOR NUMBER OF CONNECTED COMPONENTS.. XXXXXXXXXX JUST PRINT THE UNIQUE VALUES IN PARENT VECTOR XXXXXXXXXX
    // FOR THIS.. YOU HAVE TO PRINT THE LEADERS OF THE GROUP... SINCE THERE WILL BE CASES WHEN THE 2 TREES ARE MERGEED BUT
    // THEIR CHILD STILL POINTS TO THE OLD LEADER SO IT WILL GIVE FALSE VALUE...
    //INSTEAD COUNT THE TOTAL LEADERS IN THE PARENT SET(I.E WHERE PARENT[I]==I).. JITNE LEADER HONGE UTNE HI TOTAL CONNECTED COMPONENTS

    //THIS METHOD IS HELPFUL FOR QUERY BASED PROBLEMS ON TREE

    //WHEN TO FIND THE CYCLE ... IF THE PARENT OF BOTH THE NODES ARE SAME...THEN THERE IS CYCLE IN THE GRAPH
}