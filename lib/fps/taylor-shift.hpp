#pragma once
#include "./formal-power-series.hpp"
#include "../math/comb.hpp"

template <typename mint>
FormalPowerSeries<mint> TaylorShift(FormalPowerSeries<mint> f, mint a,
                                    Comb<mint>& C) {
  using fps = FormalPowerSeries<mint>;
  int N = f.size();
  for (int i = 0; i < N; i++) f[i] *= C.fact(i);
  std::reverse(f.begin(), f.end());
  fps g(N, mint(1));
  for (int i = 1; i < N; i++) g[i] = g[i - 1] * a * C.inv(i);
  f = (f * g).pre(N);
  std::reverse(f.begin(), f.end());
  for (int i = 0; i < N; i++) f[i] *= C.finv(i);
  return f;
}

/**
 * @brief 平行移動
 * @docs docs/fps/fps-taylor-shift.md
 */