import matplotlib.pyplot as plt
import numpy as np

dane_str = []
dane = []

file = open("zad12/zad21.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_21 = dane[::4]
if_21 = dane[1::4]
swap_21 = dane[2::4]
height_21 = dane[3::4]

avg_n_21 = []
avg_if_21 = []
avg_swap_21 = []
avg_height_21 = []

max_if_21 = []
max_swap_21 = []
max_height_21 = []

for i in range(10):
    avg_n_21.append(n_21[i * 20])
    avg_if_21.append(0)
    max_if_21.append(0)
    avg_swap_21.append(0)
    max_swap_21.append(0)
    avg_height_21.append(0)
    max_height_21.append(0)
    for j in range(20):
        avg_if_21[i] += if_21[i * 20 + j]
        max_if_21[i] = max(max_if_21[i], if_21[i * 20 + j])
        avg_swap_21[i] += swap_21[i * 20 + j]
        max_swap_21[i] = max(max_swap_21[i], swap_21[i * 20 + j])
        avg_height_21[i] += height_21[i * 20 + j]
        max_height_21[i] = max(max_height_21[i], height_21[i * 20 + j])
    avg_if_21[i] /= 20
    avg_swap_21[i] /= 20
    avg_height_21[i] /= 20

dane_str = []
dane = []

file = open("zad12/zad22.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_22 = dane[::4]
if_22 = dane[1::4]
swap_22 = dane[2::4]
height_22 = dane[3::4]

avg_n_22 = []
avg_if_22 = []
avg_swap_22 = []
avg_height_22 = []

max_if_22 = []
max_swap_22 = []
max_height_22 = []

for i in range(10):
    avg_n_22.append(n_22[i * 20])
    avg_if_22.append(0)
    max_if_22.append(0)
    avg_swap_22.append(0)
    max_swap_22.append(0)
    avg_height_22.append(0)
    max_height_22.append(0)
    for j in range(20):
        avg_if_22[i] += if_22[i * 20 + j]
        max_if_22[i] = max(max_if_22[i], if_22[i * 20 + j])
        avg_swap_22[i] += swap_22[i * 20 + j]
        max_swap_22[i] = max(max_swap_22[i], swap_22[i * 20 + j])
        avg_height_22[i] += height_22[i * 20 + j]
        max_height_22[i] = max(max_height_22[i], height_22[i * 20 + j])
    avg_if_22[i] /= 20
    avg_swap_22[i] /= 20
    avg_height_22[i] /= 20

dane_str = []
dane = []

file = open("zad34/zad41.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_41 = dane[::4]
if_41 = dane[1::4]
swap_41 = dane[2::4]
height_41 = dane[3::4]

avg_n_41 = []
avg_if_41 = []
avg_swap_41 = []
avg_height_41 = []

max_if_41 = []
max_swap_41 = []
max_height_41 = []

for i in range(10):
    avg_n_41.append(n_41[i * 20])
    avg_if_41.append(0)
    max_if_41.append(0)
    avg_swap_41.append(0)
    max_swap_41.append(0)
    avg_height_41.append(0)
    max_height_41.append(0)
    for j in range(20):
        avg_if_41[i] += if_41[i * 20 + j]
        max_if_41[i] = max(max_if_41[i], if_41[i * 20 + j])
        avg_swap_41[i] += swap_41[i * 20 + j]
        max_swap_41[i] = max(max_swap_41[i], swap_41[i * 20 + j])
        avg_height_41[i] += height_41[i * 20 + j]
        max_height_41[i] = max(max_height_41[i], height_41[i * 20 + j])
    avg_if_41[i] /= 20
    avg_swap_41[i] /= 20
    avg_height_41[i] /= 20

dane_str = []
dane = []

file = open("zad34/zad42.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_42 = dane[::4]
if_42 = dane[1::4]
swap_42 = dane[2::4]
height_42 = dane[3::4]

avg_n_42 = []
avg_if_42 = []
avg_swap_42 = []
avg_height_42 = []

max_if_42 = []
max_swap_42 = []
max_height_42 = []

for i in range(10):
    avg_n_42.append(n_42[i * 20])
    avg_if_42.append(0)
    max_if_42.append(0)
    avg_swap_42.append(0)
    max_swap_42.append(0)
    avg_height_42.append(0)
    max_height_42.append(0)
    for j in range(20):
        avg_if_42[i] += if_42[i * 20 + j]
        max_if_42[i] = max(max_if_42[i], if_42[i * 20 + j])
        avg_swap_42[i] += swap_42[i * 20 + j]
        max_swap_42[i] = max(max_swap_42[i], swap_42[i * 20 + j])
        avg_height_42[i] += height_42[i * 20 + j]
        max_height_42[i] = max(max_height_42[i], height_42[i * 20 + j])
    avg_if_42[i] /= 20
    avg_swap_42[i] /= 20
    avg_height_42[i] /= 20

dane_str = []
dane = []

file = open("zad56/zad61.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_61 = dane[::4]
if_61 = dane[1::4]
swap_61 = dane[2::4]
height_61 = dane[3::4]

avg_n_61 = []
avg_if_61 = []
avg_swap_61 = []
avg_height_61 = []

max_if_61 = []
max_swap_61 = []
max_height_61 = []

for i in range(10):
    avg_n_61.append(n_61[i * 20])
    avg_if_61.append(0)
    max_if_61.append(0)
    avg_swap_61.append(0)
    max_swap_61.append(0)
    avg_height_61.append(0)
    max_height_61.append(0)
    for j in range(20):
        avg_if_61[i] += if_61[i * 20 + j]
        max_if_61[i] = max(max_if_61[i], if_61[i * 20 + j])
        avg_swap_61[i] += swap_61[i * 20 + j]
        max_swap_61[i] = max(max_swap_61[i], swap_61[i * 20 + j])
        avg_height_61[i] += height_61[i * 20 + j]
        max_height_61[i] = max(max_height_61[i], height_61[i * 20 + j])
    avg_if_61[i] /= 20
    avg_swap_61[i] /= 20
    avg_height_61[i] /= 20


dane_str = []
dane = []

file = open("zad56/zad62.txt")
dane_str = file.read().split()
file.close()

for i in dane_str:
    dane.append(int(i))

n_62 = dane[::4]
if_62 = dane[1::4]
swap_62 = dane[2::4]
height_62 = dane[3::4]

avg_n_62 = []
avg_if_62 = []
avg_swap_62 = []
avg_height_62 = []

max_if_62 = []
max_swap_62 = []
max_height_62 = []

for i in range(10):
    avg_n_62.append(n_62[i * 20])
    avg_if_62.append(0)
    max_if_62.append(0)
    avg_swap_62.append(0)
    max_swap_62.append(0)
    avg_height_62.append(0)
    max_height_62.append(0)
    for j in range(20):
        avg_if_62[i] += if_62[i * 20 + j]
        max_if_62[i] = max(max_if_62[i], if_62[i * 20 + j])
        avg_swap_62[i] += swap_62[i * 20 + j]
        max_swap_62[i] = max(max_swap_62[i], swap_62[i * 20 + j])
        avg_height_62[i] += height_62[i * 20 + j]
        max_height_62[i] = max(max_height_62[i], height_62[i * 20 + j])
    avg_if_62[i] /= 20
    avg_swap_62[i] /= 20
    avg_height_62[i] /= 20


# Zadanie 2

plt.figure(1)

plt.title("Wykres ilości porównań kluczy BST")
plt.xlabel("n")
plt.ylabel("# porównań kluczy")

plt.plot(avg_n_21, avg_if_21, "b-", label = "Avg # key comp worst-case")
plt.plot(avg_n_21, max_if_21, "y-", label = "Max # key comp worst-case")
plt.plot(avg_n_22, avg_if_22, "g-", label = "Avg # key comp avg-case")
plt.plot(avg_n_22, max_if_22, "c-", label = "Max # key comp avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/if_2.png", dpi=300)
plt.close()

plt.figure(2)

plt.title("Wykres ilości podmian nodów BST")
plt.xlabel("n")
plt.ylabel("# podmian nodów")

plt.plot(avg_n_21, avg_swap_21, "b-", label = "Avg # swap node worst-case")
plt.plot(avg_n_21, max_swap_21, "y-", label = "Max # swap node worst-case")
plt.plot(avg_n_22, avg_swap_22, "g-", label = "Avg # swap node avg-case")
plt.plot(avg_n_22, max_swap_22, "c-", label = "Max # swap node avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/swap_2.png", dpi=300)
plt.close()

plt.figure(3)

plt.title("Wykres wysokości BST")
plt.xlabel("n")
plt.ylabel("Wysokość")

plt.plot(avg_n_21, avg_height_21, "b-", label = "Avg # height of BST worst-case")
plt.plot(avg_n_21, max_height_21, "y-", label = "Max # height of BST worst-case")
plt.plot(avg_n_22, avg_height_22, "g-", label = "Avg # height of BST avg-case")
plt.plot(avg_n_22, max_height_22, "c-", label = "Max # height of BST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/height_2.png", dpi=300)
plt.close()

# Zadanie 4

plt.figure(4)

plt.title("Wykres ilości porównań kluczy RBBST")
plt.xlabel("n")
plt.ylabel("# porównań kluczy")

plt.plot(avg_n_41, avg_if_41, "b-", label = "Avg # key comp worst-case")
plt.plot(avg_n_41, max_if_41, "y-", label = "Max # key comp worst-case")
plt.plot(avg_n_42, avg_if_42, "g-", label = "Avg # key comp avg-case")
plt.plot(avg_n_42, max_if_42, "c-", label = "Max # key comp avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/if_4.png", dpi=300)
plt.close()

plt.figure(5)

plt.title("Wykres ilości podmian nodów RBBST")
plt.xlabel("n")
plt.ylabel("# podmian nodów")

plt.plot(avg_n_41, avg_swap_41, "b-", label = "Avg # swap node worst-case")
plt.plot(avg_n_41, max_swap_41, "y-", label = "Max # swap node worst-case")
plt.plot(avg_n_42, avg_swap_42, "g-", label = "Avg # swap node avg-case")
plt.plot(avg_n_42, max_swap_42, "c-", label = "Max # swap node avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/swap_4.png", dpi=300)
plt.close()

plt.figure(6)

plt.title("Wykres wysokości RBBST")
plt.xlabel("n")
plt.ylabel("Wysokość")

plt.plot(avg_n_41, avg_height_41, "b-", label = "Avg height of RBBST worst-case")
plt.plot(avg_n_41, max_height_41, "y-", label = "Max height of RBBST worst-case")
plt.plot(avg_n_42, avg_height_42, "g-", label = "Avg height of RBBST avg-case")
plt.plot(avg_n_42, max_height_42, "c-", label = "Max height of RBBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/height_4.png", dpi=300)
plt.close()

# Zadanie 6

plt.figure(7)

plt.title("Wykres ilości porównań kluczy SplayBST")
plt.xlabel("n")
plt.ylabel("# porównań kluczy")

plt.plot(avg_n_61, avg_if_61, "b-", label = "Avg # key comp worst-case")
plt.plot(avg_n_61, max_if_61, "y-", label = "Max # key comp worst-case")
plt.plot(avg_n_62, avg_if_62, "g-", label = "Avg # key comp avg-case")
plt.plot(avg_n_62, max_if_62, "c-", label = "Max # key comp avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/if_6.png", dpi=300)
plt.close()

plt.figure(8)

plt.title("Wykres ilości podmian nodów SplayBST")
plt.xlabel("n")
plt.ylabel("# podmian nodów")

plt.plot(avg_n_61, avg_swap_61, "b-", label = "Avg # swap node worst-case")
plt.plot(avg_n_61, max_swap_61, "y-", label = "Max # swap node worst-case")
plt.plot(avg_n_62, avg_swap_62, "g-", label = "Avg # swap node avg-case")
plt.plot(avg_n_62, max_swap_62, "c-", label = "Max # swap node avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/swap_6.png", dpi=300)
plt.close()

plt.figure(9)

plt.title("Wykres wysokości SplayBST")
plt.xlabel("n")
plt.ylabel("Wysokość")

plt.plot(avg_n_61, avg_height_61, "b-", label = "Avg height of SplayBST worst-case")
plt.plot(avg_n_61, max_height_61, "y-", label = "Max height of SplayBST worst-case")
plt.plot(avg_n_62, avg_height_62, "g-", label = "Avg height of SplayBST avg-case")
plt.plot(avg_n_62, max_height_62, "c-", label = "Max height of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/height_6.png", dpi=300)
plt.close()

# Porównywanie różnych rodzajów drzew

plt.figure(10)

plt.title("Wykres średniej ilości porównań kluczy dla róznych BST")
plt.xlabel("n")
plt.ylabel("# porównań kluczy")

plt.plot(avg_n_21, avg_if_21, "b-", label = "Avg # if of BST worst-case")
plt.plot(avg_n_22, avg_if_22, "y-", label = "Avg # if of BST avg-case")
plt.plot(avg_n_41, avg_if_41, "r-", label = "Avg # if of RBBST worst-case")
plt.plot(avg_n_42, avg_if_42, "m-", label = "Avg # if of RBBST avg-case")
plt.plot(avg_n_61, avg_if_61, "g-", label = "Avg # if of SplayBST worst-case")
plt.plot(avg_n_62, avg_if_62, "c-", label = "Avg # if of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/avg_if.png", dpi=300)
plt.close()

plt.figure(11)

plt.title("Wykres maksymalnej ilości porównań kluczy dla róznych BST")
plt.xlabel("n")
plt.ylabel("# porównań kluczy")

plt.plot(avg_n_21, max_if_21, "b-", label = "Max # if of BST worst-case")
plt.plot(avg_n_22, max_if_22, "y-", label = "Max # if of BST avg-case")
plt.plot(avg_n_41, max_if_41, "r-", label = "Max # if of RBBST worst-case")
plt.plot(avg_n_42, max_if_42, "m-", label = "Max # if of RBBST avg-case")
plt.plot(avg_n_61, max_if_61, "g-", label = "Max # if of SplayBST worst-case")
plt.plot(avg_n_62, max_if_62, "c-", label = "Max # if of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/max_if.png", dpi=300)
plt.close()

plt.figure(12)

plt.title("Wykres średniej ilości podmian nodów dla róznych BST")
plt.xlabel("n")
plt.ylabel("# podmian nodów")

plt.plot(avg_n_21, avg_swap_21, "b-", label = "Avg # swap of BST worst-case")
plt.plot(avg_n_22, avg_swap_22, "y-", label = "Avg # swap of BST avg-case")
plt.plot(avg_n_41, avg_swap_41, "r-", label = "Avg # swap of RBBST worst-case")
plt.plot(avg_n_42, avg_swap_42, "m-", label = "Avg # swap of RBBST avg-case")
plt.plot(avg_n_61, avg_swap_61, "g-", label = "Avg # swap of SplayBST worst-case")
plt.plot(avg_n_62, avg_swap_62, "c-", label = "Avg # swap of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/avg_swap.png", dpi=300)
plt.close()

plt.figure(13)

plt.title("Wykres maksymalnej ilości podmian nodów dla róznych BST")
plt.xlabel("n")
plt.ylabel("# podmian nodów")

plt.plot(avg_n_21, max_swap_21, "b-", label = "Max # swap of BST worst-case")
plt.plot(avg_n_22, max_swap_22, "y-", label = "Max # swap of BST avg-case")
plt.plot(avg_n_41, max_swap_41, "r-", label = "Max # swap of RBBST worst-case")
plt.plot(avg_n_42, max_swap_42, "m-", label = "Max # swap of RBBST avg-case")
plt.plot(avg_n_61, max_swap_61, "g-", label = "Max # swap of SplayBST worst-case")
plt.plot(avg_n_62, max_swap_62, "c-", label = "Max # swap of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/max_swap.png", dpi=300)
plt.close()

plt.figure(14)

plt.title("Wykres średniej wysokości dla róznych BST")
plt.xlabel("n")
plt.ylabel("Wysokość")

plt.plot(avg_n_21, avg_height_21, "b-", label = "Avg height of BST worst-case")
plt.plot(avg_n_22, avg_height_22, "y-", label = "Avg height of BST avg-case")
plt.plot(avg_n_41, avg_height_41, "r-", label = "Avg height of RBBST worst-case")
plt.plot(avg_n_42, avg_height_42, "m-", label = "Avg height of RBBST avg-case")
plt.plot(avg_n_61, avg_height_61, "g-", label = "Avg height of SplayBST worst-case")
plt.plot(avg_n_62, avg_height_62, "c-", label = "Avg height of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/avg_height.png", dpi=300)
plt.close()

plt.figure(15)

plt.title("Wykres maksymalnej wysokości nodów dla róznych BST")
plt.xlabel("n")
plt.ylabel("Wysokość")

plt.plot(avg_n_21, max_height_21, "b-", label = "Max height of BST worst-case")
plt.plot(avg_n_22, max_height_22, "y-", label = "Max height of BST avg-case")
plt.plot(avg_n_41, max_height_41, "r-", label = "Max height of RBBST worst-case")
plt.plot(avg_n_42, max_height_42, "m-", label = "Max height of RBBST avg-case")
plt.plot(avg_n_61, max_height_61, "g-", label = "Max height of SplayBST worst-case")
plt.plot(avg_n_62, max_height_62, "c-", label = "Max height of SplayBST avg-case")

plt.legend(loc = 2, fontsize = "small")

plt.savefig("wykresy/max_height.png", dpi=300)
plt.close()