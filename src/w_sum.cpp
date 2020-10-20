#include "../include/w_sum.h"

float w_sum(std::vector<float> vec_a, std::vector<float> vec_b)
{
  /* Calculate dot product */

  assert(vec_a.size() == vec_b.size());
  float output = 0;

  for(int i=0; i<int(vec_a.size()); i++)
  {
    output += (vec_a[i] * vec_b[i]);
  }

  return output;
}

