# Bitcoin Puzzle 71 - Kangaroo Solver (CUDA & CPU)

Solveur de clé privée Bitcoin basé sur l'algorithme **Pollard's Kangaroo** optimisé avec la symétrie par négation ($-P$) pour `secp256k1`.

## Fonctionnalités
- Support GPU NVIDIA (CUDA) et CPU multi-threading (AVX2).
- Optimisation pour le Puzzle 71 (Plage $2^{70}$ à $2^{71}-1$).

## Compilation
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)