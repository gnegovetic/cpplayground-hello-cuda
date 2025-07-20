#include "stdio.h"

__global__ void HelloCuda() {
    printf("Hello from GPU, block (%d,%d,%d), thread(%d,%d,%d)\n", 
        blockIdx.x, blockIdx.y, blockIdx.z, threadIdx.x, threadIdx.y, threadIdx.z);
}

void launchKernel() {
    HelloCuda<<<dim3(3,1,1), dim3(2,1,1)>>>();
}
