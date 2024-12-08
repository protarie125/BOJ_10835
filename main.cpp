#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = int64_t;
using vl = vector<ll>;
using vvl = vector<vl>;

ll N;
vl A, B;
vvl dp;

ll solve(ll l, ll r) {
  if (l >= N || r >= N) {
    return 0;
  }

  if (dp[l][r] < 0) {
    dp[l][r] = 0;
    if (B[r] < A[l]) {
      dp[l][r] = max(dp[l][r], solve(l, r + 1) + B[r]);
    }
    dp[l][r] = max(dp[l][r], solve(l + 1, r));
    dp[l][r] = max(dp[l][r], solve(l + 1, r + 1));
  }

  return dp[l][r];
}

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> N;
  A = vl(N);
  for (auto&& a : A) cin >> a;
  B = vl(N);
  for (auto&& b : B) cin >> b;

  dp = vvl(N, vl(N, -1));
  const auto& ans = solve(0, 0);
  cout << ans;

  return 0;
}