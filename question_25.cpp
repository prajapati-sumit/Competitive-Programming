/* *
 * Starter file for:  *
 *   W22, Final Exam, Question 25 *
 * *
 * Do not try to submit this file to the autograder!  *
 * Upload it to Gradescope: *
 *   [W22] Final Question 25  *
 *  *
 * Before uploading, as you "browse" for the file, check the last modified time!  *
 * It should be when you last saved the file.  *
 * Make sure you are uploading a file named question_25.cpp *
 */

// DO NOT MODIFY ANYTHING ABOVE THIS LINE!

// You may use whatever you want, we just added some standard includes
// that might be useful for any question.  If you want to use something
// else, make sure to #include it.
// Additional includes do not add to your line count.
#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;


// question 25
int maxUpgrade(const vector<vector<int>> &a, int M) {
    int N = a.size();
    int ans = 0;
    int dp[M + 1][N][N];
    const int INF = 1e9;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            dp[0][i][j] = a[i][j];
    for (int m = 1; m <= M; m++)
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) {
                dp[m][i][j] = max({
                    dp[m - 1][i][j],
                    a[i][j],
                    a[i][j] + (i > 0 ? dp[m - 1][i - 1][j] : -INF),
                    a[i][j] + (j > 0 ? dp[m - 1][i][j - 1] : -INF)
                });
                ans = max(ans, dp[m][i][j]);
            }
    return ans;

} // maxUpgrade()

int main() {
    int n, M;
    cin >> n >> M;
    vector<vector<int>>a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    cout << maxUpgrade(a, M);
    return 0;
}