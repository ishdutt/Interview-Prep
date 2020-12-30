#include<bits/stdc++.h>
using namespace std;

//TODO: COMLICATED MATH RELATION BETWEEN INDEX AND MAX ELEMENT AND MIN ELEMENT.
int main()
{
    vector<int> arr= {1,2,3,4,5,6};
    sort(arr.begin(),arr.end(),[&](int a,int b){
        return b>a;        
    });

    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}