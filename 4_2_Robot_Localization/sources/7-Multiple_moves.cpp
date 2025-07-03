#include <cmath>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

std::vector<float> initializeRobot(size_t gridLength)
{
    std::vector<float> grid(gridLength);
    std::fill(grid.begin(), grid.end(), 1.0 / gridLength);
    return grid;
}

template <typename T>
void print(const std::vector<T>& grid)
{
    for (const T& p : grid) {
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

enum Direction {
    LEFT = 0,
    RIGHT = 1
};

template <typename T>
void moveInWorld(std::vector<T>& grid, int displacement)
{
    std::vector<T> newGrid(grid.size());
    for (int i = 0; i <= grid.size(); i++) {
        int pos = (i + displacement) % grid.size();
        if (pos < 0)
            pos += grid.size() - 1;
        newGrid[i] = grid[pos];
    }
    std::swap(newGrid, grid);
}

void uncertainMoveInWorld(std::vector<float>& grid, int displacement, float pUnderShoot, float pExact, float pOverShoot)
{
    std::vector<float> newGrid(grid.size());
    std::fill(newGrid.begin(), newGrid.end(), 0);
    for (int i = 0; i < grid.size(); i++) {
        int posExact = (i + displacement) % grid.size();
        if (posExact < 0)
            posExact += grid.size() - 1;

        int posUnderShoot = (i + displacement - 1) % grid.size();
        if (posUnderShoot < 0)
            posUnderShoot += grid.size() - 1;

        int posOverShoot = (i + displacement + 1) % grid.size();
        if (posOverShoot < 0)
            posOverShoot += grid.size() - 1;

        newGrid[posExact] += grid[i] * pExact;
        newGrid[posUnderShoot] += grid[i] * pUnderShoot;
        newGrid[posOverShoot] += grid[i] * pOverShoot;
    }

    std::swap(newGrid, grid);
}

struct Iteration {
    int displacement;
    char sensorValue;
};

int main(int argc, char* argv[])
{
    std::vector<char> world { 'g', 'r', 'r', 'g', 'g' };
    std::vector<float> grid = initializeRobot(world.size());

    print(world);
    print(grid);
    char sensorReading = 'g';
    float pHit = 0.6;
    float pMiss = 0.2;

    float pOverShoot = 0.1;
    float pExact = 0.8;
    float pUnderShoot = 0.1;

    std::vector<Iteration> iterations { { 1, 'r' }, { 1, 'r' } };

    for (const Iteration& ite : iterations) {
        sense(grid, world, ite.sensorValue, pHit, pMiss);
        uncertainMoveInWorld(grid, ite.displacement, pUnderShoot, pExact, pOverShoot);
        print(grid);
    }

    return 0;
}
