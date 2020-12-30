#include<bits/stdc++.h>
using namespace std;

// MORE LIKE KNIGTH TOUR PROBLEM
bool isValid(vector<vector<int>>&maze,int i,int j)
{
    return i>=0 && j>=0 && i<maze.size() && j<maze[0].size() && maze[i][j]==1;
}

int mazeSolver(vector<vector<int>>&maze,bool visited[4][4],int i,int j,int x,int y)
{   
    //CHECK IF THE POINT WE REACHED IS VALID OR NOT
    if(!isValid(maze,i,j))
    {
        return 0;
    }

    if(visited[i][j]!=0)return 0;

    if(i==x && j==y)return 1;

    visited[i][j]=true;

    if(mazeSolver(maze,visited,i,j+1,x,y))return 1;
    if(mazeSolver(maze,visited,i+1,j,x,y))return 1;

    //BACkTRACK;
    visited[i][j]=false;
    return 0;
}

int main()
{
    vector<vector<int>> maze={
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1},
    };

    bool visited[4][4]={0};

    //Final DEstination is 3,3 initial is 0,0
    int ans = mazeSolver(maze,visited,0,0,3,3);

    if(ans==0)
        cout<<"PATH NOT POSSIBLE\n";
    else
    {
        visited[3][3]=true;
        cout<<"PATH EXISTS\n";  
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
                cout<<visited[i][j]<<" ";
            }
            
            cout<<"\n";
        }
    }
         
}