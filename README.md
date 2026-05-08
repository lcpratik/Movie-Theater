# Movie Theater

A command-line cinema seat management program written in C. Reads a theater layout from a file, lets a customer purchase up to four seats interactively, and writes the updated layout back to an output file.

## Features

- Loads seat map from a text file (rows × columns, `X` marks taken seats)
- Enforces a four-ticket-per-transaction limit
- Prevents double-booking — already-sold seats are rejected immediately
- Prints a formatted seat map before each selection
- Saves the updated layout to a new output file after purchase

## Tech Stack

| Layer  | Technology |
|--------|------------|
| Language | C (C99)  |
| I/O    | Standard file I/O (`stdio.h`) |
| Build  | GCC / any C compiler |

## Project Structure

```
movie-theater/
└── Movie Theater.c   # All logic in a single self-contained file
```

## Getting Started

### Compile

```bash
gcc "Movie Theater.c" -o movie_theater
```

### Input File Format

The first line is `<rows> <cols>`, followed by rows of seat characters (`O` = available, `X` = taken):

```
3 5
OOOOO
OOXOO
OOOOO
```

### Run

```bash
./movie_theater
```

The program will prompt for the input filename, the number of tickets, seat selections (e.g. `A2`), and an output filename.

## Author

**Pratik Lamichhane** · [GitHub](https://github.com/lcpratik) · [LinkedIn](https://linkedin.com/in/lcpratik)
