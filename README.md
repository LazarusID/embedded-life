# Conway's Game of Life - Embedded Edition

This repo was designed for a deep-dive code retreat about advanced testing and mocking.  To use this, you'll need the following installed on your system:

- [Docker](http://docker.com) to install a working Linux development
  environment on your workstation.

## More Details

More information about the usage is available from the repo's [website](https://lazarusid.github.io/embedded-life/).


## Setting Up the Docker Container

The first time you run the project on your computer, run the `build-devimage.bat` script to build the docker image "life."

To create the "lifedev" container, run `launch-devcontainer.bat` which should eventually end in a command prompt.

To rejoin the "lifedev" container, run `enter-devcontainer.bat` which should end in a command prompt.

## To Run Tests

From the docker command line:

    cd life
    make test

## Writing Tests

The idea of Test Driven Development is to write a failing test, then enough coee, and no more, to make the test pass.  This project uses the [check](https://libcheck.github.io/check/) library.  The website contains both documentation and extensive examples of how to use it.

## Preferred Setup

The original intent of this repo is that you will start a docker container in this folder.  This gives you a shell in the Linux container from which to compile and build.

Another terminal window is open for managing git.

Start your favorite editor in the folder, with the appropriate plugins for C++ programming.  I'm using VS Code, but Atom, vi and emacs are also viable contenders.


# Using Branches

To facilitate using this in a workshop, there are three branches provided:

1. `master` contains a valid starting environment for any of the supported
   languages.  It has just enough content to start coding Conway's Game of
   Life, with a failing test that needs to be fixed.
1. `solution` contains a working implementation of Conway's Game of Life.  It
   includes a working set of rules and a board implementation.  At this point
   they don't contain a final program which implements the repeating life
   cycles of the game.
1. `displaytests` contains a shell of the game implementation, as well as a
   first passing test and an example mock.  Content about programming mocks
   should start here.
