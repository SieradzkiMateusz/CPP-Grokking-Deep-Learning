#include <iostream>
#include <cassert>
#include <math.h>
#include <vector>


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


float neural_network(std::vector<float> input, std::vector<float> weights)
{
  float out = 0;
  for(int i=0; i<int(input.size()); i++)
    out += (input[i] * weights[i]);

  return out;
}


int main()
{
  std::vector<float> toes = {8.5, 9.5, 9.9, 9.0};
  std::vector<float> wlrec = {0.65, 0.8, 0.8, 0.9};
  std::vector<float> nfans = {1.2, 1.3, 0.5, 1.0};

  std::vector<float> weights = {0.1, 0.2, -.1};

  std::vector<float> win_or_lose_binary = {1, 1, 0, 1};

  float goal_pred = win_or_lose_binary[0];

  float alpha = 0.01;

  std::vector<float> input = {toes[0], wlrec[0], nfans[0]};

  for(int i=0; i<3; i++)
  {
    float pred = neural_network(input, weights);

    float delta = pred - goal_pred;
    float error = pow(delta, 2);

    std::vector<float> weight_deltas = ele_mul(delta, input);

    std::cout << "Iteration: " << i+1 << std::endl;
    std::cout << "Prediction: " << pred << std::endl;
    std::cout << "Error: " << error << std::endl;
    std::cout << "Delta: " << delta << std::endl;
    std::cout << "Weights: [";
    for(float weight : weights)
      std::cout << weight << " ";
    std::cout << "]\nWeight_deltas: [";
   for(float wd : weight_deltas)
    std::cout << wd << " ";
   std::cout << "]\n"; 

   for(int i=0; i<int(weights.size()); i++)
     weights[i] -= alpha * weight_deltas[i];
  }

  return 0;
}
