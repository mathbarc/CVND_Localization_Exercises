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
void moveInWorld(std::vector<T>& grid, Direction direction)
{
    if (direction == Direction::RIGHT) {
        T tmp = grid.front();
        for (int i = grid.size() - 1; i >= 0; i--) {
            std::swap(grid[i], tmp);
        }
    } else if (direction == Direction::LEFT) {
        T tmp = grid.back();
        for (size_t i = 0; i < grid.size(); i++) {
            std::swap(grid[i], tmp);
        }
    }
}

int main(int argc, char* argv[])
{
    std::vector<float> grid = initializeRobot(5);
    std::vector<char> world { 'g', 'r', 'r', 'g', 'g' };
    print(world);
    print(grid);
    char sensorReading = 'g';
    float pHit = 0.6;
    float pMiss = 0.2;

    sense(grid, world, sensorReading, pHit, pMiss);
    print(grid);
    moveInWorld(world, Direction::RIGHT);
    moveInWorld(grid, Direction::RIGHT);
    print(grid);
    print(world);

    return 0;
}
