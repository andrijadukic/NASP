#ifndef SIMPLEX_H
#define SIMPLEX_H

#include <vector>

int solve(std::vector<std::vector<double>> &tableau, std::vector<double> &solution, double &obj);

bool is_optimum_reached(std::vector<std::vector<double>> &tableau);

int pivot_column(std::vector<std::vector<double>> &tableau);

bool is_viable_solution_possible(std::vector<std::vector<double>> &tableau, int q);

int pivot_row(std::vector<std::vector<double>> &tableau, int q);

void pivot_about(std::vector<std::vector<double>> &tableau, int p, int q);

#endif