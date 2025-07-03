#include <cmath>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

std::vector<float> initializeRobot(size_t gridLength)
{
    std::vector<float> grid(gridLength);
    std::fill(grid.begin(), grid.end(), 1.0 / gridLength);
    return grid;
}

void print(const std::vector<float>& grid)
{
    for (const float& p : grid) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    std::vector<float> grid = initializeRobot(5);
    print(grid);

    float pHit = 0.6;
    float pMiss = 0.2;

    grid[0] *= pMiss;
    grid[1] *= pHit;
    grid[2] *= pHit;
    grid[3] *= pMiss;
    grid[4] *= pMiss;

    print(grid);

    float sum = std::accumulate(grid.begin(), grid.end(), 0.0);
    std::cout << sum << std::endl;
    sum = 1.0 / sum;

    for (float& v : grid) {
        v *= sum;
    }
    print(grid);

    return 0;
}
