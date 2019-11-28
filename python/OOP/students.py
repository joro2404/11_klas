
class Person :

    def __init__(self, address):

        self.address = address

class Student(Person) :

    def __init__(self, id_in_class, marks, computer):

        self.id_in_class = id_in_class
        self.marks = marks
        self.computer = computer

    def addMark(self, mark):

        marks.append(mark)

    def getAverage(self):

        avg = 0
        k = 0

        for i in marks:
            avg += i
            k += 1
        
        return avg/k

p = Person("bul. Kopenhagen 38")
marks = [3, 6, 6, 5]
s = Student(10, marks, "wtf")
s.addMark(6)

print(s.getAverage())