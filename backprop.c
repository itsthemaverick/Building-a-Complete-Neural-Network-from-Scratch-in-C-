#include <stdio.h>
#include <math.h>

//
static float sigmoid(float z){
    return 1.0f/(1.0 + expf(-z));
}