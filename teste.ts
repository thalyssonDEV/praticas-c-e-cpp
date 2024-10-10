import { question } from "readline-sync"

class BankData {
    public saldo: number;
    public log: string[];
     
    constructor(saldoInicial: number) {
        this.saldo = saldoInicial;
        this.log = [];
    }

    mostrarSaldo(): void {
        console.log(`\nSALDO: ${this.saldo}\n`);
        const timestamp = new Date().toLocaleString();
        this.log.push(`{ Operation Type > Consultation: _> CONSULTA DE SALDO } Value: ${this.saldo} On ${timestamp}`)
    }

    sacar(valorSaque: number): void {
        this.saldo -= valorSaque;
        const timestamp = new Date().toLocaleString();
        this.log.push(`{ Operation Type > Transaction: _> SAQUE } Value: ${valorSaque} On ${timestamp}`);
    }

    depositar(valorDeposito: number): void {
        this.saldo += valorDeposito;
        const timestamp = new Date().toLocaleString();
        this.log.push(`{ Operation Type > Transaction: _> DEPÓSITO } Value: ${valorDeposito} On ${timestamp}`);
    }

    mostrarLog() {
        this.log.forEach((entry) => {
            console.log(entry);
        });
    }
}


function pauseExecution(): void  {
    question("Pressione Enter Para Continuar...");
}


function showMenu(): void {
    console.log("===== BANCO DO BOSTIL =====\n")
    console.log("[ 1 ] MOSTRAR SALDO ATUAL");
    console.log("[ 2 ] SACAR VALOR");
    console.log("[ 3 ] DEPOSITAR VALOR\n");
    console.log("[ 4 ] MOSTRAR LOG DE OPERAÇÕES\n");
}


function main(): void {
    console.clear();
    let saldoInicial: number = parseFloat(question("Digite Seu Saldo: "));
    let conta = new BankData(saldoInicial);

    while (true) {
        console.clear();
        showMenu();
        let opcao: number = parseInt(question("Digite Sua Opção: "));

        switch (opcao) {
            case 1:
                conta.mostrarSaldo();
                pauseExecution();
                break;

            case 2:
                let valorSaque = parseFloat(question("Digite o Valor Que Deseja Sacar: "));
                conta.sacar(valorSaque);
                
                break;

            case 3:
                let valorDeposito = parseFloat(question("Digite o Valor Que Deseja Depositar: "));
                conta.depositar(valorDeposito);
                break;

            case 4:
                conta.mostrarLog();
                pauseExecution();
                break;
        }
    }
}

main();
