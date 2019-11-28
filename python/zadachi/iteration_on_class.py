from time import sleep

class Iteratable:

    def __init__(self, max):
        self.max = max
        self.arr = []
        self.i = 0


    def __iter__(self):
        self.n = 0
        if len(self.arr) == self.max and self.i + 1 <= self.max :
            return iter(self.arr)
        return self

    def __next__(self):

        if self.n < self.max and len(self.arr) < self.max :
            sleep(1)
            self.n += 1
            self.arr.append(self.n)
            return self.n 
        
        else:
            raise StopIteration

    
p = Iteratable(5)

for i in p:
    print(i)

for i in p:
    print(i)