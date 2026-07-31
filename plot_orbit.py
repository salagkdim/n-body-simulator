import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("orbit.csv", delimiter=",", skiprows= 1)         # skipping the x,y header

x = data[:, 0]          # all rows, column 0 (the x's)
y = data[:, 1]          # all rows, column 1 (the y's)




plt.plot(x, y)
plt.plot(0, 0, "y*")    # puts a yellow star at the origin (0,0)

plt.axis("equal")       # forces x and y axes to the same scale

plt.title("Orbit")
plt.xlabel("x")
plt.ylabel("y")

plt.show()