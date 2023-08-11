class Persona:
    def __init__(self, nombre, edad):
        self.__nombre = nombre #private -> '__'
        self.__edad = edad
    
    def get_nombre(self):
        return self.__nombre
    
    def get_edad(self):
        return self.__edad
    
    def set_nombre(self, nombre):
        self.__nombre = nombre

    def set_edad(self, edad):
        self.__edad = edad

persona = Persona("Esteban", 56)
print(persona.get_nombre())
print(persona.get_edad())

persona.set_nombre("Pepito")
persona.set_edad(46)
print(persona.get_nombre())
print(persona.get_edad())