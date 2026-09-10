#include "kangaroo.h"
#include <cstring>

int main(int argc, char* argv[]) {
    Config config;
    config.start_hex = "400000000000000000";
    config.end_hex = "7fffffffffffffffff";
    config.pubkey_hex = "0290e6900a58d33393bc1097b5aed31f2e4e7cbd3e5466af958665bc0121248483";

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-start") == 0 && i + 1 < argc) config.start_hex = argv[++i];
        else if (strcmp(argv[i], "-end") == 0 && i + 1 < argc) config.end_hex = argv[++i];
        else if (strcmp(argv[i], "-pubkey") == 0 && i + 1 < argc) config.pubkey_hex = argv[++i];
        else if (strcmp(argv[i], "-cpu") == 0) config.use_gpu = false;
        else if (strcmp(argv[i], "-threads") == 0 && i + 1 < argc) config.threads = std::stoi(argv[++i]);
    }

    std::cout << "=== Bitcoin Puzzle Solver (Kangaroo - secp256k1) ===\n";
    std::cout << "Target PubKey : " << config.pubkey_hex << "\n";
    std::cout << "Range         : [" << config.start_hex << " ; " << config.end_hex << "]\n";

    if (config.use_gpu) {
        run_kangaroo_gpu(config);
    } else {
        run_kangaroo_cpu(config);
    }

    return 0;
}