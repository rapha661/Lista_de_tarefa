#include <stdio.h>
#include "lib.h"

int main() {
  // Projeto feito por: Nathan Gabriel da Fonseca Leite RA: 221230287 e Raphael Garavati Erbert RA: 221230147
  int opcao = -1;
  int index_tarefa;
  lista_tarefa lt;
  lt.qtnd = 0;

  le_arquivo(&lt); // Atualiza o lt.qtnd e as tarefas dentro do tarefa[100]

  do {
    exibe_menu(&opcao);

    if (opcao == 1) {
    cadastra_tarefa(&lt);
  }
  else if (opcao == 2) {
    printf("\n");
    deleta_tarefa(&lt, index_tarefa);
  }
  else if (opcao == 3) {
    printf("\n");
    listar_tarefa(&lt);
  }
  else if (opcao == 4) {
    printf("\n");
    alterar_tarefa(&lt);
  }
  } while(opcao != 0);

  escreve_arquivo(&lt); // Adiciona as mudanças no arquivo
  
  return 0;
}
