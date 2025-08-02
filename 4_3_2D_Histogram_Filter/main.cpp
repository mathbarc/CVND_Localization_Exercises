#include "simulator.hpp"
#include <Eigen/src/Core/Matrix.h>
int main(int argc, char** argv)
{

    Eigen::MatrixX<uint8_t> grid(5, 5);
    grid << 'R', 'G', 'G', 'G', 'R',
        'G', 'G', 'R', 'G', 'R',
        'G', 'R', 'G', 'G', 'G',
        'R', 'R', 'G', 'R', 'G',
        'R', 'G', 'R', 'G', 'R';

    Simulator sim(grid);

    return 0;
}
