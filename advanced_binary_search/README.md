##Advanced Binary Search

Write a function that searches for a value in a sorted array of integers.

Prototype : int advanced_binary(int \*array, size_t size, int value);
array is a pointer to the first element of the array to search in
size is the number of elements in array
value is the value to search for
Your function must return the index where value is located
You can assume that array will be sorted in ascending order
If value is not present in array or if array is NULL, your function must return -1
Every time you split the array, you have to print the new array (or subarray) you’re searching in (See example)
You have to use recursion. You may only use one loop (while, for, do while, etc.) in order to print the array
