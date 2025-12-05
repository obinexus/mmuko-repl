# **mmuko-repl (RIFT REPL)**

### **Minimalist Red-Black Trie + Permission Consensus + Interactive REPL**

`mmuko-repl` is a lightweight experimental REPL environment built around:

* A **Red-Black Trie (RTrie)** for storing file paths
* A simple **permission model** (`P_READ`, `P_EXEC`)
* A **consensus module** controlling execution permissions
* A built-in interactive shell called **RIFT**
* Automatic scanning of directories for `*.txt` files

This project is written in C and kept intentionally small, hackable, and dependency-free (aside from libc).

---

## **Features**

### ✅ Red-Black Trie (RTrie)

* Stores arbitrary paths
* Ordered traversal (in-order print)
* Search & insert operations

### ✅ Permission System

* Nodes carry a permission flag
* Execution permission (`P_EXEC`) requires consensus
* Supports request/apply semantics

### ✅ Consensus Module

* Simple internal state machine
* `consensus_ready()` / `consensus_clear()`

### ✅ RIFT REPL

A small command interpreter offering:

| Command              | Description              |                    |
| -------------------- | ------------------------ | ------------------ |
| `help`               | Show REPL commands       |                    |
| `ls`                 | List all RTrie nodes     |                    |
| `tree`               | Pretty-print the trie    |                    |
| `scan <folder>`      | Import all `*.txt` files |                    |
| `perm <path> <P_READ | P_EXEC>`                 | Change permissions |
| `exit`               | Quit the shell           |                    |

### Example:

```
$ ./mmukocycle
RIFT Shell Ready
rift> help
rift> scan ./data
rift> ls
rift> tree
```

---

## **Building**

### **Requirements**

* GCC / Clang
* A POSIX-compatible environment (Linux, macOS, MSYS2 OK)

### **Build**

```
make
```

### **Clean**

```
make clean
```

### **Run**

```
./mmukocycle
```

---

## **Project Structure**

```
mmuko-repl/
 ├── include/
 │    ├── rtrie.h
 │    ├── consensus.h
 │    └── rift_repl.h
 ├── src/
 │    ├── rtrie.c
 │    ├── consensus.c
 │    └── rift_repl.c
 ├── main.c
 ├── Makefile
 └── README.md
```

---

## **RTrie Node Structure**

```c
typedef struct RTrieNode {
    char *path;
    PermType perm;
    char color;              // 'R' or 'B'
    struct RTrieNode *left;
    struct RTrieNode *right;
    struct RTrieNode *parent;
} RTrieNode;
```

---

## **Status**

This is an early experimental version
→ "v001"

Features are incomplete. Red-Black balancing is not implemented in this release.

---

## **License**

MIT License

---

## **Repository**

```
github.com/obineus/mmuko-repl
```
