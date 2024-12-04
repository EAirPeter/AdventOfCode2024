#include <cstdio>
#include <cstring>

constexpr int N = 140;
char A[N + 6][N + 6];

int main()
{
    std::freopen("Day4-CeresSearch.txt", "r", stdin);
    for (int i = 0; i < N; ++i)
        std::scanf("%s", A[i + 3] + 3);
    char V[4];
    int Ans = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int x = -1; x <= 1; ++x)
                for (int y = -1; y <= 1; ++y)
                {
                    for (int k = 0; k < 4; ++k)
                        V[k] = A[3 + i + x * k][3 + j + y * k];
                    if (!memcmp(V, "XMAS", 4))
                        ++Ans;
                }
    printf("%d\n", Ans);
}
