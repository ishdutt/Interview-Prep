#include<bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>&grid,int i,int j,int lastelement)
{
    //cout<<"TEST="<<i<<" "<<j<<" "<<grid[i][j]<<" "<<lastelement<<endl;
    //BASE CONDITION
    if(i<0 || j<0 || i>=grid.size()||j>=grid[0].size())
        return 0;

    //CHOICE DIAGRAM
    if(grid[i][j]<lastelement)
    {
        cout<<"MOSHI\n";
        return max(max(solve(grid,i-1,j,lastelement),
                        solve(grid,i+1,j,lastelement)),
                   max(solve(grid,i,j-1,lastelement),
                        solve(grid,i,j+1,lastelement)));
    }
    else
    {
        cout<<"ELSE\n";
        int left=solve(grid,i-1,j,grid[i][j])+1;
        cout<<"YO1\n";
        int right=solve(grid,i+1,j,grid[i][j])+1;
        cout<<"YO2\n";
        int up=solve(grid,i,j-1,grid[i][j])+1;
        cout<<"YO3\n";
        int down=solve(grid,i,j+1,grid[i][j])+1;
        cout<<"YO4\n";
        
        int taken= max(max(left,right),max(up,down));

        int nottaken= max(max(solve(grid,i-1,j,lastelement),
                        solve(grid,i+1,j,lastelement)),
                   max(solve(grid,i,j-1,lastelement),
                        solve(grid,i,j+1,lastelement)));
        
        return max(taken,nottaken);
    }
    
}

int main()
{
    vector<vector<int>> grid= { { 1, 2, 9 }, 
                                { 5, 3, 8 }, 
                                { 4, 6, 7 } }; 

    cout<<solve(grid,0,0,INT_MIN)<<endl;

}