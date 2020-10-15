#include <iostream>
#include <math.h>

int main()
{
  const float input = 0.5;
  const float goal_prediction = 0.8;
  const float step_amount = 0.001;

  float weight = 0.5;

  for(int i=0; i<1101; i++)
  {
    float prediction = input * weight;
    float error = pow(prediction - goal_prediction,  2);

    std::cout << "Error: " << error << " Prediction: " << prediction << std::endl;

    float up_prediction = input * (weight + step_amount);
    float up_error = pow(goal_prediction - up_prediction, 2);

    float down_prediction = input * (weight - step_amount);
    float down_error = pow(goal_prediction - down_prediction, 2);

    if(down_error < up_error)
      weight = weight - step_amount;
    else if(down_error > up_error)
      weight = weight + step_amount;
  }

  return 0;
}
