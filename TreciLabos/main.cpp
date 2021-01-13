#include <iostream>
#include <vector>
#include <algorithm>

int pivot_column(std::vector<double> &tableau) {
    return std::distance(std::min_element(tableau.begin(), tableau.end()), tableau.begin());
}

int main() {
    std::vector<double>vec{1, 2, 3, 4, 5};
    pivot_column(vec);
}