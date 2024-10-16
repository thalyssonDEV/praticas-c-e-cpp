import { question } from 'readline-sync'
import { Cores, Fundo } from '../cores/Cores'
import { Personagem } from '../personagens/Personagem';
import { Mago } from '../personagens/Mago';
import { Guerreiro } from '../personagens/Guerreiro';
import { Arqueiro } from '../personagens/Arqueiro';

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


function awaitInput(): void {
    question(`\n${Cores.cianoBrilhanteNegrito}Pressione ENTER para Continuar...${Cores.reset}\n`);
    console.clear();
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

  console.log(`${Cores.azulBrilhante}============== RPG PARTY ===============${Cores.reset}\n`);
  console.log(`Jogador 1: ${Cores.azulNegrito}${jogador1.nome}${Cores.reset} 
    Escolheu a Classe ${Cores.verdeBrilhanteNegrito}${jogador1.classeNome}${Cores.reset}`);
  console.log(`Jogador 2: ${Cores.azulNegrito}${jogador2.nome}${Cores.reset} 
    Escolheu a Classe ${Cores.verdeBrilhanteNegrito}${jogador2.classeNome}${Cores.reset}`);
  awaitInput();

  console.log(`${Cores.vermelhoBrilhanteNegrito}============== FIGHT ==============${Cores.reset}`);

  process.stdout.write(` ${Cores.azulNegrito}${jogador1.nome}: ${Cores.verdeBrilhanteNegrito}${jogador1.classeNome}${Cores.reset}`);
  process.stdout.write(`                 ${Cores.azulNegrito}${jogador2.nome}: ${Cores.verdeBrilhanteNegrito}${jogador2.classeNome}${Cores.reset}`);

  process.stdout.write(` ${Cores.verdeBrilhanteNegrito}VIDA:${Cores.reset} ${jogador1.vida}                 
    ${Cores.verdeBrilhanteNegrito}VIDA:${Cores.reset} ${jogador2.vida}`)

  while (jogador1.estaVivo() && jogador2.estaVivo()) {
    }
}

main();