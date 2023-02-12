import numpy as np
import matplotlib.pyplot as plt
import tikzplotlib
import csv

def main():

    data = load_csv()
    plt.plot(data[0], data[1], label = 'Population over Time')
    plt.xlabel('Tick')
    plt.ylabel('Population')
    plt.title('Population over time')
    tikzplotlib.save("mytikz.tex")
    plt.show()



def load_csv():
    tick = []
    pop = []

    i = 0
    c = 0
    with open('out.csv') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        for row in csv_reader:
            print("here")
            tick.append(int(row[0]))
            pop.append(int(row[1]))

    return (tick, pop)

main()
