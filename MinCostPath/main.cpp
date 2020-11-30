#include <iostream>
#include <vector>
#include <algorithm>

typedef unsigned int uint;

uint solve(const uint N, const uint M, const uint16_t *const problem, std::vector<std::pair<uint, uint>> &solution) {
    uint i, j;
    uint dest_i = N - 1;
    uint dest_j = M - 1;
    uint cost[N][M];

    cost[0][0] = problem[0];

    for (i = 1; i < M; i++) {
        cost[0][i] = cost[0][i - 1] + problem[i];
    }

    for (i = 1; i < N; i++) {
        cost[i][0] = cost[i - 1][0] + problem[i * M];
    }

    for (i = 1; i < N; i++) {
        uint row_offset = i * M;
        uint prev_row = i - 1;
        for (j = 1; j < M; j++) {
            cost[i][j] = problem[row_offset + j] + std::min(cost[i][j - 1], cost[prev_row][j]);
        }
    }

    i = 0;
    j = 0;
    while (i < dest_i && j < dest_j) {
        solution.emplace_back(i, j);
        if (cost[i][j + 1] < cost[i + 1][j]) {
            j++;
        } else {
            i++;
        }
    }
    if (i == dest_i) {
        while (j != dest_j) {
            solution.emplace_back(dest_i, j++);
        }
    } else {
        while (i != dest_i) {
            solution.emplace_back(i++, dest_j);
        }
    }
    solution.emplace_back(dest_i, dest_j);

    return cost[dest_i][dest_j];
}

int main() {
    const uint16_t problem[] = {100, 200, 1000, 0, 200, 100, 600, 0, 300, 1600, 100, 0};
    std::vector<std::pair<uint, uint>> solution;
    std::cout << solve(3, 4, problem, solution);
    return 0;
}
