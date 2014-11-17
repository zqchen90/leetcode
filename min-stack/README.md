# Introduction
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.

# Thought
Using another stack to save the min element, this min stack will push and pop at the same time when the data stack pushes or pops.