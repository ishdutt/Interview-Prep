#include<bits/stdc++.h>
using namespace std;


//FIXME:
// RETURN THE PATH LENGHT TO REACH X,Y (SHORTEST)

// HAVE TO MANTAIN A VISITED ARRAY WHICH WILL ENSURE THAT WE DON'T VISTIT THE SAME PLACE TWICE
// THIS WILL ALSO BE OUR BACKTRACKING IDEA

// I,J INTIAL CO-ORDINATES AND X,Y ARE FINAL(DESTINATION) CO-ORDINATE
int path(vector<vector<int>>a,int i, int j, int x,int y,vector<vector<bool>>visited)
{
    //base condition->reaches the end of matrix 
    //IT SHOULD RETURN 100000 SINCE WE CAN'T VISIT THERE
    if(i<0 || j<0 || i>=a.size() || j>=a[0].size() || visited[i][j])
    {
        if(i>=a.size())cout<<"MOSHI\n";
        cout<<"YOYO\n";
        return 0;
    }
        
    
    //IF NUMBER AT THAT POSITION IS 0 THEN RETURN OR WHEN THAT PATH IS ALREADY VISITED  
    if(a[i][j]==0)
        return 100000;

    //TERMINATION CONDITION
    if(i==x && j==y) return 0;
    
    //MARK AS VISITED
    visited[i][j]=true;

    //NOW TAKE CARE OF THE SURROUNDING 4 BLOCKS EITHER USE RECURION OR JUST WRITE THE SENTENCES
    int left = path(a,i,j-1,x,y,visited)+1; 
    int right = path(a,i,j+1,x,y,visited)+1; 
    int up = path(a,i-1,j,x,y,visited)+1; 
    int down = path(a,i+1,j,x,y,visited)+1;    

    //BACKTRAKING IDEA
    visited[i][j]=false;

    return min(min(left,down),min(up,right));
}

int main()
{
    vector<vector<int>> a = {
                    { 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
					{ 0, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
					{ 0, 0, 1, 0, 1, 1, 1, 0, 0, 1 },
					{ 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 },
					{ 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },
					{ 1, 0, 1, 1, 1, 0, 0, 1, 1, 0 },
					{ 0, 0, 0, 0, 1, 0, 0, 1, 0, 1 },
					{ 0, 1, 1, 1, 1, 1, 1, 1, 0, 0 },
					{ 1, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
					{ 0, 0, 1, 0, 0, 1, 1, 0, 0, 1 },
    };
    
    //DEFINE FUNCTION CALL
    int i=0,j=0;
    int x=0,y=3;
    //VISITED ARRAY
    vector<vector<bool>>visited(10,vector<bool>(10,false));

    //cout<<"mohi\n";
    if(path(a,0,0,0,9,visited)> 100000)
        cout<<"No Path Exists\n";
    
    else
        cout<<path(a,0,0,0,9,visited)<<endl;    
}