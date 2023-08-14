class Personaje:
    def __init__(self, nombre, fuerza, velocidad):
        self.nombre = nombre
        self.fuerza = fuerza
        self.velocidad = velocidad
    
    def __repr__(self):
        return f"{self.nombre} (Fuerza: {self.fuerza}, velocidad: {self.velocidad})"
    
    def __add__(self, otro):
        new_name = self.nombre + "-" + otro.nombre
        new_force = ((self.fuerza + otro.fuerza) / 2) ** 2
        new_velocidad = ((self.velocidad + otro.velocidad) / 2) ** 2
        return Personaje(new_name, new_force, new_velocidad)

personaje1 = Personaje("Goku", 100, 100)
personaje2 = Personaje("Vegeta", 99, 99)

gogeta = personaje1 + personaje2

print(gogeta)