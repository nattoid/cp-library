# Formal Power Series (形式的冪級数) ライブラリ

`std::vector<mint>` を継承し、形式的冪級数 $F(x) = \sum_{i=0}^{\infty} c_i x^i$ に関する各種演算を提供する。

## インクルードの使い分け

対象とする法（Mod）によって、インクルードするヘッダファイルを切り替える。

- **法が `998244353` などの NTT-friendly な素数の場合:**
  ```cpp
  #include "ntt-friendly-fps.hpp"
  ```
  内部でin-place NTTを利用し、高速に動作する。

- **法が `1000000007` などの任意Modの場合:**
  ```cpp
  #include "arbitrary-fps.hpp"
  ```
  内部で3つの素数を用いたGarnerのアルゴリズム（Arbitrary NTT）を利用する。定数倍は重いが動作する。

## 初期化・基本的な使い方

コンストラクタは `std::vector` のものをすべて引き継ぐ。

```cpp
using mint = atcoder::modint998244353;
using fps = FormalPowerSeries<mint>;

fps f = {1, 2, 3}; // 1 + 2x + 3x^2
fps g(10, 0);      // 0次から9次まで全て0
```

## 基本演算 (formal-power-series.hpp)

- `f + g`, `f - g`: $O(N)$
- `f * g`: $O(N \log N)$
- `f / g`: $O(N \log N)$
- `f % g`: $O(N \log N)$
- `f.pre(d)`: 次数を $d$ 未満に打ち切った（$d$ 項の）FPSを返す。$\pmod{x^d}$ に相当。
- `f.rev()`: 係数を反転したFPSを返す。
- `f.diff()`: 微分 $F'(x)$ を返す。$O(N)$
- `f.integral()`: 積分 $\int F(x) dx$ を返す（定数項は0）。$O(N)$
- `f.eval(x)`: $F(x)$ を評価する。$O(N)$

## 高度な演算

以下は基本的に $O(N \log N)$ で動作する（任意Modの場合は定数倍が掛かる）。引数 `deg` を省略した場合、元のFPSのサイズが適用される。

- `f.inv(deg)`: $F(x)^{-1} \pmod{x^{deg}}$ を返す。$c_0 \neq 0$ が必要。
- `f.log(deg)`: $\log F(x) \pmod{x^{deg}}$ を返す。$c_0 = 1$ が必要。
- `f.exp(deg)`: $\exp F(x) \pmod{x^{deg}}$ を返す。$c_0 = 0$ が必要。
- `f.pow(k, deg)`: $F(x)^k \pmod{x^{deg}}$ を返す。

## 拡張機能

必要に応じて各ヘッダを追加でインクルードする。

### 平方根 (fps-sqrt.hpp)
- `sqrt(f, deg)`: $F(x)^{1/2} \pmod{x^{deg}}$ を返す。$c_0$ の平方根が存在しない場合は空のFPSを返す。$O(N \log N)$

### 多項式累乗剰余 (mod-pow.hpp)
- `mod_pow(k, base, d)`: $base(x)^k \pmod{d(x)}$ を返す。ダブリングにより計算。

### 三角関数 (fps-circular.hpp)
- `circular(fre, fim, deg)`: 複素係数のFPSに関する微分方程式の解。実部と虚部のペアを返す。

### 疎な多項式に対する演算 (sparse-fps.hpp)
$G(x)$ の非ゼロ項の数を $K$ とする。NTTが使えない状況や、$K$ が非常に小さい場合に高速。
- `sparse_div(f, g, deg)`: $F(x) / G(x)$ を $O(N K)$ で計算。
- `sparse_inv(f, deg)`: $O(N K)$
- `sparse_log(f, deg)`: $O(N K)$
- `sparse_exp(f, deg)`: $O(N K)$
- `sparse_pow(f, k, deg)`: $O(N K)$

### テイラーシフト (taylor-shift.hpp)
- `TaylorShift(f, a, C)`: $F(x+a)$ を計算して返す。事前に `Comb<mint> C;` を用意しておくこと。$O(N \log N)$

### ラグランジュ補間 (lagrange-interpolation-point.hpp)
- `lagrange_interpolation(y, x, C)`: $y(0), y(1), \dots, y(N)$ の値を持つ配列 `y` が与えられたとき、$N$ 次以下の多項式 $y(x)$ の値を評価して返す。事前に `Comb<mint> C;` を用意しておくこと。$O(N)$