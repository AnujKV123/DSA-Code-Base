// Longest Common Prefix in an Array **********************

// Given a array of N strings, find the longest common prefix among all strings present in the array.

#include<iostream>
#include<algorithm>

using namespace std;

// Function to find the longest common prefix
string longestCommonPrefix(string ar[], int n)
{

	// If size is 0, return empty string
	if (n == 0)
		return "-1";

	if (n == 1)
		return ar[0];

	// Sort the given array
	sort(ar, ar + n);

	// Find the minimum length from
	// first and last string
	int en = min(ar[0].size(), ar[n - 1].size());

	// Now the common prefix in first and
	// last string is the longest common prefix
	string first = ar[0], last = ar[n - 1];
	int i = 0;
	while (i < en && first[i] == last[i])
		i++;

	string pre = first.substr(0, i);
	if(pre.size() != 0)
        return pre;
    else
        return "-1";
}

// Driver Code
int main()
{
	string ar[] = {"abc", "abd", "abd", "abdz"};
	int n = sizeof(ar) / sizeof(ar[0]);
	cout << "The longest common prefix is: "
		<< longestCommonPrefix(ar, n);
	return 0;
}