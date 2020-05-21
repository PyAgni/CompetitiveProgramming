// C++ program to count divisors in array multiplication. 
#include <bits/stdc++.h> 
using namespace std; 


void SieveOfEratosthenes(int largest, vector<int> &prime) 
{ 
	// Create a boolean array "isPrime[0..n]" and initialize 
	// all entries it as true. A value in isPrime[i] will 
	// finally be false if i is Not a isPrime, else true. 
	bool isPrime[largest+1]; 
	memset(isPrime, true, sizeof(isPrime)); 

	for (int p=2; p*p<=largest; p++) 
	{ 
		// If isPrime[p] is not changed, then it is a isPrime 
		if (isPrime[p] == true) 
		{ 
			// Update all multiples of p 
			for (int i=p*2; i<=largest; i += p) 
				isPrime[i] = false; 
		} 
	} 

	// Print all isPrime numbers 
	for (int p=2; p<=largest; p++) 
		if (isPrime[p]) 
			prime.push_back(p); 
} 

// Returns number of divisors in array 
// multiplication 
int countDivisorsMult(vector<int> arr, int n) 
{ 
	// Find all prime numbers smaller than 
	// the largest element. 
	int largest = *max_element(arr.begin(), arr.end()); 
	vector<int> prime; 
	SieveOfEratosthenes(largest, prime); 

	// Find counts of occurrences of each prime 
	// factor 
	unordered_map<int, int> mp; 
	for (int i=0; i<n; i++) 
	{ 
		for (int j=0; j<prime.size(); j++) 
		{ 
			while(arr[i] > 1 && arr[i]%prime[j] ==0 ) 
			{ 
				arr[i] /= prime[j]; 
				mp[prime[j]]++; 
			} 
		} 
		if (arr[i] != 1) 
			mp[arr[i]]++; 
	} 

	// Compute count of all divisors using counts 
	// prime factors. 
	long long int res = 1; 
	for (auto it : mp) 
	res *= (it.second + 1L); 

	return res; 
} 

// Driver code 
int main() 
{ 
	vector<int> v(3);
	v[0]=1000;
	v[1]=1000;
	v[2]=999; 
	// int n = sizeof(arr) / sizeof(arr[0]); 
	cout << countDivisorsMult(v, 3) << endl; 
	return 0; 
} 
