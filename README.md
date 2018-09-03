# Conway's Game of Life - Embedded Edition

This repo was designed for a deep-dive code retreat about advanced testing and mocking.  To use this, you'll need the following installed on your system:

- [Docker](http://docker.com) to install a working Linux development environment on your workstation.  If you are already running on a Linux or OS X system, you will instead need to install a working C/C++ development environment and the *check* testing framework.
- [Arduino](http://arduino.cc) to get necessary headers for testing, and to build a final executable if you are going to actually run on embedded hardware.

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