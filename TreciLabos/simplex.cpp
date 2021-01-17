#include <algorithm>
#include "simplex.h"

int solve(std::vector<std::vector<double>> &tableau, std::vector<double> &solution, double &obj) {
    convert_min_to_max(tableau[0]);
    std::vector<int> active = init_active(tableau);
    while (true) {
        int q = pivot_column(tableau);
        if (tableau[0][q] >= 0.) {
            std::pair<std::vector<double>, double> extracted_solution = extract(tableau, active);
            solution = extracted_solution.first;
            obj = extracted_solution.second;
            return 0;
        }
        int p = pivot_row(tableau, q);
        if (p == -1) {
            return 1;
        }
        active[p - 1] = q;
        pivot_about(tableau, p, q);
    }
}

void convert_min_to_max(std::vector<double> &obj) {
    for (double &c : obj) {
        c = -c;
    }
}

std::vector<int> init_active(std::vector<std::vector<double>> &tableau) {
    size_t n = tableau.size() - 1;
    size_t ind = tableau[0].size() - 1 - n;
    std::vector<int> active(n);
    for (int i = 0; i < n; i++) {
        active[i] = ind + i;
    }
    return active;
}

int pivot_column(std::vector<std::vector<double>> &tableau) {
    std::vector<double> &obj = tableau[0];
    return std::distance(obj.begin(), std::min_element(obj.begin(), obj.end() - 1));
}

int pivot_row(std::vector<std::vector<double>> &tableau, int q) {
    int p = -1;
    double min = std::numeric_limits<double>::infinity();
    size_t m = tableau[0].size() - 1;
    for (int i = 1, n = tableau.size(); i < n; i++) {
        double yiq = tableau[i][q];
        if (yiq <= 0.) continue;
        double curr = tableau[i][m] / yiq;
        if (curr < min) {
            min = curr;
            p = i;
        }
    }
    return p;
}

void pivot_about(std::vector<std::vector<double>> &tableau, int p, int q) {
    size_t m = tableau[0].size();
    double pq = tableau[p][q];
    for (int j = 0; j < m; j++) {
        if (j == q) {
            tableau[p][j] = 1.;
            continue;
        }
        tableau[p][j] /= pq;
    }
    for (int i = 0, n = tableau.size(); i < n; i++) {
        if (i == p) continue;
        double yiq = tableau[i][q];
        for (int j = 0; j < m; j++) {
            if (j == q) {
                tableau[i][j] = 0.;
                continue;
            }
            tableau[i][j] -= yiq * tableau[p][j];
        }
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