#include "cuda_runtime.h"
#include <iostream>
#include <format>
#include "hello_cuda.cuh"

int main()
{
    // Choose which GPU to run on, change this on a multi-GPU system.
    auto cudaStatus = cudaSetDevice(0);
    if (cudaStatus != cudaSuccess) {
        std::cerr << "cudaSetDevice failed!  Do you have a CUDA-capable GPU installed?" << std::endl;
        return -1;
    }

    std::cout << "Hello from CPU\n";

    launchKernel();
    cudaStatus = cudaGetLastError();
    if (cudaStatus != cudaSuccess) {
        std::cerr << std::format("Error launching kernel: {}\n", cudaGetErrorString(cudaStatus));
        return -1;
    }

    cudaStatus = cudaDeviceSynchronize();
    if (cudaStatus != cudaSuccess) {
        std::cerr << std::format("Kernel launch failed: {}\n", cudaGetErrorString(cudaStatus));
        return -1;
    }

    std::cout << "Done\n";
    return 0;
}
