#include <iostream>
#include <math.h>

float neural_network(float input, float weight)
{
  float prediction = input * weight;

  return prediction;
}

int main()
{
  const float alpha = 0.01;
  float weight = 0.1;

  float number_of_toes = 8.5;
  float goal_pred = 1;

  float input = number_of_toes;

  float prediction = neural_network(input, weight);

  float delta = prediction - goal_pred;
  float error = pow(delta, 2);

  float weight_delta = input * delta;

  weight -= weight_delta * alpha;

  return 0;
}
