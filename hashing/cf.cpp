#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long int t;
    // map<string,long long int>m;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long int> a;

        for(long long int i=0;i<n;i++)
        {
            long long int input;
            cin>>input;
            a.push_back(input);
        }

        //LOOOP
        //MAKE ODD AS NEG AND EVEN AS +
        for(long long int i=0;i<a.size();i++)
            if(i%2!=0)
                a[i]=-a[i];

        for(long long int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
    }

    
    return 0;
}