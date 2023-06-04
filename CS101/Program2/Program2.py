#Luke Talcott
#CS101 1:00-2:15
#Program 2
#Created 9/22/2018
#Due 9/23/2018

import random

def flip_coins():
    '''Flips 3 random coins heads or tails'''
    coins_string = ''
    for n in range(0, 3):
        coin = random.randint(0, 1)
        if coin == 0:
            n = 'H'
        else:
            n = 'T'
        coins_string += n
    return coins_string


def sorts_coins(coins, current_pot):
    '''If a coin is heads in the string, add number to the pot'''
    for n in coins:
        if n == 'H':
            current_pot += 1
    return current_pot


#Variables included
your_score = 0
AI_score = 0
pot = 0
i = 0
x = 0
a = 0
e = 0
s = 0
turn = 'Your Turn'

print('Welcome to Greedy Dice')

#Runs the entire game loop continously unless no is selected to stop playing. Resets variables back to original state when turn flips. 
while i == 0:
    print('\nScore  You :',  your_score, '      AI :', AI_score, '\n')
    print('%s.' % turn, end = ' ')
    enter_turn = input('Hit enter to continue')
    x = 0
    a = 0
    e = 0
    s = 0
    coins_string = ''
    pot = 0

#Runs the player or computers turn until an end point is hit by user or computer.    
    while x == 0:
        a = 0
        coins_string = ''
        coins_string = flip_coins()

#If coins are all tails, ends computer or users turn.
        if coins_string == 'TTT':
            print('Coins : TTT  Pot :', pot, 'BUST')
            x += 1
        else:
            pot = sorts_coins(coins_string, pot)

#if user turn and gets a heads, as long as total score isn't 20 or more, asks to flip or hold.
            if turn == 'Your Turn':
                while a == 0:
                    print('Coins :', coins_string, '  Pot :', pot, end = ' ')
                    if (your_score + pot) >= 20:
                        your_score += pot
                        x += 1
                        e = 1
                        a += 1
                    else:
                        flip_again = input('(F)lip Again or (H)old?')
                        if flip_again == 'f':
                            a += 1
                        elif flip_again == 'F':
                            a += 1
                        elif flip_again == 'h':
                            your_score += pot
                            a += 1
                            x += 1
                        elif flip_again == 'H':
                            your_score += pot
                            a += 1
                            x += 1

#Keeps computers turn going until 8 or more heads in pot or total score over 20
            elif turn == 'It\'s the computers turn':
                print('Coins :', coins_string, '  Pot :', pot)
                if (AI_score + pot) >= 20:
                    AI_score += pot
                    x += 1
                    e = 2
                if pot >= 8:
                    AI_score += pot
                    x += 1

#When score hits over 20 for computer or user, prints who won and score.
    while e != 0:    
        if e == 1:
            print('\nCongratulations, you won.')
            print('Score  You :',  your_score, '      AI :', AI_score, '\n')
        elif e == 2:
            print('The computer won.')
            print('Score  You :',  your_score, '      AI :', AI_score, '\n')

#Asks if user would like to keep playing. Yes, runs the game again. No, ends it. Options of YES/Y/NO/N.
        while s == 0:
            play_again = input('Do you want to play Greedy Coin agian (YES/Y/NO/N)')
            if play_again == 'YES':
                if turn == 'Your Turn':
                    turn = 'It\'s the computers turn'
                elif turn == 'It\'s the computers turn':
                    turn = 'Your Turn'
                x += 1
                s += 1
                e = 0
                your_score = 0
                AI_score = 0
            elif play_again == 'Y':
                if turn == 'Your Turn':
                    turn = 'It\'s the computers turn'
                elif turn == 'It\'s the computers turn':
                    turn = 'Your Turn'
                x += 1
                s += 1
                e = 0
                your_score = 0
                AI_score = 0
            elif play_again == 'NO':
                s += 1
                i += 1
                e = 0
            elif play_again == 'N':
                s += 1
                i += 1
                e = 0
            else:
                s = 0

#Changes turns to computer or user.
    if turn == 'Your Turn':
        turn = 'It\'s the computers turn'
    elif turn == 'It\'s the computers turn':
        turn = 'Your Turn'
            
    
