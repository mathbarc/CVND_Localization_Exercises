#ifndef SIMULATOR_HPP
#define SIMULATOR_HPP
#include <Eigen/Eigen>
#include <Eigen/src/Core/Matrix.h>

class Simulator {
private:
    Eigen::MatrixX<uint8_t> grid;

public:
    Simulator(Eigen::MatrixX<uint8_t> grid);
};

#endif
