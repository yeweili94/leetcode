
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

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int size = candidates.size();
        vector<vector<int>> ret;
        if (size <= 0) {
            return ret;
        }
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        helper(ret, candidates, temp, 0, target);
        return ret;
    }

    void helper(vector<vector<int>>& ret, const vector<int>& candidates,
                vector<int>& temp, int pos, int target) {
        if (target == 0) {
            ret.push_back(temp);
            return;
        }
        if (pos >= candidates.size() || target < 0) {
            return;
        }
        for (int i = pos; i < candidates.size(); i++) {
            if (i > pos && candidates[i] == candidates[i-1]) {
                continue;
            }
            temp.push_back(candidates[i]);
            helper(ret, candidates, temp, i + 1, target - candidates[i]);
            temp.pop_back();
        }
    }
};

int main() {
  Solution s;
  decay<vector<int>&>::type p0 = {10,1,2,7,6,1,5};
  decay<int>::type p1 = 8;
  auto res = s.combinationSum2(p0,p1);
  cout << res << endl;
  return 0;
}
