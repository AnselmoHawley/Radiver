
      #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define LIMPAR_TELA printf("\e[1;1H\e[2J")

// Combate

    // Organizacao dos dados do jogador e dos inimigos em structs:

        struct Jogador
        {
            struct Classe
            {
                struct Guerreiro
                {
                    char nome[20];
                    int vida, mana, atq_fraco, atq_forte;
                }
                guerreiro;
                
                struct Mago
                {
                    char nome[20];
                    int vida, mana, atq_fraco, atq_forte;
                }
                mago;
            }
            classe;
            
            struct Item
            {
                int pocaoDeVida;
            }
            item;
        }
        jogador;
        
        struct Inimigo
        {
            struct Slime
            {
                char nome[30], nome_atq_um[30], nome_atq_dois[30];
                int vida, nivel, dano_atq_um, dano_atq_dois;
            }
            slime;
        
            struct Hobgoblin
            {
                char nome[30], nome_atq_um[30], nome_atq_dois[30];
                int vida, nivel, dano_atq_um, dano_atq_dois;
            }
            hobgoblin;
            
            struct Lobo
            {
                char nome[30], nome_atq_um[30], nome_atq_dois[30];
                int vida, nivel, dano_atq_um, dano_atq_dois;
            }
            lobo;
            
            struct EspiritoDoVento
            {
                char nome[30], nome_atq_um[30], nome_atq_dois[30];
                int vida, nivel, dano_atq_um, dano_atq_dois;
            }
            espirito;
        }
        inimigo;

    // Funcao para inicializar os membros da structs:

        void InicializarClasses()
        {
            // Nome
                // - Guerreiro
                    strcpy(jogador.classe.guerreiro.nome, "Guerreiro");
                
                // - Mago
                    strcpy(jogador.classe.mago.nome, "Mago");
                    
            // Vida
                // - Guerreiro
                    jogador.classe.guerreiro.vida = 90;
                
                // - Mago
                    jogador.classe.mago.vida = 70;
        
            // Mana
                // - Guerreiro
                    jogador.classe.guerreiro.mana = 20;
                    
                // - Mago
                    jogador.classe.mago.mana = 30;
        
            // Dano do ataque fraco
                // - Guerreiro
                    jogador.classe.guerreiro.atq_fraco = 15;
                    
                // - Mago
                    jogador.classe.mago.atq_fraco = 10;
        
            // Dano do ataque forte
                // - Guerreiro
                    jogador.classe.guerreiro.atq_forte = 30;
                    
                // - Mago
                    jogador.classe.mago.atq_forte = 35;
        }
        
        void InicializarInimigos()
        {
            // Nome
                // - Slime
                    strcpy(inimigo.slime.nome, "Slime da Caverna");
                
                // - Hobgoblin
                    strcpy(inimigo.hobgoblin.nome, "Hobgoblin");
                
                // - Lobo
                    strcpy(inimigo.lobo.nome, "Lobo Soturno");
                
                // - Espirito
                    strcpy(inimigo.espirito.nome, "Espirito do Vento");
        
            // Nomes dos ataques
                // - Slime
                    strcpy(inimigo.slime.nome_atq_um, "Investida");
                    strcpy(inimigo.slime.nome_atq_dois, "Engolir");
                
                // - Hobgoblin
                    strcpy(inimigo.hobgoblin.nome_atq_um, "Cortar");
                    strcpy(inimigo.hobgoblin.nome_atq_dois, "Furia");
                
                // - Lobo
                    strcpy(inimigo.lobo.nome_atq_um, "Mordida");
                    strcpy(inimigo.lobo.nome_atq_dois, "Lacerar");
                
                // - Espirito
                    strcpy(inimigo.espirito.nome_atq_um, "Rajada");
                    strcpy(inimigo.espirito.nome_atq_dois, "Redemoinho");
            
            // Nivel
                // - Slime
                    inimigo.slime.nivel = 1 + (rand() % 3);
                
                // - Hobgoblin
                    inimigo.hobgoblin.nivel = 3 + (rand() % 4);
                
                // - Lobo
                    inimigo.lobo.nivel = 6 + (rand() % 4);
                
                // - Espirito
                    inimigo.espirito.nivel = 9 + (rand() % 4);
            
            // Vida
                // - Slime
                    inimigo.slime.vida = inimigo.slime.nivel * 10;
                
                // - Hobgoblin
                    inimigo.hobgoblin.vida = inimigo.hobgoblin.nivel * 10;
                
                // - Lobo
                    inimigo.lobo.vida = inimigo.lobo.nivel * 10;
                
                // - Espirito
                    inimigo.espirito.vida = inimigo.espirito.nivel * 10;
            
            // Dano dos ataques
                // - Slime
                    inimigo.slime.dano_atq_um = inimigo.slime.nivel * 2;
                    inimigo.slime.dano_atq_dois = inimigo.slime.nivel * 3;
                
                // - Hobgoblin
                    inimigo.hobgoblin.dano_atq_um = inimigo.hobgoblin.nivel * 2;
                    inimigo.hobgoblin.dano_atq_dois = inimigo.hobgoblin.nivel * 3;
                
                // - Lobo
                    inimigo.lobo.dano_atq_um = inimigo.lobo.nivel * 2;
                    inimigo.lobo.dano_atq_dois = inimigo.lobo.nivel * 3;
                
                // - Espirito
                    inimigo.espirito.dano_atq_um = inimigo.espirito.nivel * 3;
                    inimigo.espirito.dano_atq_dois = inimigo.espirito.nivel * 4;
        }
        
        void InicializarItens()
        {
            // Pocao de vida
            
            jogador.item.pocaoDeVida = 0;
        }
        
    // Funcoes que exibem as telas de vitoria e derrota:
        
        void VitoriaDoInimigo()
        {
            printf("|> Vida restante do jogador: 0\n");
            
            sleep(3);
            
            LIMPAR_TELA;
            
            printf("*-----------------------------*\n");
            printf("|         Voce morreu!        |\n");
            printf("*-----------------------------*\n\n");
            
            sleep(5);
            
            LIMPAR_TELA;
        }
        
        void VitoriaDoJogador()
        {
            printf("|> Vida restante do inimigo: 0\n");
            
            sleep(3);
            
            LIMPAR_TELA;
            
            printf("*-----------------------------*\n");
            printf("|         Voce venceu!        |\n");
            printf("*-----------------------------*\n\n");
            
            sleep(5);
            
            LIMPAR_TELA;
        }

    // Funcao que exibe a fala de um inimigo de forma aleatoria:
        
        void ExibirFala(char inimigo_escolhido[])
        {
            int dado_inimigo = rand() % 5;
            
            // Falas do slime
                
                if (strcmp(inimigo_escolhido, "slime") == 0)
                {
                    if (dado_inimigo == 0)
                    {
                        printf("\"Voce nunca ira me derrotar.\"\n\n");
                    }
                    
                    else if (dado_inimigo == 1)
                    {
                        printf("\"Voce eh fraco, lhe falta odio.\"\n\n");
                    }
                    
                    else if (dado_inimigo == 2)
                    {
                        printf("\"Voce esta perdido? Vou te mostrar o caminho da destruicao!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 3)
                    {
                        printf("\"Esta com medo? NAO?! Irei te destruir!\"\n\n");
                    }
                    
                    else
                    {
                        printf("\"...\"\n\n");
                    }
                }
            
            // Falas do goblin
                
                if (strcmp(inimigo_escolhido, "goblin") == 0)
                {
                    if (dado_inimigo == 0)
                    {
                        printf("\"Seu otario >:(\"\n\n");
                    }
                    
                    else if (dado_inimigo == 1)
                    {
                        printf("\"Ha ha ha, voce nao tem chance contra mim!!!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 2)
                    {
                        printf("\"Vou te destruir!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 3)
                    {
                        printf("\"Um humano por aqui?! Vou acabar com sua raca!\"\n\n");
                    }
                    
                    else
                    {
                        printf("\"...\"\n\n");
                    }
                }
            
            // Falas do lobo
                
                if (strcmp(inimigo_escolhido, "lobo") == 0)
                {
                    if (dado_inimigo == 0)
                    {
                        printf("\"Sinto cheiro de covarde >:(\"\n\n");
                    }
                    
                    else if (dado_inimigo == 1)
                    {
                        printf("\"Voce eh uma presa facil para um cacador como eu!!!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 2)
                    {
                        printf("\"Vou lhe trucidar em pedacinhos!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 3)
                    {
                        printf("\"Humanos? Sao mais deliciosos quando estao com medo!\"\n\n");
                    }
                    
                    else
                    {
                        printf("\"...\"\n\n");
                    }
                }
            
            // Falas do espirito
            
                if (strcmp(inimigo_escolhido, "espirito") == 0)
                {
                    if (dado_inimigo == 0)
                    {
                        printf("\"Voce nao passara!!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 1)
                    {
                        printf("\"Vou te mandar para outra dimensao! Outra Dimensao!!!\"\n\n");
                    }
                    
                    else if (dado_inimigo == 2)
                    {
                        printf("\"Sacie minha vontade.\"\n\n");
                    }
                    
                    else if (dado_inimigo == 3)
                    {
                        printf("\"Voce nao pode escapar das minhas laminas, elas cortam ate diamantes.\"\n\n");
                    }
                    
                    else
                    {
                        printf("\"...\"\n\n");
                    }
                }
        }
        
    // Funcao da batalha:

        int Batalha(char classe_escolhida[], char inimigo_escolhido[])
        {
            srand((unsigned)time(NULL));
            
            // *----------------------*
            // | Variaveis do jogador |
            // *----------------------*
                
                char *classe_jogador;
                int vida_jogador, mana_jogador;
                int dano_atq_fraco, dano_atq_forte;
                
                InicializarClasses();
                
                // (1) Se a classe escolhida pelo jogador for Guerreiro:
                
                if (strcmp(classe_escolhida, "guerreiro") == 0)
                {
                    classe_jogador = jogador.classe.guerreiro.nome;
                    
                    vida_jogador = jogador.classe.guerreiro.vida;
                    mana_jogador = jogador.classe.guerreiro.mana;
                    
                    dano_atq_fraco = jogador.classe.guerreiro.atq_fraco;
                    dano_atq_forte = jogador.classe.guerreiro.atq_forte;
                }
                
                // (2) Senao, se a classe escolhida pelo jogador for Mago:
                
                else if (strcmp(classe_escolhida, "mago") == 0)
                {
                    classe_jogador = jogador.classe.mago.nome;
                    
                    vida_jogador = jogador.classe.mago.vida;
                    mana_jogador = jogador.classe.mago.mana;
                    
                    dano_atq_fraco = jogador.classe.mago.atq_fraco;
                    dano_atq_forte = jogador.classe.mago.atq_forte;
                }
            
            // *----------------------*
            // | Variaveis do inimigo |
            // *----------------------*
                
                char *nome_inimigo, *nome_atq_um, *nome_atq_dois;
                int nivel_inimigo, vida_inimigo;
                int dano_atq_um, dano_atq_dois;
                
                InicializarInimigos();
                
                // (1) Se a batalha for contra um slime:
                
                if (strcmp(inimigo_escolhido, "slime") == 0)
                {
                    nome_inimigo = inimigo.slime.nome;
                    
                    nivel_inimigo = inimigo.slime.nivel;
                    vida_inimigo = inimigo.slime.vida;
                    
                    nome_atq_um = inimigo.slime.nome_atq_um;
                    nome_atq_dois = inimigo.slime.nome_atq_dois;
                    
                    dano_atq_um = inimigo.slime.dano_atq_um;
                    dano_atq_dois = inimigo.slime.dano_atq_dois;
                }
                
                // (2) Senao, se a batalha for contra um goblin:
                
                else if (strcmp(inimigo_escolhido, "goblin") == 0)
                {
                    nome_inimigo = inimigo.hobgoblin.nome;
                    
                    nivel_inimigo = inimigo.hobgoblin.nivel;
                    vida_inimigo = inimigo.hobgoblin.vida;
                    
                    nome_atq_um = inimigo.hobgoblin.nome_atq_um;
                    nome_atq_dois = inimigo.hobgoblin.nome_atq_dois;
                    
                    dano_atq_um = inimigo.hobgoblin.dano_atq_um;
                    dano_atq_dois = inimigo.hobgoblin.dano_atq_dois;
                }
                
                // (3) Senao, se batalha for contra um lobo:
                
                else if (strcmp(inimigo_escolhido, "lobo") == 0)
                {
                    nome_inimigo = inimigo.lobo.nome;
                    
                    nivel_inimigo = inimigo.lobo.nivel;
                    vida_inimigo = inimigo.lobo.vida;
                    
                    nome_atq_um = inimigo.lobo.nome_atq_um;
                    nome_atq_dois = inimigo.lobo.nome_atq_dois;
                    
                    dano_atq_um = inimigo.lobo.dano_atq_um;
                    dano_atq_dois = inimigo.lobo.dano_atq_dois;
                }
                
                // (4) Senao, se batalha for contra um espirito:
                
                else if (strcmp(inimigo_escolhido, "espirito") == 0)
                {
                    nome_inimigo = inimigo.espirito.nome;
                    
                    nivel_inimigo = inimigo.espirito.nivel;
                    vida_inimigo = inimigo.espirito.vida;
                    
                    nome_atq_um = inimigo.espirito.nome_atq_um;
                    nome_atq_dois = inimigo.espirito.nome_atq_dois;
                    
                    dano_atq_um = inimigo.espirito.dano_atq_um;
                    dano_atq_dois = inimigo.espirito.dano_atq_dois;
                }
            
            // *-----------------------------------------------*
            // ||||||||||||||| INICIO DO COMBATE |||||||||||||||
            // *-----------------------------------------------*
                
                // Variavel da escolha do jogador:
                    
                    int escolha;
                
                // Variaveis dos dados:
                    
                    int dado_jogador, dado_inimigo;
                
                // Mensagem inicial:
                    
                    printf("Um %s de nivel %d apareceu!\n", nome_inimigo, nivel_inimigo);
                    
                    sleep(3);
                
                // Loop da batalha:
                    
                    while (1)
                    {
                        // Loop do menu de escolhas:
                            
                            do
                            {
                                // *-----------------*
                                // | Tela da batalha |
                                // *-----------------*
                                    
                                    LIMPAR_TELA;
                                    
                                    // Status do jogador:
                                        
                                        printf("< Voce >\n");
                                        printf("Vida: %d | Mana: %d\n\n", vida_jogador, mana_jogador);
                                    
                                    // Status do monstro:
                                        
                                        printf("< %s >\n", nome_inimigo);
                                        printf("Vida: %d | Nivel: %d\n\n", vida_inimigo, nivel_inimigo);
                                    
                                    // Opcoes:
                                        
                                        printf("*------------------------*\n");
                                        printf("|    [1] ataque fraco    |\n");
                                        printf("|    [2] ataque forte    |\n");     
                                        printf("*------------------------*\n");
                                        printf("|  [3] pocao de vida | %d |\n", jogador.item.pocaoDeVida);     
                                        printf("*------------------------*\n\n");
                                    
                                    // Escolha do jogador:
                                        
                                        printf("> ");
                                        scanf("%d", &escolha);

                                // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                
                                // *---------------------*
                                // | Tratamento de erros |
                                // *---------------------*
                                    
                                    // (1) Se o jogador digitar algum valor que esteja fora das opcoes:
                                        
                                        if (escolha < 1 || escolha > 3)
                                        {
                                            printf("> Opcao invalida! Tente novamente\n");
                                            
                                            sleep(1);
                                        }
                                    
                                    // (2) Senao, se o jogador escolher o ataque forte:
                                        
                                        else if (escolha == 2)
                                        {
                                            // Se o jogador nao possuir mana:
                                                
                                                if (mana_jogador <= 0)
                                                {
                                                    printf("> Mana insuficiente para realizar ataque!\n");
                                                    
                                                    sleep(1);
                                                    
                                                    escolha = -1;
                                                }
                                        }
                                    
                                    // (3) Senao, se o jogador escolher a pocao de vida:
                                        
                                        else if (escolha == 3)
                                        {
                                            // Se o jogador nao possuir pocao:
                                                
                                                if (jogador.item.pocaoDeVida <= 0)
                                                {
                                                    printf("> Voce nao tem pocoes para usar!\n");
                                                    
                                                    sleep(1);
                                                    
                                                    escolha = -1;
                                            }
                                        }
                            }
                            while (escolha < 1 || escolha > 3);
                        
                        // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                        
                        LIMPAR_TELA;
                        
                        // |-*-------------------------*-|
                        // |*|   Escolhas do jogador   |*|
                        // |-*-------------------------*-|
                            
                            // (1) Se o jogador escolher o ataque fraco:
                                
                                if (escolha == 1)
                                {
                                    // Sera gerado um valor aleatorio para o dado.
                                        
                                        dado_jogador = rand() % 7;
                                    
                                    // (1) Se o valor do dado for 0, o jogador erra o ataque.
                                        
                                        if (dado_jogador == 0)
                                        {
                                            printf("Voce errou o ataque!\n");
                                            
                                            sleep(2);
                                        }
                                    
                                    // (2) Senao, o ataque e efetuado.
                                        
                                        else
                                        {
                                            printf("Voce usou o ataque fraco!\n\n");
                                            
                                            sleep(1);
                                            
                                            // Sera gerado um valor aleatorio para o dado.
                                                
                                                dado_jogador = rand() % 5;
                                            
                                            // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                                
                                                if (dado_jogador == 0)
                                                {
                                                    printf("|> Dano causado: %d (critico)\n", dano_atq_fraco + 10);
                                                    
                                                    sleep(1);
                                                    
                                                    vida_inimigo -= dano_atq_fraco + 10;
                                                }
                                                
                                            // (2) Senao, o dano do ataque sera normal.
                                                
                                                else
                                                {
                                                    printf("|> Dano causado: %d\n", dano_atq_fraco);
                                                    
                                                    sleep(1);
                                                    
                                                    vida_inimigo -= dano_atq_fraco;
                                                }
                                            
                                            // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                            
                                            // (1) Se o ataque matar o inimigo:
                                                
                                                // *--------------------------------------------*
                                                // ||||||||||||||| FIM DO COMBATE |||||||||||||||
                                                // *--------------------------------------------*
                                                    
                                                    if (vida_inimigo <= 0)
                                                    {
                                                        VitoriaDoJogador();
                                                        
                                                        return 1;
                                                    }
                                                
                                            // (2) Caso o ataque nao mate o inimigo:
                                            
                                                else
                                                {
                                                    printf("|> Vida restante do inimigo: %d\n", vida_inimigo);
                                                    
                                                    sleep(2);
                                                }
                                        }
                                }
                            
                            // (2) Se for escolhido o ataque forte.
                                
                                else if (escolha == 2)
                                {
                                    // Sera gerado um valor aleatorio para o dado.
                                        
                                        dado_jogador = rand() % 2;
                                    
                                    // Se o valor do dado for 0, o jogador erra o ataque.
                                        
                                        if (dado_jogador == 0)
                                        {
                                            printf("Voce errou o ataque!\n\n");
                                            
                                            printf("|> Mana: -5\n");
                                            
                                            mana_jogador -= 5;
                                            
                                            sleep(2);
                                        }
                                    
                                    // Caso for qualquer outro valor, o ataque eh efetuado.
                                        
                                        else
                                        {
                                            printf("Voce usou o ataque forte!\n\n");
                                            
                                            sleep(1);
                                            
                                            // Sera gerado um valor aleatorio para o dado.
                                                
                                                dado_jogador = rand() % 7;
                                            
                                            // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                                
                                                if (dado_jogador == 0)
                                                {
                                                    printf("|> Dano causado: %d (critico)\n", dano_atq_forte + 10);
                                                    
                                                    sleep(1);
                                                    
                                                    vida_inimigo -= dano_atq_forte + 10;
                                                }
                                                
                                            // (2) Se for qualquer outro valor, o dano do ataque sera normal.
                                                
                                                else
                                                {
                                                    printf("|> Dano causado: %d\n", dano_atq_forte);
                                                    
                                                    sleep(1);
                                                    
                                                    vida_inimigo -= dano_atq_forte;
                                                }
                                            
                                            // Custo de usar o ataque forte:
                                                
                                                printf("|> Mana: -5\n");
                                                
                                                mana_jogador -= 5;
                                                
                                                sleep(1);
                                            
                                            // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                            
                                            // (1) Se o ataque matar o inimigo:
                                                
                                                // *--------------------------------------------*
                                                // ||||||||||||||| FIM DO COMBATE |||||||||||||||
                                                // *--------------------------------------------*
                                                    
                                                    if (vida_inimigo <= 0)
                                                    {
                                                        VitoriaDoJogador();
                                                        
                                                        return 1;
                                                    }
                                                
                                            // (2) Caso o ataque nao mate o inimigo:
                                            
                                                else
                                                {
                                                    printf("|> Vida restante do inimigo: %d\n", vida_inimigo);
                                                    
                                                    sleep(2);
                                                }
                                        }
                                }
                            
                            // (3) Se for escolhido a pocao de vida:
                                
                                else if (escolha == 3)
                                {
                                    printf("Voce usou uma pocao de vida!\n\n");
                                    
                                    sleep(1);
                                    
                                    // Sera gerado um valor aleatorio para o dado.
                                        
                                        dado_jogador = rand() % 2;
                                    
                                    // (1) Se o valor do dado for 0, o jogador recupera 10 de vida.
                                        
                                        if (dado_jogador == 0)
                                        {
                                            printf("|> Vida: +10\n");
                                            
                                            vida_jogador += 10;
                                        }
                                    
                                    // (2) Senao, se o valor do dado for 1, o jogador recupera 20 de vida.
                                        
                                        else if (dado_jogador == 1)
                                        {
                                            printf("|> Vida: +20\n");
                                            
                                            vida_jogador += 20;
                                        }
                                    
                                    // (3) Senao, se o valor do dado for 2, o jogador recupera 30 de vida.
                                        
                                        else if (dado_jogador == 2)
                                        {
                                            printf("|> Vida: +30\n");
                                            
                                            vida_jogador += 30;
                                        }
                                    
                                    jogador.item.pocaoDeVida--;
                                    
                                    sleep(2);
                                }
                        
                        printf("\n|||||||||||||||||||||||||||||||||||||||\n\n");
                        
                        // |-*------------------------*-|
                        // |*|   Ataques do inimigo   |*|
                        // |-*------------------------*-|
                            
                            // Sera gerado um valor aleatorio para o dado.
                                
                                dado_inimigo = rand() % 2;
                            
                            // (1) Se o valor do dado for 0, o inimigo erra o ataque.
                                
                                if (dado_inimigo == 0)
                                {
                                    printf("%s errou o ataque!\n", nome_inimigo);
                                    
                                    sleep(2);
                                }
                                
                            // (2) Senao, se o valor do dado for 1, o ataque eh efetuado.
                                
                                else if (dado_inimigo == 1)
                                {
                                    // Fala do inimigo:
                                        
                                        ExibirFala(inimigo_escolhido);
                                    
                                    // Nome e ataque do inimigo:
                                        
                                        printf("%s usou %s!\n\n", nome_inimigo, nome_atq_um);
                                        
                                        sleep(1);
                                    
                                    // Sera gerado um valor aleatorio para o dado.
                                        
                                        dado_inimigo = rand() % 5;
                                    
                                    // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                        
                                        if (dado_inimigo == 0)
                                        {
                                            printf("|> Dano causado: %d (critico)\n", dano_atq_um + 10);
                                        
                                            sleep(1);
                                            
                                            vida_jogador -= dano_atq_um + 10;
                                        }
                                        
                                    // (2) Senao, se for qualquer outro valor, o dano do ataque sera normal.
                                        
                                        else
                                        {
                                            printf("|> Dano causado: %d\n", dano_atq_um);
                                            
                                            sleep(1);
                                            
                                            vida_jogador -= dano_atq_um;
                                        }
                                    
                                    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                    
                                    // (1) Se o ataque matar o jogador:
                                        
                                        // *--------------------------------------------*
                                        // ||||||||||||||| FIM DO COMBATE |||||||||||||||
                                        // *--------------------------------------------*
                                            
                                            if (vida_jogador <= 0)
                                            {
                                                VitoriaDoInimigo();
                                                
                                                return 0;
                                            }
                                        
                                    // (2) Caso o ataque nao mate o jogador:
                                        
                                        else
                                        {
                                            printf("|> Vida restante do jogador: %d\n", vida_jogador);
                                            
                                            sleep(4);
                                        }
                                }
                                
                            // (3) Senao, se o valor do dado for 2, o monstro efetua o ataque 2.
                                
                                else if (dado_inimigo == 2)
                                {
                                    // Caso o inimigo tenha alguma fala.
                                        
                                        ExibirFala(inimigo_escolhido);
                                    
                                    // Nome e ataque do inimigo
                                        
                                        printf("%s usou %s!\n\n", nome_inimigo, nome_atq_dois);
                                        
                                        sleep(1);
                                    
                                    // Sera gerado um valor aleatorio para o dado.
                                        
                                        dado_inimigo = rand() % 5;
                                    
                                    // Caso o valor do dado seja 0, o dano do ataque aumenta em 10.
                                        
                                        if (dado_inimigo == 0)
                                        {
                                            printf("|> Dano causado: %d (critico)\n", dano_atq_dois + 10);
                                        
                                            sleep(1);
                                            
                                            vida_jogador -= dano_atq_dois + 10;
                                        }
                                        
                                    // Caso nao seja 0, o dano do ataque sera normal.
                                        
                                        else
                                        {
                                            printf("|> Dano causado: %d\n", dano_atq_dois);
                                            
                                            sleep(1);
                                            
                                            vida_jogador -= dano_atq_dois;
                                        }
                                    
                                    // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                                    
                                    // (1) Se o ataque matar o jogador:
                                        
                                        // *--------------------------------------------*
                                        // ||||||||||||||| FIM DO COMBATE |||||||||||||||
                                        // *--------------------------------------------*
                                            
                                            if (vida_jogador <= 0)
                                            {
                                                VitoriaDoInimigo();
                                                
                                                return 0;
                                            }
                                        
                                    // (2) Caso o ataque nao mate o jogador:
                                        
                                        else
                                        {
                                            printf("|> Vida restante do jogador: %d\n", vida_jogador);
                                            
                                            sleep(4);
                                        }
                                }
                    }
        }

// Historia

    void Parte_1()
    {
        char nome[26];
        int esc_a = 0, esc_b = 0, esc_c = 0, esc_d = 0, esc_e = 0;
        int a, b, c, d, e;

        printf("\n\t\t\t\t\t\t(VOCE)");
        printf("\n\t\t...Finalmente, a vila de radiver.\n");

        // Descricao
        printf("\n>O lodo nas pedras do caminho sinuoso de pavimento irregular deduravam sua idade, mas mostravam que ali havia cuidado. As casas nao eram muito altas ou elaboradas, apenas o suficiente para proteger os moradores da pequena vila de Radiver da chuva ou da neve, parecia um bom lugar para uma vida simples<\n----\n>O motivo de sua visita, no entanto, nao era tao simples<\n");

        printf("\n\t\t\t\t\t(LIDER DA VILA)");
        printf("\n- Macacos me mordam! voce deve ser o aventureiro enviado para salvar nossa vila. Por favor, meu caro(a), como se chama?\n");

        // Descricao
        printf("\n>Cabelos curtos, barba grande e grisalha, aneis e colares dourados nas maos e pescoco. O chefe da vila, vestindo um casaco feito de pele de animal, parecia contradizer a simplicidade da vila com seu ar de politico<\n");

        // Inicio da selecao A

        printf("\n[1] (Informar seu nome ao lider da vila)\n[2] Pode me chamar do que quiser\n");
    
        printf("\n Resposta: ");

        scanf("%d", &a);
    
        while (esc_a == 0)
        {
            switch (a)
            {
                case 1:
                    printf("Seu nome eh: ");
                    scanf("%s", nome);

                    esc_a = 1;

                    break;

                case 2:
                    printf("\n\t\t\t\t\t(LIDER DA VILA)");
                    printf("\n- Entao vou chama-lo de... Andre!\n");

                    esc_a = 1;

                    break;

                default:
                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! nos de uma resposta valida...\n");
                    printf("\n Resposta: ");
                    scanf("%d", &a);

                    break;
            } 
        }

        // Fim da selecao A

        printf("\n\n>O chefe da vila estende um aperto de maos para voce<\n\n");
        printf("\n\t\t\t\t\t(LIDER DA VILA)");
    
        // Inicio da string nome

        if (a == 1)
        {
            puts(nome);

            printf("\n- %s...Combina muito com o nome de um heroi! Mas agora venha, nao temos tempo a perder, deixe-me te mostrar algo\n", nome);
        }

        else if (a == 2)
        {
            printf("\n- Andre... Combina muito com o nome de um heroi! Mas agora venha, nao temos tempo a perder, deixe-me te mostrar algo...\n");
        }

        // Fim do uso da string nome
    
        printf("\n\n>O lider da vila guia voce para a parte mais exterior de Radiver, onde localizam-se as plantacoes<\n\n");

        printf("A plantacao parecia farta e bem organizada, as culturas estavam bem dispostas em terras bem aradas, entao o sustento dos camponeses parecia promissor se nao fossem pelos vegetais murchos, cinzentos e cheios de moscas");

        printf("\n\t\t\t\t\t(LIDER DA VILA)");
        printf("\n- Desde de antes da vila de Radiver ser fundadada, a floresta da noite sempre foi a casa da bruxa do musgo. Nossos fundadores conseguiram fazer um acordo, o qual dizia que se nosso povo nao adentrasse demais em seu territorio profano, seriamos deixados em paz\n");

        printf("\n\n>Ele parece pensativo<\n\n");

        printf("\n\t\t\t\t\t(LIDER DA VILA)");
        printf("- Depois de tantas decadas ela quebrou o acordo! Da noite pro dia, lancou-nos uma maldicao e nossas plantacoes adoeceram e murcharam... Mal ha como sustentar-se neste outono!\n\n");

        printf("\n[1] Quando a maldicao comecou? \n[2] (Ficar calado)\n");
        printf("\n Resposta: ");
        scanf("%d", &b);

        // Inicio da selecao B

        while (esc_b != 1)
        {
            switch (b)
            {
                case 1:
                    printf("\n\t\t\t\t\t(LIDER DA VILA)");
                    printf("\n- No fim do verao\n");

                    esc_b = 1;

                    break;

                case 2:
                    printf("\n\t\t\t\t\t(LIDER DA VILA)");
                    printf("\n- Voce esta meio caladao em... Se serve de algo, a maldicao comecou no fim do verao.\n");

                    esc_b = 1;

                    break;

                default:
                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                    printf("\n Resposta: ");
                    scanf("%d", &b);

                    break;
            }
        }

        // Fim da selecao B

        printf("\n[1] Mais alguma coisa estranha tem acontecido na vila?\n[2] Vou resolver seu problema (despedir-se do chefe da vila)\n");
        printf("\n Resposta: ");
        scanf("%d", &c);
    
        // Selecao C

        while (esc_c != 1)
        {
            switch (c)
            {
                case 1:
                    printf("\n\t\t\t\t\t(LIDER DA VILA)");
                    printf("\n- Apenas a maldicao da bruxa.\n");

                    esc_c = 1;

                    break;

                case 2:
                    printf("\n\t\t\t\t\t(LIDER DA VILA)");
                    printf("\n- Boa sorte aventureiro, nao esqueca de pegar seus suprimentos.\n");

                    esc_c = 1;

                    break;

                default:
                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                    printf("\n Resposta: ");
                    scanf("%d", &c);

                    break;
            }
        }
        
        // Fim da selecao C

        if (c != 2)
        {
            printf("\n[1] Ha mais alguem com quem eu possa falar?\n[2] Vou resolver seu problema (despedir-se do chefe da vila)\n");
            printf("\n Resposta: ");
            scanf("%d", &d);

            // Selecao D

            while (esc_d != 1)
            {
                switch (d)
                {
                    case 1:
                        printf("\n\t\t\t\t\t(LIDER DA VILA)");
                        printf("\n- Niguem que possa te informar tao bem quanto eu! Boa sorte aventureiro, nao esqueca de pegar seus suprimentos.\n");
                        
                        esc_d = 1;

                        break;

                    case 2:
                        printf("\n\t\t\t\t\t(LIDER DA VILA)");
                        printf("\n- Boa sorte aventureiro, nao esqueca de pegar seus suprimentos.\n");
                        
                        esc_d = 1;

                        break;

                    default:
                        printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                        printf("\n Resposta: ");
                        scanf("%d", &d);

                        break;
                }
            }

            // Fim da selecao D

            if (d == 1)
            {
                printf("\n\n>O aventureiro volta a vila para pegar seus itens, mas ainda nas plantacoes ve um fazendeiro lhe acenando<\n\n");
                printf("\n>O fazendeiro repousa um chapeu de palha em sua cabeca, suas roupas humildes estao sujas, ele carrega uma enxada velha no ombro e masca um longo pedaco de feno<\n");

                printf("\n[1] (Ir a o fazendeiro)\n[2] (Ignorar o fazendeiro)\n");
                printf("\n Resposta: ");
                scanf("%d", &e);
                
                // Selecao E
                
                while (esc_e != 1)
                {
                    switch(e)
                    {
                        case 1:
                            printf("\n\t\t\t\t\t(FAZENDEIRO)");
                            printf("\n- Tem mais uma coisa estranha acontecendo na vila... Todas as noites sem falta um animal de alguma fazenda vem sumindo, meu melhor burro de carga desapareceu ontem...\n");           printf("\n\n>Voce agradece a informacao e decide ir buscar seus suprimentos, ja esta na hora de adentrar a Floresta da Noite<\n\n");
                            
                            esc_e = 1;

                            break;

                        case 2:
                            printf("\n\n>Voce acena de volta por educacao, mas nao aguenta mais ficar sentindo o fedor de abobora murcha e prefere ir atras de seus suprimentos, ja esta na hora de adentrar a Floresta da Noite<\n\n");
                            
                            esc_e = 1;

                            break;

                        default:
                            printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                            printf("\n Resposta: ");
                            scanf("%d", &e);
                            
                            break;
                    }
                }

                // Fim da selecao E
            }

            else if (d == 2)
            {
                printf("\n\n>Voce nao aguenta mais ficar sentindo o fedor de abobora murcha e finalmente vai atras de seus suprimentos, ja esta na hora de adentrar a Floresta da Noite<\n\n");
            }
        }

        else if (c == 2)
        {
            printf("\n\n>Voce nao aguenta mais ficar sentindo o fedor de abobora murcha e finalmente vai atras de seus suprimentos, ja esta na hora de adentrar a Floresta da Noite<\n\n");
        }
    }

    int CombateParte2(int escolha, char inimigo[])
    {
        int battle;

        if (escolha == 1)
        {
            battle = Batalha("guerreiro", inimigo);

            if (battle == 1) { return 1; }
            
            else { return 0; }
        }

        else if (escolha == 2)
        {
            battle = Batalha("mago", inimigo);

            if (battle == 1) { return 1; }
            
            else { return 0; }
        }
    }

    void Parte_2()
    {
        int battle, escolha;

        printf("\n>O ar da floresta entregava que havia algo estranho por la. Seus primeiros passos adentrando a linha das arvores quebravam alguns galhos secos e espantavam os passaros repousados nas arvores<\n");

        printf("-----\n");

        printf(">Sua experiencia como aventureiro lhe dizia que era apenas a calmaria antes da tempestade<\n");
    }

    void Parte_3()
    {
        int a2, esc_a2;

        printf("> Seu corpo estava cansado das batalhas arduas, mas nao era apenas isso que pesava em seus ombros. Havia energia pairando no ar como uma nevoa grossa e cada passo adentrando a mata fazia a ideia de desistir soar cada vez mais plausivel<");
        
        printf("\n-----\n"); 

        printf(">Mas finalmente, depois de seus esforcos e de resistir por tanto tempo ao ar saturado de enxofre, emerge uma estrutura no meio da floresta. Parecia uma cabana de madeira escura e janelas pequenas, que talvez ja tenha sido aconchegante, mas agora permanecia mofada e se misturava ao musgo e as vinhas, tornando-se parte da vegetacao murcha<\n");
        
        printf("\n[1] (Bater na porta)\n[2] Pode sair dai!\n");
        printf("\n Resposta: ");
        scanf("%d", &a2);
        
        // SELECAO A2
        
        do
        {
            switch (a2)
            {
                case 1:
                    printf(">\nVoce ouve uma risada de gelar a espinha e rapidamente recua<\n\n");
                    printf("- Quem vem de tao longe em busca de Mariela? Mariela nao lembra de convidar ninguem\n");

                    printf("\n\t\t\t\t\t\t(MARIELA)\n");
                    printf(">Vestida em cetim negro rasgado e sujo, o  vestido recai sobre um corpo palido e desnutrido, se fundindo com os longos cabelos negros. Seus olhos sao fundos como duas fossas, mas pareciam ja ter sido de um belo tom violeta<");
                    
                    printf("[SISTEMA] Prepare-se para enfrentar Mariela");

                    esc_a2 = 1;
                    
                    break;
                
                case 2:
                    printf("\n\t\t\t\t\t\t(BRUXA)\n");
                    printf("\n- Pela forma como fala... Mais um aventureiro vem morrer em minhas maos\n");
                    printf(">Vestida em cetim negro rasgado e sujo, o  vestido recai sobre um corpo palido e desnutrido, se fundindo com os longos cabelos negros. Seus olhos sao fundos como duas fossas, mas pareciam ja ter sido de um belo tom violeta<");
                    
                    printf("[SISTEMA] Prepare-se para enfrentar Mariela");
                    
                    esc_a2 = 1;
                    
                    break;
                
                default:
                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! nos de uma resposta valida...\n");
                    printf("\n Resposta: ");
                    scanf("%d", &a2);
                    
                    break;
            }
        }
        while (esc_a2 == 0);
    }

    void Parte_4()
    {
        int a3, b3, c3;
        int esc_a3 = 0, esc_b3 = 0, esc_c3 = 0;

        printf("\n>Logo apos a batalha ardua, voce aproveita alguns minutos para recuperar o folego e cuidar das feridas antes de juntar novamente suas coisas e voltar para a vila como um heroi<\n----\n");
        printf(">Logo que sua pequena mochila fica pronta para partir novamente, um vulto nao muito distante agita os ramos da floresta<\n");

        printf("\n[1] Cai pra dentro!(puxar a espada)\n[2] Quem esta ai?\n");
        printf("\n Resposta: ");
        scanf("%d", &a3);

        printf("\n>Uma mulher alta desliza cuidadosamente pra fora da vegetacao, seus olhos sao verdes, e o cabelo cacheado e loiro repousa sobre os ombros. A pele morena esta coberta por ramos entrelacados num tecido vegetal e na mao direita ha um cajado de madeira retorcida e rocoberta de musgo<\n");

        // SELECAO A3

        while (esc_a3 == 0)
        {
            switch (a3)
            {
                case 1:
                    printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                    printf("- Ei! Guarde isso, voce quase cortou um ramo do pobre teixo!");

                    esc_a3 = 1;

                    break;

                case 2:
                    printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                    printf("\n- Nao se preocupe, eu nao represento perigo para voce, aventureiro\n");

                    esc_a3 = 1;

                    break;
                    
                default:
                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                    printf("\n Resposta: ");

                    scanf("%d", &a3);

                    break;
            }
        }

        if (a3 == 1)
        {
            printf("\n\n>Ela nao parece muito feliz com sua acao<\n");
            printf("\n[1] Desculpe, hoje foi um dia dificil...\n[2] Eh so uma arvore, que diferenca faz um galho ou dois?\n");

            printf("\n Resposta: ");
            scanf("%d", &b3);
            
            // SELECAO B3

            while (esc_b3 == 0)
            {
                switch (b3)
                {
                    case 1:
                        printf("\n>O pedido de desculpas melhorou a expressao da mulher<\n");

                        printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                        printf("- Voce nao parece uma ma pessoa no fim das contas... Eu sou Mesha, uma driade guardia que vive aqui ha muito mais tempo que qualquer um. Venha comigo aventureiro, precisa saber de algo\n");
                        printf("\n>Voces caminham despreocupadamente, a floresta parece respeitar a presenca da driade e as criaturas ferozes se afastam<\n");
                        
                        printf("-----\n");
                        
                        printf(">Enfim, uma larga clareira coberta por um tapete de grama e vegetacao silvestre se desdobra a sua frente. Diferente da sensacao ruim ao se aproximar da area contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmoes e o vento balanca seu cabelo<\n");

                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("- A bruxa que voce derrotou se abrigou aqui de uma perseguicao e protegia fielmente seu novo lar. Ateh que pouco antes do fim do verao algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais nao pareciam mais consigo mesmos\n");

                        printf("\n[1] Voce viu quem era?\n[2] Quem voce acha que foi?\n");
                        printf("\n Resposta: ");
                        scanf("%d", &c3);

                        // 1 SELECAO C3

                        while (esc_c3 == 0)
                        {
                            switch (c3)
                            {
                                case 1:
                                    printf("\n\t\t\t\t\t\t(MESHA)\n");
                                    printf("- Nao, e sua presenca poderia facilmente se passar por uma ilusao... Se a figura nao houvesse derrubado algo, tome.\n\n");
                                    printf(">Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");

                                    printf("\n\t\t\t[SISTEMA] Voce obteve: Chave misteriosa (1/2)\n");

                                    printf("\n\t\t\t\t\t\t(MESHA)\n");
                                    printf("Isso eh tudo que posso fazer, mas no lago ha um velho amigo que pode te ajudar, procure pelo Sabio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
                                    
                                    esc_c3 = 1;

                                    break;

                                case 2:
                                    printf("\n\t\t\t\t\t\t(MESHA)\n");
                                    printf("\n- Meu julgamento pode ser tendencioso, eh melhor que descubra por si so, e sua presenca poderia facilmente se passar por uma ilusao... Se a figura nao houvesse derrubado algo, tome.\n");
                                    printf(">Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");

                                    printf("\n\t\t\t[SISTEMA] Voce obteve: Chave misteriosa (1/2)\n");

                                    printf("\n\t\t\t\t\t\t(MESHA)\n");
                                    printf("Isso eh tudo que posso fazer, mas no lago ha um velho amigo que pode te ajudar, procure pelo Sabio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");
                                    
                                    esc_c3 = 1;
                                    
                                    break;

                                default:
                                    printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! nos de uma resposta valida...\n");
                                    printf("\n Resposta: ");
                                    scanf("%d", &c3);

                                    break;
                            }
                        }

                        esc_b3 = 1;
                        
                        break;

                    case 2:
                        printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                        printf("- So uma arvore? Parece que voce nao eh muito diferente dos outros humanos... Infelizmente nao tenho escolha, precisarei contar com a ajuda disponivel\n");
                        printf("\n>Ela sopra uma especie de poeira amarelada na sua direcao e em poucos segundos sua consciencia vai embora<\n");

                        printf("-----\n");

                        printf("\n>Quando acorda, voce se encontra numa larga clareira coberta por um tapete de grama e vegetacao silvestre. Diferente da sensacao ruim ao se aproximar da area contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmoes e o vento balanca seu cabelo<\n");

                        printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                        printf("- A bruxa que voce derrotou se abrigou aqui de uma perseguicao e protegia fielmente seu novo lar. Ate que pouco antes do fim do verao algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais nao pareciam mais consigo mesmos\n");

                        printf("\n\t\t\t\t\t\t(VOCE)\n");
                        printf("\t\t\t\t\t\t ....\n\n");

                        printf("\n\t\t\t\t\t\t(\?\?\?)\n");
                        printf("- Nao precisa acreditar em mim se quiser, mas ele deixou algo para tras, tome.\n\n");
                        printf(">Ela lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n");

                        printf("\n\t\t\t[SISTEMA] Voce obteve: Chave misteriosa (1/2)\n");

                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("No lago ha um velho amigo que pode saber mais do que eu, ele atende pelo nome de Sabio do Lago e se quiser descobrir mais da verdade, eis o caminho.");

                        esc_b3 = 1;

                        break;

                    default:
                        printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                        printf("\n Resposta: ");
                        scanf("%d", &b3);

                        break;
                }
            }
        }

        else if (a3 == 2)
        {
            printf("\nEu sou Mesha, uma driade guardia que vive aqui ha muito mais tempo que qualquer um. Venha comigo aventureiro, precisa saber de algo.\n");
            printf("\n>Voces caminham despreocupadamente, a floresta parece respeitar a presenca da driade e as criaturas ferozes se afastam<\n");

            printf("-----\n");

            printf(">Enfim, uma larga clareira coberta por um tapete de grama e vegetacao silvestre se desdobra a sua frente. Diferente da sensacao ruim ao se aproximar da area contaminada ao redor do casebre da bruxa, ali o cheiro limpa seus pulmoes e o vento balanca seu cabelo<\n");

            printf("\n\t\t\t\t\t\t(MESHA)\n");
            printf("- A bruxa que voce derrotou se abrigou aqui de uma perseguicao e protegia fielmente seu novo lar. Ate que pouco antes do fim do verao algum intruso andou pelas profundezas da floresta e pouco tempo depois Mariela e os animais nao pareciam mais consigo mesmos\n");

            printf("\n[1] Voce viu quem era?\n[2] Quem voce acha que foi?\n");
            printf("\n Resposta: ");
            scanf("%d", &c3);

            // 2 SELECAO C3

            while(esc_c3 == 0)
            {
                switch(c3)
                {
                    case 1:
                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("- Nao, e sua presenca poderia facilmente se passar por uma ilusao... Se a figura nao houvesse derrubado algo, tome.\n\n");
                        printf("\n>Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");

                        printf("\n\t\t\t[SISTEMA] Voce obteve: Chave misteriosa (1/2)\n\n");

                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("Isso eh tudo que posso fazer, mas no lago ha um velho amigo que pode te ajudar, procure pelo Sabio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");

                        esc_c3 = 1;

                        break;
                    
                    case 2:
                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("\n- Meu julgamento pode ser tendencioso, eh melhor que descubra por si so, e sua presenca poderia facilmente se passar por uma ilusao... Se a figura nao houvesse derrubado algo, tome.\n");
                        printf("\n>Mesha lhe entrega uma chave negra com um cristal azul cintilante encravado no pomo<\n\n");

                        printf("\n\t\t\t[SISTEMA] Voce obteve: Chave misteriosa (1/2)\n\n");

                        printf("\n\t\t\t\t\t\t(MESHA)\n");
                        printf("Isso eh tudo que posso fazer, mas no lago ha um velho amigo que pode te ajudar, procure pelo Sabio do Lago se quiser descobrir mais da verdade, e boa sorte aventureiro");

                        esc_c3 = 1;

                        break;

                    default:
                        printf("\n[SISTEMA]: Ei, essa nao eh uma das opcoes! Nos de uma resposta valida...\n");
                        printf("\n Resposta: ");
                        scanf("%d", &c3);

                        break;
                }
            }
        }

        printf("\n\n[SISTEMA] Parabens! Voce concluiu a DEMO de 'Radiver: The Witch and the Crystal Keys'");
    }

int main()
{
    int escolha, temp;

    InicializarItens();

    Parte_1();

    printf("\nSelecione a sua arma:\n1 - Espada\n2 - Cajado\n\n");

    scanf("%d", &escolha);

    /* temp = CombateParte2(escolha, "slime");

    if (temp == 1) { jogador.item.pocaoDeVida++; }
    else { return 0; }

    temp = CombateParte2(escolha, "goblin");

    if (temp == 1) { jogador.item.pocaoDeVida++; }
    else { return 0; } */

    temp = CombateParte2(escolha, "lobo");

    if (temp == 1) { jogador.item.pocaoDeVida++; }
    else { return 0; }

    Parte_3();

    Parte_4();

    return 0;
}
