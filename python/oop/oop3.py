#Inheritance in Python
class Persona:
    def __init__(self, nombre, edad, nacionalidad):
        self.nombre = nombre
        self.edad = edad
        self.nacionalidad = nacionalidad
    
    def hablar(self):
        print("Estoy hablando")


class Empleado(Persona):
    def __init__(self, nombre, edad, nacionalidad, trabajo, salario):
        super().__init__(nombre, edad, nacionalidad)
        self.trabajo = trabajo
        self.salario = salario
    
    def hablar(self):
        print(f"Soy el empleado {self.nombre} y gano {self.salario}")


empleado1 = Empleado("Roberto", 43, 'chilena', 'Programador', 100000)
empleado1.hablar()
