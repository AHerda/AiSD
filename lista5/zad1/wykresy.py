import matplotlib.pyplot as plt
import numpy as np

iteracje = 20
ny = 10

file = open("results.txt")
dane_str = file.read().split()
file.close()

dane = []
for i in dane_str:
    dane.append(int(i))

n = dane[::4]
time = dane[1::4]
iff = dane[2::4]
length =dane[3::4]

avg_n = []
avg_time = []
avg_time_n2 = []
avg_if = []
avg_if_n2 = []
avg_len = []
avg_len_n = []

for i in range(ny):
    avg_n.append(n[i * iteracje])
    avg_time.append(0)
    avg_if.append(0)
    avg_len.append(0)

    for j in range(iteracje):
        avg_time[i] += time[i * iteracje + j]
        avg_if[i] += iff[i * iteracje + j]
        avg_len[i] += length[i * iteracje + j]
    
    avg_time[i] /= iteracje
    #avg_time_n2.append(avg_time[i] / (avg_n[i]  * (np.log(avg_n[i]))))
    avg_if[i] /= iteracje
    #avg_if_n2.append(avg_if[i] / (avg_n[i] ** 2 * np.log(avg_n[i])))
    avg_len[i] /= iteracje
    #avg_len_n.append(avg_len[i] / (np.log(avg_n[i]) * avg_n[i]))




plt.figure(1)

plt.title("Wykres czasu od długości ciągów")
plt.xlabel("n")
plt.ylabel("Czas (ms)")

plt.plot(avg_n, avg_time, "bo-")

plt.savefig("wykresy/time.png", dpi=300)
plt.close()

plt.figure(2)

plt.title("Wykres ilości porównań od długości ciągów")
plt.xlabel("n")
plt.ylabel("# porównań")

plt.plot(avg_n, avg_if, "bo-")

plt.savefig("wykresy/if.png", dpi=300)
plt.close()

plt.figure(3)

plt.title("Wykres długości najdłuższego podciągu od długości ciągów")
plt.xlabel("n")
plt.ylabel("Długość najdłuższego podciągu")

plt.plot(avg_n, avg_len, "bo-")

plt.savefig("wykresy/length.png", dpi=300)
plt.close()
