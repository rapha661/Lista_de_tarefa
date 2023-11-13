#include <stdio.h>
#include "lib.h"

int main() {
  // Projeto feito por: Raphael Garavati Erbert RA: 221230147
  int opcao = -1;
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
    deleta_tarefa(&lt);
  }
  else if (opcao == 3) {
    printf("\n");
    listar_tarefa(&lt);
  }
  else if (opcao == 4) {
    printf("\n");
    alterar_tarefa(&lt);
  }
  else if(opcao == 5){
    printf("\n");
    filtro_prioridade(&lt);
  }
  else if(opcao == 6){
    printf("\n");
    filtrar_estado(&lt);
  }
  else if(opcao == 7){
    printf("\n");
    filtrar_categoria(&lt);
  }
  else if(opcao == 8){
    printf("\n");
    filtrar_prioridade_e_categoria(&lt);
  }
  else if(opcao == 9){
    printf("\n");
    exportar_prioridade_arquivo(&lt);
  }
  } while(opcao != 0);

  escreve_arquivo(&lt); // Adiciona as mudanças no arquivo
  
}
