# tiniest

`tiniest` is a coreutils implementation that is as simple as possible.
Who needs a `--version` flag on a simple `pwd` or `clear` command? Not me.

`tiniest` was made as a C++ learning project.

## Differences with GNU

- `touch`: only creates files
- `yes`: if `argv[0]` is `no`, output `n` instead of `y`
- `chroot`: use `/bin/sh` as def shell, use `.` as def dir
- `clear`: command originally from `ncurses`, not coreutils

## Building from source

We have a simple Makefile for compilation. It compiles every file in `src/`
as a separate program, and outputs it to `bin/` (change with env: `BIN_DIR`).
By defualt, it uses `g++`, but you can switch the compiler by changing the
`CXX` enviroment variable, and you can change the flags with `CXXFLAGS`.

Start compilation:

```bash
make -j$(nproc)
```

Clean:

```bash
make clean
```
