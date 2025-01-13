# Cobra

This is a toy python interpreter written in C.

[![Status](https://github.com/oslundstrom/cobra/actions/workflows/ci.yml/badge.svg)](https://github.com/oslundstrom/cobra/actions/workflows/ci.yml)

## Getting started

Prerequisites for compiling the project is:

```
make
gcc
```

To compile the project, clone the repo

```
git clone <url>
cd cobra
```

Change directory to the repo and run `make`.

## Testing

The tests are run by triggering the `check` make-target:

```
make check
```

The tests uses the Unity framework, and when running the make-command the first time, the unity repo will automatically be cloned into a directory called `unity`.
