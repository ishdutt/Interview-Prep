#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll t;
    cin>>t;
    while (t--)
    {
        ll n,c;
        cin>>n>>c;
        vector<int>a(n,0);

        for(int i=0;i<n;i++)
            cin>>a[i];
        
        //SORT THE ARRAY
        sort(a.begin(),a.end());

        //FOR EACH ELEMENT FIND THE ELEMENT WHICH SATISFIES THE MAX DIF
        //WE TEND TO MOVE TO THE SIDE WHERE DISTANCE IS MAX SO THAT WE MANTAIN A MAX OF MIN DIFFERENCE
        vector<int>poscow;
        poscow.push_back(a[0]);
        poscow.push_back(a[n-1]);

        for(int i=2;i<c;i++)
        {
            int low=0;
            int high=n-1;
            while (low<=high)
            {
                int mid=low+(high-low)/2
                if(a[mid])
            }
            
        }

    }
    
}