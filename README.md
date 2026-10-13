# Quadratic Equation Solver

An educational C++ project built around a familiar math problem: solve a quadratic equation. The goal was to treat even a small task like a complete software project, with separate modules, clear interfaces, automated tests, input checks, and a repeatable build.

The program reads `ax² + bx + c = 0`, handles quadratic, linear, and degenerate cases, prints the equation and its roots, and plots the corresponding function with [raylib](https://www.raylib.com/).

## What the project practices

- Breaking a program into modules with distinct responsibilities.
- Separating declarations in headers from implementations in source files.
- Checking behavior with reference, file-driven, and generated tests.
- Handling invalid console input and reporting test failures.
- Building with strict compiler warnings and runtime sanitizers through a Makefile.

## Tests

At startup, the program asks whether to run its test suite.

- **Unit-style reference tests:** 9 hand-written cases compare the solver's reported number of roots and root values with known answers. They cover quadratic, linear, repeated-root, no-root, and infinitely-many-solutions cases.
- **File-driven tests:** cases from `tests.txt` are solved and checked by substituting each reported root back into the original equation.
- **Generated tests:** 100 coefficient sets are generated and checked by substitution as well.

The `smart_tests` file contains formatted examples with expected results.

## File guide

### Application code

| File | Responsibility |
|---|---|
| `src/main.cpp` | Coordinates the application flow: offers testing, reads coefficients, solves the equation, prints the result, and opens the graph window. |
| `src/square_equation.cpp` | Implements the math: dispatches between quadratic and linear cases, computes the discriminant, and classifies the number of solutions. |
| `src/input_output.cpp` | Handles console interaction: reads coefficients, formats the equation and roots, and reports test results. |
| `src/testing_solving.cpp` | Runs the reference, file-driven, and generated tests; checks roots by substitution and compares reference answers. |
| `src/painting.cpp` | Draws the coordinate grid and the function graph, and converts between mathematical and screen coordinates. |
| `src/tehnical_fiches.cpp` | Implements shared helpers for approximate float comparison, input-buffer cleanup, random values, yes/no answers, and console output. |

### Headers and shared declarations

| File | Responsibility |
|---|---|
| `header/general.h` | Defines the equation and coefficient structures, solution-count values, comparison tolerance, and console color constants. |
| `header/square_equation.h` | Declares the equation-solving functions. |
| `header/input_output.h` | Declares console input, equation/root output, and test-reporting functions. |
| `header/testing_solving.h` | Declares the test runner and stores the reference cases and test constants. |
| `header/painting.h` | Declares graph-drawing functions and screen/coordinate settings. |
| `header/tehnical_fiches.h` | Declares the shared helper functions. |

### Build, test, and documentation files

| File | Responsibility |
|---|---|
| `Makefile` | Builds the program from its modules and provides a `clean` target. |
| `flags` | Lists compiler warning, debugging, and sanitizer options used for development. |
| `tests.txt` | Supplies coefficient sets for file-driven tests. |
| `smart_tests` | Keeps readable examples of test cases with expected roots and solution counts. |
| `latex/refman.tex` | LaTeX source for the generated Doxygen reference manual. |
| `.vscode/tasks.json` | VS Code build-task configuration for the active C/C++ file. |

## Build and run

The project uses C++17, GNU Make, and raylib (with SDL2):

```bash
make
./programm
```

To remove the executable and object files:

```bash
make clean
```
