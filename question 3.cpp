#include <iostream>
#include <vector>
using namespace std;



int longestSubstrDitinctChars(string str) {
	int n = str.length();
	int res = 0;
	for (int i = 0; i < n; i++) {
		vector<int> charType(256);
		for (int j = i; j < n; j++) {
			if (charType[str[j]] == true) // break the inner loop if cur char is visited
				break;
			else {
				res = max(res, j - i + 1);
				charType[str[j]] = true;
			}
		}
		charType[str[i]] = true;
	}
	return res;
}


int main() {
	string S = "geeksforgeeks";
	cout << longestSubstrDitinctChars(S);
	return 0;
}