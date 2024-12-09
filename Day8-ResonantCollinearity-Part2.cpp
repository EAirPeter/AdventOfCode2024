#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <vector>

template<class... DimTs>
constexpr auto Dims(DimTs... InDims)
{
    return std::views::cartesian_product(std::views::iota(DimTs(), InDims)...);
}

int main()
{
    auto In = std::ifstream("Day8-ResonantCollinearity.txt");
    auto A = std::vector<std::string>();
    std::ranges::copy(std::views::istream<std::string>(In), std::back_inserter(A));
    const auto N = A.size();
    const auto M = A[0].size();
    auto V = std::vector<std::vector<bool>>(N, std::vector<bool>(M, false));
    auto D = std::array<std::vector<std::tuple<int, int>>, 128>();
    for (const auto [x, y] : Dims(N, M))
        if ('.' != A[x][y])
            D[A[x][y]].emplace_back(x, y);
    for (const auto& E : D)
        for (const auto [i, j] : Dims(E.size(), E.size()))
            if (i != j)
            {
                const auto [xi, yi] = E[i];
                const auto [xj, yj] = E[j];
                const auto [dx, dy] = std::make_tuple(xj - xi, yj - yi);
                for (const auto k : std::views::iota(1))
                {
                    const auto [xk, yk] = std::make_tuple(xi + dx * k, yi + dy * k);
                    if (0 <= xk && xk < N && 0 <= yk && yk < M)
                        V[xk][yk] = true;
                    else
                        break;
                }
            }
    std::cout << std::ranges::count(V | std::views::join, true) << std::endl;
    return 0;
}
