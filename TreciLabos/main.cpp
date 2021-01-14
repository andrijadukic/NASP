#include <iostream>
#include <vector>
#include <algorithm>
#include "simplex.h"

int main() {
    std::vector<std::vector<double>> tableau = std::vector<std::vector<double>>
            {
                    {1, 5, 0, 0, 0},
                    {5, 6, 1, 0, 30},
                    {3, 2, 0, 1, 12}
            };

    std::vector<double> solution(4);
    double obj;

    solve(tableau, solution, obj);

    for (double i : solution) {
        std::cout << i << std::endl;
    }
}