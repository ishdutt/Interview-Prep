#include<bits/stdc++.h>
using namespace std;

//                  TITLE: LARGEST SUBARRAY WITH SUM K
//                  GET A SUBARRAY(CONTINOUS) WHICH HAS A SUM OF K

//FIXME: FAIL IN VARIOUS TESTCASE
int main()
{
    vector<int> a={ 100,0,-2, 3, 1, 10,20 };
    int n=a.size();
    //BRUTE FORCE O(n*n*n)
    //O(n*n for getting all the list of subarray's)
    //MAP will store sum of 0 to ith element
    //key will store the sum and index is stored as value
    unordered_map<int,int> m;    
    int longest = 0;
    int cum = 0;
    int k = 1;
    //IDEA: the sum till 0-x and 0-y is same then the sum between y-x must be zero(here K instead of 0)

    //In this way only the longest will be stored in all the keys since find works on keys only
    // So key = sum of highest order and since the sum is from 0 we just have to subtract 0 from the highest 
    // found index with same sum
    for(int i=0;i<n;i++)
    {
        //Hashmap will store the highest key for that sum and then search for it's conjugate 
        //if found then length longest will be max(longest,i-pos(of conjugate))
        //THis sum can be calculated in a separate loop also :) 
        cum+=a[i];
        //FOr handling base case When first element is also included and sum is equal to the K 
        // in that case longest =  i+1
        if(cum -k ==0)
            longest=i+1;
        
        if(m.find(cum - k)!=m.end())
            longest = max(longest , i - m.find(cum-k)->second );
        else
            m[cum]=i;
    }

    cout<<"the answer is "<<longest<<endl;
    
}
