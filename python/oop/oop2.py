class Estudiante:
    def __init__(self, name, age, grade):
        self.name = name
        self.age = age
        self.grade = grade

    def estudiar(self):
        print("Estudiando...")

name = input("Ingrese su nombre: ")
age = int(input("Ingrese su edad: "))
grade = int(input("Ingrese su grado: "))

estudiante = Estudiante(name, age, grade)

print(estudiante.name)

estudiante.estudiar()

#run in VSCode terminal 'python file_name.py'