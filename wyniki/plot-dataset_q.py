# -*- coding: utf-8 -*- at

import matplotlib.pyplot as plt
import csv
from matplotlib.backends.backend_pdf import PdfPages
pp = PdfPages('datasets_it_qs.pdf')
sortings = ["Quicksort iterative - random", "Quicksort iterative - rightmost"]

for sorting in sortings:
	random_count = []
	random_times = []
	descending_count = []
	descending_times = []
	constant_count = []
	constant_times = []
	v_shaped_count = []
	v_shaped_times = []
	sorting_name = sorting + " sort"
	with open('wyniki_qs_it.csv') as csvfile:
		reader = csv.reader(csvfile)
		for row in reader:
			print "%s" % row[0]
			if(row[1] == sorting):
				if(row[0] == "Random"):
					print "Using random!"
					random_count.append(int(row[2]))
					random_times.append(float(row[3]))
				
				if(row[0] == "Ascending"):
					descending_count.append(int(row[2]))
					descending_times.append(float(row[3]))
				
				if(row[0] == "Constant"):
					constant_count.append(int(row[2]))
					constant_times.append(float(row[3]))

				if(row[0] == "V-shaped"):
					v_shaped_count.append(int(row[2]))
					v_shaped_times.append(float(row[3]))

	plt.plot(random_count, random_times, marker='h', markersize=20,color='red', linewidth=2.5, linestyle='-', label="Random dataset")
	plt.plot(descending_count, descending_times, marker='^', markersize=15,color='yellow', linewidth=2.5, linestyle='-', label="Ascending dataset")
	plt.plot(constant_count, constant_times, marker='s', markersize=7,color='blue', linewidth=2.5, linestyle='-', label="Constant dataset")
	plt.plot(v_shaped_count, v_shaped_times, marker='o', color='orange', linewidth=2.5, linestyle='-', label="V-shapedd dataset")
	plt.suptitle(sorting + " sorting", fontsize=20)
	plt.legend(loc='upper left')
	plt.ylabel('Time in seconds')
	plt.xlabel('Number of elements')
	plt.grid(True)
	pp.savefig()
	plt.clf()
pp.close()
			
