# tiniest

`tiniest` is a coreutils implementation that is as simple as possible.
Who needs a `--version` flag on a simple `pwd` or `clear` command? Not me.

`tiniest` was made as a C++ learning project, is a WIP and should not be
used in production as it purposely removes several features and in some
places even basic error checking.

## Differences with GNU

Basically every command is different from GNU, but these differences were made
on purpose, other than the `-v` and `-h` stuff:

- `touch`: only creates files
- `yes`: if `argv[0]` is `no`, output `n` instead of `y`
- `chroot`: use `/bin/sh` as def shell, use `.` as def dir
- `clear`: command originally from `ncurses`, not coreutils
- `echo`: does not allow any flags, just prints all arguments
- `hostname`: read `src/hostname.cpp` for info
- `ls`: currently does not have colors

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
