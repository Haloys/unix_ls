# README for Unix_Ls Project

## Introduction

Welcome to Unix_LS, a meticulous recreation of the classic Unix 'ls' command. This project showcases a deep dive into the Unix file system

## Features

- **Selective Flag Functionality:** Unix_LS includes key flags such as -a (show all files), -d (list directories themselves), -l (long listing format), -r (reverse order), and -t (sort by modification time).

- **Multiple Flag Integration:** Seamlessly handle multiple flags simultaneously, mirroring the versatile and robust nature of the real 'ls' command. This feature exemplifies the project's capability to interpret and execute complex command combinations with precision.

## Getting Started

### Prerequisites

Ensure you have the following installed:
- A C compiler (GCC recommended)
- Make

### Installation

```bash
git clone git@github.com:Haloys/unix_ls.git
cd unix_ls
```

```bash
make
```

```bash
./my_ls [OPTION]
```