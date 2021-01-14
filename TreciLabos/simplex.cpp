#include <algorithm>
#include <vector>
#include "simplex.h"

int solve(std::vector<std::vector<double>> &tableau, std::vector<double> &solution, double &obj) {
    for (double &i : tableau[0]) {
        i = -i;
    }

    std::vector<int> active = init_active(tableau);
    while (true) {
        if (is_optimum_reached(tableau)) {
            std::pair<std::vector<double>, double> extracted_solution = extract(tableau, active);
            solution = extracted_solution.first;
            obj = extracted_solution.second;
            return 0;
        }
        int q = pivot_column(tableau);
        if (!is_viable_solution_possible(tableau, q)) {
            return 1;
        }
        int p = pivot_row(tableau, q);
        active[p] = q;
        pivot_about(tableau, p, q);
    }
}

std::vector<int> init_active(std::vector<std::vector<double>> &tableau) {
    size_t n = tableau.size() - 1;
    std::vector<int> active(n);
    for (int i = 0; i < n; i++) {
        active[i] = n + i;
    }
    return active;
}

bool is_optimum_reached(std::vector<std::vector<double>> &tableau) {
    size_t n = tableau[0].size() - 1;
    for (int j = 0; j < n; j++) {
        if (tableau[0][j] < 0.) return false;
    }
    return true;
}

int pivot_column(std::vector<std::vector<double>> &tableau) {
    return std::distance(tableau[0].begin(), std::min_element(tableau[0].begin(), tableau[0].end() - 1));
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
    std::vector<double> candidates(n - 1);
    for (int i = 1; i < n; i++) {
        candidates[i - 1] = tableau[i][m] / tableau[i][q];
    }
    return std::distance(candidates.begin(), std::min_element(candidates.begin(), candidates.end()));
}

void pivot_about(std::vector<std::vector<double>> &tableau, int p, int q) {
    p = p + 1;
    size_t m = tableau[0].size() - 1;
    double pivot = tableau[p][q];
    for (int i = 0, n = tableau.size(); i < n; i++) {
        if (i == p) continue;
        for (int j = m; j >= 0; j--) {
            tableau[i][j] -= tableau[i][q] * tableau[p][j] / pivot;
        }
    }
    for (int j = 0; j <= m; j++) {
        tableau[p][j] /= pivot;
    }
}

std::pair<std::vector<double>, double> extract(std::vector<std::vector<double>> &tableau, std::vector<int> &active) {
    size_t m = tableau[0].size() - 1;
    std::vector<double> solution(m, 0.);
    for (int i = 0, n = active.size(); i < n; i++) {
        solution[active[i]] = tableau[i + 1][m];
    }
    return std::pair<std::vector<double>, double>(solution, tableau[0].back());
}