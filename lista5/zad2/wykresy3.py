import matplotlib.pyplot as plt
import numpy as np

dane1 = np.empty(100, dtype=int)

file = open(f"wyniki/bin_2.txt")
dane_str = file.read().split()[1::2]

for j in range(len(dane_str)):
    dane1[j] = int(dane_str[j])

dane2 = np.empty(100, dtype=int)

file = open(f"wyniki/fibb_2.txt")
dane_str = file.read().split()[1::2]

for j in range(len(dane_str)):
    dane2[j] = int(dane_str[j])



plt.figure(1)

plt.title("Wykresy porównujący ilość porówanń BinHeap oraz FibHeap w zależności od n")
plt.xlabel("n")
plt.ylabel("# Porównań kluczy")

plt.plot(np.linspace(100, 10000, 100, True), dane1, "b-", label="Binomial Heap")
plt.plot(np.linspace(100, 10000, 100, True), dane2, "r-", label="Fibbonacci Heap")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/bin_fib.png", dpi=300)
plt.close()