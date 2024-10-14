
# Marriage Pact Program

This program reads a list of student names from a file and finds matches based on specified criteria using C++ Standard Library containers such as `set` and `queue`. The program demonstrates how to use input/output streams, containers, and pointers to manage and manipulate student names.

## Table of Contents

- [Overview](#overview)
- [File Structure](#file-structure)
- [Functions](#functions)
- [Usage](#usage)
- [Compilation](#compilation)
- [Example](#example)

## Overview

The program consists of two main parts:
1. **Get Applicants**: Reads student names from a file and stores them in a `set` to ensure uniqueness.
2. **Find Matches**: Finds students whose first name starts with 'J' and last name starts with 'H', returning a queue of pointers to the matching student names.

## File Structure

- `students.txt`: The file containing the list of student names. Each line contains a full name (first and last).
- `main.cpp`: The main C++ program file.
- `README.md`: This documentation file.

## Functions

### 1. `std::set<std::string> get_applicants(std::string filename)`
This function reads student names from a given file and returns a `set` of student names to ensure uniqueness.

- **Parameters**: 
  - `filename`: The path to the input file (e.g., `students.txt`).
- **Returns**: A `std::set<std::string>` containing the student names.

### 2. `std::queue<const std::string *, std::list<const std::string *>> find_matches(std::set<std::string> &students)`
This function takes the `set` of student names and searches for names where:
- The first letter of the first name is 'J'.
- The first letter of the last name is 'H'.
Matching names are returned as a queue of pointers to the student names.

- **Parameters**: 
  - `students`: A `std::set<std::string>` containing the list of student names.
- **Returns**: A `std::queue<const std::string *, std::list<const std::string *>>` containing pointers to matching names.

### 3. `void print_applicants(std::set<std::string> applicants)`
Prints all student names stored in the `set`.

### 4. `void print_matches(std::queue<const std::string *, std::list<const std::string *>> matches)`
Prints all matched student names stored in the queue. If no matches are found, it prints `"NO STUDENT FOUND."`.

## Usage

1. Add the student names to `students.txt`. Each line should contain one full name (first and last name).
2. Compile the program (see below).
3. Run the program. The program will:
   - Read names from `students.txt`.
   - Print the names of students whose first name starts with 'J' and last name starts with 'H'.

## Compilation

To compile the program, use a C++ compiler like `g++`:

```bash
g++ -o marriage_pact main.cpp
```

This will generate an executable file called `marriage_pact`.

## Example

### Input (`students.txt`):

```
John Harris
Jane Hill
Alex Smith
Jenny Hope
Jack Harper
James Hook
```

### Expected Output:

```
John Harris
Jenny Hope
Jack Harper
James Hook
```

If no students match the criteria, the output will be:

```
NO STUDENT FOUND.
```

## Notes

- Ensure the input file `students.txt` is in the correct location and properly formatted.
- The matching criteria can be easily modified in the `find_matches()` function by adjusting the conditional logic.

