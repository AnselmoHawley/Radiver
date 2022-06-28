 #include <stdio.h>

int main()
{
int a3, b3, c3;
int esc_a3=0, esc_b3=0, esc_c3=0;

  printf("\n>Logo após a batalha árdua, você aproveita alguns minutos para recuperar o fôlego e cuidar das feridas antes de juntar novamente suas coisas e voltar para a vila como um herói<\n----\n");
  printf(">Logo que sua pequena mochila fica pronta para partir novamente, um vulto não muito distante agita os ramos da floresta<\n");

  printf("\n[1] Cai pra dentro!(puxar a espada)\n[2] Quem está aí?\n");
  printf("\n Resposta: ");
    scanf("%d", &a3);

  printf("\n>Uma mulher alta desliza cuidadosamente pra fora da vegetação, seus olhos são verdes, e o cabelo cacheado e loiro repousa sobre os ombros. A pele morena está coberta por ramos entrelaçados num tecido vegetal e na mão direita há um cajado de madeira retorcida e rocoberta de musgo<\n");

    //SELEÇÃO A3
   while(esc_a3 == 0){
      switch(a3){
        case 1:
          printf("\n\t\t\t\t\t\t(???)\n");
  printf("- Ei! Guarde isso, você quase cortou um ramo do pobre teixo!");
          esc_a3=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t\t(???)\n");
  printf("\n- Não se preocupe, eu não represento perigo para você, aventureiro\n");
          esc_a3=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &a3);
        break;
      }
    }

  if(a3==1){
    printf("\n\n>Ela não parece muito feliz com sua ação<\n");
    printf("\n[1] Desculpe, hoje foi um dia difícil...\n[2] É só uma árvore, que diferença faz um galho ou dois?\n");
  printf("\n Resposta: ");
    scanf("%d", &b3);
    
    //SELEÇÃO B3
    while(esc_b3 == 0){
      switch(b3){
      case 1:
          printf("\n>O pedido de desculpas melhorou a expressão da mulher<\n");
          printf("\n\t\t\t\t\t\t(???)\n");
          printf("- Você não parece uma má pessoa no fim das contas... Eu sou Mesha, uma dríade guardiã que vive aqui há muito mais tempo que qualquer um. Venha comigo aventureiro, precisa saber de algo\n");
          printf("\n>Vocês caminham despreocupadamente, a floresta parece respeitar a presença da dríade e as criaturas ferozes se afastam<\n");
          printf("-----\n");
          printf(">Enfim, uma larga clareira coberta por um tapete de grama e vegetação silvestre se desdobra à sua frente. Diferente da sensação ruím ao se aproximar da área contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmões e o vento balança seu cabelo<\n");
        printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("- A bruxa que você derrotou se abrigou aqui de uma perseguição e protegia fielmente seu novo lar. Até que pouco antes do fim do verão algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais não pareciam mais consigo mesmos\n");

    printf("\n[1] Você viu quem era?\n[2] Quem você acha que foi?\n");
  printf("\n Resposta: ");
    scanf("%d", &c3);

        //1° SELEÇÃO C3
    while(esc_c3 == 0){
      switch(c3){
        case 1:
          printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("- Não, e sua presença poderia facilmente se passar por uma ilusão... Se a figura não houvesse derrubado algo, tome.\n\n");
          printf(">Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");
          printf("\n\t\t\t[SISTEMA] Você obteve: Chave misteriosa (1/2)\n");
          printf("\n\t\t\t\t\t\t(MESHA)\n");
          printf("Isso é tudo que posso fazer, mas no lago há um velho amigo que pode te ajudar, procure pelo Sábio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
          esc_c3=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("\n- Meu julgamento pode ser tendencioso, é melhor que descubra por si só, e sua presença poderia facilmente se passar por uma ilusão... Se a figura não houvesse derrubado algo, tome.\n");
          printf(">Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");
          printf("\n\t\t\t[SISTEMA] Você obteve: Chave misteriosa (1/2)\n");
          printf("\n\t\t\t\t\t\t(MESHA)\n");
          printf("Isso é tudo que posso fazer, mas no lago há um velho amigo que pode te ajudar, procure pelo Sábio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
          esc_c3=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &c3);
        break;
      }
    }
          esc_b3=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t\t(???)\n");
  printf("- Só uma árvore? Parece que você não é muito diferente dos outros humanos... Infelizmente não tenho escolha, precisarei contar com a ajuda disponível\n");
          printf("\n>Ela sopra uma espécie de poeira amarelada na sua direção e em poucos segundos sua consciência vai embora<\n");
          printf("-----\n");
          printf("\n>Quando acorda, você se encontra numa larga clareira coberta por um tapete de grama e vegetação silvestre. Diferente da sensação ruim ao se aproximar da área contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmões e o vento balança seu cabelo<\n");
          printf("\n\t\t\t\t\t\t(???)\n");
          printf("- A bruxa que você derrotou se abrigou aqui de uma perseguição e protegia fielmente seu novo lar. Até que pouco antes do fim do verão algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais não pareciam mais consigo mesmos\n");
          printf("\n\t\t\t\t\t\t(VOCÊ)\n");
          printf("\t\t\t\t\t\t ....\n\n");
          printf("\n\t\t\t\t\t\t(???)\n");
          printf("- Não precisa acreditar em mim se quiser, mas ele deixou algo para trás, tome.\n\n");
          printf(">Ela lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n");
          printf("\n\t\t\t[SISTEMA] Você obteve: Chave misteriosa (1/2)\n");
          printf("\n\t\t\t\t\t\t(MESHA)\n");
          printf("No lago há um velho amigo que pode saber mais do que eu, ele atende pelo nome de Sábio do Lago e se quiser descobrir mais da verdade, eis o caminho.");
          esc_b3=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &b3);
        break;
      }
    }
  }
  else if(a3==2){
    printf("\nEu sou Mesha, uma dríade guardiã que vive aqui há muito mais tempo que qualquer um. Venha comigo aventureiro, precisa saber de algo.\n");
    printf("\n>Vocês caminham despreocupadamente, a floresta parece respeitar a presença da dríade e as criaturas ferozes se afastam<\n");
  printf("-----\n");
  printf(">Enfim, uma larga clareira coberta por um tapete de grama e vegetação silvestre se desdobra à sua frente. Diferente da sensação ruím ao se aproximar da área contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmões e o vento balança seu cabelo<\n");
  printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("- A bruxa que você derrotou se abrigou aqui de uma perseguição e protegia fielmente seu novo lar. Até que pouco antes do fim do verão algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais não pareciam mais consigo mesmos\n");

    printf("\n[1] Você viu quem era?\n[2] Quem você acha que foi?\n");
  printf("\n Resposta: ");
    scanf("%d", &c3);

        //2° SELEÇÃO C3
    while(esc_c3 == 0){
      switch(c3){
        case 1:
          printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("- Não, e sua presença poderia facilmente se passar por uma ilusão... Se a figura não houvesse derrubado algo, tome.\n\n");
          printf("\n>Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");
          printf("\n\t\t\t[SISTEMA] Você obteve: Chave misteriosa (1/2)\n\n");
          printf("\n\t\t\t\t\t\t(MESHA)\n");
          printf("Isso é tudo que posso fazer, mas no lago há um velho amigo que pode te ajudar, procure pelo Sábio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
          esc_c3=1;
          break;
        case 2:
          printf("\n\t\t\t\t\t\t(MESHA)\n");
  printf("\n- Meu julgamento pode ser tendencioso, é melhor que descubra por si só, e sua presença poderia facilmente se passar por uma ilusão... Se a figura não houvesse derrubado algo, tome.\n");
          printf("\n>Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");
          printf("\n\t\t\t[SISTEMA] Você obteve: Chave misteriosa (1/2)\n\n");
          printf("\n\t\t\t\t\t\t(MESHA)\n");
          printf("Isso é tudo que posso fazer, mas no lago há um velho amigo que pode te ajudar, procure pelo Sábio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
          esc_c3=1;
        break;
        default:
          printf("\n[SISTEMA]: Ei, essa não é uma das opções! nos dê uma resposta válida...\n");
        printf("\n Resposta: ");
        scanf("%d", &c3);
        break;
      }
    }
  }
  printf("\n\n[SISTEMA] Parabéns! Você concluiu a DEMO de 'Chaves de cristal'");
  return 0;
}