#include <stdio.h>

struct DATA {
  int a1, a2, a3;
  DATA() {}
  DATA(int a1, int a2, int a3) : a1(a1), a2(a2), a3(a3){}
  bool operator == (const DATA&A) const {
    return a1 == A.a1 && a2 == A.a2 && a3 == A.a3;
  }
  bool operator !=(const DATA &A) const {
    return a1 != A.a1 || a2 != A.a2 || a3 != A.a3;
  }
};
