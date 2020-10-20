#include <iostream>
#include <math.h>

#include "../include/vect_mat_mul.h"
#include "../include/w_sum.h"


std::vector<float> neural_network(std::vector<float> input, std::vector<std::vector<float>> weights)
{
  std::vector<float> pred = vect_mat_mul(input, weights);

  return pred;
}


std::vector<std::vector<float>> outer_prod(std::vector<float> vec_a, std::vector<float>  vec_b)
{
    int rows = vec_a.size();
    int cols = vec_a.size();
    std::vector<std::vector<float>> output (rows, std::vector<float>(cols, 0));

    for (int i = 0; i<rows; i++)
        for (int j = 0; j<cols; j++)
            output[i][j] = vec_a[i] * vec_b[j];

    return output;
}


int main()
{
  std::vector<std::vector<float>> weights = {
    {0.1, 0.1, -0.3},
    {0.1, 0.2, 0.0},
    {0.0, 1.3, 0.1} };

  // Inputs
  std::vector<float> toes = {8.5, 9.5, 9.9, 9.0};
  std::vector<float> wlrec = {0.65, 0.8, 0.8, 0.9};
  std::vector<float> nfans = {1.2, 1.3, 0.5, 1.0};

  // Goal pred
  std::vector<float> hurt = {0.1, 0.0, 0.0, 0.1};
  std::vector<float> win = {1, 1, 0, 1};
  std::vector<float> sad = {0.1, 0.0, 0.1, 0.2};

  float alpha = 0.01;

  std::vector<float> input = {toes[0], wlrec[0], nfans[0]};
  std::vector<float> goal_pred = {hurt[0], win[0], sad[0]};

  std::vector<float> pred = neural_network(input, weights);

  std::vector<float> error = {0, 0, 0};
  std::vector<float> delta = {0, 0, 0};

  for(int i=0; i<int(goal_pred.size()); i++)
  {
    delta[i] = pred[i] - goal_pred[i];
    error[i] = pow(delta[i], 2);
  }

  std::cout << "Predictions : ";
  for(float prediction : pred)
    std::cout << prediction << " ";

  std::vector<std::vector<float>> weight_deltas = outer_prod(input, delta);

  for(int i=0; i<int(weights.size()); i++)
    for(int j=0; j<int(weights[0].size()); i++)
      weights[i][j] -= alpha * weight_deltas[i][j];

  return 0;
}
