---
title: "Workstation Setup"
layout: page
---

## Required Software

- Docker
- A programming editor such as [VS Code](https://code.visualstudio.com/) or [Atom](https://atom.io/)
- C++ plugins for your editor.
  - For *VS Code* I use the following:
    - **C/C++** from Microsoft.
    - **C++ Intellisense** from austin.
    - **Clang-Format** from xaver using the google format.
    - **vscode-icons** from Roberto Huertas.
  - For *Atom* I use:
    - **language-c** installed by default.
    - **clang-format** from Liquid Helium, using the google format.

## Getting the Repo

Clone the repository from GitHub.

If your workstation is already set up to use SSH keys with GitHub:

    git clone git@github.com:LazarusID/embedded-life.git

If you don't have a GitHub account or don't use SSH keys:

    git clone https://github.com/LazarusID/embedded-life.git

### The Docker Container

Build the *life* image (from `build-devimage.bat`)

    docker build -t life .

Create the *lifedev* container (from `launch-devcontainer.bat`)
    docker run --name lifedev -v .:/life -t -i life /bin/bash

If your laptop goes to sleep, your docker container will likely be suspended.  You can restart it with

    docker start lifedev
    docker attach lifedev
