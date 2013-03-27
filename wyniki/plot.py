# -*- coding: utf-8 -*- at

import matplotlib.pyplot as plt
import csv
from matplotlib.backends.backend_pdf import PdfPages
pp = PdfPages('sortings.pdf')
datasets = ["Random", "Ascending", "Descending", "Constant", "V-shaped"]
for dataset in datasets:
	with open('wyniki.csv') as csvfile:
		reader = csv.reader(csvfile)
		select_count = []
		select_times = []
		insert_count = []
		insert_times = []
		shell_count = []
		shell_times = []
		heap_count = []
		heap_times = []
		for row in reader:
			if(row[0] == dataset):
				print "Using %s dataset" % dataset
				if(row[1] == "Bubble sort"):
					bubble_count.append(int(row[2]))
					bubble_times.append(float(row[3]))
			
				if(row[1] == "Selection sort"):
					select_count.append(int(row[2]))
					select_times.append(float(row[3]))
				
				if(row[1] == "Insertion sort"):
					insert_count.append(int(row[2]))
					insert_times.append(float(row[3]))
				
				if(row[1] == "Shell sort"):
					shell_count.append(int(row[2]))
					shell_times.append(float(row[3]))
				
				if(row[1] == "Heap sort"):
					heap_count.append(int(row[2]))
					heap_times.append(float(row[3]))
		
	plt.plot(select_count, select_times, marker='o', color='red', linewidth=2.5, linestyle='-', label="Select sort")
	plt.plot(insert_count, insert_times, marker='o', color='green', linewidth=2.5, linestyle='-', label="Insert sort")
	plt.plot(shell_count, shell_times, marker='o', color='yellow', linewidth=2.5, linestyle='-', label="Shell sort")
	plt.plot(heap_count, heap_times, marker='o', color='blue', linewidth=2.5, linestyle='-', label="Heap sort")
	plt.suptitle(dataset + " dataset", fontsize=20)
	plt.legend(loc='upper right')
	plt.ylabel('Time in seconds')
	plt.xlabel('Number of elements')
	plt.grid(True)
	pp.savefig()
	plt.clf()

pp.close()
			
