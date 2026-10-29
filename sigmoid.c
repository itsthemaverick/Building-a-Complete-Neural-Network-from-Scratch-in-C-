#include <stdio.h>
#include <math.h>

static float sigmoid(float z)
{

    return 1.0f / (1.0f + expf(-z));
}

int main()
{

    float w0 = 0.2f, w1 = 0.1f, b = -0.2f;

    float X[4][2] = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};

    int s;

    printf("AND Gate with Sigmoid Activation : \n");
    for ( s = 0; s < 4; s++)
    {
        float z = (X[s][0]*w0 + X[s][1]*w1)- b;
        float sig = sigmoid(z);
        float dsig = sig*(1.0f - sig);

        printf("%.0f %.0f -> sigmiod=%.4f derivative = %.4f \n",X[s][0],X[s][1],sig,dsig);
    }
    return 0;
}