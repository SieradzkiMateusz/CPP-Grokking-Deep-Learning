#include <iostream>
#include <vector>
#include <cassert>

// --- Challenge: Vector math --- 

float elementwise_multiplication(std::vector<float> vec_a, std::vector<float> vec_b)
{
  assert(vec_a.size() == vec_b.size());
  
  float output = 0;

  for(int i=0; i<int(vec_a.size()); i++)
  {
   output += (vec_a[i] * vec_b[i]); 
  }
  
  return output;
}

float vector_sum(std::vector<float> vec_a)
{
  float output = 0;
  
  for(int i : vec_a)
  {
    output += vec_a[i];
  }

  return output;
}

float vector_average(std::vector<float> vec_a)
{
  float sum = vector_sum(vec_a);
  float output = sum/vec_a.size();
  
  return output;
}

// --- Challenge end --- 

float w_sum(std::vector<float> vec_a, std::vector<float> vec_b)
{
  assert(vec_a.size() == vec_b.size());
  float output = elementwise_multiplication(vec_a, vec_b);
  
  return output;
}

float neural_network(std::vector<float> input, std::vector<float> weights)
{
  float prediction = w_sum(input, weights);
  return prediction;
}

int main()
{
  std::vector<float> weights = {0.1, 0.2, 0};
  std::vector<float> toes = {8.5, 9.5, 10, 9};
  std::vector<float> wlrec = {0.65, 0.8, 0.8, 0.9};
  std::vector<float> nfans = {1.2, 1.3, 0.5, 1.0};

  std::vector<float> input = {toes[0], wlrec[0], nfans[0]};
  
  float prediction = neural_network(input, weights);
  
  std::cout << "Prediction: " << prediction << std::endl;

  return 0;
}
