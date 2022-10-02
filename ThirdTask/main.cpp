#include <iostream>
#include <vector>
#include "simplex.h"

int main() {
    std::vector<std::vector<double>> tableau = std::vector<std::vector<double>>
            {
                    {1, 5, 0, 0, 0},
                    {5, 6, 1, 0, 30},
                    {3, 2, 0, 1, 12}
            };


    double obj;
    std::vector<double> solution;
    solve(tableau, solution, obj);

    std::cout << obj << std::endl;

    for (double i : solution) {
        std::cout << i << std::endl;
    }
}

