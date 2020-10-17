#include <iostream>
#include <math.h>

int main()
{
  float weight = 0.0, goal_pred = 0.8, input = 0.5;

  for(int i=0; i<20; i++)
  {
    std::cout << "-----\nWeight: " << weight << std::endl;
    float pred = input * weight;
    float delta = pred - goal_pred;
    float error = pow(delta, 2);
    float weight_delta = delta * input;
    weight -= weight_delta;

    std::cout << "Error: " << error << " Prediction: " <<  pred << std::endl;
    std::cout << "Delta: " << delta << " Weight delta: " << weight_delta << std::endl;
  }

  return 0;
}
