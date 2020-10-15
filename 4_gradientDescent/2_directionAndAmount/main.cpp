#include <iostream>
#include <math.h>

int main()
{
  const float goal_pred = 0.8;
  const float input = 0.5;

  float weight = 0.5;

  for(int i=0; i<20; i++)
  {
    float pred = input * weight;
    float pure_error = pred - goal_pred;
    float error = pow(pure_error, 2);

    float direction_and_amount = pure_error * input;
    weight -= direction_and_amount;

    std::cout << "Error: " << error << " Prediction: " << pred << std::endl;
  }

  return 0;
}
