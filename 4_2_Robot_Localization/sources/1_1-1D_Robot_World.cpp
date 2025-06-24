#include <iostream>
#include <vector>

std::vector<float> initializeRobot(size_t gridLength)
{
    std::vector<float> grid(gridLength);
    std::fill(grid.begin(), grid.end(), 1.0 / gridLength);
    return grid;
}

int main(int argc, char* argv[])
{
    std::vector<float> grid = initializeRobot(5);
    for (const float& p : grid) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    return 0;
}
