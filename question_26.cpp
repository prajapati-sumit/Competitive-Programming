/*
 *
 * Starter file for:
  *
 *   W22, Final Exam, Question 26
 *
 *
 *
 * Do not try to submit this file to the autograder!
  *
 * Upload it to Gradescope:
 *
 *   [W22] Final Question 26
  *
 *
  *
 * Before uploading, as you "browse" for the file, check the last modified time!
  *
 * It should be when you last saved the file.
  *
 * Make sure you are uploading a file named question_26.cpp
 *
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


// DO NOT MODIFY struct Node
struct Node {
    double value;
    Node *left;
    Node *right;
    Node(double v) : value{ v }, left{ nullptr }, right{ nullptr } {}
};


// DO NOT MODIFY the deallocate() function declaration; do not code it.
extern Node *deallocate(Node *);

// HINT: Depending on how you write the code, you might need helper functions here
map<double, int>mp;
double mod;
void calc(Node* cur) {
    if (cur == nullptr)
        return;
    mp[cur->value]++;
    calc(cur->left);
    calc(cur->right);
}
Node* helper(Node* cur) {
    if (cur == nullptr || cur ->value == mod)
        return deallocate(cur);
    helper(cur->left);
    helper(cur->right);
    swap(cur->left, cur->right);
    cur->value = 1.0 / cur->value;
    return cur;
}

Node *question_26(Node *root) {
    // TODO: Write this function
    calc(root);
    int count = 0;
    for (auto &el : mp) {
        if (el.second > count) {
            count = el.second;
            mod = el.first;
        }
    }
    return helper(root);
} // question_26()