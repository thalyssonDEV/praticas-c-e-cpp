#include <iostream>
#include <string>
#include <time.h>

typedef class Pinto {
    // Atributos;
    private:
        enum tiposPica {
            GROWER,
            SHOWER
        };

        float tamanho;
        float espessura;
        float largura;
        bool isEreto;
        std::string user;
        tiposPica tipo;

    // Construtor;
    public:
        Pinto(float largura, float tamanho, float espessura, std::string user){
            this->largura = largura;
            this->espessura = espessura;
            this->tamanho = tamanho;
        }

        float getTamanho() {
            return tamanho;
        }
        float getLargura() {
            return largura;
        }
        float getEspessura() {
            return espessura;
        }




        // Métodos;
        void eregir(float tamanhoInicial, float larguraInicial, float espessuraInicial) {
            if (this -> isEreto) {
                std::cerr << "Ereção Mal Sucedida, Motivo: Já Está Ereto";
                return;
            }
            this->isEreto = true;

            this -> tamanho = tamanhoInicial;
            this -> largura = larguraInicial;
            this -> espessura = espessuraInicial;
        }

        void masturbar(void) {

        }

        void ejacular(void) {
            if (!this -> isEreto) {
                std::cerr << "Ejaculação Mal Sucedida, Motivo: Broxa!";
                return;
            }

            if (this -> tipo == "shower") {
                this -> tamanho *= 0.7;
                this -> espessura *= 0.7;
                this -> largura *= 0.7;

            } else if (this -> tipo == "grower") {
                this -> tamanho /= 4.0;
                this -> espessura /= 4.0;
                this -> largura /= 4.0;
            }
            this -> isEreto = false;
        }
    } Pintos;

int main(void) {
    Pinto infoPinto(15.0, 3.0, 2.0, "jubilau");


    return 0;

}
