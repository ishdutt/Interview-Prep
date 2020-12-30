#include <bits/stdc++.h> 
using namespace std; 

//curExp = Current expression string
//input = input string
//taget= target value
//pos = position till which input is processed.(pointer to the location)
//curVal= Current evaluated value from the curExp. Needed to compare with target.
//last = last value in evaluation (It is taken so that things can work ni scenario like for Multiplication)
//SInce 1+2*5 will be 3-2+2*5(2 will not be added to 1)

void expression( string curExp, string input, int target, int pos, int curVal, int last) 
{ 
    
	//TErmintaion case when pos is at the
	if (pos == input.length()) 
	{ 
		// if current value is equal to target 
		//then only add to final solution 
		// if question is : all possible o/p then just 
		//push_back without condition 
		if (curVal == target) 
			cout<<curExp<<endl; 
		return; 
	} 

	// loop to put operator at all positions and Expression can have multiple lenght instead of just 1
	for (int i = pos; i < input.length(); i++) 
	{ 
        cout<<"The pos value is "<<pos<<" I is "<<i<<endl;
		// ignoring case which start with 0 as they 
		// are useless for evaluation 
		if (input[pos] == '0') 
			break; 

		// take part of input from pos to i 
        //Substr creates a substring from pos of length i+1-pos(Min lenght =1)
		string part = input.substr(pos, i + 1 - pos); 

		// take numeric value of part 
		int cur = stoi(part); 

		// if pos is 0 then just send numeric value and CurrentExpression for the first element
		// for next recurion 
		if (pos == 0) 
			expression( curExp + part, input, target, i + 1, cur, cur); 

		// try all given binary operator for evaluation 
		else
		{ 
            //Generate 3 branches for each operator
			expression( curExp + "+" + part, input, target, i + 1, curVal + cur, cur); 
			expression( curExp + "-" + part, input, target, i + 1, curVal - cur, -cur); 
			expression( curExp + "*" + part, input, target, i + 1, curVal - last + last * cur, last * cur); 
		} 
	} 
} 


int main() 
{ 
	string input = "123"; 
	int target = 6; 
	expression( "", input, target, 0, 0, 0);
} 
