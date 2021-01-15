#include <iostream>
#include <vector>
#include <algorithm>
#include "simplex.h"

int main() {
    std::vector<std::vector<double>> tableau = std::vector<std::vector<double>>
            {
//                    {1300, 1500, 0, 0, 0, 0},
//                    {1, 1, 1, 0, 0, 10},
//                    {-1, -1, 0, 1, 0, -7},
//                    {1, 2, 0, 0, 1, 12}
//                    {1, 5, 0, 0, 0},
//                    {5, 6, 1, 0, 30},
//                    {3, 2, 0, 1, 12}
//                    {7, 6, 0, 0, 0},
//                    {2, 1, 1, 0, 3},
//                    {1, 4, 0, 1, 4}
                    {74,  75,  20,  93,  84,  33,  50,  44,  -21, 56,  53,  -61, 69,  -82, 5,   70,  -81, -34, -77, -82, -4,  -45, -88, 99,  57,  -63, -65, -32, -24, -22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {27,  41,  72,  79,  -28, -24, 18,  -65, -70, -99, 72,  -87, -46, -19, -56, -81, -18, 78,  -73, 20,  59,  84,  65,  -41, 47,  0,   50,  -63, -71, 86,  1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {96,  -94, 35,  62,  -61, -45, 45,  94,  -25, -25, -95, 3,   68,  83,  45,  -28, -41, -50, -89, -58, 28,  -67, 30,  84,  -63, -48, -23, -19, -50, 13,  0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {-46, 28,  3,   70,  -68, 56,  85,  -83, -76, 71,  -13, -52, -99, 51,  92,  19,  -71, 55,  75,  22,  36,  33,  -71, 71,  -3,  70,  56,  10,  -16, -6,  0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {60,  -53, 52,  -73, 64,  -39, 4,   -74, 96,  -32, 60,  -90, -51, 33,  -84, 44,  26,  74,  50,  -21, 87,  55,  66,  97,  36,  -84, 21,  49,  -32, -52, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {-50, 90,  -33, 78,  -25, -2,  81,  -21, 36,  -93, -96, -75, 81,  1,   -32, 27,  -21, 63,  63,  2,   9,   -29, 75,  -69, 76,  9,   -13, -27, 98,  -93, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {50,  35,  -20, 14,  -69, -17, -82, 58,  63,  55,  22,  79,  60,  -5,  -16, -51, 22,  68,  51,  62,  29,  23,  42,  32,  -64, 92,  -74, -3,  -0,  -37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10},
                    {16,  1,   80,  -11, 84,  -90, 21,  -12, 59,  -2,  -61, 53,  63,  91,  -84, -26, -28, 25,  91,  -80, -45, 25,  59,  29,  8,   -73, 52,  80,  -69, -8,  0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                    {10,  -28, -97, -53, 45,  99,  45,  6,   -39, -9,  -80, 19,  84,  -26, 38,  -37, 88,  48,  26,  -30, 8,   17,  -9,  51,  22,  -85, -86, 35,  29,  23,  0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {-82, 13,  -25, 1,   8,   -77, -37, 36,  -85, 83,  29,  -80, 22,  -74, -72, -41, 92,  90,  -6,  47,  -23, -41, -74, 76,  39,  33,  -50, 91,  31,  -91, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                    {69,  82,  -81, -39, 71,  -55, -16, 64,  -11, 85,  -23, -49, 35,  -47, -92, 71,  -97, -31, 74,  -25, -69, -23, 27,  82,  31,  -42, 30,  81,  19,  5,   0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10},
                    {-30, -24, -87, -17, 46,  57,  -33, -20, -10, 35,  12,  -40, 82,  24,  -96, -47, 33,  64,  -1,  12,  -12, -97, 14,  -86, -74, -43, 5,   77,  60,  -3,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10},
                    {90,  -22, 38,  1,   63,  28,  -20, 44,  -11, -95, -59, 83,  -95, 15,  -32, 4,   6,   49,  -39, -50, -65, 54,  9,   21,  9,   -91, -89, -78, -77, 1,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {57,  -20, 52,  74,  83,  -8,  -68, 85,  55,  18,  -25, -49, 65,  -37, -49, 56,  37,  -89, -61, 23,  50,  19,  20,  -80, 73,  4,   82,  86,  2,   97,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {52,  81,  73,  38,  29,  -28, 56,  5,   -76, -90, 10,  -81, -16, -41, -16, -4,  -78, 25,  29,  -43, -0,  -61, -51, 27,  -70, -71, -36, 92,  26,  -20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
                    {82,  42,  73,  -52, -60, -16, -52, -4,  -43, -70, 63,  -89, -12, -75, -44, 31,  -14, 23,  -25, 7,   53,  -22, 85,  74,  25,  -42, 45,  69,  57,  63,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                    {83,  -55, 55,  -61, -62, -99, -21, -84, -94, 64,  -48, 88,  -19, -64, 85,  -96, 93,  -59, 52,  -96, -52, 15,  -62, -20, 22,  -36, 11,  -46, -39, -44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {-18, 78,  -67, -26, -17, 78,  -16, 38,  -14, -85, -73, 44,  -50, 16,  -78, 56,  -54, 74,  26,  -0,  46,  -1,  35,  9,   22,  3,   -65, -76, -52, -1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {-38, 46,  -58, -95, -32, 56,  14,  47,  -92, 1,   26,  -9,  14,  -64, -17, -46, 89,  -27, 3,   28,  60,  -59, -49, 53,  92,  -21, -48, -72, -85, 27,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {79,  -61, 52,  31,  -37, 64,  78,  -17, 57,  71,  65,  27,  76,  28,  31,  -80, 46,  46,  34,  23,  -99, 56,  -39, 88,  29,  71,  36,  -87, 46,  -67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {-60, 96,  35,  29,  -92, -63, 19,  86,  -78, 43,  -56, -23, 61,  25,  9,   68,  -58, -52, 1,   -59, -29, -35, -66, -82, 18,  60,  -87, 61,  -71, 34,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {-49, -52, 74,  17,  51,  -98, 33,  6,   -67, -37, -40, -22, -93, -37, 20,  1,   68,  -56, 94,  16,  34,  -48, -72, 48,  63,  -53, 75,  -65, 43,  -67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                    {64,  41,  59,  76,  -3,  -55, 34,  6,   -36, -41, 34,  21,  -82, -50, 75,  -28, 73,  -66, 81,  7,   -38, 6,   -13, 21,  51,  52,  -5,  81,  -52, 68,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {99,  -16, -42, 8,   -85, -71, 28,  -37, 26,  -86, 41,  89,  -66, 97,  63,  -34, 27,  -83, -12, 79,  23,  54,  72,  27,  38,  45,  -25, -82, -78, 30,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                    {58,  -33, -2,  96,  26,  -24, 59,  29,  -72, 52,  -51, -52, -99, -45, -90, 78,  88,  -61, 11,  -7,  -76, 37,  -3,  -4,  73,  17,  70,  -63, -5,  19,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {-60, -87, -30, -25, -89, 42,  2,   -4,  86,  -83, -75, 3,   96,  82,  -74, 37,  58,  -35, 21,  37,  -73, 16,  87,  -35, 12,  -21, 34,  -59, 0,   -22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4},
                    {79,  -7,  28,  53,  -64, 71,  -42, -44, -76, -92, 26,  79,  11,  -3,  -76, 11,  -77, -15, 37,  6,   -16, -20, 16,  -11, -47, -14, -49, -65, -0,  91,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                    {-35, -51, -7,  82,  87,  -91, -58, 53,  -1,  -27, -19, -15, -10, -45, -53, 80,  -72, 7,   -99, -35, -64, -89, 71,  -49, 37,  -61, -71, 50,  -90, -14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {-40, -38, -20, 75,  -4,  98,  -76, 44,  -35, 20,  -35, -18, -71, -15, -55, -61, -62, -69, -32, 29,  88,  -32, -22, 45,  -96, -98, 41,  20,  80,  75,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                    {-94, 66,  -58, 12,  49,  -0,  15,  -36, -83, -75, 18,  24,  30,  -26, 83,  77,  -95, -49, -96, 14,  -89, -95, -15, 38,  75,  -41, 43,  -98, -21, 55,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
                    {-4,  72,  -94, 11,  -80, 8,   -52, -61, -34, 51,  -19, 52,  -80, 13,  86,  72,  -73, 94,  87,  2,   43,  86,  -64, -13, 10,  83,  95,  65,  44,  17,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {15,  68,  51,  43,  -24, -38, -90, -9,  -20, -7,  26,  -19, 24,  50,  54,  11,  41,  22,  -34, -47, -25, -2,  -70, 43,  14,  65,  -69, 22,  65,  -19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8},
                    {72,  76,  3,   -79, 48,  32,  0,   -51, -91, -44, 92,  42,  93,  88,  -13, -8,  -9,  -21, 91,  11,  -81, -37, -14, 85,  82,  76,  -56, 0,   -11, 17,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                    {-94, -77, -19, -74, 6,   -62, 2,   -4,  -63, -8,  88,  59,  -28, 0,   -90, -76, -77, 73,  -15, 25,  -34, -99, 15,  13,  -38, -81, 98,  -67, 32,  -1,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                    {-23, -42, 74,  5,   -98, 81,  72,  36,  -33, -92, 6,   3,   -40, 47,  51,  -37, 21,  49,  -17, 37,  69,  -71, -92, -17, 52,  -25, 32,  -47, 96,  -70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {72,  89,  3,   11,  -85, -82, 75,  4,   -85, -9,  -96, 54,  -70, 16,  25,  67,  34,  -18, 72,  55,  31,  80,  78,  -31, -82, -51, -42, -23, -98, -66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                    {-6,  -64, 21,  88,  -53, -16, -50, 37,  -89, 78,  -41, -67, 75,  -7,  -66, -48, 56,  57,  87,  26,  19,  -60, 49,  99,  69,  27,  -30, 70,  27,  88,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {-54, -36, -4,  42,  15,  -95, 7,   -87, -56, -17, -43, 65,  -78, 1,   -6,  -45, 15,  -41, 10,  -20, -95, 49,  34,  -14, -20, -85, 24,  -61, -18, -70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                    {-24, 95,  10,  -84, 77,  -59, 55,  -32, 83,  42,  -58, -57, 63,  -74, -14, 61,  -68, 17,  -85, 2,   30,  -9,  -77, 7,   -54, 19,  -82, 86,  35,  -24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9},
                    {-51, 49,  -0,  39,  35,  62,  20,  15,  -65, -5,  51,  -75, -50, 17,  80,  -65, 66,  -87, 31,  10,  -6,  33,  -63, -10, -67, 25,  10,  -60, -85, -57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
                    {-98, 35,  99,  31,  -99, -68, -47, -91, 6,   -20, 25,  -96, -69, -39, 65,  69,  82,  -29, 21,  28,  84,  69,  68,  5,   9,   -48, -78, -8,  -12, 19,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {70,  13,  55,  6,   46,  50,  -51, -84, -93, 82,  58,  72,  36,  -23, 64,  36,  14,  10,  -9,  -57, 81,  -81, 75,  51,  32,  -78, 1,   -3,  88,  56,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {34,  -48, -47, -53, -33, 41,  -47, 96,  -13, 68,  -39, 86,  51,  -32, 11,  77,  -26, 91,  -38, -22, 63,  37,  -55, 54,  -25, 1,   -86, 92,  -51, 31,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {-10, 46,  -17, -94, 34,  97,  69,  -1,  -14, -67, 92,  -67, 24,  56,  -79, 25,  95,  73,  41,  74,  -50, -83, -64, -73, -12, -0,  -21, 88,  -0,  77,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {-56, 46,  40,  -30, 56,  6,   -72, 34,  64,  -26, 80,  -4,  -75, 83,  90,  7,   59,  92,  92,  93,  25,  44,  -3,  -71, -84, -72, -36, 60,  27,  67,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5},
                    {82,  51,  77,  -31, 92,  -26, -82, 80,  57,  -42, -64, -81, 46,  33,  78,  79,  -11, -61, -53, -91, 45,  -6,  82,  -68, 41,  97,  55,  -89, 46,  -6,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6},
                    {87,  62,  47,  23,  43,  18,  -49, 69,  46,  -78, -58, -74, -71, 3,   50,  23,  92,  -11, 96,  0,   77,  80,  -20, -6,  -17, 22,  54,  -91, -41, -97, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {-43, -3,  -85, 35,  -11, -98, -77, 55,  -96, 82,  -13, 18,  -4,  43,  59,  89,  85,  96,  -52, -81, -96, 28,  -17, 17,  -18, -30, 70,  -17, 49,  2,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                    {-78, 78,  95,  58,  70,  -44, 79,  29,  -62, 38,  90,  -40, 69,  0,   -73, 11,  -30, -51, 0,   65,  62,  -43, 27,  91,  60,  -57, 5,   13,  -97, -90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3},
                    {63,  -87, -8,  27,  48,  -39, -32, 91,  -15, -31, 92,  -1,  96,  75,  77,  43,  90,  61,  66,  48,  -95, 82,  73,  72,  -83, 10,  -81, 85,  48,  43,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2},
                    {56,  -72, 9,   -94, -3,  -32, -69, 3,   13,  59,  14,  -17, 57,  14,  52,  82,  73,  86,  94,  -48, -73, -72, -85, -62, -24, -87, -88, -16, 95,  -5,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 8},
                    {-43, -57, 48,  -83, -82, 45,  39,  49,  -14, -48, 1,   42,  34,  -9,  -70, -38, -16, 57,  47,  -40, 46,  -99, 92,  27,  -24, 89,  57,  -25, 85,  34,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 2},
                    {10,  -49, 50,  31,  -21, -83, 18,  90,  1,   50,  78,  77,  19,  -1,  -68, -16, -80, 79,  92,  -36, 70,  -41, 38,  -39, 46,  46,  53,  -61, -77, 88,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
                    {49,  40,  -37, -88, 80,  2,   -15, -89, 38,  72,  -53, 80,  39,  -13, -57, -4,  -12, -52, 31,  -81, 0,   9,   95,  -47, -27, -53, 40,  -97, -73, -70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 8},
                    {-90, 98,  -64, 5,   -58, 44,  22,  62,  -63, -10, 80,  36,  70,  -48, -1,  27,  -19, -45, 13,  57,  -34, 66,  2,   -36, 32,  94,  8,   -96, 55,  -77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
                    {-11, -40, -29, 4,   -29, -51, -87, -48, -9,  29,  5,   40,  -51, 1,   94,  -26, 68,  -38, 50,  -72, 73,  -53, -63, -87, -17, -82, 16,  -50, -62, 45,  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 3},
                    {-96, 12,  17,  49,  96,  30,  -99, -62, -37, -56, -28, 84,  -48, 81,  -99, 31,  -25, -29, -48, 79,  -81, -61, 4,   35,  18,  47,  93,  16,  32,  3,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 10},
                    {-50, 35,  -82, -32, 10,  -82, -46, 66,  -74, -96, -68, 10,  -45, -20, 85,  95,  -8,  -85, -3,  26,  -66, -71, -45, 29,  -55, -45, -6,  69,  21,  -70, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1},
            };


    double obj;
    std::vector<double> solution;
    solve(tableau, solution, obj);

    std::cout << obj << std::endl;

    for (double i : solution) {
        std::cout << i << std::endl;
    }
}