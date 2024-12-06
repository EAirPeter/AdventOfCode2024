#include <cstdio>
#include <ranges>

constexpr int N = 130;

char A[N][N + 1];
bool V[N][N];

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
    for (int i = sx, j = sy, dx = -1, dy = 0; 0 <= i && i < N && 0 <= j && j < N; i += dx, j += dy)
    {
        if (!V[i][j])
        {
            ++Ans;
            V[i][j] = true;
        }
        int px = i + dx;
        int py = j + dy;
        if (0 <= px && px < N && 0 <= py && py < N && A[px][py] == '#')
        {
            int odx = dx;
            dx = dy;
            dy = -odx;
        }
    }
    std::printf("%d\n", Ans);
}
