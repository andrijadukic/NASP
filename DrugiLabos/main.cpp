#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned int uint;

void trace(const uint N, const uint M, const uint *const cost, std::vector<std::pair<uint, uint>> &solution) {
    uint i = N - 1;
    uint j = M - 1;
    while (i > 0 && j > 0) {
        solution.emplace_back(i, j);
        if (cost[i * M + j - 1] < cost[(i - 1) * M + j]) {
            j--;
        } else {
            i--;
        }
    }
    if (i == 0) {
        while (j != 0) {
            solution.emplace_back(0, j--);
        }
    } else {
        while (i != 0) {
            solution.emplace_back(i--, 0);
        }
    }
    solution.emplace_back(0, 0);
    std::reverse(solution.begin(), solution.end());
}

uint solve(const uint N, const uint M, const uint16_t *const problem, std::vector<std::pair<uint, uint>> &solution) {
    uint i, j, curr, row, prev_row;
    uint *cost = new uint[N * M];

    cost[0] = problem[0];
    for (j = 1; j < M; j++) {
        cost[j] = problem[j] + cost[j - 1];
    }
    for (i = 1; i < N; i++) {
        row = i * M;
        prev_row = row - M;
        cost[row] = problem[row] + cost[prev_row];
        for (j = 1; j < M; j++) {
            curr = row + j;
            cost[curr] = problem[curr] + std::min(cost[curr - 1], cost[prev_row + j]);
        }
    }

    trace(N, M, cost, solution);

    uint min_cost = cost[N * M - 1];
    delete[] cost;
    return min_cost;
}

int main() {
    const uint16_t problem[] = {100, 200, 1000, 0,
                                200, 100, 600, 0,
                                300, 1600, 100, 0};
    std::vector<std::pair<uint, uint>> solution;
    std::cout << solve(3, 4, problem, solution);
    return 0;
}
