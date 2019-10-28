import sys
import numpy as np
import matplotlib.pyplot as plt

# setup title and lables
case = int(sys.argv[1])
if case == 6:
    plt.title('Histogram of Problem 6')
    plt.xlabel('Number of updates')
elif case == 7:
    plt.title('Histogram of Problem 7')
    plt.xlabel('Error rate')
elif case == 8:
    plt.title('Histogram of Problem 8')
    plt.xlabel('Error rate')
else:
    pass
plt.ylabel('Frequency')

# retrieve data by stdin
data = np.fromstring(input(), dtype=float, sep=' ')
plt.hist(data, bins=30, rwidth=0.8)

# plot average line
plt.axvline(data.mean(), color='k', linestyle='dashed', linewidth=1)
min_ylim, max_ylim = plt.ylim()
plt.text(data.mean() * 1.1, max_ylim * 0.9, 'Mean: {:.2f}'.format(data.mean()))

# save as png
plt.savefig('histogram.png')
