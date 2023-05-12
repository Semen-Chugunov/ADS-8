// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() :countOp(0), first(nullptr) {}
void Train::addCage(bool light) {
  Cage* tm = nullptr;
  if (!first) {
    first = new Cage;
    first->next = first;
    first->prev = first;
    first->light = light;
  } else {
    tm = new Cage;
    tm->next = first;
    tm->prev = first->prev;
    first->prev = tm;
    tm->prev->next = tm;
    tm->light = light;
  }
}
int Train::getLength() {
  int c = 1;
  Cage* p = first;
  p->light = 1;
  while (p) {
    p = p->next;
    if (!p->light) {
      c++;
      countOp++;
    }
    if (p -> light) {
      p->light = 0;
      for (int i = c; i > 0; i--)
        p = p->prev;
      countOp += c + 1;
      if (p->light == 0)
        return  c;
    }
  }
  return -1;
}
int Train::getOpCount() {
  return countOp;
}
