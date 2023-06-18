import matplotlib.pyplot as plt
import numpy as np

plots = ["b-", "r-", "y-", "g-", "c-"]

dane = np.zeros((5, 2003), dtype=int)

for i in range(5):
    file = open(f"wyniki/bin_1_n_500_{i + 1}.txt")
    dane_str = file.read().split()[1::2]
    for j in range(len(dane_str)):
        dane[i][j] = int(dane_str[j])

plt.figure(1)

plt.title("Wykresy dla n=500")
plt.xlabel("Numer operacji")
plt.ylabel("# Porównań kluczy")

for i in range(5):
    plt.plot(np.linspace(1, 2003, 2003, True), dane[i], plots[i], linewidth=.5, label=f"Test nr {i + 1}")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/bin_n_500.png", dpi=300)
plt.close()


dane = np.zeros((5, 4003), dtype=int)

for i in range(5):
    file = open(f"wyniki/bin_1_n_1000_{i + 1}.txt")
    dane_str = file.read().split()[1::2]
    for j in range(len(dane_str)):
        dane[i][j] = int(dane_str[j])

plt.figure(2)

plt.title("Wykresy dla n=1000")
plt.xlabel("Numer operacji")
plt.ylabel("# Porównań kluczy")

for i in range(5):
    plt.plot(np.linspace(1, 4003, 4003, True), dane[i], plots[i], linewidth=.5, label=f"Test nr {i + 1}")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/bin_n_1000.png", dpi=300)
plt.close()