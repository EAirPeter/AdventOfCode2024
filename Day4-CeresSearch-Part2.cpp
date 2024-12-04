#include <cstdio>
#include <cstring>

constexpr int N = 140;
char A[N][N + 1];

int main()
{
    std::freopen("Day4-CeresSearch.txt", "r", stdin);
    for (int i = 0; i < N; ++i)
        std::scanf("%s", A[i]);
    char V[4];
    int Ans = 0;
    for (int i = 1; i < N - 1; ++i)
        for (int j = 1; j < N - 1; ++j)
            if (A[i][j] == 'A')
            {
                V[0] = A[i - 1][j - 1];
                V[1] = A[i - 1][j + 1];
                V[2] = A[i + 1][j + 1];
                V[3] = A[i + 1][j - 1];
                if (!memcmp(V, "MMSS", 4))
                    ++Ans;
                if (!memcmp(V, "MSSM", 4))
                    ++Ans;
                if (!memcmp(V, "SSMM", 4))
                    ++Ans;
                if (!memcmp(V, "SMMS", 4))
                    ++Ans;
            }
    printf("%d\n", Ans);
}
