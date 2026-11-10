#include <stdio.h>
#include <math.h>



static float sigmiod(float z){
    return 1.0f / (1.0f + expf(-z));
}

typedef struct {
    float wh[2][2];
    float bh[2];
    float wo[2];
    float bo;
}Net;

static float forward( const Net *n, const float x[2],const h[2]){
    int i , j;
    
}
