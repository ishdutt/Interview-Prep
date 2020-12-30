#include<bits/stdc++.h>
using namespace std;

//FIXME:

bool isSafe(pair<int,int>a)
{
    return a.first>=0 && a.first<4 && a.second>=0 && a.second<4;
}

void bfs(vector<vector<int>>maze)
{
    //POINT KA PAIR AND OTHER PART DISTANCE
    queue<pair<pair<int,int>,int>>q;
    q.push(make_pair(make_pair(0,0),0));

    set<pair<pair<int,int>,pair<int,int>>>visited;
    visited.insert(make_pair(make_pair(0,0),make_pair(-1,-1)));
    while(!q.empty())
    {
        int pointx=q.front().first.first;
        int pointy=q.front().first.second;

        //cout<<"TEST="<<pointx<<" "<<pointy<<" "<<q.front().second<<" "<<maze.size()<<endl;

        if(q.front().first.first==maze.size()-1 && q.front().first.second==maze.size()-1)
        {
            cout<<"MIL GAYA RASTA \n"<<endl;
            
            while(pointx)

            return ;
        }
        int posx[]={-1,0,1,0};
        int posy[]={0,1,0,-1};

        for(int i=0;i<4;i++)
            if(isSafe(make_pair(pointx+posx[i],pointy+posy[i]))
             && visited.find(make_pair(make_pair(pointx+posx[i],pointy+posy[i]),q.front().first))==visited.end())
            {
                q.push(make_pair(make_pair(pointx+posx[i],pointy+posy[i]),q.front().second));
                visited.insert(make_pair(make_pair(pointx+posx[i],pointy+posy[i]),q.front().first));
            }
        q.pop();
    }
}

int main()
{
    vector<vector<int>>maze={ { 1, 0, 0, 0 }, 
                               { 1, 1, 0, 1 }, 
                               { 0, 1, 0, 0 }, 
                               { 1, 1, 1, 1 } 
                            };


    bfs(maze); 
}