#include<bits/stdc++.h>
using namespace std;


bool solve(vector<int>a,vector<int>b, stack<int>visited,int i,int j,vector<string>&ans)
{
    cout<<i<<" "<<j<<" "<<visited.size()<<" "<<a.size()<<endl;
   
    if(visited.size()==a.size() && j==b.size())  return 1;

    //INVLAID KA BHI SOCHO
    if(i==a.size() && j!=b.size())    return 0;

    if(j==b.size())
    {
        return 1;
    }

    if(visited.find(i)!=visited.end())      solve(a,b,visited,i-1,j,ans);

    //agar matching hai then simply 2 options
    if(a[i]==b[j])
    {
        vector<string>newans=ans;
        newans.push_back("o_"+to_string(a[i]));
        ans.push_back("p_"+to_string(a[i]));

        vector<int>newa=a;
        newa.erase(a.begin()+i);
        set<int>newvisited=visited;
        newvisited.insert(i);
        return solve(newa,b,newvisited,i,j+1,newans) || solve(a,b,visited,i+1,j,ans);
    }

    //ELSE MOVE ON
    else
    {
        ans.push_back("p_"+to_string(a[i]));
        return solve(a,b,visited,i+1,j,ans);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    //HANDLING THE INPUTS 
    int n;
    cin>>n;
    vector<int>push_seq(n,0);
    vector<int>pop_seq(n,0);
    for(int i=0;i<n;i++)
        cin>>push_seq[i];
    
    for(int i=0;i<n;i++)
        cin>>pop_seq[i];
    
    int i=0,j=0;
    vector<string>ans;
    stack<int>visited;

    if(!solve(push_seq,pop_seq,visited,i,j, ans))
        cout<<"Invalid input";
    
    else
    {
        for(auto it:ans)
            cout<<it<<",";
        cout<<endl;
    }

    return 0;
}

/*
4
1 1 2 3
2 1 3 1*/