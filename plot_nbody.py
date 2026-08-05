import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("nbody.csv", delimiter=",")         # no skiprows because we deleted the header

plt.plot(data[:, 0], data[:, 1], label = "body 0")  # columns 0,1
plt.plot(data[:, 2], data[:, 3], label = "body 1")  # columns 2,3
plt.plot(data[:, 4], data[:, 5], label = "body 2")  # columns 4,5

plt.plot(0, 0, "ko")

plt.axis("equal")       # forces x and y axes to the same scale

plt.legend()

plt.title("3 bodies")
plt.xlabel("x")
plt.ylabel("y")

plt.show()