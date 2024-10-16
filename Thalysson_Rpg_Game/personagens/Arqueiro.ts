import { Personagem } from "./Personagem";

export class Arqueiro extends Personagem {
    constructor(nome: string) {
      super(nome, 150, 50, 5)
    }
  
    get classeNome(): string {
      return "Arqueiro";
    }
  }
  