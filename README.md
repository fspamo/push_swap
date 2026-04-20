*This project has been created as part of the 42 curriculum by melipola, cbozkurt.*

# push_swap

> Because swap_push doesn't feel as natural.

---

## Description

**push_swap** is a sorting algorithm project from the 42 curriculum. The goal is to sort a stack of integers using only two stacks (`a` and `b`) and a restricted set of operations, while generating the **smallest possible number of moves**.

The project enforces a concrete understanding of algorithmic complexity by requiring four distinct sorting strategies with different complexity classes. The program selects the most appropriate strategy either manually (via flags) or automatically based on a **disorder metric** computed from the initial stack.

---

## Allowed Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the top two elements of stack a |
| `sb` | Swap the top two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top of b onto a |
| `pb` | Push the top of a onto b |
| `ra` | Rotate a upward (top becomes bottom) |
| `rb` | Rotate b upward |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate a (bottom becomes top) |
| `rrb` | Reverse rotate b |
| `rrr` | `rra` and `rrb` simultaneously |

---

## Instructions

### Compilation

```bash
make
```

This produces the `push_swap` binary. Use `make clean` to remove object files, `make fclean` to remove everything, and `make re` to recompile from scratch.

### Usage

```bash
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <integers>
```

**Strategy flags (optional):**

| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Bubble sort | O(n²) |
| `--medium` | Chunk sort | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Auto-select based on disorder | varies |

If no strategy flag is given, `--adaptive` is used by default.

If multiple strategies given, the program proceeds with the last given strategy since it wasn't clarified enough in the 
subject and it's programmers' desire to handle.

**`--bench` flag:** Prints sorting statistics (disorder, strategy used, total ops, per-operation counts) to `stderr` after sorting.

### Examples

```bash
# Basic sort
./push_swap 5 3 1 4 2

# Force radix sort
./push_swap --complex 5 3 1 4 2

# Count operations on 500 random numbers
shuf -i 0-9999 -n 500 > args.txt
./push_swap $(cat args.txt) | wc -l

# View benchmark stats
./push_swap --bench --adaptive 4 67 3 87 23 2>/dev/null

# Verify output is correct
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

### Error Handling

The program prints `Error` to `stderr` and exits if:
- Any argument is not a valid integer
- There are duplicate values

---

## Algorithms

### Disorder Metric

Before any sorting begins, the program computes a **disorder score** between `0.0` (already sorted) and `1.0` (fully reversed). It counts adjacent inversions:

```
disorder = inversions / (n - 1)
```

This score drives the adaptive strategy selection.

### 1. Simple — Bubble Sort `O(n²)`

A straightforward bubble sort adapted for stack operations. In each pass, the top of stack `a` is compared with its neighbor using `sa`, and `ra` advances through the list. After each full pass, `rra` resets the stack. Simple and reliable for nearly-sorted inputs.

**Used when:** `--simple` flag or adaptive with disorder `< 0.2`.

### 2. Medium — Chunk Sort `O(n√n)`

Elements are first **indexed** (ranked 0 to n-1). The stack is then divided into chunks of size `√n`. Elements are pushed to `b` chunk by chunk; elements already in the right chunk range get pushed and immediately rotated to the bottom of `b` (`pb` + `rb`), keeping the next chunk on top. Once all elements are in `b`, the maximum index is found and rotated to the top of `b` before each `pa`, reconstructing a sorted `a` in descending-index order.

**Used when:** `--medium` flag or adaptive with disorder `0.2 ≤ d < 0.5`.

### 3. Complex — Radix Sort LSD `O(n log n)`

Elements are indexed (0 to n-1) and sorted bit by bit, from least significant to most significant. For each bit position, every element is examined: if the current bit is `0`, it goes to `b` via `pb`; if `1`, it stays in `a` via `ra`. After each pass, all elements from `b` are pushed back to `a`. After `log₂(n)` passes, the stack is sorted.

**Space complexity:** O(1) auxiliary (no arrays — only the two stacks are used).

**Used when:** `--complex` flag or adaptive with disorder `≥ 0.5`.

### 4. Adaptive — Auto-select

Computes the disorder before any move, then delegates to one of the three strategies above:

| Disorder range | Strategy chosen | Complexity |
|----------------|-----------------|------------|
| `d < 0.2` | Bubble sort | O(n²) |
| `0.2 ≤ d < 0.5` | Chunk sort | O(n√n) |
| `d ≥ 0.5` | Radix sort | O(n log n) |

The thresholds were chosen empirically: at low disorder, bubble sort's overhead is minimal and avoids the indexing cost of heavier algorithms. At medium disorder, chunk sort balances simplicity and efficiency. At high disorder, radix sort's consistent O(n log n) behaviour avoids worst-case blowups.

For inputs of 5 or fewer elements, a dedicated hardcoded solver is used regardless of strategy.

---

## Performance Targets

| Input size | Pass | Good | Excellent |
|------------|------|------|-----------|
| 100 numbers | < 2000 ops | < 1500 ops | < 700 ops |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

---

## Contributions

| Login | Contributions |
|-------|--------------|
| `cbozkurt` | Core architecture, parsing, stack operations, radix sort, chunk sort, indexer, disorder metric, benchmark system, Makefile |
| `melipola` | Bubble sort, memory management and safe coding, input validation & parsing, five-or-less solver, chunk sort, argument handling, header consolidation, testing |

---

## Resources

- [Sorting algorithm visualizer](https://visualgo.net/en/sorting) — helpful for understanding algorithm behavior visually
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — visualizes your push_swap output in real time
- [Radix sort explained](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O cheat sheet](https://www.bigocheatsheet.com/)
- Knuth, D. E. — *The Art of Computer Programming, Vol. 3: Sorting and Searching*

### AI Usage

Claude (Anthropic) was used during this project for the following tasks:
- Explaining algorithmic concepts (radix sort bit manipulation, chunk partitioning strategy)
- Reviewing edge cases in input validation logic
- Drafting and refining this README

All AI-generated suggestions were reviewed, understood, and either adopted, modified, or rejected by both team members before inclusion in the project.
