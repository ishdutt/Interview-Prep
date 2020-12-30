#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int k,n;
	    cin>>k>>n;
	    vector<int>a;
	    for(int i=0;i<n;i++)
	    {
	        int temp;
	        cin>>temp;
	        a.push_back(temp);
	        if(a.size()<k)
	        {
	            cout<<"-1"<<" ";
	            continue;
	        }
	            
	       priority_queue<int,vector<int>,greater<int>>pq(a.begin(),a.end());
	       
	       int counter=a.size()-k;
	       int ans=0;
	       while(counter--)
	       {
                pq.pop();
	       }
	       cout<<pq.top()<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}