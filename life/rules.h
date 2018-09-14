#ifndef _RULES_H_
#define _RULES_H_

class Rules {
public:
  virtual bool isAlive(bool currentlyAlive, int neighbors);
};

#endif