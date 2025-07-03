#include <cmath>
#include <cstddef>
#include <iostream>
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

void sense(std::vector<float>& grid, const std::vector<char>& world, const char sensorReading, const float pHit, const float pMiss)
{
    float sum = 0;
    for (size_t i = 0; i < grid.size(); i++) {
        grid[i] *= (sensorReading == world[i]) ? pHit : pMiss;
        sum += grid[i];
    }

    sum = 1.0 / sum;

    for (float& v : grid) {
        v *= sum;
    }
}

int main(int argc, char* argv[])
{
    std::vector<float> grid = initializeRobot(5);
    std::vector<char> world { 'g', 'r', 'r', 'g', 'g' };
    print(grid);
    char sensorReading = 'g';
    float pHit = 0.6;
    float pMiss = 0.2;

    sense(grid, world, sensorReading, pHit, pMiss);
    print(grid);

    sense(grid, world, sensorReading, pHit, pMiss);
    print(grid);

    sensorReading = 'r';
    sense(grid, world, sensorReading, pHit, pMiss);
    print(grid);
    return 0;
}
