#include <algorithm>
#include "simplex.h"

int solve(std::vector<std::vector<double>> &tableau, std::vector<double> &solution, double &obj) {
    for (double &i : tableau[0]) {
        i = -i;
    }

    int n = tableau.size();
    int m = tableau[0].size();

    while (true) {
        if (is_optimum_reached(tableau)) {
            obj = -tableau[0][m - 1];
            return 0;
        }

        int q = pivot_column(tableau);

        if (!is_viable_solution_possible(tableau, q)) {
            return 1;
        }

        pivot_about(tableau, pivot_row(tableau, q), q);
    }
}

bool is_optimum_reached(std::vector<std::vector<double>> &tableau) {
    for (double val : tableau[0]) {
        if (val < 0.) return false;
    }
    return true;
}

int pivot_column(std::vector<std::vector<double>> &tableau) {
    std::distance(std::min_element(tableau[0].begin(), tableau[0].end()), tableau[0].begin());
}

bool is_viable_solution_possible(std::vector<std::vector<double>> &tableau, int q) {
    for (std::vector<double> &i : tableau) {
        if (i[q] > 0.) return true;
    }
    return false;
}

int pivot_row(std::vector<std::vector<double>> &tableau, int q) {
    size_t n = tableau.size();
    size_t m = tableau[0].size() - 1;
    std::vector<int> candidates(n);
    for (int i = 1; i < n; i++) {
        candidates[i] = tableau[i][m] / tableau[i][q];
    }
    return std::distance(std::min_element(candidates.begin(), candidates.end()), candidates.begin());
}

void pivot_about(std::vector<std::vector<double>> &tableau, int p, int q) {
    double pivot = tableau[p][q];
    size_t n = tableau.size();
    size_t m = tableau[0].size();
    for (int j = 1; j < n; j++) {
        tableau[p][j] /= pivot;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == p) {
                tableau[i][j] /= pivot;
            } else {
                tableau[i][j] -= tableau[i][q] * tableau[p][j] / pivot;
            }
        }
    }
}

std::vector<double> extract_solution(std::vector<std::vector<double>> &tableau) {

}