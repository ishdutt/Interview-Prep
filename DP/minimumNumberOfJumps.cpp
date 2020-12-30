#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	//code
	ll t;
	cin>>t;
	while(t--)
	{
	    ll n;
	    cin>>n;
	    vector<ll>a(n,0);
	    for(ll i=0;i<n;i++)
	        cin>>a[i];
	   
	    ll current_jump=a[0];
	   
	    ll count=0;
        ll position=0;
        if(a[0]==0)
        {
            cout<<"-1\n";
            continue;
        }
	    while(position<n)
	    {
            
	        count++;
	        ll nextjump=INT_MIN;
	        ll nextindex=0;

            position+=current_jump;
            cout<<"TEST Position="<<position;
	        for(ll j=0;j<=current_jump;j++)
	        {
	            if(nextjump<a[position+j])
	            {
	                nextjump=a[j];
	                nextindex=j;
	            }
	        }
	        cout<<" "<<nextjump<<"\n";
	        current_jump=nextjump;
            if(position+nextjump>=n-1)
            {
                count++;
                break;
            }
                
            
            position++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}