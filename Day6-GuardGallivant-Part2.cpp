#include <cstdio>
#include <ranges>

constexpr int N = 130;

char A[N][N + 1];
bool V[N][N][4];

int main()
{
    std::freopen("Day6-GuardGallivant.txt", "r", stdin);
    for (char* R : A | std::views::take(N))
        std::scanf("%s", R);
    int sx = 0, sy = 0;
    for (int i : std::views::iota(0, N))
        for (int j : std::views::iota(0, N))
            if (A[i][j] == '^')
            {
                sx = i;
                sy = j;
            }
    int Ans = 0;
    for (int x : std::views::iota(0, N))
        for (int y : std::views::iota(0, N))
        {
            if (A[x][y] != '.')
                continue;
            int dx[4]{-1,0,1,0};
            int dy[4]{0,1,0,-1};
            memset(V, 0, sizeof(V));
            A[x][y] = '#';
            for (int i = sx, j = sy, k = 0; 0 <= i && i < N && 0 <= j && j < N; i += dx[k], j += dy[k])
            {
                if (V[i][j][k])
                {
                    ++Ans;
                    goto JEnd;
                }
                V[i][j][k] = true;
                int px = i + dx[k];
                int py = j + dy[k];
                while (0 <= px && px < N && 0 <= py && py < N && A[px][py] == '#')
                {
                    k = 3 & (k + 1);
                    if (V[i][j][k])
                    {
                        ++Ans;
                        goto JEnd;
                    }
                    V[i][j][k] = true;
                    px = i + dx[k];
                    py = j + dy[k];
                }
            }
        JEnd:
            A[x][y] = '.';
        }
    std::printf("%d\n", Ans);
}
