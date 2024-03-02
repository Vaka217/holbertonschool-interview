#!/usr/bin/python3
"""Making Change Module"""


def makeChange(coins, total):
    """Given a pile of coins of different values, determine the fewest number
            of coins needed to meet a given amount total

        coins: list of the values of your the coins. The value of a coin will
        always be an int > 0
        total: The amount to achieve

    Returns: fewest number of coins needed to meet total"""

    if total <= 0:
        return 0

    if (coins is None or len(coins) == 0):
        return -1

    my_coins = sorted(coins, reverse=True)
    money_left = total
    change = 0

    for coin in my_coins:
        while (money_left % coin >= 0 and money_left >= coin):
            change += int(money_left / coin)
            money_left = money_left % coin

    if money_left == 0:
        change = change
    else:
        change = -1

    return change
