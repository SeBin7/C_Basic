# C_Basic

This repository is for practicing **C fundamentals** with a focus on  
memory, system-level concepts, optimization, and parallel programming.  
The structure follows a learning roadmap: from basic syntax to advanced performance tuning.  
Additionally, it includes a **Docker-based development environment** for reproducibility.

---

## Folder Structure
- `00_practice/` : Practice examples
- `01_basics/` : Basic syntax (variables, operators, functions, arrays, strings, structs, enums)
- `02_system/` : Memory model, pointers, bit operations, compilation & linking
- `03_optimization/` : Compiler flags, memory access patterns, loop optimizations, profiling
- `04_parallel/` : Multithreading (pthreads), process & IPC, OpenMP, CUDA introduction

---

## Commit Convention
We follow [Conventional Commits](https://www.conventionalcommits.org/) style:

**Pattern**
```
<type>(<scope>): <subject>
```

### Types
- `feat` ¡æ new feature  
- `fix` ¡æ bug fix  
- `docs` ¡æ documentation only  
- `style` ¡æ formatting, code style only  
- `refactor` ¡æ code change that neither fixes a bug nor adds a feature  
- `test` ¡æ add or modify tests  
- `chore` ¡æ maintenance tasks (build, configs, deps)  


### Examples
- `feat(basics): add hello world and array sum examples`
- `feat(system): implement pointer swap and bit operations`
- `feat(optimization): add loop unrolling demo`
- `feat(parallel): add pthread thread_demo`
- `docs: update README with roadmap`

---

## Development Workflow
1. Write exploration and small demo code in each section
2. Use **CMake** to organize and build all executables
3. Keep build artifacts inside `/build/` or `/out/` (ignored by git)
4. Commit with clear type and scope
5. Push and review via GitHub

---

## Build Instructions (WSL/Ubuntu)
```bash
# Install build tools
sudo apt update && sudo apt install -y build-essential cmake ninja-build

# Configure & build
mkdir build && cd build
cmake .. -G Ninja
cmake --build . -j
```

## Run executables:
```bash
./practice      # from 00_practice
./basics        # from 01_basics
```

---

## Docker Development Environment
A reproducible dev environment is provided with **docker-compose.yml**.

### Run 00_practice
```bash
docker compose up run_practice
```

### Run 01_basics
```bash
docker compose up run_basics
```


### Stop container
```bash
docker compose down
```


### Exit container
```bash
exit
```