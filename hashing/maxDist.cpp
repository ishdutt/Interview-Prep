
#include<bits/stdc++.h> 
using namespace std; 
  
int maxDistance(int arr[], int n) 
{ 
    //Stores the intial position of each element
    unordered_map<int, int> mp; 
  
    // Traverse elements and find maximum distance between 
    // same occurrences with the help of map
    int max_dist = 0; 
    for (int i=0; i<n; i++) 
    { 
        // If this is first occurrence of element, insert its 
        // index in map-> Save the first occurence of element.
        if (mp.find(arr[i]) == mp.end()) 
            mp[arr[i]] = i; 
  
        // Else update max distance when the element is already in map(subtract current pos from fist occurence) 
        //arr[i] gives the same element so no fear of different element.
        else
            max_dist = max(max_dist, i - mp[arr[i]]); 
    } 
  
    return max_dist; 
} 

int main() 
{ 
    int arr[] = {3, 2, 1, 2, 1, 4, 5, 8, 6, 7, 4, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << maxDistance(arr, n); 
    return 0; 
} 
