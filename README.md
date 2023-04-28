# TuringMachine Introduction

Execute the file Main.cpp

How long should the tape be?

```enter the length of tape you want, if you want infinite tape, please input -1.```

1. Create dense Turing machine
2. Create sparse Turing machine
3. Add state to Turing machine
4. Compact Turing machine
5. Execute Turing machine
6. Output current information

Write q or Q to quit

Enter Option 

```Enter your option```

## About create turing machine
If you enter 3, You can create turing machine by this format, either for dense turing machine or sparse turing machine.

``` currentState currentContent nextState nextContent moveDirection ```
- currentState: current turing machine state.
- currentContent: the content on the tape, at the current position.
- nextState: next state you want to move.
- nextContent: if move success, waht content you want to change on this position.
- moveDirection: a string, "->" or "<-".

## Dense Turing Machine and Sparse Turing Machine
For example, <0 0 1 1 ->><0 1 0 0 <-><1 0 2 1 ->><2 0 0 0 <->, this is a dense turing machine state, because there is no big gap between state and state.

For example, <0 0 1000 1000 ->><0 1000 0 0 <-><1000 0 2000 1000 ->><2000 0 0 0 <->, this is a sparse turing machine, because there are some big gaps between state and state.

- If you enter 1 to create a dense turing machine, you also need to input two integers, which are max state and max content you want.
- If you enter 2 to create a sparse turing machine, there is no need to enter numbers.
- if you enter 4, this will compact your sparse turing machine to dense turing machine, like example above, it will be <0 0 1 1 ->><0 1 0 0 <-><1 0 2 1 ->><2 0 0 0 <-> after. compacting.
- Notification: even it is dense turing machine, the program still compact it to the most dense turing machine.
- If you enter 5, it will remind you to input steps you want to execute, any number is ok. Beacuse it will be stop if out of bound.
- If out of bound, it will give you a reminder like ```In step *, the position is *, but that is outside the tape.```, * is the number of step or position.
- If you enter 6, program will output some properties of the turing machine, like
```
The current state is 0.
The current position is -1.
The content of the tape is 000.
The Turing machine has states: <0 0 1 1 ->><0 1 0 0 <-><1 0 2 1 ->><2 0 0 0 <->
```
Press q or Q to quit the program, and mmm... have a nice day.
