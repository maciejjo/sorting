# -*- coding: utf-8 -*- at

import matplotlib.pyplot as plt
import csv
from matplotlib.backends.backend_pdf import PdfPages
pp = PdfPages('datasets.pdf')
sortings = ["Selection", "Insertion", "Shell", "Heap"]

for sorting in sortings:
	random_count = []
	random_times = []
	ascending_count = []
	ascending_times = []
	descending_count = []
	descending_times = []
	constant_count = []
	constant_times = []
	v_shaped_count = []
	v_shaped_times = []
	sorting_name = sorting + " sort"
	with open('wyniki.csv') as csvfile:
		reader = csv.reader(csvfile)
		for row in reader:
			if(row[1] == sorting_name):
				if(row[0] == "Random"):
					random_count.append(int(row[2]))
					random_times.append(float(row[3]))
				
				if(row[0] == "Ascending"):
					ascending_count.append(int(row[2]))
					ascending_times.append(float(row[3]))
				
				if(row[0] == "Descending"):
					descending_count.append(int(row[2]))
					descending_times.append(float(row[3]))
				
				if(row[0] == "Constant"):
					constant_count.append(int(row[2]))
					constant_times.append(float(row[3]))

				if(row[0] == "V-shaped"):
					v_shaped_count.append(int(row[2]))
					v_shaped_times.append(float(row[3]))
	if(sorting == "Insertion"):
		print ascending_count
		print ascending_times
		print descending_count
		print descending_times
	plt.plot(random_count, random_times, marker='h', markersize=20,color='red', linewidth=2.5, linestyle='-', label="Random dataset")
	plt.plot(ascending_count, ascending_times, marker='d', markersize=15,color='green', linewidth=2.5, linestyle='-', label="Ascending dataset")
	plt.plot(descending_count, descending_times, marker='^', markersize=15,color='yellow', linewidth=2.5, linestyle='-', label="Descending dataset")
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
			
