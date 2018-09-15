---
title: "Working In the lifedev Container"
layout: page
---

You will be working in a Linux shell.  If you are familiar with Linux or the OS-X command line, this will feel familiar to you.  If you normally work with Windows or with an IDE, keep these commands handy.

### The First Time

The first time you use a new *lifedev* container, you need to take the following steps.

We will be working in the `/life` folder.  Make that your current folder:

    cd /life          # Makes /life the current directory

We will create actual builds outside of the source tree, in a subfolder named *build*.

    mkdir build       # Creates the build folder
    cd build

This project uses CMake to manage builds.  All of the build description files and all of the tools necessary are already installed as part of the *life* container.  We need to create the build files:

    cmake ..

This will examine the system and determine which tools to use to build, and create the actual build scripts.

### After Adding a File

Any time you add a file to the project, you need to rerun CMake, so that your new file is added to the build scripts.

    cmake ..

### Building Your Program

To build our program, we run a program called *make.*  Make uses the build scripts produced by CMake to figure out which files need to be compiled, and to actually assemble them into a final program.

    make

This build has been defined to automatically run our test suite after compiling, to ensure that the code we have written is the code we meant to write.  The first time you build you should see a failed test.
