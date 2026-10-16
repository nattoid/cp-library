#pragma once
#include <vector>
#include "../math/comb.hpp"

// given  : y(x=0) , y(x=1) , ... , y(k)
// return : y(x)
// time   : O(N)
template <typename mint>
mint lagrange_interpolation(const std::vector<mint>& y, long long x,
                            Comb<mint>& C) {
  int N = (int)y.size() - 1;
  if (x <= N) return y[x];
  mint ret = 0;
  std::vector<mint> dp(N + 1, 1), pd(N + 1, 1);
  mint a = x, one = 1;
  for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;
  for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a += one;
  for (int i = 0; i <= N; i++) {
    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);
    ret += ((N - i) & 1) ? -tmp : tmp;
  }
  return ret;
}

// given  : (x_0, y_0), ..., (x_{N-1}, y_{N-1})
// return : y(eval_x)
// time   : O(N^2)
template <typename mint>
mint lagrange_interpolation_arbitrary(const std::vector<mint>& x, const std::vector<mint>& y, mint eval_x) {
    int n = x.size();
    mint res = 0;
    for (int i = 0; i < n; i++) {
        mint num = 1, den = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            num *= (eval_x - x[j]);
            den *= (x[i] - x[j]);
        }
        res += y[i] * num * den.inv();
    }
    return res;
}