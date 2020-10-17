#include <iostream>
#include <math.h>

int main()
{
  float alpha = 0.1;
  float weight = 0.5;
  float input = 2;
  const float goal_pred = 0.8;

  for(int i=0; i<20; i++)
  {
    float prediction = input * weight;
    float error = pow(prediction - goal_pred, 2);
    float derivative = (prediction - goal_pred) * input;
    weight -= alpha * derivative;

    std::cout << "Error: " << error << " Prediction: " << prediction << std::endl;
  }

  return 0;
}

