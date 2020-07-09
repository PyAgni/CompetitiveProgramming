#include <iostream> 
using namespace std; 
  
// Recursive function to find the number of times 
// the second string occurs in the first string, 
// whether continuous or discontinuous 
int count(string a, string b) 
{ 
    int m = a.length(); 
    int n = b.length(); 
  
    // Create a table to store results of sub-problems 
    int lookup[m + 1][n + 1] = { { 0 } }; 
  
    // If first string is empty 
    for (int i = 0; i <= n; ++i) 
        lookup[0][i] = 0; 
  
    // If second string is empty 
    for (int i = 0; i <= m; ++i) 
        lookup[i][0] = 1; 
  
    // Fill lookup[][] in bottom up manner 
    for (int i = 1; i <= m; i++) 
    { 
        for (int j = 1; j <= n; j++) 
        { 
            // If last characters are same, we have two  
            // options - 
            // 1. consider last characters of both strings 
            //    in solution 
            // 2. ignore last character of first string 
            if (a[i - 1] == b[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1] +  
                               lookup[i - 1][j]; 
                  
            else
                // If last character are different, ignore 
                // last character of first string 
                lookup[i][j] = lookup[i - 1][j]; 
        } 
    } 
  
    return lookup[m][n]; 
} 
  
// Driver code 
int main() 
{ 
    #ifndef ONLINE_JUDGE
    freopen("/home/agni/Documents/CP/input", "r", stdin);
    freopen("/home/agni/Documents/CP/output", "w", stdout);
    #endif

    string a = "codeforceses"; 
    string b = "codeforces"; 
  
    cout << count(a, b) << endl; 
    // cout<<1;
  
    return 0; 
} 