#pragma once

#include <vector>
#include <assert.h>
#include <math.h>
#include <random>

namespace mf {

  std::vector<float> ele_mul(float number, std::vector<float> vec);

  std::vector<float> vect_mat_mul(std::vector<float> vect, std::vector<std::vector<float>>matrix);

  std::vector<float> vect_sub(std::vector<float> vec_a, std::vector<float> vec_b);

  std::vector<float> dot(std::vector<float> vec_a, std::vector<float> vec_b);

  std::vector<std::vector<float>> random_matrix(int rows, int cols, int modifier);

  //Scalar-Vector Addition/Subratcion
  //Vector transpose
  //Relu
  //Relu2Deriv

}
