#include <iostream>
#include <vector>
#include <math.h>
#include "../include/mathFuncs.h"

int main()
{
  std::vector<float> weights = {0.5, 0.48, -0.7};
  float alpha = 0.1;

  std::vector<std::vector<float>> streetlights = {
    {1, 0, 1},
    {0, 1, 1},
    {0, 0, 1},
    {1, 1, 1},
    {0, 1, 1},
    {1, 0, 1} };

  std::vector<float> walk_vs_stop = {0, 1, 0, 1, 1, 0};

  std::vector<float> input = streetlights[0];
  float goal_prediction = walk_vs_stop[0];

  for(int i=0; i<20; i++)
  {
    float prediction = mf::dot_product(input, weights);
    float delta = prediction - goal_prediction;
    float error = pow(delta, 2);
    weights = mf::vect_subt(weights, mf::scalar_mult(alpha, (mf::scalar_mult(delta, input))));

    std::cout << "Error: " << error << " Prediction: " << prediction << std::endl;
  }

  return 0;
}
