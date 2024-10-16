import { Personagem } from "./Personagem";

export class Guerreiro extends Personagem {
    constructor(nome: string) {
      super(nome, 300, 25, 25)
    }
  
    get classeNome(): string {
      return "Guerreiro";
    }
  }