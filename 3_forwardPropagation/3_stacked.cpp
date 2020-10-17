#include <iostream>
#include <vector>
#include <cassert>


float w_sum(std::vector<float> vec_a, std::vector<float> vec_b)
{
  assert(vec_a.size() == vec_b.size());
  float output = 0;

  for(int i=0; i<int(vec_a.size()); i++)
  {
    output += (vec_a[i] * vec_b[i]);
  }

  return output;
}

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


std::vector<float> neural_network(std::vector<float> input, std::vector<std::vector<std::vector<float>>> weights)
{
  std::vector<float> hidden = vect_mat_mul(input, weights[0]);
  std::vector<float> predictions = vect_mat_mul(hidden, weights[1]);

  return predictions;
}


int main()
{
  std::vector<std::vector<float>> ih_wgt { 
    {0.1, 0.2, -0.1},
    {-0.1, 0.1, 0.9},
    {0.1, 0.4, 0.1} };

  std::vector<std::vector<float>> hp_wgt {
    {0.3, 1.1, -0.3},
    {0.1, 0.2, 0.0},
    {0.0, 1.3, 0.1} };

  std::vector<std::vector<std::vector<float>>> weights = {ih_wgt, hp_wgt};

  std::vector<float> toes = {8.5, 9.5, 9.9, 9.0};
  std::vector<float> wlrec = {0.65, 0.8, 0.8, 0.9};
  std::vector<float> nfans = {1.2, 1.3, 0.5, 1.0};

  std::vector<float> input = {toes[0], wlrec[0], nfans[0]};

  std::vector<float> predictions = neural_network(input, weights);

  std::cout << "Predictions: ";

  for(float prediction : predictions)
  {
    std::cout << prediction << " ";
  } 

  return 0;
}
    
