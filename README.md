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
