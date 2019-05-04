#   Gets input from user : Change owed
#   Takes change and separates it into 25c, 10c, 5c and 1c coins
#   Spits back the minimum number of coins needed to return change.

from cs50 import get_float

# get input from user as positive
while True:
    try:
        input = get_float("Change Owed: ")
        if input > 0:
            break
    except:
        print("", end="")

# declare number of coins variable
coins = 0

# make change act like an int so it's more precise
change = input * 100

# count 25c coins
while change >= 25:
    change = change - 25
    coins = coins + 1

# count 10c coins
while change >= 10:
    change = change - 10
    coins = coins + 1

# count 5c coins
while change >= 5:
    change = change - 5
    coins = coins + 1

# count 1c coins
while change >= 1:
    change = change - 1
    coins = coins + 1

print(coins)