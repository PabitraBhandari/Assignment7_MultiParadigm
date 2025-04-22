# Multi-Paradigm Problem Solving: Mean, Median, and Mode

This project explores how the same problem can be solved using three different programming paradigms. The task is simple: calculate the mean, median, and mode of a list of integers. But the goal is deeper — to understand how programming style impacts how we think and build solutions.

## Objective

“Different tools for different minds.”  
This project demonstrates how programming paradigms — procedural, functional, and object-oriented — shape how we approach problem-solving.

Given a list of integers, each version calculates:
- Mean – The average
- Median – The middle value
- Mode – The most frequent number(s)

## Three Languages, Three Styles

| Language | Paradigm           | Description |
|----------|--------------------|-------------|
| C        | Procedural         | Step-by-step logic with manual memory and array handling |
| OCaml    | Functional         | Pure functions, no loops or mutable state |
| Python   | Object-Oriented    | Class-based, using encapsulation and built-in tools |

## What You'll Find Inside
```
MultiParadigmStats/
├── C/           → Pure procedural code with functions and arrays  
├── OCaml/       → Functional approach using recursion and lists  
├── Python/      → Class-based object-oriented implementation
```

## Run It Yourself

### C
```bash
cd C  
gcc stats.c -o stats  
./stats
```
### OCaml
```bash
cd OCaml  
ocaml stats.ml
```

### Python
```bash
cd Python  
python3 stats.py
```
