import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns


def average_pass_ratio(classes):
    avg_per_class = classes[:,0]/classes[:,1]
    apr = np.average(avg_per_class)
    return apr

def check_significance(classes):
    significance = 0
    key = 88
    for i in range(len(classes[:,0])):
        #print("significance =", significance)
        initial = classes[i,0]/classes[i,1]
        #print("initial= ", initial)
        final = (classes[i,0]+1)/(classes[i,1]+1)
        #print("final= ",final)

        #since final > initial 
        dif = final-initial
        #print("dif= ",dif)
        
        
        if dif > significance:
            significance = dif
            key = i

    #add 1 on the chosen class
    classes[key,0]+=1
    classes[key,1]+=1
    print(" Added 1 in the ",str(key+1),"th class.")
    return classes


classes = np.array([[7,1007],[15,25],[19,30],[17,20]])
extraStudents = 10 #brilliant students that are guaranteed to pass the exam of any class they are assigned to

for student in range(extraStudents):
    classes = check_significance(classes)

#By adding the student I lower the ratio of this class and as a consequence of all the classes. So It might be a god idea to add them
# to the class with the most amount of student ssince it will have the smallest impact to the average of the classes

#If the ratio is more than 1 (which is) when adding one  up and down it raises the ratio. But after the first one, every other addition
#is less significant. So after every one I add I ll check if I should add to a different one

#i need to get the same results if i switch the classes


print("averagem pass ratio is ",average_pass_ratio(classes))


