#include <stdio.h>

int main() {
  int a2, esc_a2;
  
  printf(">Seu corpo estava cansado das batalhas árduas, mas não era apenas isso que pesava em seus ombros. Havia energia pairando no ar como uma névoa grossa e cada passo adentrando a mata fazia a idéia de desistir soar cada vez mais plausível<");
  printf("\n-----\n"); 
  printf(">Mas finalmente, depois de seus esforços e de resistir por tanto tempo ao ar saturado de enxofre, emerge uma estrutura no meio da floresta. Parecia uma cabana de madeira escura e janelas pequenas, que talvez já tenha sido aconchegante, mas agora permanecia mofada e se misturava ao musgo e às vinhas, tornando-se parte da vegetação murcha<\n");
  
  printf("\n[1] (Bater na porta)\n[2] Pode sair daí!\n");
  printf("\n Resposta: ");
    scanf("%d", &a2);

  //SELEÇÃO A2
  do{
      switch(a2){
        case 1:
          printf(">\nVocê ouve uma risada de gelar a espinha e rapidamente recua<\n\n");
          printf("- Quem vem de tão longe em busca de Mariela? Mariela não lembra de convidar ninguém\n");
          printf("\n\t\t\t\t\t\t(MARIELA)\n");
          printf(">Vestida em cetim negro reasgado e sujo, o  vestido recai sobre um corpo pálido e desnutrido, se fundindo com os longos cabelos negros. Seus olhos são fundos como duas fossas, mas pareciam já ter sido de um belo tom violeta<");
          printf("[SISTEMA] Prepare-se para enfrentar Mariela");
          esc_a2=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t\t(BRUXA)\n");
  printf("\n- Pela forma como fala... Mais um aventureiro vem morrer em minhas mãos\n");
          printf(">Vestida em cetim negro reasgado e sujo, o  vestido recai sobre um corpo pálido e desnutrido, se fundindo com os longos cabelos negros. Seus olhos são fundos como duas fossas, mas pareciam já ter sido de um belo tom violeta<");
          printf("[SISTEMA] Prepare-se para enfrentar Mariela");
          esc_a2=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &a2);
        break;
      }
    }
    while(esc_a2 == 0);
  return 0;
}