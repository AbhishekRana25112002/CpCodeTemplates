#include <bits/stdc++.h>
using namespace std;

vector<int> computeLPS(string& pattern) {
    int n = pattern.length();
    vector<int> lps(n, 0);
    
    int len = 0;
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> kmpSearch(string& text, string& pattern) {
    vector<int> result;
    int m = pattern.length();
    int n = text.length();
    vector<int> lps = computeLPS(pattern);

    int i = 0; // Index for text
    int j = 0; // Index for pattern

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            // Pattern found at index i-j
            result.push_back(i - j);
            j = lps[j - 1];
        } else if (i < n && pattern[j] != text[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    string text = "ABABDABACDABABCABAB";
    string pattern = "AB";

    vector<int> result = kmpSearch(text, pattern);

    if (!result.empty()) {
        cout << "Pattern found at indices:";
        for (int index : result) {
            cout << " " << index;
        }
        cout << std::endl;
    } else {
        cout << "Pattern not found in the text." << endl;
    }

    return 0;
}
