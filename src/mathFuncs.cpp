#include "../include/mathFuncs.h"

namespace mf{


  std::vector<float> scalar_mult(float scalar, std::vector<float> vec)
  {
    /* Scalar-vector elementwise multiplication */

    int out_size = vec.size();
    std::vector<float> output(out_size, 0);
    
    for(int i=0; i<out_size; i++)
      output[i] = scalar * vec[i];

   return output; 
  }


  float dot_product(std::vector<float> vec_a, std::vector<float> vec_b)
  {
    /* Dot product of two vectors of the same size */

    assert(vec_a.size() == vec_b.size());
    
    float output = 0;
    
    for(int i=0; i<int(vec_a.size()); i++)
      output += (vec_a[i] * vec_b[i]);

    return output;
  }


  std::vector<float> vect_mat_mul(std::vector<float> vec, std::vector<std::vector<float>> matrix)
  {
    /* Vector-matrix multiplication */

    assert(vec.size() == matrix.size());
    int out_size = vec.size();

    std::vector<float> output(out_size, 0);

    for(int i=0; i<out_size; i++)
      output[i] = dot_product(vec, matrix[i]);

    return output;
  }


  std::vector<float> vect_subt(std::vector<float> vec_a, std::vector<float> vec_b)
  {
    /* Vector subtraction */

    assert(vec_a.size() == vec_b.size());
    int out_size = vec_a.size();

    std::vector<float> output(out_size, 0);

    for(int i=0; i<int(vec_a.size()); i++)
      output[i] = (vec_a[i] - vec_b[i]);

    return output;
  }

}
