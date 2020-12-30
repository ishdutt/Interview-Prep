#include<bits/stdc++.h>
using namespace std;

int rev(int ans,int n)
{
    //Extra 10 is mupltiplied even tough number is acheived
    if(n==0)
        return ans/10;
    else
    {
        rev((ans+n%10)*10,n/10);
    }
    
}

int main()
{
    int n=1251;
    int ans=0;
    if(n==rev(ans,n))
        cout<<"Pallindromic Number\n";
    else
    {
        cout<<"Non Pallindromic number\n";
    }
    
}