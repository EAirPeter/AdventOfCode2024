#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <unordered_map>

constexpr int N = 1000;
long long A[N];
long long B[N];

std::unordered_map<long long, long long> M;

int main()
{
    std::freopen("Day1-HistorianHysteria.txt", "r", stdin);
    for (int i = 0; i < N; ++i)
    {
        std::scanf("%lld%lld", &A[i], &B[i]);
        ++M[B[i]];
    }
    long long Ans = 0;
    for (int i = 0; i < N; ++i)
        Ans += A[i] * M[A[i]];
    std::printf("%lld\n", Ans);
}
