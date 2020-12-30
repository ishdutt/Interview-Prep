#include<bits/stdc++.h>
using namespace std;

int toh(int n,char source,char destination,char auxilary)
{
    if(n==0)
        return 0;
    else
    {
        toh(n-1,source,auxilary,destination);
        cout<<n<<"Moved from "<<source<<" to "<<auxilary<<"\n";
        toh(n-1,auxilary,destination,source);   
    }
    
}


int main()
{
    int n;
    toh(3,'s','d','a');
}