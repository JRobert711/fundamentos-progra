//Trabajo realizado por: Julio Roberto Guardado Quijano
#include <iostream>
#include <string>
#include <vector>

class Vehiculo {
public:
    std::string marca;
    std::string modelo;
    int año;
    double precioBase;

public:
    Vehiculo(const std::string& marca, const std::string& modelo, int año, double precioBase) {
        this->marca = marca;
        this->modelo = modelo;
        this->año = año;
        this->precioBase = precioBase;
        std::cout << "Se ha creado un vehículo genérico" << std::endl;
    }
    virtual double calcularPrecioFinal() {
        return precioBase;
    }
};

class Auto : public Vehiculo {
private:
    int numeroPuertas;

public:
    // Constructor
    Auto(const std::string& marca, const std::string& modelo, int año, double precioBase,
         int numeroPuertas)
        : Vehiculo(marca, modelo, año, precioBase), numeroPuertas(numeroPuertas) {
        std::cout << "Y se ha especificado que es un auto." << std::endl;
    }

    double calcularPrecioFinal() override {
        return precioBase + (precioBase * 0.15);
    }

    int getNumeroPuertas() const {
        return numeroPuertas;
    }
};

class Moto : public Vehiculo {
private:
    int cilindrada;

public:
    // Constructor
    Moto(const std::string& marca, const std::string& modelo, int año, int precioBase,
         int cilindrada)
        : Vehiculo(marca, modelo, año, precioBase), cilindrada(cilindrada) {
        std::cout << "Y se ha especificado que es una moto." << std::endl;
    }

    double calcularPrecioFinal() override {
        return precioBase + (precioBase * 0.1);
    }

    int getCilindrada() const {
        return cilindrada;
    }
};

int main() {
    std::vector<Vehiculo*> vehiculos;

    Auto* auto1 = new Auto("Toyota", "Corolla", 2020, 20000, 4);
    Moto* moto1 = new Moto("Yamaha", "R3", 2021, 5000, 321);

    vehiculos.push_back(auto1);
    vehiculos.push_back(moto1);

    for (Vehiculo* vehiculo : vehiculos) {
        std::cout << "Marca: " << vehiculo->marca << ", Modelo: " << vehiculo->modelo
                  << ", Año: " << vehiculo->año << ", Precio Final: " << vehiculo->calcularPrecioFinal();

        // Verificar el tipo de vehículo y mostrar atributos exclusivos
        if (Auto* autoPtr = dynamic_cast<Auto*>(vehiculo)) {
            std::cout << ", Número de Puertas: " << autoPtr->getNumeroPuertas();
        } else if (Moto* motoPtr = dynamic_cast<Moto*>(vehiculo)) {
            std::cout << ", Cilindrada: " << motoPtr->getCilindrada();
        }

        std::cout << std::endl;
    }

    for (Vehiculo* vehiculo : vehiculos) {
        delete vehiculo;
    }

    return 0;
}