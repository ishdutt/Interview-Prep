#include<bits/stdc++.h>
using namespace std;

//                                          VVIMP!!!!!

//APPROACH IS : THE WATER AT ANY BLOCK IS EQUAL TO THE MIN(LEFT MAX , RIGHT MAX) - HEIGHT OF THAT BLOCK
// THIS IS CALCULATED FOR EVERY BLOCK.. CHECK THE SCENARIO YOU WILL GET THE FORMULA

//1.BRUTE FORCE: USING ONE LOOP FOR TRAVERSING EACH BLOCK AND THEN FOR EACH BLOCK, CALCULATE THE
//              LEFT MAX AND RIGHT MAX RELATIVE TO THAT ELEMENT.

//2. THE RIGHT AND LEFT MAX ELEMENT CAN BE STORED IN AN ARRAY OR A HASHMAP 

int main()
{
    vector<int> block={ 6 ,9 ,9};
    map<int,pair<int,int>> m;
    // Key will  contain right max and left max values;

    //for left max element calculation
    int leftmax = INT_MIN;
    for(int i=0;i<block.size();i++)
    {
        leftmax = max(leftmax,block[i]);
        m[block[i]].first = leftmax;
    }
        
    int rightmax = INT_MIN;
    for(int i=block.size()-1;i>=0;i--)
    {
        rightmax = max(rightmax,block[i]);
        m[block[i]].second = rightmax;
    }
    
    int water = 0;
    for(int i=0;i<block.size();i++)
    {
        water+= min(m[block[i]].second,m[block[i]].first)-block[i];
    }
    cout<< water<<endl;
}