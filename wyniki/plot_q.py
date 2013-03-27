# -*- coding: utf-8 -*- at

import matplotlib.pyplot as plt
import csv
from matplotlib.backends.backend_pdf import PdfPages
pp = PdfPages('sortings_qs_iterative.pdf')
datasets = ["Random", "Ascending", "Constant", "V-shaped"]
for dataset in datasets:
	with open('wyniki_qs_it.csv') as csvfile:
		reader = csv.reader(csvfile)
		qs_rec_rand_count = []
		qs_rec_rand_times = []
		qs_rec_right_count = []
		qs_rec_right_times = []
		for row in reader:
			if(row[0] == dataset):
				print "Using %s dataset" % dataset
				if(row[1] == "Quicksort iterative - random"):
					qs_rec_rand_count.append(int(row[2]))
					qs_rec_rand_times.append(float(row[3]))
				
				if(row[1] == "Quicksort iterative - rightmost"):
					qs_rec_right_count.append(int(row[2]))
					qs_rec_right_times.append(float(row[3]))
		
	plt.plot(qs_rec_rand_count, qs_rec_rand_times, marker='o', color='red', linewidth=2.5, linestyle='-', label="Qsort iterative random sort")
	plt.plot(qs_rec_right_count, qs_rec_right_times, marker='o', color='green', linewidth=2.5, linestyle='-', label="Qsort iterative right sort")
	plt.suptitle(dataset + " dataset", fontsize=20)
	plt.legend(loc='upper right')
	plt.ylabel('Time in seconds')
	plt.xlabel('Number of elements')
	plt.grid(True)
	pp.savefig()
	plt.clf()

pp.close()
			
