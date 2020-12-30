#include<bits/stdc++.h>
using namespace std;

//THIS FUNCTION RETURNS PROFIT MAXIMISED VALUE :)

int solve(vector<int>h,int n)
{
    cout<<"MOSHI "<<n<<endl;
    if(n>=h.size()) return 0;

    else
    {
        return max(solve(h,n+1)+abs(h[n]-h[n+1]),
                    solve(h,n+2)+abs(h[n]-h[n+2]));
    }
    
}


//                                         ==CAUTION===
// BHAI COUNTER YAHA PE COUNTER VALUE START N-1 NAI PASS KARTE HAI... n PASS KARTE HAI PAGAL!!
// STANDARD YAHI HAI... ISILIYE N-1 SE ACESS KARTE HAI MAIN CODE ME... TU PASS HI N-1 KARTA HAI SAALE!!

int main()
{
    int n;
    cin>>n;
    vector<int>h(n+2,0);

    for(int i=0;i<n;i++)
        cin>>h[i];
    
    h[n]=0;
    h[n+1]=0;

    cout<<solve(h,0)<<endl;
}