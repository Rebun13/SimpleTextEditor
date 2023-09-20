# SimpleTextEditor

## Description

Implementation of a simple text editor. The editor initially contains an empty string, _S_. Perform _Q_ operations of the following _4_ types:

1. append(_W_) - Append string to the end of _S_.
2. delete(_k_) - Delete the last characters of _S_.
3. print(_k_) - Print the character of _S_.
4. undo() - Undo the last (not previously undone) operation of type _1_ or _2_, reverting _S_ to the state it was before to that operation. 

## Output

- Each operation of type _3_ must print the character on a new line.

## Input

- The first line contains an integer, _Q_, denoting the number of operations.
- Each line _i_ of the _Q_ subsequent lines (where $0 ≤ i < Q$) defines an operation to be performed. Each operation starts with a single integer, _T_ (where $t ∈ {1, 2, 3, 4}$), denoting a type of operation as defined in the Problem Statement above. If the operation requires an argument, _t_ is followed by its space-separated argument. For example, if _t = 2_ and _W = "abcd"_, line _1_ will be _1 abcd_. 
