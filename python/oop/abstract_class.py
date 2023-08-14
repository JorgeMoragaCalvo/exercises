# Una clase abstracta es una clase que no se puede instanciar
from abc import ABC, abstractclassmethod # abstractclassmethod -> decorador
#ABC clase auxiliar, abc modulo de Python

#metodo abstracto esta declarado pero sin implementacion

class Persona(ABC):
    @abstractclassmethod
    def __init__(self, nombre, edad, sexo, actividad):
        self.nombre = nombre
        self.edad = edad
        self.sexo = sexo
        self.actividad = actividad
    
    @abstractclassmethod
    def hacer_actividad(self):
        pass

    def presentarse(self):
        print(f"Hola, me llamo: {self.nombre} y tengo {self.edad} anios")
    
class Estudiante(Persona):
    def __init__(self, nombre, edad, sexo, actividad):
        super().__init__(nombre, edad, sexo, actividad)
    
    def __str__(self): #representacion del objeto en una cadena de texto
        return f'Estudiante (nombre = {self.nombre}, edad = {self.edad})'

    def hacer_actividad(self):
        print(f"Estoy estudiando: {self.actividad}")
    
class Trabajador(Persona):
    def __init__(self, nombre, edad, sexo, actividad):
        super().__init__(nombre, edad, sexo, actividad)
    
    def hacer_actividad(self):
        print(f"Estoy trabajando en: {self.actividad}")
    

estudiante = Estudiante("Pedrito", 25, "No Binario", "programacion")
trabajador = Trabajador("Lucas", 21, "Masculino", "programacion")

estudiante.hacer_actividad()
estudiante.presentarse()
trabajador.hacer_actividad()
print(estudiante)


