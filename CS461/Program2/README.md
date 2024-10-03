# Program Two - Genetic Algorithm
Genetic Algorithm used to build a space utilization schedule that generates a 'Best Fit Schedule' given a list of activities, facilitators and rooms information. 
Assumptions:
 - Input files of "Activites", "Facilitators", "Rooms"
 - Ouput file of "BestScheduleResults" returns Final Schedules of Highest Fitness Score
 - Output Text of:
   o Input of Activities information
   o Best First Schedule and Fitness Value,
   o For Each Generation, Generation Number, Best Schedule Fitness, Current Fitness Average
   o Final Schedule and Fitness Value
 - Mutation Rate of (0.000625)
 - Mutation Rate used for each activity so if an activity of a schedule was chosen for mutation, then the
   room, time slot and facilitator would all be randomly changed.
 - Assumed the use of a random crossover line.
 - Next Generation Only consists of offspring from the parents of the parent generation.
 - Parents are chosen by the probability distribution from softmax.
