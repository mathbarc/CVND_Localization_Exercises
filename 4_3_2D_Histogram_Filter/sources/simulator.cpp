#include "simulator.hpp"
#include <Eigen/src/Core/Matrix.h>
#include <ostream>

Simulator::Simulator(Eigen::MatrixX<uint8_t> grid)
    : grid(grid)
{
}
