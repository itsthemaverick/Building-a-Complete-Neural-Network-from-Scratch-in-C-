#include <stdio.h>
#include <math.h>

//
static float sigmoid(float z){
    return 1.0f/(1.0 + expf(-z));
}
//
typedef struct{
    float wh[2][2];
    float bh[2];
    float wo[2];
    float bo;
}Net;

static float forward(const Net *n,const float x[2],float h[2]){
    int i,j;

    for ( i = 0; i < 2; i++)
    {
        float z = n->bh[i];
        for ( j = 0; j < 2; j++)
        {
            z += n->wh[i][j]*x[j];
        }
        h[i] = sigmoid(z);
    }
    {
        float z = n->bo;
        for ( i = 0; i < 2; i++)
        {
            z += n->wo[i]*h[i];
        }
        return sigmoid(z);
    }
    
}
static void backward(Net *n, const float x[2],
                      const float h[2],
                      float y, float t, float lr)
{
    int i, j;
    float delta_out, delta_h[2];

    /* Output delta: d_loss/dy * dy/dz_out */
    delta_out = -2.0f * (t - y) * y * (1.0f - y);

    /* Hidden deltas: error flows back through wo */
    for (i = 0; i < 2; i++)
        delta_h[i] = delta_out * n->wo[i]
                     * h[i] * (1.0f - h[i]);
    for (i = 0; i < 2; i++)
        n->wo[i] -= lr * delta_out * h[i];
    n->bo -= lr * delta_out;

    /* Update hidden weights and biases */
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            n->wh[i][j] -= lr * delta_h[i] * x[j];
        n->bh[i] -= lr * delta_h[i];
    }
}
static void init_random(Net *n)
{
    int i, j;
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++)
            n->wh[i][j] =
                ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        n->bh[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
        n->wo[i] = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    }
    n->bo = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
}
