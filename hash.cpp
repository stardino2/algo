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

class hash_table{
  public:
  const static int SIZE = 10000;
  struct NODE{
    DATA value;
    NODE* next;
    NODE() {}
    NODE(DATA value, NODE* next): value(value), next(next){}
  };
  NODE *table[SIZE];
  hash_table(){
    for(int i = 0; i < SIZE; i++) table[i] = NULL;
  }
  int hash(DATA &A){
    return (A.a1 + A.a2 + A.a3) % SIZE;
  }
  void insert(DATA key) {
    int index = hash(key);
    table[index] = new NODE(key, table[index]);
  }
}
