#include <bits/stdc++.h>
using namespace std;
typedef long long      ll;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    cin>>n>>m;
    queue<pair<int,int>>q;
    unordered_set<int>visited;
    q.push(make_pair(n,0));

    while (!q.empty())
    {
        visited.insert(q.front().first);
        // if(q.front().second==5)
        // {
        //     return 0;
        // }
        //cout<<q.front().first<<" "<<q.front().second<<endl;
        if(q.front().first==m)
        {
            cout<<q.front().second<<endl;
            return 0;
        }
        if(visited.find(q.front().first-1)==visited.end() && q.front().first-1>=0 )
            q.push(make_pair(q.front().first-1,q.front().second+1));
        
        if(visited.find(q.front().first*2)==visited.end() && q.front().first*2>=0 && q.front().first*2<=3*m)
            q.push(make_pair(q.front().first*2,q.front().second+1));
        
        q.pop();
    }
    

}
    
