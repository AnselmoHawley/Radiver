#include <stdio.h>

int main(void)
{
    char nome[26];
    int esc_a=0, esc_b=0, esc_c=0, esc_d=0, esc_e=0;
    int a, b, c, d, e;

    printf("\n\t\t\t\t\t\t(VOCÊ)");
    printf("\n\t\t...Finalmente, a vila de radiver.\n");
//Descrição
  printf("\n>O lodo nas pedras do caminho sinuoso de pavimento irregular deduravam sua idade, mas mostravam que ali havia cuidado. As casas não eram muito altas ou elaboradas, apenas o suficiente para proteger os moradores da pequena vila de Radiver da chuva ou da neve, parecia um bom lugar para uma vida simples<\n----\n>O motivo de sua visita, no entanto, não era tão simples<\n");

    printf("\n\t\t\t\t\t(LÍDER DA VILA)");
    printf("\n- Macacos me mordam! você deve ser o aventureiro enviado para salvar nossa vila. Por favor, meu caro(a), como se chama?\n");
//DESCRIÇÃO
    printf("\n>Cabelos curtos, barba grande e grisalha, anéis e colares dourados nas mão e pescoço. O chefe da vila, vestindo um casaco feito de pele de animal, parecia contradizer a simplicidade da vila com seu ar de político<\n");

//SELEÇÃO A ---
    printf("\n[1] (Informar seu nome ao líder da vila)\n[2] Pode me chamar do que quiser\n");
  
    printf("\n Resposta: ");
    scanf("%d", &a);
  
    while(esc_a == 0){
      switch(a){
        case 1:
          printf("Seu nome é: ");
          scanf("%s", nome);
          esc_a=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Então vou chamá-lo de... André!\n");
          esc_a=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &a);
        break;
      } 
    }
  //FIM SELEÇÃO A ---
  
    printf("\n\n>O chefe da vila estende um aperto de mãos para você<\n\n");
    printf("\n\t\t\t\t\t(LÍDER DA VILA)");
  
  //USO DA STRING NOME
      if(a==1){
        puts(nome);
        printf("\n- %s...Combina muito com o nome de um herói! Mas agora venha, não temos tempo a perder, deixe-me te mostrar algo\n", nome);
      }
      else if(a==2){
        printf("\n- André... Combina muito com o nome de um herói! Mas agora venha, não temos tempo a perder, deixe-me te mostrar algo...\n");
      }
  //FIM DO USO
  
  printf("\n\n>O líder da vila guia você para a parte mais exterior de Radiver, onde localizam-se as plantações<\n\n");

  printf("A plantação parecia farta e bem organizada, as culturas estavam bem dispostas em terras bem aradas, então o sustento dos camponeses parecia promissor se não fossem pelos vegetais murchos, cinzentos e cheios de moscas");

  printf("\n\t\t\t\t\t(LÍDER DA VILA)");
  printf("\n- Dês de antes da vila de Radiver ser fundadada, a floresta da noite sempre foi a casa da bruxa do musgo. Nossos fundadores conseguiram fazer um acordo, o qual dizia que se nosso povo não adentrasse demais seu território profano, seríamos deixados em paz\n");

  printf("\n\n>Ele parece pensativo<\n\n");

  printf("\n\t\t\t\t\t(LÍDER DA VILA)");
  printf("- Depois de tantas décadas ela quebrou o acordo! Da noite pro dia, lançou-nos uma maldição e nossas plantações adoeceram e murcharam... Mal há como sustentar-se neste outono!\n\n");

  printf("\n[1] Quando a maldição começou? \n[2] (Ficar calado)\n");
  printf("\n Resposta: ");
    scanf("%d", &b);

  //SELEÇÃO B
  while(esc_b != 1){
      switch(b){
        case 1:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- No fim do verão\n");
          esc_b=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Você é meio caladão em... Se serve de algo, a maldição começou no fim do verão.\n");
          esc_b=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &b);
        break;
      }
    }
//FIM SELEÇÃO C

  printf("\n[1] Mais alguma coisa estranha tem acontecido na vila?\n[2] Vou resolver seu problema (despedir-se do chefe da vila)\n");
  printf("\n Resposta: ");
    scanf("%d", &c);
  
//SELEÇÃO C
  while(esc_c != 1){
      switch(c){
        case 1:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Apenas a maldição da bruxa.\n");
          esc_c=1;
        break;
        case 2:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Boa sorte aventureiro, não esqueça de pegar seus suprimentos.\n");
          esc_c=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &c);
        break;
      }
    }
  if(c!=2){
  printf("\n[1] Há mais alguém com quem eu possa falar?  \n[2] Vou resolver seu problema (despedir-se do chefe da vila)\n");
  printf("\n Resposta: ");
    scanf("%d", &d);
//SELEÇÃO D
    while(esc_d != 1){
      switch(d){
        case 1:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Ninguém que possa te informar tão bem quanto eu! Boa sorte aventureiro, não esqueça de pegar seus suprimentos.\n");
          esc_d=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t(LÍDER DA VILA)");
          printf("\n- Boa sorte aventureiro, não esqueça de pegar seus suprimentos.\n");
          esc_d=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &d);
        break;
      }
    }
    //FIM SELEÇÃO D
    if(d==1){
      printf("\n\n>O aventureiro volta à vila para pegar seus itens, mas ainda nas plantações vê um fazendeiro lhe acenando<\n\n");
      printf("\n>O fazendeiro repousa um chapéu de palha em sua cabeça, suas roupas humildes estão sujas, ele carrega uma enxada velha no ombro e masca um longo pedaço de feno<\n");

      printf("\n[1] (Ir até o fazendeiro)\n[2] (Ignorar o fazendeiro)\n");
      printf("\n Resposta: ");
      scanf("%d", &e);
      
      //SELEÇÃO E
      while(esc_e != 1){
      switch(e){
        case 1:
          printf("\n\t\t\t\t\t(FAZENDEIRO)");
          printf("\n- Tem mais uma coisa estranha acontecendo na vila... Todas as noites sem falta um animal de alguma fazenda vem sumindo, meu melhor burro de carga desapareceu ontem...\n");           printf("\n\n>Você agradece a informação e decide ir buscar seus suprimentos, já está na hora de adentrar a Floresta da Noite<\n\n");
          esc_e=1;
          break;
        case 2:
          printf("\n\n>Você acena de volta por educação, mas não aguenta mais ficar sentindo o fedor de abóbora murcha e prefere ir atrás de seus suprimentos, já está na hora de adentrar a Floresta da Noite<\n\n");
          esc_e=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &e);
        break;
      }
    }
//FIM DA SELEÇÃO E
  }
    else if(d==2){
    printf("\n\n>Você não aguenta mais ficar sentindo o fedor de abóbora murcha e finalmente vai atrás de seus suprimentos, já está na hora de adentrar a Floresta da Noite<\n\n");
  }
  }
  else if(c==2){
    printf("\n\n>Você não aguenta mais ficar sentindo o fedor de abóbora murcha e finalmente vai atrás de seus suprimentos, já está na hora de adentrar a Floresta da Noite<\n\n");
  }
    
    return 0;
}