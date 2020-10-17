#include <iostream>
#include <math.h>

const float lr = 0.01;

float neural_network(float input, float weight)
{
  float prediction = input * weight;

  return prediction;
}

int main()
{
  float weight = 0.1;
  float number_of_toes = 8.5;
  bool result = 1;

  float input = number_of_toes;

  float pred = neural_network(input, weight);

  float error = pow(pred - result, 2);

  std::cout << "Error: " << error << std::endl;

  // Compare with weight up
  float prediction_up = neural_network(input, weight+lr);
  float error_up = pow(prediction_up - result, 2);
  
  std::cout << "Error_up: " << error_up << std::endl;

  // Compare with weight down
  float prediction_down = neural_network(input, weight-lr);
  float error_down = pow(prediction_down - result, 2);

  std::cout << "Error_down: " << error_down << std::endl;

  if(error > error_down || error > error_up)
  {
    if(error_down < error_up)
      weight -= lr;
    else
      weight += lr;
  }
  
  return 0;
}
