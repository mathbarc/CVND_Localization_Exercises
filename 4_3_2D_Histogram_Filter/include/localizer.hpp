#ifndef LOCALIZER_HPP
#define LOCALIZER_HPP
#include <Eigen/Eigen>
#include <Eigen/src/Core/Matrix.h>
#include <cstddef>
class Localizer {
private:
    Eigen::MatrixXf beliefs;

public:
    Localizer(size_t rows, size_t cols);
};

#endif
