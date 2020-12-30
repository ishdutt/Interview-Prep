#include<bits/stdc++.h>
using namespace std;


void dfs(vector<vector<char>>& grid, pair<int,int>source,set<pair<int,int>>&visited)
    {
        queue<pair<int,int>>q;
        q.push(source);
        while(!q.empty())
        {
            //see the 4 directions x+1,y
            int x=q.front().first;
            int y=q.front().second;
            cout<<"Main TEST="<<x<<" "<<y<<endl;
            int dimx=grid.size();
            int dimy=grid[0].size();

            //PUSHING AND CHECKING FOR ALL THE CONNECTED NODES(4 DIRECTIONS)
            if(x+1<dimx && visited.find(make_pair(x+1,y))==visited.end() && grid[x+1][y]=='1')
            {
                cout<<"TEST="<<x+1<<" "<<y<<endl;
                q.push(make_pair(x+1,y));
                visited.insert(make_pair(x+1,y));
            }
            
            if(y+1<dimy && visited.find(make_pair(x,y+1))==visited.end() && grid[x][y+1]=='1')
            {
                cout<<"TEST "<<x<<" "<<y+1<<endl;
                q.push(make_pair(x,y+1));
                visited.insert(make_pair(x,y+1));
            }
            
            if(x-1>=0 && visited.find(make_pair(x-1,y))==visited.end() && grid[x-1][y]=='1')
            {
                cout<<"TEST="<<x-1<<" "<<y<<endl;
                 q.push(make_pair(x-1,y));
                visited.insert(make_pair(x-1,y));
            }
            
            if(y-1>=0 && visited.find(make_pair(x,y-1))==visited.end() && grid[x][y-1]=='1')
            {
                cout<<"TEST="<<x<<" "<<y-1<<endl;
                 q.push(make_pair(x,y-1));
                visited.insert(make_pair(x,y-1));
            }
            q.pop();
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        //bfs
        
        set<pair<int,int>>visited;
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                pair<int,int>point=make_pair(i,j);
                
                if(visited.find(point)==visited.end() && grid[i][j]=='1')
                {
                    cout<<"ITER="<<i<<" "<<j<<endl;
                    dfs(grid,point,visited);
                    ans++;
                }
                
            }
        }
        return ans;
    }

int main()
{
    //adjacentcy list 
    vector<vector<char>>graph={
        {'1','1','0'}
        ,{'1','0','1'}
    };

    //MANTAINED SO THAT THE SAME NODE IS NOT VISITED TWICE
    unordered_set<int>visited;
    //dfs(graph,visited,0);

    numIslands(graph);

}