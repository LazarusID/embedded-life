---
title: "How We Mock"
---

The simplest form of test double is just a function or object with the same call signature as the real function or object that you're trying to replace.  This is called a stub, and it doesn't do anything, but it lets your tests run without invoking the actual code of what you're doubling.

Usually we want more sophisticated behavior from our test doubles.  A test double you can control is called a *mock.*  Usually you can control what a mocked function or method returns, and can examine the calling parameters.  This lets you determine that your code is interacting with the object correctly, without the expense of actually calling the doubled code.

## Creating a Mock

1. Create a class or function with the same interface.  If your language supports the abstract concept of an intereface, and the class your are mocking implements an interface, the easiest route is to implement the same interface in your mock.
1. Add methods/functions to control the return value of functions and examine parameters used to call the function.

## Using a Mock

There are two ways to use a mock: *dependency injection* and *linking.*

### Dependency Injection

If you are testing a class with an initialization step, like a constructor, you might be able to pass your mocked class into the initialization step.  This is the easiest approach in most object oriented programming.

## Linking

When your program is resolving its dependencies, if your mock is offered up as a solution to resolve the dependency before the actual code is, your mock will be used instead of the actual code.  This is easiest in languages with an explicit linking stage, like C and C++, but some frameworks like Spring allow it even in Java, which links at runtime.