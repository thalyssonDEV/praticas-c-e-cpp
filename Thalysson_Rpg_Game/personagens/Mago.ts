import { Personagem } from "./Personagem";

export class Mago extends Personagem {
    constructor(nome: string) {
      super(nome, 100, 70, 10)
    }
  
    get classeNome(): string {
      return "Mago";
    }
  }