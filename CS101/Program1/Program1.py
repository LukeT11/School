#Luke Talcott
#CS101 1:00-2:15
#Program 1
#Created 9/8/2018
#Due 9/9/2018

#Dictionaries created to inlclude the recipes for each item. Used later to help
#compile the proper amount of ingredients for the number of items you are making.

dozenCookies = {'Butter': 2.5, 'Sugar': 2, 'Eggs': 2, 'Flour': 8}

sheetCake = {'Butter': .5, 'Sugar': 1, 'Eggs': 2, 'Flour': 1.5}

dozenDonuts = {'Butter': .25, 'Sugar': .5, 'Eggs': 3, 'Flour': 5}


print('Welcome to Carmack\'s Bakery\n')

#Created variables for the number of each item the user wants to identify the
#number of of each needed to get the amount of ingredients.

nCookies = int(input('\nHow many dozen cookies?'))

nCakes = int(input('\n\nHow many cakes?'))

nDonuts = int(input('\n\nHow many dozen donuts?'))


#Variables to compile the operators for the amount of ingredients needed.

nButter = ((nCookies * dozenCookies['Butter']) + (nCakes * sheetCake['Butter'])+
          (nDonuts * dozenDonuts['Butter']))

nSugar = ((nCookies * dozenCookies['Sugar']) + (nCakes * sheetCake['Sugar'])+
          (nDonuts * dozenDonuts['Sugar']))

nEggs = ((nCookies * dozenCookies['Eggs']) + (nCakes * sheetCake['Eggs'])+
          (nDonuts * dozenDonuts['Eggs']))

nFlour = ((nCookies * dozenCookies['Flour']) + (nCakes * sheetCake['Flour'])+
          (nDonuts * dozenDonuts['Flour']))


#Outputs and prints results for the amount of each ingredient the user needs

print('\n\n\nYou will need to order')

print(nButter, 'cups of butter')

print(nSugar, 'cups of sugar')

print(nEggs, 'eggs')

print(nFlour, 'cups of flour')
