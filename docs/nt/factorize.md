---
documentation_of: //lib/nt/factorize.hpp
---

# 整数論ライブラリ (素因数分解・素数判定)

素数判定、素因数分解、約数列挙、オイラーの $\phi$ 関数などを提供するライブラリです。
内部的にモンゴメリ乗算を用いた Miller-Rabin 素数判定法と、Pollard's rho アルゴリズムを使用しており、$O(N^{1/4})$ ベースで高速に動作します。

## 提供する関数

### `is_prime(ll n)`
`n` が素数かどうかを判定します。
- **計算量:** $O(\log N)$
- 内部仕様: 64bit整数の範囲で確定的に判定するため、底として特定の素数の集合を用いています。

### `factorize(ll n)`
`n` を素因数分解し、`(素因数, 指数)` のペアの配列を素因数の昇順にソートして返します。
- **計算量:** 期待値 $O(N^{1/4})$
- $n \le 1$ の場合は空の配列を返します。

### `divisors(ll n)`
`n` のすべての約数を昇順に列挙して返します。
- **計算量:** 期待値 $O(N^{1/4} + D \log D)$ （$D$ は約数の個数）
- 内部で `factorize` を呼び出し、得られた素因数からDFS的に約数を構築してソートします。

### `phi(ll n)`
オイラーの $\phi$ 関数（$n$ と互いに素な $1$ 以上 $n$ 以下の整数の個数）の値を返します。
- **計算量:** 期待値 $O(N^{1/4})$

## 参考文献
- [https://andantesoft.hatenablog.com/entry/2025/05/21/164352](https://andantesoft.hatenablog.com/entry/2025/05/21/164352)
- [https://judge.yosupo.jp/submission/189742](https://judge.yosupo.jp/submission/189742)