#include <iostream>
#include <vector>
using namespace std;
bool isSubsetSum(int a[], int n, int sum) {
 bool dp[n + 1][sum + 1];
 for (int i = 0; i <= n; i++)
 dp[i][0] = true;
 for (int j = 1; j <= sum; j++)
 dp[0][j] = false;
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= sum; j++) {
 if (a[i - 1] > j) 
 dp[i][j] = dp[i - 1][j];
 else
 dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
 }
 }
 if (!dp[n][sum]) {
 cout << "No subset with the given sum." << endl;
 return false;
 }
 vector<int> subset;
 int i = n, j = sum;
 while (i > 0 && j > 0) {
 if (dp[i][j] != dp[i - 1][j]) {
 subset.push_back(a[i - 1]);
 j -= a[i - 1];
 }
 i--;
 }
 cout << "Subset with the given sum: ";
 for (int x : subset) {
 cout << x << " ";
 }
 cout << endl;
 return true;
}
int main() {
 int n, sum;
 cout << "Enter the size of the array: ";
 cin >> n;
 int a[n];
 cout << "Enter the array elements: ";
 for (int i = 0; i < n; i++) {
 cin >> a[i];
 }
 cout << "Enter the target sum: ";
 cin >> sum;
 isSubsetSum(a, n, sum);
 return 0;
}
