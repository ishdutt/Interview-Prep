/*
The idea is to fix first and last bits and then recur for remaining 2*(n-1) bits. There are four possibilities when we fix first and last bits –

    1.First and last bits are 1, remaining n – 1 bits on both sides should also have the same sum.
    2.First and last bits are 0, remaining n – 1 bits on both sides should also have the same sum.
    3.First bit is 1 and last bit is 0, sum of remaining n – 1 bits on left side should be 1 less than the sum n-1 bits on right side.
    4.First bit is 0 and last bit is 1, sum of remaining n – 1 bits on left side should be 1 more than the sum n-1 bits on right side.

*/


#include <bits/stdc++.h> 
using namespace std; 

// diff --> difference between sums of first n bits 
// and last n bits 
// out --> output array 
// l --> starting index 
// r --> ending index 
void findAllSequences(int diff, char out[], int l, int r) 
{ 
	// We can't cover difference of more than n with 2n bits 
    //So taking those parameters only and coming up with end case using those parameters 
	if (abs(diff) > (r - l + 1) / 2) 
		return; 

	// if all bits are filled 
	if (l > r) 
	{ 
		// if sum of first n bits and last n bits are same 
		if (diff == 0) 
			cout << out << " "; 
		return; 
	} 

	// fill first bit as 0 and last bit as 1 
	out[l] = '0', out[r] = '1'; 
	findAllSequences(diff + 1, out, l + 1, r - 1); 

	// fill first and last bits as 1 
	out[l] = out[r] = '1'; 
	findAllSequences(diff, out, l + 1, r - 1); 

	// fill first and last bits as 0 
	out[l] = out[r] = '0'; 
	findAllSequences(diff, out, l + 1, r - 1); 

	// fill first bit as 1 and last bit as 0 
	out[l] = '1', out[r] = '0'; 
	findAllSequences(diff - 1, out, l + 1, r - 1); 
} 

// Driver program 
int main() 
{ 
	// input number 
	int n = 2; 
	// allocate string contaning 2*n characters 
	char out[2 * n + 1]; 
	// null terminate output array 
	//out[2 * n] = '\0'; 
	findAllSequences(0, out, 0, 2*n - 1); 
} 
