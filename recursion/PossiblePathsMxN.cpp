#include<bits/stdc++.h>
using namespace std;

//Error
int combin(int n,int r)
{
    //If r==1 Then nc0=1 and when n=r then 1
    if(r==0|| n==r)
        return 1;
    else
    {
        //+ Means Or condition
        return combin(n-1,r)+combin(n-1,r-1);
    }
    
}

int main()
{
    //2x2 matrix is just upto 1,1 so k and l should be subtracted by one 
    //In maths:numbering from 1 but in programming from 0. 

    int k=3;
    int l=3;
    cout<<combin(l+k,l)<<"\n";
}