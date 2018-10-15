---
title: "Lessons Learned from the First Session"
---

## The Good

In general people responded well to the material, and found learning how to
build their own mocks useful.

The format of the class, with mob programming, was helpful for people.  In fact
everyone was able to get some keyboard time.

## The Bad

- C++, especially with this library, was too confusing for many people.
  Mentioned by four separate reviewers.  I am inclined to agree, especially
  because my first example mock required several hours on my own, and expanded
  my knowledge of how a C++ virtual table works.
- Too much time was spent just doing test driving, and that prevented us from
  getting to the meat of writing our own mocks.  While some people liked
  getting brought up to speed on test first development, it would be better to
  shift the balance towards mocking early.
- There was too much material, which prevented us from actually trying this on
  hardware (my ultimate goal).  A simpler example is needed.
- At least one participant thought that creating a custom mock was too
  complicated as an introduction to mocking, and that doing mocking with a
  mocking framework would have been better.

## Plans for the Future

- In the interest of staying with an embedded project, switching to C, which
  has a simpler syntax and easier linkage rules.
- Realistically to make this more relevant, I will probably need to move to a
  language in more popular usage, such as C# or Javaa.  Learning new concepts
  is easier if people aren't stumbling over new syntax as well.
- Possibly present this to more focused groups, e.g. groups focused on a
  particular language, or to a company, where everybody will have some language
  in common.
