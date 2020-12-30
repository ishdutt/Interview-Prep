#include <bits/stdc++.h> 
using namespace std; 

//			VERY IMPORTANT APPROACH IN CASE OF FINDING ANY SUBARRAY WITH CERTAIN PROPERTY

int main() 
{ 
	vector<int> a = { 8, 25, 10, 19, 19, 18, 20, 11, 18 }; 
	int n = a.size(); 
	int k = 13; 

	int count = 0; 
	int maxlength = 0; 

	for (int i = 0; i < n; i++) { 
		// check if array element greater then X or not(if continous element fall in it)
		//then count will be incremented else it will be set to 0 again
		if (a[i] > k) { 
			count += 1; 
		} 
		//if the continous part is not greater then make the count 0 and store the max length
		else { 
			maxlength = max(maxlength, count); 
			count = 0; 
		} 
	} 

	// After iteration complete 
	// check for the last segment 
	if (count) 
		maxlength = max(maxlength, count); 

	cout<<maxlength<<endl;
} 
