# Unlimited-Integer
Implementation of an integer data type with unlimited (i.e., limited by RAM) size. 
Addition and Subtraction functions also implemented with <img src="https://latex.codecogs.com/svg.image?O(log_1_8(n))" title="O(log_1_8(n))" /> time complexity.

## Functions
*	`add()` and `sub()` - To call `driver()` with appropriate operation sign.
*	`driver()` - To handle all possible cases of  addition and subtraction of negative and positive UnlimitedIntegers and call `addOp()` or `subOp()`, whatever applicable.
*	`UnlimCmp()` - 
*	`addOp()` - Implements addition of UnlimitedInt data type.
*	`subOp()` - Implements subtraction between two UnlimitedInt data type.

## Implementation
To implement our UnlimitedInteger data type, first we use strings to store the large number.

Then, to implement addition and subtraction of such large numbers in less than <img src="https://latex.codecogs.com/svg.image?O(n)" title="O(n)" /> time complexity, we implement a method called `chunkingAdd()` for addition and `chunkingSub()` for subtraction which converts our string of numbers into chunks of 18 digits and store it in a vector of `long long int`.

For addition, after chunking, we add individual chunks of 18 digit numbers, and have implemented separate `carry` variable to handle carry-over in case of an overflow during addition of two chunks. 

## Contributors
BT20CSE216 Abhishek Kanojia
<br>BT20CSE209 Kshitij Agarkar
<br>BT20CSE214 Aviral Verma
