---
layout: page
title: About
---

This website and repository are intended to be used for a full-day workshop on creating and using Test Doubles.

If you don't know what a test double is, imagine software where you want to test the interaction between two components, but it isn't practical to set those components up on your workstation in the way you need for an automated test.  You can use a *Test Double* to stand in for the real object in your test.

## This Project

This workshop builds software to drive an art project which will display Conway's Game of Life on an LED panel.  Your workstation doesn't have the same hardware as the microcontroller which is used in the art project.

What we do have is a well tested API which interacts with the hardware.  Because we trust the API to behave as expected, we can create a *Test Double* for that API, much like an actor would have a stunt double for scenes where their character needs to do things that the actor can't.

Using the test doubles, we will be able to prove that our software does the right thing with the hardware API.  This will reduce our programming time from first draft to working implementation by quite a bit.
