#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> array = { 16, 17, 4, 3, 5, 2};
    int k=3;
    cout<<"MOSHI\n";
    int i=0;
    // for(int i=0;i<array.size();i+k)
    while(i<array.size())
    {
        reverse(array.begin()+i,array.begin()+i+k);
        i=i+k;
    }
        
    cout<<"MOSHI\n";

    for(int i=0;i<array.size();i++)
        cout<<array[i]<<" ";
    cout<<endl;
}