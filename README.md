# Push_swap

## Introduction

Push_swap is a project in the algorithms branch of [Hive Helsinki](https://www.hive.fi/en/). It's object is to write a sorting algorithm which sorts a set of integers as efficiently as possible. The twist is that there are rules limiting how memory can be used and how data can be manipulated, which renders most standard sorting algorithms invalid for this task, and forces the programmer to be creative when solving this problem. Below is a summary of these rules and the game logic followed by a description of my solution to the problem. The full assignment pdf can be found [here](https://www.hive.fi/en/)

## The rules

The game is composed of two stacks named a and b. At the start of the game all numbers are in stack a in a random order and stack b is empty. Duplicate numbers are not allowed. You can only manipulate the stacks using the commands in the table below. The goal is to sort all the numbers in ascending order to stack a using as few commands as possible.

| Command | Description |
| :------:| :----------:|
| sa | swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements). |
| sb | swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements). |



