<p align="center">
  <a href="" rel="noopener">
    <img width="200px" height="200px" src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/18/C_Programming_Language.svg/1200px-C_Programming_Language.svg.png" alt="C Logo">
  </a>
</p>

<h3 align="center">Shell Basics</h3>

<div align="center">

[![Status](https://img.shields.io/badge/status-completed-success.svg)]()
[![Language](https://img.shields.io/badge/language-C-blue.svg)]()
[![License](https://img.shields.io/badge/license-none-lightgrey)]()

</div>

---

<p align="center"> C programs exploring Linux system calls, process management, and shell fundamentals.
    <br> 
    <i>Holberton School France — Low-Level Programming</i>
</p>

## 📝 Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [Exercises](#exercises)
- [Usage](#usage)
- [Built Using](#built_using)
- [Authors](#authors)
- [Acknowledgements](#acknowledgement)

## 🧐 About <a name = "about"></a>

This repository contains C programs written as part of the Holberton School shell and system programming curriculum. The exercises cover process IDs, command-line argument parsing, reading from stdin, and executing external programs.

## 🏁 Getting Started <a name = "getting_started"></a>

### Prerequisites

- GCC compiler
- Linux/Unix environment

### Compiling

Clone and compile:

```bash
git clone https://github.com/hugou74130/shell.git
cd shell
gcc -Wall -Wextra -Werror -pedantic *.c -o shell
```

## 📝 Exercises <a name = "exercises"></a>

| File | Description |
|------|-------------|
| `0.av.c` | Print command-line arguments |
| `0.getppid.c` | Display parent process ID |
| `1.readline.c` | Read a line from standard input |
| `1.procsyskernelpidmax` | Read max PID from procfs |
| `2.commandlinetoav.c` | Tokenize command line into arguments |
| `Executing a program.c` | Execute an external program |

## 🎈 Usage <a name = "usage"></a>

Run individual compiled binaries:

```bash
./0.getppid
./0.av hello world
./1.readline
```

## ⛏️ Built Using <a name = "built_using"></a>

- [C](https://en.wikipedia.org/wiki/C_(programming_language)) — Systems programming
- [Linux](https://www.kernel.org/) — Operating system

## ✍️ Authors <a name = "authors"></a>

- [@hugou74130](https://github.com/hugou74130) — Hugex

## 🎉 Acknowledgements <a name = "acknowledgement"></a>

- Holberton School France for the low-level programming curriculum
- The Linux kernel documentation
