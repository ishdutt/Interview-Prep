#include<bits/stdc++.h>
using namespace std;

int main()
{
    int start=238;
    int n=3;
    for(int i=start;i<=9999;i++)
    {
        if(i%3==0 || i%5==0)
        {
            if(i%15!=0)
            {
                n--;
            }
            if(n==0)
            {
                cout<<i<<endl;
                return 0;
            }
                
        }
    }
    return -1;
}