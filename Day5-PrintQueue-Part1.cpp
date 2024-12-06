#include <bitset>
#include <cstdio>
#include <fstream>

constexpr int N = 100;
constexpr int M = 1176;
constexpr int W = 191;

std::bitset<N> A[N];
int B[100];

int main()
{
    std::ifstream In("Day5-PrintQueue.txt");
    for (int i = 0; i < M; ++i)
    {
        int U, V;
        In >> U;
        In.ignore();
        In >> V;
        A[U].set(V);
    }
    int Ans = 0;
    for (int i = 0; i < W; ++i)
    {
        int K = 0;
        for (;;)
        {
            In >> B[K++];
            if (In.peek() != ',')
                break;
            In.ignore();
        }
        std::bitset<N> V;
        V.set();
        bool bGood = true;
        for (int j = 0; j < K; ++j)
        {
            if (!V.test(B[j]))
            {
                bGood = false;
                break;
            }
            V &= A[B[j]];
        }
        if (bGood)
            Ans += B[K / 2];
    }
    std::printf("%d\n", Ans);
}
