// Sort elements by frequency. If two elements have same
// count, then put the elements that appears first
#include <bits/stdc++.h>
using namespace std;

void sortByFrequency(vector<int>a)
{
    map<int,int>m;
    int n=a.size();
    for(int i=0;i<n;i++)
        m[a[i]]++;

    priority_queue<pair<int,int>>pq;
    
    for(auto it: m)
        pq.push(it.second);
    
    for(auto )
    
}

// Driver program
int main()
{
	vector<int> arr = { 2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8 };

	sortByFrequency(arr);

	return 0;
}
