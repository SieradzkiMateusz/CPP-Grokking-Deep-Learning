#include "../include/ele_mul.h"

std::vector<float> ele_mul(float number, std::vector<float> vec)
{
  std::vector<float> output = {0, 0, 0};
  assert(output.size() == vec.size());

  for(int i=0; i<int(vec.size()); i++)
  {
    output[i] = number * vec[i];
  }

  return output;
}

