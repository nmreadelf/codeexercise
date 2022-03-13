#include <stdio.h>
#include <math.h>
#include <stdbool.h>

const double GOODENOUGH = 0.001;

bool good_enough(double x, double guess) {
  if (fabs(x-guess*guess) < 0.001) {
    return true;
  }
  return false;
}

double improve(double x, double y) {
  return (x+y)/2;
}


double square_iter(double x, double guess) {
  if (good_enough(x, guess)) {
    return guess;
  } else {
    return square_iter(x, improve(x/guess, guess));
  }
}

double square(double x) {
  return square_iter(x, 1.0);
}


int main() {
  printf("square root of 4: %f\n", square(4));
  printf("square root of 2: %f\n", square(2));
  return 0;
}
