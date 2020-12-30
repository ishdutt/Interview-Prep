#include<bits/stdc++.h>
     
using namespace std;
     
int main() 
{
 
    int A[] = {1,2,3,4};
    int k =2;
    for(int i=0;i<4-k+1;i++)
    {
        unordered_set<int> s(A+i,A+i+k);
        cout<<s.size()<<endl;
    }

	return 0;
}