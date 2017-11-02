// **********************************************
// 
// Author: Michael Geng
// Class: CS 3610
// Project 1
// Due: 9/12/17
// Submitted: 9/11/17
// Description: Create a program that can use The 
// Sieve of Eratosthenes algorithm to find prime
// numbers within a given range. Enter all inputs 
// from the command line. Integer inputs only.
//
// ***********************************************


#include<iostream>
#include<istream>
#include<cmath>
#include<iomanip>
#include<string>
#include<cstdlib>

using namespace std;

bool is_int(const string str);	// Tests the input for type 
void Sieve_of_Eratosthenes(int sieve);

int main(int argc, char *argv[])
{
	int n;	// Number to count to

	if(argc < 2)	// Tests if input is given
	{
		cout << "Missing Argument." << endl;
		return 0;
	}

	if(!is_int(argv[1]))	// Tests if input is integer
	{
		cout << "Nan."<< endl;
		return 0;
	}

	n = atoi(argv[1]);	// Converts input to integer

	if(n > 30000 || n < 2)	// Tests if input is within the required range
	{
		cout << "Out of Range. " << endl;
		return 0;
	}

	Sieve_of_Eratosthenes(n);	// The Sieve of Eratosthenes algorithm
}

// --------------- Function implementations ----------------


/* This function tests if the given input is a string. 
It will go through each character in the given string and
if each character is an integer and nothing else then it 
will return true.*/
bool is_int(const string str)
{
	string::const_iterator it = str.begin();
	while(it != str.end() && isdigit(*it)) ++it;
	return !str.empty() && it == str.end();
}

// This is the Sieve of Eratosthenes algorithm used to find 
// the prime numbers up to a given number.
void Sieve_of_Eratosthenes(int sieve)
{
	int stopping_point;		// Will be used to indicate when to halt the algorithm
	int prime_count = 0;	// Tally prime numbers in set
	int composite_count = 0;	// Tally composite numbers in set
	bool data[sieve + 1];	// Boolean array to mark prime numbers

	stopping_point = abs(sqrt(sieve));	// Equation to determine stopping point
	data[0] = false;	// Set 0 and 1 as not prime (special cases)
	data[1] = false;

	for(int i = 2; i <= sieve; ++i)
	{
		data[i] = true;	// Mark all numbers as prime -> Composite numbers will  
	}					// have mark removed.

	/* This for loop will stop at each prime number before the 
	stopping_point and divide the remaining numbers by it. If 
	any of the following numbers are divisible by the number we 
	are looking at then they will be removed from the list as they 
	are divisible by more than 1 and itself and therefore composite.*/
	for(int k = 2; k <= stopping_point; ++k)	
	{
		if(data[k] == true)	// Prime number check
		{
			for(int g = k + 1; g <= sieve; ++g)	// Divides all following numbers testing for divisability 
			{
				if(g % k == 0)	// If g is divisible by k, mark as composite
				{
					data[g] = false;
				}
			}
		}
	}

	/* This for loop goes through the boolean array. It tallies 
	the number of true(prime) places and false(composite) 
	places. */
	for(int m = 2; m <= sieve; ++m)
	{
		if(data[m] == true)
		{
			++prime_count;
		}
		else
		{
			++composite_count;
		}
	}

	int prime[prime_count + 1];	// Creates an array to store prime numbers
	int composite[composite_count + 1]; // Creates an array to store composite numbers
	int track_p = 0;	// Tracks placement for each input in prime array
	int track_c = 0;	// Tracks placement for each input in composite array

	/* This for loop loads different numbers into the arrays 
	that they best fit(prime or composite). */
	for(int b = 2; b <= sieve; ++b)
	{
		if(data[b] == true)	
		{
			prime[track_p] = b;	
			++track_p;	
		}
		else
		{
			composite[track_c] = b;
			++track_c;
		}
	}
	
	cout << "Prime: ";	// Labels prime output to user
	/* This for loop outputs all of the values in the 
	prime array. */
	for(int p = 0; p < track_p; ++p)
	{
		cout << prime[p] << " ";
	}

	cout << endl  << "Composite: ";	// Labels the composite output to user
	/* This for loop outputs all of the values in the 
	composite array. */
	for(int c = 0; c < track_c; ++c)
	{
		cout << composite[c] << " ";
	}

	cout << endl;	// Inserted for formatting	
}
