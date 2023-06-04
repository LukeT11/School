#Luke Talcott
#CS101 1:00-2:15
#Program 3
#Created 10/5/2018
#Due 10/7/2018

def num_characters(x):
    '''Checks to make sure string is 13 characters, if not pulls up error'''
    s = 0
    for n in x:
        s += 1
    if s != 13:
        raise AssertionError('Assignment # must be 13 characters in length\n')
    return x

def valid_digit(x):
    '''Checks to make sure all character in the string are valid digits of (0-9) and (A-F), if not pull up error'''
    s = ''
    for n in x:
        if n not in valid_chr:
            s += n + ' '
    if s != '':
        raise ValueError('String Contains invalid characters %s\n' % s) 
    return x

def check_digit_one(x):
    '''Checks to make sure first character in the string is (A-D), if not pulls up error'''
    if x[0] == 'A' or x[0] == 'B' or x[0] == 'C' or x[0] == 'D':
        x = x
    else:
        raise ValueError('The first digit must be a valid class identifier. ABCD\n')
    return x

def check_digit_two(x):
    '''Checks to make sure first character in the string is (A-E), if not pulls up error'''
    if x[0] == 'A' or x[0] == 'B' or x[0] == 'C' or x[0] == 'D' or x[0] == 'E':
        x = x
    else:
        raise ValueError('The second digit must be a valid assignment type identifier. ABCDE\n')
    return x

#List and Dictionaries used to check for valid digits in the string.
valid_chr = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F']
First_chr = {'A': 'CS101', 'B': 'CS191', 'C': 'CS201', 'D': 'CS291'}
Second_chr = {'A': 'Test', 'B': 'Program', 'C': 'Quiz', 'D': 'Final', 'E': 'Other'}

#Variable i used to run while loop.
i = 0

#While loop to continuously run and check strings for classes until an empty string is entered.
while i == 0:
    print('Welcome to the assignment # validator')
    assignment_num = input('Enter the assignment number')
    if assignment_num == '':
        break
    
#Checks each function to make sure each part of the string and all of its components are valid.
    try:
        assignment_num = assignment_num.upper()

        x = num_characters(assignment_num)
        x = valid_digit(assignment_num)
        x = check_digit_one(assignment_num)
        x = check_digit_two(assignment_num)
        

        print('\nThe value given was valid')
        print('Assignment %s is for class %s, and is a %s\n' % (assignment_num, First_chr[assignment_num[0]], Second_chr[assignment_num[1]]))

#Errors pulled up when certain aspects of the string are not valid.
    except AssertionError as error:
        print('\nThe value entered was incorrect')
        print(error)
    except ValueError as error:
        print('\nThe value entered was incorrect')
        print(error)
