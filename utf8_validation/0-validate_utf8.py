#!/usr/bin/python3
"""UTF-8 Validation Module"""


def validUTF8(data):
    """Return: True if data is a valid UTF-8 encoding, else return False
    A character in UTF-8 can be 1 to 4 bytes long
    The data set can contain multiple characters
    The data will be represented by a list of integers
    Each integer represents 1 byte of data, therefore you only need to handle
    the 8 least significant bits of each integer
    """
    count = 0
    for char in data:
        if count == 0:
            if (char >> 5) == 0b110:
                count = 1
            elif (char >> 4) == 0b1110:
                count = 2
            elif (char >> 3) == 0b11110:
                count = 3
            elif (char >> 7):
                return False
        else:
            if (char >> 6) != 0b10:
                return False
            count -= 1
    return count == 0
