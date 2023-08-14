class Persona:
    def __init__(self, nombre, edad):
        self.__nombre = nombre #private -> '__'
        self.__edad = edad 

    @property #getter
    def nombre(self):
        return self.__nombre

    @property #getter
    def edad(self):
        return self.__edad
    
    @nombre.setter #setter
    def nombre(self, nombre):
        self.__nombre = nombre

    @edad.setter #setter
    def edad(self, edad):
        self.__edad = edad


persona = Persona("Esteban", 56)
print(persona.nombre)
persona.nombre = "Pepito"
print(persona.nombre)