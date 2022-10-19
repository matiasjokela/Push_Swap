# Push_swap

## Introduction

Push_swap is a project in the algorithms branch of [Hive Helsinki](https://www.hive.fi/en/). It's object is to write a sorting algorithm which sorts a set of integers as efficiently as possible. The twist is that there are rules limiting how memory can be used and how data can be manipulated, which renders most standard sorting algorithms invalid for this task, and forces the programmer to be creative when solving this problem. Below is a summary of these rules and the game logic followed by a description of my solution to the problem. The full assignment pdf can be found [here](https://github.com/matiasjokela/Push_Swap/blob/master/push_swap.en.pdf)

## The rules

The game is composed of two stacks named a and b. At the start of the game all numbers are in stack a in a random order and stack b is empty. Duplicate numbers are not allowed. You can only manipulate the stacks using the commands in the table below. The goal is to sort all the numbers in ascending order to stack a using as few commands as possible.

| Command | Description |
| :------:| :----------:|
| sa | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements. |
| sb | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements. |
| ss | sa and sb at the same time. |
| pa | push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty. |
| pb | push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty. |
| ra | rotate a - shift up all elements of stack a by 1. The first element becomes the last one. |
| rb | rotate b - shift up all elements of stack b by 1. The first element becomes the last one. |
| rr | ra and rb at the same time. |
| rra | reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one. |
| rrb | reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one. |
| rrr | rra and rrb at the same time. |

The project requires you to write two separate programs called push_swap and checker. Both programs receive the initial set of numbers as command line arguments, and both programs must display an error message if the input is not valid (duplicate numbers, non-numeric input etc.).

Push_swap is the program that does the heavy lifting. It's job sort the numbers received using the available commands and the two stacks a and b. It must print the commands it uses to stdout, the fewer commands needed the better.

Checker is a validator program for push_swap and it's job is simply to check that the set of instructions push_swap generates actually results in a properly sorted stack. It does this by reading commands from stdin and applying them to the stacks. If any of the commands it receives is invalid, it must print an error message and stop. Otherwise after there are no more commands, it checks that stack b is empty and that stack a is sorted correctly. If this is the case, it prints OK, otherwise it prints KO.

### Some examples

![examples](./examples/example.png)
