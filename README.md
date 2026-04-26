# Mini CP Judge (C++)

This project simulates a simplified competitive programming judge.
It automates compilation, execution, and output verification of user programs.

This project simulates a simplified competitive programming judge.
It automates compilation, execution, and output verification of user programs.

A minimal competitive programming judge implemented in C++.
It compiles a user-provided source file, runs it with predefined input, captures the output, and compares it against an expected output.

---

## Features

* Verifies existence of the source file
* Compiles code using `g++`
* Executes program with file-based input/output redirection
* Stores program output in `output.txt`
* Compares output with expected results
* Prints verdict (`OK` or `WRONG ANSWER`)
* Ignores whitespace differences during comparison

---

## Project Structure

```
mini-cp-judge/
├── judge.cpp        # Main judge program
├── input.txt        # Input for the tested program
├── expected.txt     # Expected correct output
├── output.txt       # Generated output (created at runtime)
├── .gitignore
└── README.md
```

---

## Requirements

* Linux / WSL / Unix-like environment
* `g++` compiler installed

Check compiler:

```bash
g++ --version
```

---

## How to Use

### 1. Compile the Judge

```bash
g++ judge.cpp -o judge
```

---

### 2. Run the Judge

```bash
./judge
```

---

### 3. Provide Source File

When prompted, enter the filename:

```
tst.cpp
```

---

### 4. Execution Flow

The judge performs:

1. File existence check
2. Compilation:

   ```
   g++ tst.cpp -o tst
   ```
3. Execution:

   ```
   ./tst < input.txt > output.txt
   ```
4. Comparison:

   ```
   output.txt vs expected.txt
   ```
5. Verdict output:

   * `OK`
   * `WRONG ANSWER`

---

## Example

Given:

```
tst.cpp
input.txt
expected.txt
```

Run:

```bash
./judge
```

Output:

```
Compilation Successful
OK
```

---

## Comparison Method

* Uses token-based comparison (`>>`)
* Ignores:

  * extra spaces
  * line breaks
* Detects:

  * mismatched values
  * missing/extra tokens

---

## Limitations

* Supports only `.cpp` files
* No time limit enforcement
* No memory limit enforcement
* No sandboxing (executes code directly)
* No floating-point tolerance handling
* Basic error reporting

---

## Future Improvements

* Support for multiple test cases
* Floating-point comparison with tolerance
* Time and memory constraints
* Safer execution (sandboxing)
* Command-line argument support
* Detailed diff output on failure

---

## Notes

This project is intended for learning:

* file handling in C++
* system command execution (`system()`)
* basic judge workflow
* interaction between programs and OS

