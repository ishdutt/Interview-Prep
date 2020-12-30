#include<bits/stdc++.h>
using namespace std;


//HERE BEST APPROACH IS TO SOLVE THE NUMBERS BY TAKING AS STRING AND CHECKING WHICH IS GREATER

//THIS IS HOW WE CHECK TOO.. COMBINE THE TWO NUMBER USUALY WITH CONFLICT AND CHECK WHICH IS GREATER
int main()
{
    vector<long long int> a = {  54, 546 ,548 ,60};
    sort(a.begin(),a.end(),[&](int a,int b){
        
        string AB = to_string(a)+to_string(b);
        string BA = to_string(b)+to_string(a);
        
        //NO NEED TO CONVERT BACK TO STRING TO CHECK WHICH IS BIG, CAN BE SIMPLY DONE USING STRING TOO
        return AB>BA;
        
    });

    for(int i=0;i<a.size();i++)
        cout<<a[i];
    cout<<endl;

}