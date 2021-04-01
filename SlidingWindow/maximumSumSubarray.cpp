#include<bits/stdc++.h>
using namespace std;

//SUBARRAY WITH MAX SUM GIVEN LENTH OF SUBARRAY

int main()
{
    vector<int>a={1,5,4,7,3,79,9,7,3,10};
    int k=3;

    //BRUTE FORCE       => O(N*N)
    int ans=0;
    // for(int i=0;i<a.size()-3;i++)
    // {
    //     int temp=0;
    //     for(int j=0;j<3&&i+j<a.size();j++)
    //         temp+=a[i+j];
    //     ans=max(temp,ans);
    // }
    int temp=0;
    // for(int i=0;i<a.size();i++)
    // {

    //     if(i<k)
    //         temp+=a[i];
    //     else
    //     {
    //         temp=temp-a[i-k]+a[i];
    //     }
    //     ans=max(ans,temp);
    // }

    int i=0,j=0;
    while(j<a.size())
    {
        if(j<k)
            temp+=a[j++];
        else
            temp=temp-a[i++]+a[j++];
        ans=max(ans,temp);
    }
    
    cout<<ans<<endl;
}