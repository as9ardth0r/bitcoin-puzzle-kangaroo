#ifndef KANGAROO_H
#define KANGAROO_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>

struct Config {
    std::string start_hex;
    std::string end_hex;
    std::string pubkey_hex;
    int threads = 4;
    bool use_gpu = true;
};

// Prototype du kernel GPU CUDA
void run_kangaroo_gpu(const Config& config);

// Prototype du solver CPU
void run_kangaroo_cpu(const Config& config);

#endif // KANGAROO_H