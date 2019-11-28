import math


class Vector:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z

    def _coords(self):
        return (self.x, self.y, self.z)

    def length(self):
        return sum(_ ** 2 for _ in self._coords()) ** 0.5

v1 = Vector(1.0, 2.0, 3.0)
v2 = Vector(4.0, 5.0, 6.0)
v3 = Vector(7.0, 8.0, 9.0)


print(*list(map(Vector.length, [v1, v2, v3])), sep = '\n')