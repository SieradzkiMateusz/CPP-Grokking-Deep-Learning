#include <iostream>
#include <vector>
#include <cassert>


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


std::vector<float> neural_network(float input, std::vector<float> weights)
{
  std::vector<float> prediction = ele_mul(input, weights);

  return prediction;
}


int main()
{
  std::vector<float> weights = {0.3, 0.2, 0.9};

  std::vector<float> wlrec = {0.65, 0.8, 0.8, 0.9};
  float input = wlrec[0];

  std::vector<float> predictions = neural_network(input, weights);
  
  std::cout << "Predictions: ";

  for(float prediction : predictions)
  {
    std::cout << prediction << " ";
  }

  return 0;
}
 
