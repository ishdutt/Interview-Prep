#include<bits/stdc++.h>
using namespace std;
typedef long long      ll;

bool isvalid(pair<int,int>point)
{
    // if(point.second<8 && point.second>=0 && point.first>=0 &&point.first<8) return true;

    return point.second<8 && point.second>=0 && point.first>=0 &&point.first<8;

    //else    false;
}

int bfs(pair<int,int>s,pair<int,int>d)
{
    queue<pair<pair<int,int>,int>>q;
    set<pair<int,int>>visited;
    q.push(make_pair(s,0));

    while (!q.empty())
    {
        // 8 directions of adjacent nodes
        //directions=

        int curx=q.front().first.first;
        int cury=q.front().first.second;
        //cout<<curx<<" "<<cury<<" "<<q.front().second<<" check="<<isvalid(make_pair(curx,cury))<<endl;

        if(curx==d.first && cury==d.second)
        {
            return q.front().second;
        }

        vector<int>nextx={2,2,-2,-2,1,1,-1,-1};
        vector<int>nexty={-1,1,1,-1,2,-2,2,-2};

        for(int i=0;i<8;i++)
        {

            if(isvalid(make_pair(curx+nextx[i],cury+nexty[i])) && 
            visited.find(make_pair(curx+nextx[i],cury+nexty[i]))==visited.end())
            {
                q.push(make_pair(make_pair(curx+nextx[i],cury+nexty[i]),q.front().second+1));
                visited.insert(make_pair(curx+nextx[i],cury+nexty[i]));
            }
        }
        q.pop();
    }
}


int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while (t--)
    {
        string source,destination;
        cin>>source>>destination;

        map<char,int>link;
        link.insert(make_pair('a',1));
        link.insert(make_pair('b',2));
        link.insert(make_pair('c',3));
        link.insert(make_pair('d',4));
        link.insert(make_pair('e',5));
        link.insert(make_pair('f',6));
        link.insert(make_pair('g',7));
        link.insert(make_pair('h',8));

        pair<int,int>s;

        s.first=link[source[0]]-1;
        s.second=int(source[1])-49;
        
        pair<int,int>d;
        d.first=link[destination[0]]-1;
        d.second=int(destination[1])-49;

        //cout<<"TEST="<<s.first<<" "<<s.second<<" d="<<d.first<<" "<<d.second<<endl;
        cout<<bfs(s,d)<<endl;
    }
    return 0;
}