# Unlimited-Integer
Implementation of an integer data type with unlimited (i.e., limited by RAM) size. 
Addition and Subtraction functions also implemented with <img src="https://latex.codecogs.com/svg.image?O(log_1_8(n))" title="O(log_1_8(n))" /> time complexity.

## Functions
### User Functions - 
*	`add()` and `sub()` - To call `driver()` with appropriate operation sign.
### Internal Functions - 
*	`driver()` - To handle all possible cases of  addition and subtraction of negative and positive UnlimitedIntegers and call `addOp()` or `subOp()`, whatever applicable.
*	`UnlimCmp()` - Compares and returns `1` if first parameter is greater than second, `-1` if the second is greater, and `0` is equal.
*	`addOp()` - Implements addition of UnlimitedInt data type.
*	`subOp()` - Implements subtraction between two UnlimitedInt data type.
*	`chunkingAdd()` - Converts string of our unlimited integer number into chunks of long long int and stores it into a vector for `addOp()`.
*	`chunkingSub()` - Converts string of our unlimited integer number into chunks of long long int and stores it into a vector for `subOp()` (in addition to `chunkingAdd()`, `chunkingSub()` also takes care of leading zeros.
*	`fixsize()` - Takes care of zeros in chunks so that we don't lose chunk size while converting a string to long long int and vice-versa.
*	`leadingzero()` - It removes all the leading zeros in the output string.
*	`print()` - Prints the value of UnlimitedInteger.

## Implementation
To implement our UnlimitedInteger data type, first we use strings to store the large number.

Then, to implement addition and subtraction of such large numbers in less than <img src="https://latex.codecogs.com/svg.image?O(n)" title="O(n)" /> time complexity, we implement a method called `chunkingAdd()` for addition and `chunkingSub()` for subtraction which converts our string of numbers into chunks of 18 digits and store it in a vector of `long long int`.

For addition, after chunking, we add individual chunks of 18 digit numbers, and have implemented separate `carry` variable to handle carry-over in case of an overflow during addition of two chunks.

For subtraction, after chunking, we add individual chunks of 18 digit numbers, and take care of borrow by subtracting `1` from the next chunk  in case if the upper chunk is smaller than the lower chunk, during subtraction of two chunks.

We have also overloaded the appropriate operators to carry out addition and subtraction via `+` and `-` sign, and initialize UnlimitedInteger via `=` sign respectively.
You can also assign values to object `obj` of `akaUnlimInt` class by using `cin >> obj` and print value of the object by using `cout << obj`.

## Contributors
BT20CSE216 Abhishek Kanojia
<br>BT20CSE209 Kshitij Agarkar
<br>BT20CSE214 Aviral Verma
