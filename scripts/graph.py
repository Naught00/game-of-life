import numpy as np
import matplotlib.pyplot as plt
import tikzplotlib

def main():

    ag = [0.0, 2.6, 2.0, 6.2, 5.6, 1.6, 3.1, 2.3, 2.6, 1.2]
    ye = [1983, 1987, 1991, 1995, 1999, 2003, 2007, 2011, 2015, 2019] 
    plt.plot(ye, ag, label='Finnish Electorate Volatility', marker='o')
    plt.xlabel('Year')
    plt.axis([1983, 2019, 0, 7])
    plt.ylabel('Volatility')
    plt.title('Finnish Electoral Volatility')
    tikzplotlib.save("mytikz.tex")



main()
