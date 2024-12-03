#include <algorithm>
#include <cstdio>
#include <cstdlib>

constexpr int N = 1000;
long long A[N];
long long B[N];

int main()
{
    std::freopen("Day1-HistorianHysteria.txt", "r", stdin);
    for (int i = 0; i < N; ++i)
        std::scanf("%lld%lld", &A[i], &B[i]);
    std::sort(A, A + N);
    std::sort(B, B + N);
    long long Ans = 0;
    for (int i = 0; i < N; ++i)
        Ans += std::abs(A[i] - B[i]);
    std::printf("%lld\n", Ans);
}
