#Inheritance in Python
class Persona:
    def __init__(self, nombre, edad, nacionalidad):
        self.nombre = nombre
        self.edad = edad
        self.nacionalidad = nacionalidad
    
    def hablar(self):
        print("Estoy hablando")


class Artista:
    def __init__(self, skill):
        self.skill = skill

    def show_skill(self):
        print(f"Mi habilidad es: {self.skill}")

class Empleado(Persona):
    def __init__(self, nombre, edad, nacionalidad, trabajo, salario):
        super().__init__(nombre, edad, nacionalidad)
        self.trabajo = trabajo
        self.salario = salario
    
    def hablar(self):
        print(f"Soy el empleado {self.nombre} y gano {self.salario}")


#Multiple inheritance
class EmpleadoArtista(Persona, Artista):
    def __init__(self, nombre, edad, nacionalidad, skill, salario, empresa):
        Persona.__init__(self, nombre, edad, nacionalidad)
        Artista.__init__(self, skill)
        self.salario = salario
        self.empresa = empresa

    def presentarse(self):
        return f'{super().show_skill()}' #self -> se refiere al metodo reescrito. super() -> accede a la clase padre


empleado1 = Empleado("Roberto", 43, 'chilena', 'Programador', 100000)
empleado1.hablar()


empleado2 = EmpleadoArtista("Carlos", 40, 'chilena', 'Cantar', 80000, 'Mi empresa')
empleado2.presentarse()

herencia = issubclass(EmpleadoArtista, Artista)
print(herencia) #True

instancia = isinstance(empleado1, EmpleadoArtista)
print(instancia) #False