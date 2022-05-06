#ifndef QUEUE_H
#define QUEUE_H
#include <string>
enum op {
  ADD,
  SUB,
  MULT,
  DIVI
};

struct expr {
  int oprd1;
  op oprt;
  int oprd2;
};

typedef expr el_t;
const int MAX = 10;
class Queue {
private:
    el_t elem[MAX];
    int rear;
    int front;
    int count;
public:
    Queue();
    void add(el_t e);
    el_t remove();

    bool isFull() const;
    bool isEmpty() const;
    
    el_t getFront() const;

    void goToBack(); // go all the way to the end
    int getSize() const;

    void displayAll() const;

    void queueError(std::string errorMessage) const;
};

#endif