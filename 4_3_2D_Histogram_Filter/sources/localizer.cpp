#include "localizer.hpp"
#include <iostream>
Localizer::Localizer(size_t rows, size_t cols)
{
    this->beliefs = Eigen::MatrixXf(cols, rows);
    this->beliefs.fill(1. / ((float)(rows) * (float)(cols)));
    std::cout << this->beliefs.rows() << ", " << this->beliefs.cols() << std::endl;
    std::cout << this->beliefs << std::endl;
}
