#include<bits/stdc++.h>
using namespace std;

int l, r;
int combin(int n,int r)
{   
    //cout<<n<<" "<<r<<endl;
    //If r==1 Then nc0=1 and when n=r then 1
    if(r==0|| n==r)
    {
        cout<<"Moshi Moshi\n";
        return 1;
    }
        
    else
    {
        //'+' means Or condition
         l = combin(n-1,r)+combin(n-1,r-1);
         //r = combin(n-1,r-1);
        //return combin(n-1,r)+combin(n-1,r-1);
        return l;
    }
    
}

int main()
{
    int n=7;
    int r=4;
    cout<<combin(n,r)<<"\n";
}