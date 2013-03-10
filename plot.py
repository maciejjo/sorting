# -*- coding: utf-8 -*- at

import matplotlib.pyplot as plt
import csv

bubble_count = []
bubble_times = []
select_count = []
select_times = []
insert_count = []
insert_times = []
shell_count = []
shell_times = []
with open('results.csv') as csvfile:
	reader = csv.reader(csvfile)
	for row in reader:
		if((row[0] == "Random") and (row[1] == "Bubble sort")):
			bubble_count.append(int(row[2]))
			bubble_times.append(float(row[3]))
	
		if((row[0] == "Random") and (row[1] == "Selection sort")):
			select_count.append(int(row[2]))
			select_times.append(float(row[3]))
		
		if((row[0] == "Random") and (row[1] == "Insertion sort")):
			insert_count.append(int(row[2]))
			insert_times.append(float(row[3]))
		
		if((row[0] == "Random") and (row[1] == "Shell sort")):
			shell_count.append(int(row[2]))
			shell_times.append(float(row[3]))
#for element in bubble_times:
#	print "%d - %f" %(int(element[0]), float(element[1]))
#	plt.plot(int(element[0]), float(element[1]), 'bo-')
plt.plot(bubble_count, bubble_times, marker='o', color='blue', linewidth=2.5, linestyle='-', label="Bubble sort")
plt.plot(select_count, select_times, marker='o', color='red', linewidth=2.5, linestyle='-', label="Select sort")
plt.plot(insert_count, insert_times, marker='o', color='green', linewidth=2.5, linestyle='-', label="Insert sort")
plt.plot(shell_count, shell_times, marker='o', color='yellow', linewidth=2.5, linestyle='-', label="Shell sort")

plt.legend(loc='upper left')
plt.ylabel('Time in seconds')
plt.xlabel('Number of elements')
plt.savefig('wykres.png')


