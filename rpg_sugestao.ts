import { question } from 'readline-sync';
import { Cores } from './cores';

class Personagem {
  public nome: string;
  protected vida: number;
  protected ataque: number;

  constructor(nome: string, vida: number, ataque: number) {
    this.nome = nome;
    this.vida = vida;
    this.ataque = ataque;
  }

  private calcularDano() {
    let forca = Math.random() * 100;

    if (forca <= 20) {
      return this.ataque * 0.7;
    } else if (forca <= 80) {
      return this.ataque;
    } else {
      return this.ataque * 1.7;
    }
  }

  public atacar(alvo: Personagem): void {
    let dano = this.calcularDano();
    console.log(`${this.nome} Atacou ${alvo.nome} e Causou ${dano.toFixed(2)} de Dano.`);
    alvo.receberDano(dano);
  }

  public receberDano(dano: number): void {
    this.vida -= dano;
    console.log(`${this.nome} Recebeu ${dano.toFixed(2)} de Dano! Vida Restante: ${this.vida}`);
  }

  public estaVivo(): boolean {
    return this.vida > 0;
  }
}

class Mago extends Personagem {
  constructor(nome: string) {
    super(nome, 100, 70);
  }
}

class Guerreiro extends Personagem {
  constructor(nome: string) {
    super(nome, 300, 25);
  }
}

class Arqueiro extends Personagem {
  constructor(nome: string) {
    super(nome, 150, 50);
  }
}

class PersonagemFactory {
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

class Jogo {
  private jogador1: Personagem;
  private jogador2: Personagem;

  constructor(jogador1: Personagem, jogador2: Personagem) {
    this.jogador1 = jogador1;
    this.jogador2 = jogador2;
  }

  public iniciar() {
    console.log(`${Cores.azulBrilhante}=========== RPG PARTY ============${Cores.reset}`);
    while (this.jogador1.estaVivo() && this.jogador2.estaVivo()) {
      this.jogarTurno(this.jogador1, this.jogador2);
      if (this.jogador2.estaVivo()) {
        this.jogarTurno(this.jogador2, this.jogador1);
      }
    }
    this.finalizar();
  }

  private jogarTurno(atacante: Personagem, defensor: Personagem) {
    atacante.atacar(defensor);
  }

  private finalizar() {
    const vencedor = this.jogador1.estaVivo() ? this.jogador1 : this.jogador2;
    console.log(`${Cores.verde}O vencedor é: ${vencedor.nome}!${Cores.reset}`);
  }
}

function main() {
  console.clear();
  const jogador1 = PersonagemFactory.criarPersonagem(
    Number(question("Escolha Classe para Jogador 1 (1-Mago, 2-Guerreiro, 3-Arqueiro): ")),
    question("Nickname Jogador 1: ")
  );
  console.clear();
  const jogador2 = PersonagemFactory.criarPersonagem(
    Number(question("Escolha Classe para Jogador 2 (1-Mago, 2-Guerreiro, 3-Arqueiro): ")),
    question("Nickname Jogador 2: ")
  );
  console.clear();

  const jogo = new Jogo(jogador1, jogador2);
  jogo.iniciar();
}

main();
