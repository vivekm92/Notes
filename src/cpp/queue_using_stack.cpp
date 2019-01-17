#include <iostream>
#include <stack>
#include <csignal>

using namespace std;
void signalHandler(int signum) {
  cout << "Interrupt signal (" << signum << ") received.\n";
  exit(signum);
}

struct queue {
  stack<int> s1, s2;

  // while s1 is not empty, push elements from s1 --> s2
  // push x to s1
  // while s2 is not empty, push elements from s2 --> s1
  // T --> O(N)
  void enqueue(int x) {
    while(!s1.empty()) {
      s2.push(s1.top());
      s1.pop();
    }
    s1.push(x);
    while(!s2.empty()){
      s1.push(s2.top());
      s2.pop();
    }
  }

  // if s1 is empty raise segmentation fault or exit, --> exit(0)
  // pop from s1 and return
  // T --> O(1)
  int dequeue() {
    if (s1.empty()) {
      cout << "stack is empty" << "\n";
      raise(SIGSEGV);
    }
    int res = s1.top();
    s1.pop();
    return res;
  }
};

int main() {
  signal(SIGSEGV, signalHandler);
  queue q;
  q.enqueue(10);
  q.enqueue(9);
  q.enqueue(3);
  q.enqueue(2);
  q.enqueue(1);

  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";
  cout << q.dequeue() << "\n";

  return 0;
}
