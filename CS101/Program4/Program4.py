#Luke Talcott
#CS101 1:00-2:15
#Program 2
#Created 10/20/2018
#Due 10/21/2018


def read_file():
    i = 0
    while i == 0:
        try:
            file = input('Enter html file to open')
            f = open(file, 'r')
            i += 1
            return f
        except FileNotFoundError:
            print('File not found', file)

def new_file():
    n = 0
    while n == 0:
        try:
            w_file = input('\nEnter name of html file to write to')
            w = open(w_file, 'r')
            n += 1
            return w
        except IOError:
            print('IO Error', file)

def write_to_file():
    
    success = print('Succesfully output to file', file_writing_to)
    return success

file_opening = read_file()
file_writing_to = new_file()
print(write_to_file())
