#include "../include/vect_sub.h"

std::vector<float> vect_sub(std::vector<float> vec_a, std::vector<float> vec_b)
{
  assert(vec_a.size() == vec_b.size());

  std::vector<float> output;

  for(int i=0; i<int(vec_a.size()); i++)
    output.push_back(vec_a[i] - vec_b[i]);

  return output;
}


