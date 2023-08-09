class Celular:
    def __init__(self, marca, modelo, camara): #constructor
        self.marca = marca
        self.modelo = modelo
        self.camara = camara
    
    def llamar(self):
        print(f"Estas haciendo un llamado desde un {self.marca} {self.modelo}")
    
    def cortar(self):
        print(f"Cortaste la llamada desde tu {self.modelo}")


celular1 = Celular("Motorola", "G51", "50MP")
celular2 = Celular("Samsung", "S23", "48MP")

celular1.llamar()
celular2.cortar()