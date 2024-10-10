import { question } from "readline-sync"

class DadosBanco {
    public saldo: number;
    public qtdSaques: number;

    constructor(saldoInicial: number) {
        this.saldo = saldoInicial;
        this.qtdSaques = 0;
    }

    sacar(valorSaque: number) {
        this.saldo -= valorSaque;
        this.qtdSaques++;
    }
}


function main(): void {


}

main();
