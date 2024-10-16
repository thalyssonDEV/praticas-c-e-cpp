import { question } from 'readline-sync'
import { Cores, Fundo } from './cores'

// Classe Pai
class Personagem {
  // Atributos
  protected _nome: string;
  protected _vida: number;
  protected _ataque: number;

  // Construtor
  constructor(nome: string, vida: number, ataque: number) {
    this._nome = nome;
    this._vida = vida;
    this._ataque = ataque;
  }

  // Métodos
  private calcularDano(){
    let forca = Math.random() * 100;

    if (forca <= 20) {
      return this._ataque * 0.7;
    } else if (forca <= 80) {
      return this._ataque;
    } else {
      return this._ataque * 1.7;
    }
  }

  public atacar(alvo: Personagem): void {
    let dano = this.calcularDano();
    console.log(`${this.nome} Atacou ${alvo.nome} e Causou ${dano.toFixed(2)} de Dano.`);

    alvo.receberDano(dano);
  }

  public receberDano(dano: number): void {
    this._vida -= dano;

    console.log(`${this.nome} Recebeu ${dano} de Dano! Vida Restante: ${this.vida}`);
  }

  public estaVivo(): boolean {
    return this.vida > 0;
  }

  // Getters e Setters
  get nome(): string {
    return this._nome;
  }

  get vida(): number {
    return this._vida;
  }

  get ataque(): number {
    return this._ataque;    
  }

  get classeNome(): string {
    return "ClasseNome";
  }
}

// Classes Filhas de Personagem;
class Mago extends Personagem {
  constructor(nome: string) {
    super(nome, 100, 70)
  }

  get classeNome(): string {
    return "Mago";
  }
}

class Guerreiro extends Personagem {
  constructor(nome: string) {
    super(nome, 300, 25)
  }

  get classeNome(): string {
    return "Guerreiro";
  }
}

class Arqueiro extends Personagem {
  constructor(nome: string) {
    super(nome, 150, 50)
  }

  get classeNome(): string {
    return "Arqueiro";
  }
}

// Criar Personagens de Ambos os Jogadores;
class PersonagemFactory {
  static mostrarClasses(): void {
    console.log(`\nEscolha Uma Classe De Personagem`);
    console.log("1. Mago");
    console.log("2. Guerreiro");
    console.log("3. Arqueiro");
  }
  
  static criarPersonagem(classe: number, nome: string): Personagem {
    switch (classe) {
      case 1:
        return new Mago(nome);
      case 2:
        return new Guerreiro(nome);
      case 3:
        return new Arqueiro(nome);
      default:
        console.log('Classe Inválida! Usando Guerreiro Como Padrão.');
        return new Guerreiro(nome);
    }
  }
}


function main() {
  console.clear();
  const nomeJogador1 = question("Nickname Jogador 1: ");
  PersonagemFactory.mostrarClasses();
  const classeJogador1 = Number(question(`Escolha a Classe Para ${nomeJogador1}: `));
  const jogador1 = PersonagemFactory.criarPersonagem(classeJogador1, nomeJogador1);
  console.clear();
  
  const nomeJogador2 = question("Nickname Jogador 2: ");
  PersonagemFactory.mostrarClasses();
  const classeJogador2 = Number(question(`Escolha a Classe Para ${nomeJogador2}: `));
  const jogador2 = PersonagemFactory.criarPersonagem(classeJogador2, nomeJogador2);
  console.clear();

  console.log(`${Cores.azulBrilhante}=========== RPG PARTY ============${Cores.reset}\n`);
  
  console.log(`Jogador 1: ${Cores.azulNegrito}${jogador1.nome}${Cores.reset} Escolheu a Classe ${Cores.verdeBrilhanteNegrito}${jogador1.classeNome}${Cores.verdeBrilhanteNegrito}`);
  console.log(`Jogador 2: ${Cores.azulNegrito}${jogador2.nome}${Cores.reset} Escolheu a Classe ${Cores.verdeBrilhanteNegrito}${jogador2.classeNome}${Cores.reset}`);
  
  
  while (jogador1.estaVivo() && jogador2.estaVivo()) {
    jogador1.atacar(jogador2);
    if (jogador2.estaVivo()) {
      jogador2.atacar(jogador1);
    }
  }
}

main();
