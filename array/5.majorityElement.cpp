#include<bits/stdc++.h>
using namespace std;

//FIXME:

//  BRUTE FORCE: CHECK FOR EACH NUMBER AND TRAVERSE THROUGH ALL ELEMENTS... NOW CHECK IF THEIR COUNT IS
//               GREATER THAN N/2....O(N**2)
// OPTIMISED: USE HASHMAP AND CHECK THE NUMBER WITH HIGHEST FREQUENCY AND CHECK IF IT IS GREATER THAN 
//            N/2.

// MOORE'S VOTING ALGORITHM: IDEA IS THE COUNT OF MAJORITY WILL BE GREATER THAN COUNT OF ALL THE OTHER
//                           ELEMENTS IN THE ARRAY.
//                            

int main()
{
    vector<int> a={2,2,1,1,1,2,2};
    int majelement=a[0];
    int count=1;
    for(int i=1;i<a.size();i++)
    {
        //AGAR GHATTE GHATTE WO ZERO HO GAYA TOH APAN PRESENT ELEMENT KO MAAN LENGE MAJ ELEMENT.
        
        if(a[i]==majelement)    count++;
        
        else    count--;
        
        if(count==0)
        {
            majelement=a[i];
            count=1;
        }
    }
    cout<<majelement<<endl;
}