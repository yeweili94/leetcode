
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

/// leetcode defined data types ///
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

ListNode* make_listnode(const vector<int> &v) {
  ListNode head(0), *p = &head, *cur;
  for (auto x: v) { cur = new ListNode(x); p->next = cur; p = cur; }
  return head.next;
}

constexpr long long null = numeric_limits<long long>::min();

TreeNode* make_treenode(const vector<long long> &v) {
  vector<TreeNode*> cur, next;
  TreeNode root(0); cur.push_back(&root);
  long long i = 0, n = v.size(), x;
  while (i < n) {
    for (auto p: cur) {
      if ((x = v[i++]) != null) { p->left = new TreeNode(x); next.push_back(p->left); }
      if (i == n || p == &root) continue;
      if ((x = v[i++]) != null) { p->right = new TreeNode(x); next.push_back(p->right); }
    }
    cur.swap(next); next.clear();
  }
  return root.left;
}

template<class T>
ostream& operator<<(ostream &os, const vector<T> &v) {
  os << "[";
  for (int i = 0; i < v.size(); ++i) os << (i > 0 ? "," : "") << v[i];
  os << "]";
  return os;
}

ostream& operator<<(ostream &os, const ListNode *p) {
  vector<int> v;
  while (p) { v.push_back(p->val); p = p->next; }
  return os << v;
}

ostream& operator<<(ostream &os, const TreeNode *t) {
  vector<string> v;
  queue<const TreeNode*> cur, next;
  if (t) cur.push(t);

  while (!cur.empty()) {
    t = cur.front(); cur.pop();
    v.push_back(t ? to_string(t->val) : "null");
    if (t && (t->left || t->right)) {
      next.push(t->left);
      if (t->right || !cur.empty()) next.push(t->right);
    }
    if (cur.empty()) cur.swap(next);
  }
  return os << v;
}

/*
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (28.78%)
 * Total Accepted:    200.3K
 * Total Submissions: 695.9K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       int size = word.size();
       if (size <= 0) {
           return false;
       }
       int row = board.size();
       if (row <= 0) return false;
       int col = board[0].size();
       if (col <= 0) return false;
       for (int i = 0; i < row; i++) {
           for (int j = 0; j < col; j++) {
               if (helper(board, word, 0, i, j)) {
                   return true;
               }
           }
       }
       return false;
    }
    
    bool helper(vector<vector<char>>& board, 
                const string& word, int pos, int row, int col) {
        if (pos >= word.size()) {
            return true;
        }
        if (row < 0 || col < 0
                    || row >= board.size() 
                    || col >= board[0].size()
                    || board[row][col] != word[pos]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*';
        bool ret = helper(board, word, pos + 1, row, col - 1)
                || helper(board, word, pos + 1, row, col + 1)
                || helper(board, word, pos + 1, row - 1, col)
                || helper(board, word, pos + 1, row + 1, col);
        board[row][col] = temp;
        return ret;
    }
};

int main() {
  Solution s;
  decay<vector<vector<char>>&>::type p0 = {{"A","B","C","E"},{"S","F","C","S"},{"A","D","E","E"}};
  decay<string>::type p1 = "ABCCED";
  auto res = s.exist(p0,p1);
  cout << res << endl;
  return 0;
}
