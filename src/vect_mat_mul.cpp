#include "../include/vect_mat_mul.h"
#include "../include/w_sum.h"


std::vector<float> vect_mat_mul(std::vector<float> vect, std::vector<std::vector<float>> matrix)
{
  assert(vect.size() == matrix.size());
  std::vector<float> output = {0, 0, 0};

  for(int i=0; i<int(vect.size()); i++)
  {
    output[i] = w_sum(vect, matrix[i]);
  }

  return output;
}
