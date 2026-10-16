#pragma once

template <typename T>
void superset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] += f[j | i];
      }
    }
  }
}

template <typename T>
void superset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j] -= f[j | i];
      }
    }
  }
}

template <typename T>
void subset_zeta_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] += f[j];
      }
    }
  }
}

template <typename T>
void subset_mobius_transform(vector<T>& f) {
  int n = f.size();
  assert((n & (n - 1)) == 0);
  for (int i = 1; i < n; i <<= 1) {
    for (int j = 0; j < n; j++) {
      if ((j & i) == 0) {
        f[j | i] -= f[j];
      }
    }
  }
}

template <typename T>
void multiple_zeta_transform(std::vector<T>& f, const std::vector<int>& primes) {
    int n = f.size() - 1;
    for (int p : primes) {
        for (int i = n / p; i >= 1; --i) {
            f[i] += f[i * p];
        }
    }
}

template <typename T>
void multiple_mobius_transform(std::vector<T>& f, const std::vector<int>& primes) {
    int n = f.size() - 1;
    for (int p : primes) {
        for (int i = 1; i * p <= n; ++i) {
            f[i] -= f[i * p];
        }
    }
}

template <typename T>
void divisor_zeta_transform(std::vector<T>& f, const std::vector<int>& primes) {
    int n = f.size() - 1;
    for (int p : primes) {
        for (int i = 1; i * p <= n; ++i) {
            f[i * p] += f[i];
        }
    }
}

template <typename T>
void divisor_mobius_transform(std::vector<T>& f, const std::vector<int>& primes) {
    int n = f.size() - 1;
    for (int p : primes) {
        for (int i = n / p; i >= 1; --i) {
            f[i * p] -= f[i];
        }
    }
}

/**
 * @brief Zeta Transform / Moebius Transform
 */