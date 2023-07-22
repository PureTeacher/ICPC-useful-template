// Jamhus Tao / GreatLiangpi
// Start at 2022/10/6
// Please using int32_t and int64_t to replace the int and long long.
#include <bits/stdc++.h>
#define int int64_t
#define endl '\n'
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

const int MOD = 1000000007;
int quick_pow(int base, int exponent, int modulo) {
    int res = 1;
    while (exponent) {
        if (exponent & 1)
            res = res * base % modulo;
        base = base * base % modulo;
        exponent >>= 1;
    }
    return res;
}

// 欧拉函数. 求区间 [1, x] 中与 x 互质的数的个数. 复杂度: O(logx) -> O(x^0.5).
int euler(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++)
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

// 扩展欧拉定理. 求 base ^ exponent = x (mod modulo). 复杂度: o(log(min(exponent, modulo)))
// 用于处理 exponent 很大的幂数, 如 base ^ (a ^ b) = x (mod modulo)
int exeuler(int base, int exponent, int modulo = MOD) {
    if (__gcd(base, modulo) == 1)
        return quick_pow(base, exponent % euler(modulo), modulo);
    else if (exponent < modulo)
        return quick_pow(base, exponent, modulo);
    else
        return quick_pow(base, exponent % euler(modulo) + modulo, modulo);
}
