#Luke Talcott
#Week 11
#Dictionaries and sets part 2
#11/2/2018

#1Start
#2Open text file with names and friends
#3Sort the names into a dictionary with who they are friends with by calling function dictionary_go()
#4Call function social_network() to print 'Social Network' and to ask for a command
    #4.1 Command I calls function two_people)() to print all friends of 2 people
    #4.2 Command D calls function friends_x_not_y() to print all friends of one person that y does not have
    #4.3 Command S calls function friends_x_y_not_both() to print the friends of x and y but not friends for both
    #4.4 Q closes the open text file and quits the while loop for asking for a command ending the program
#5End

def dictionary_go(file):
    '''Takes the open text file and sorts the names with their friends into a dictionary'''
    names = []
    diction = {}
    lines = file.readlines()
    for line in lines:
        names.append(line.split())
    for n in names:
        try:
            name = [n[1]]
            if n[0] in diction:
                s = diction[n[0]]
                diction[n[0]] = s + name
            elif n[0] not in diction:
                diction[n[0]] = name
        except IndexError:
            continue
    for key, value in diction.items():
        diction[key] = set(value)
    return diction
    

def social_network():
    '''Prints these lines and returns an input command'''
    print('\nSocial Network\n')
    print('I. Find all friends shared by 2 people')
    print('D. Find all friends of X, that person Y does not have')
    print('S. Find all friends that X and Y have, but not share with each other')
    print('Q. Quit\n\n')
    inp = input()
    return inp

def two_people(people):
    '''Asks for two valid names in the dictionary and returns people who are friends with both'''
    i = 0
    n = 0
    while i == 0:
        person1 = input('Enter 1st valid person ')
        if person1 not in people:
            print(person1, 'is not part of this network, enter another name.\n')
        elif person1 in people:
            i += 1
    while n == 0:
        person2 = input('Enter 2nd valid person ')
        if person2 not in people:
            print(person2, 'is not part of this network, enter another name.\n')
        elif person1 in people:
            n += 1
    print('%s and %s share these people' % (person1, person2))
    shared = (people[person1].intersection(people[person2]))
    for person in shared:
        print(person)

def friends_x_not_y(people):
    '''Asks for two valid names in the dictionary and returns the friends for one not with the other'''
    i = 0
    n = 0
    while i == 0:
        person1 = input('Enter 1st valid person ')
        if person1 not in people:
            print(person1, 'is not part of this network, enter another name.\n')
        elif person1 in people:
            i += 1
    while n == 0:
        person2 = input('Enter 2nd valid person ')
        if person2 not in people:
            print(person2, 'is not part of this network, enter another name.\n')
        elif person1 in people:
            n += 1
    print('\nThese people are friends with %s but not with %s.' % (person1, person2))
    person1_not_2 = people[person1].difference(people[person2])
    for person in person1_not_2:
        print(person)

def friends_x_y_not_both(people):
    '''Asks for 2 valid names in the dictionary and returns friends of x and y that aren't friends of both'''
    i = 0
    n = 0
    while i == 0:
        person1 = input('Enter 1st valid person ')
        if person1 not in people:
            print(person1, 'is not part of this network, enter another name.\n')
        elif person1 in people:
            i += 1
    while n == 0:
        person2 = input('Enter 2nd valid person ')
        if person2 not in people:
            print(person2, 'is not part of this network, enter another name.\n')
            
        elif person1 in people:
            n += 1
    print('\nThese people are friends with %s and %s, but not both.' % (person1, person2))
    share_p1 = people[person1].difference(people[person2])
    share_p2 = people[person2].difference(people[person1])
    for person in share_p1:
        print(person)
    for person in share_p2:
        print(person)

#Variable for while loop
i = 0

#Variable to open text file
f = open('friends.txt', 'r')

#Calls function to sort the text file names with friends into a dictionary
friends_dict = dictionary_go(f)

#While loop that continues to ask and output commands until Q is entered
while i == 0:
    #Calls function to print list of commands
    action = social_network()
    
    #Calls Function to print friends of two people
    if action in ['I', 'i']:
        two_people(friends_dict)
        
    #Calls Function to print friends for one but not the other
    elif action in ['D', 'd']:
        friends_x_not_y(friends_dict)

    #Calls Function to print friends for two people but not both
    elif action in ['S', 's']:
        friends_x_y_not_both(friends_dict)

    #Closes text file and quits program
    elif action in ['Q', 'q']:
        f.close()
        i += 1
    else:
        continue
