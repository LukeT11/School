#Luke Talcott
#CS101 lab
#Friday 1-3:30
#Lab Week 13- Classes

#Just for program part
#Start
#Imports time function
#Calls function user_time() for inputs of a time and check for valid input
#Inserts inputs the values into the class Clock for the variable time_
#While True, Prints the time every second continuously
#Ends when no longer True

class Clock():
    '''Clock time that has set variables, prints clock time and tick function adds 1 second to the time'''
    def __init__(self, self_hour = 0, self_minute = 0, self_second = 0, clock_type = 0):
        '''Inittily sets each value input to these inital variables for class Clock'''
        self.hour = self_hour
        self.minute = self_minute
        self.second = self_second
        self.clock_type = clock_type
                
    def __str__(self):
        '''Prints time correctly base off of military am/pm system'''
        if self.clock_type == 0:
            return('%02d:%02d:%02d' % (self.hour, self.minute, self.second))
        elif self.clock_type == 1:
            if self.hour in range(0, 12):
                if self.hour == 0:
                    return '%02d:%02d:%02d am' % (12, self.minute, self.second)
                else:
                    return '%02d:%02d:%02d am' % (self.hour, self.minute, self.second)
            if self.hour in range(12, 24):
                if self.hour == 12:
                    return '%02d:%02d:%02d pm' % (12, self.minute, self.second)
                else:
                    return '%02d:%02d:%02d pm' % ((self.hour - 12), self.minute, self.second)

    def tick(self):
        '''Adds a second to the time and changes value accordingly'''
        self.second += 1
        if self.second >= 60:
            self.second = 0
            self.minute += 1
        if self.minute >= 60:
            self.minute = 0
            self.hour += 1
        if self.hour >= 24:
                self.hour = 0


import time

def user_time():
    '''Takes input for time for hours, minutes and seconds and make sure each is a valid input'''
    while True:
        try:
            hour = input('What is the current hour ')
            if not hour.isdigit():
                raise TypeError
            hour = int(hour)
            if hour not in range(0, 25):
                raise ValueError('Hours must be between 0-24')
            minute = input('What is the current minute ')
            if not minute.isdigit():
                raise TypeError
            minute = int(minute)
            if minute not in range(0, 60):
                raise ValueError('Minutes must be between 0-59')
            second = input('What is the current second ')
            if not second.isdigit():
                raise TypeError
            second = int(second)
            if second not in range(0, 60):
                raise ValueError('Seconds must be between 0-59')
            return (hour, minute, second)
        except TypeError:
            print('Input must be an number')
        except ValueError as exc:
            print(exc)
            print('Input must be numbers')
            
#Calls function user_time for valide Hours/Mins/Secs
time_ = user_time()
#Inputs values into correct variables in the class Clock
time_ = Clock(time_[0], time_[1], time_[2], 1)

#Continuous loop that prints the time every second
seconds = 0
while True:
    print(time_)
    time_.tick()
    seconds += 1
    time.sleep(1)
