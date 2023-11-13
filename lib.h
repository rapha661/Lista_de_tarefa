#include <stdio.h>

typedef struct {
  char descricao[301];

  char categoria[101];

  char estado[21];

  int prioridade;

} tarefa; // criação do struct tarefa com a descricao, categoria e prioridade

typedef struct {
  tarefa tarefa[100];
  int qtnd;
} lista_tarefa; // criação do struct lista_tarefa com o tarefa[100], um array de struct, e o inteiro que indica a quantidade de tarefas dentro do tarefa[100]

void cadastra_tarefa(lista_tarefa *lt);

void listar_tarefa(lista_tarefa *lt);

void deleta_tarefa(lista_tarefa *lt);

void alterar_tarefa(lista_tarefa *lt);

void clear_buffer();

void filtro_prioridade(lista_tarefa *lt);

void filtrar_estado(lista_tarefa *lt);

void filtrar_categoria(lista_tarefa *lt);

void filtrar_prioridade_e_categoria(lista_tarefa *lt);

void exibe_menu(int *opcao);

int le_arquivo(lista_tarefa  *lt);

int escreve_arquivo(lista_tarefa *lt);

int exportar_prioridade_arquivo(lista_tarefa *lt);
