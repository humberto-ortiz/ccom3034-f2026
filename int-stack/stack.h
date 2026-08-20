// stack.h - integer stack class
// Copyright 2026 Humberto Ortiz Zuazaga

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// Uses a fixed size array as a backing store.
#define MAX_STACK 100

class intstack {
 private:
  int a[MAX_STACK]; // array to store stack elements
  int n; // index of next available element

 public:

  intstack() {
    // Construct an empty stack
    n = 0;
  }

  void push(int x) {
    // put x in next empty slot and advance the index
    a[n++] = x;
  }

  int pop() {
    if (n > 0) { // stack not empty
      // return the last element and set the index
      return a[--n];
    } else {
      // popping an empty stack raises an error
      throw std::runtime_error("El stack esta vacio");
    }
  }
};
