#include <stdio.h>
#include <stdlib.h>


float step(float z)
{
    return z >= 0.0f?1.0f : 0.0f ; 
}

int main(){

    float x1 = 0.7f , x2 = 0.5f;
    float w1 = 0.2f , w2 = 0.5f;


    float b = -0.7f;


    float z = (x1*w1 + x2*w2)+b;

    float y = step(z);

    printf("%.2f \n",y);

}