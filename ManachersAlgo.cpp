#include <iostream>
#include <string>
#include <vector>
using namespace std;

string findLongestPalindrome(const string &s) {
    string modifiedString = "$#";
    for (char c : s) {
        modifiedString += c;
        modifiedString += '#';
    }
    
    int n = modifiedString.length();
    vector<int> p(n, 0); // array to store palindrome lengths
    int center = 0, right = 0; // center and right boundary of the current palindrome
    int maxLen = 0, maxCenter = 0; // max length and center of palindrome found so far
    
    for (int i = 1; i < n; ++i) {
        // Calculate mirror index j
        int j = 2 * center - i;
        
        // If current index i is within the current palindrome boundary, use its mirror value
        if (i < right) {
            p[i] = min(right - i, p[j]);
        }
        
        // Attempt to expand palindrome centered at i
        while (modifiedString[i + (1 + p[i])] == modifiedString[i - (1 + p[i])]) {
            ++p[i];
        }
        
        // If the palindrome centered at i expands past the right boundary,
        // update the center and right boundary
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        
        // Update the maximum palindrome length and its center if needed
        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }
    
    // Extract the longest palindrome substring
    int start = (maxCenter - maxLen) / 2;
    return s.substr(start, maxLen);
}

int main() {
    string s = "babad";
    string longestPalindrome = findLongestPalindrome(s);
    cout << "Longest palindromic substring: " << longestPalindrome << endl;
    return 0;
}
