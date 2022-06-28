#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define LIMPAR_TELA printf("\e[1;1H\e[2J")

// Organização dos dados do jogador e dos inimigos em structs:

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

// Funções para inicializar os membros da structs:

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
                strcpy(inimigo.hobgoblin.nome_atq_dois, "Fúria");
            
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
        // Poção de vida
        
        jogador.item.pocaoDeVida = 0;
    }
    
// Funções que exibem as telas de vitória e derrota:
    
    void VitoriaDoInimigo()
    {
        printf("|> Vida restante do jogador: 0\n");
        
        sleep(3);
        
        LIMPAR_TELA;
        
        printf("*-----------------------------*\n");
        printf("|         Você morreu!        |\n");
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
        printf("|         Você venceu!        |\n");
        printf("*-----------------------------*\n\n");
        
        sleep(5);
        
        LIMPAR_TELA;
    }

// Função que exibe a fala de um inimigo de forma aleatória:
    
    void ExibirFala(char inimigo_escolhido[])
    {
        int dado_inimigo = rand() % 5;
        
        // Falas do slime
            
            if (strcmp(inimigo_escolhido, "slime") == 0)
            {
                if (dado_inimigo == 0)
                {
                    printf("\"Você nunca irá me derrotar.\"\n\n");
                }
                
                else if (dado_inimigo == 1)
                {
                    printf("\"Você é fraco, lhe falta ódio.\"\n\n");
                }
                
                else if (dado_inimigo == 2)
                {
                    printf("\"Você está perdido? Vou te mostrar o caminho da destruição!\"\n\n");
                }
                
                else if (dado_inimigo == 3)
                {
                    printf("\"Está com medo? NÃO?! Irei te destruir!\"\n\n");
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
                    printf("\"Seu otário >:(\"\n\n");
                }
                
                else if (dado_inimigo == 1)
                {
                    printf("\"Ha ha ha, você não tem chance contra mim!!!\"\n\n");
                }
                
                else if (dado_inimigo == 2)
                {
                    printf("\"Vou te destruir!\"\n\n");
                }
                
                else if (dado_inimigo == 3)
                {
                    printf("\"Um humano por aqui?! Vou acabar com sua raça!\"\n\n");
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
                    printf("\"Você é uma presa fácil para um caçador como eu!!!\"\n\n");
                }
                
                else if (dado_inimigo == 2)
                {
                    printf("\"Vou lhe trucidar em pedacinhos!\"\n\n");
                }
                
                else if (dado_inimigo == 3)
                {
                    printf("\"Humano? São mais deliciosos quando estão com medo!\"\n\n");
                }
                
                else
                {
                    printf("\"...\"\n\n");
                }
            }
        
        // Falas do espírito
        
            if (strcmp(inimigo_escolhido, "espirito") == 0)
            {
                if (dado_inimigo == 0)
                {
                    printf("\"Você não passará!!\"\n\n");
                }
                
                else if (dado_inimigo == 1)
                {
                    printf("\"Vou te mandar para outra dimensão!\"\n\n");
                }
                
                else if (dado_inimigo == 2)
                {
                    printf("\"Sacie minha vontade.\"\n\n");
                }
                
                else if (dado_inimigo == 3)
                {
                    printf("\"Você não pode escapar das minhas lâminas, elas cortam até diamantes.\"\n\n");
                }
                
                else
                {
                    printf("\"...\"\n\n");
                }
            }
    }
    
// Função da batalha:

    int Batalha(char classe_escolhida[], char inimigo_escolhido[])
    {
        srand((unsigned)time(NULL));
        
        // *----------------------*
        // | Variáveis do jogador |
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
            
            // (2) Senão, se a classe escolhida pelo jogador for Mago:
            
            else if (strcmp(classe_escolhida, "mago") == 0)
            {
                classe_jogador = jogador.classe.mago.nome;
                
                vida_jogador = jogador.classe.mago.vida;
                mana_jogador = jogador.classe.mago.mana;
                
                dano_atq_fraco = jogador.classe.mago.atq_fraco;
                dano_atq_forte = jogador.classe.mago.atq_forte;
            }
        
        // *----------------------*
        // | Variáveis do inimigo |
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
            
            // (2) Senão, se a batalha for contra um goblin:
            
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
            
            // (3) Senão, se batalha for contra um lobo:
            
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
            
            // (4) Senão, se batalha for contra um espirito:
            
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
            
            // Variável da escolha do jogador:
                
                int escolha;
            
            // Variáveis dos dados:
                
                int dado_jogador, dado_inimigo;
            
            // Mensagem inicial:
                
                printf("Um %s de nível %d apareceu!\n", nome_inimigo, nivel_inimigo);
                
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
                                    
                                    printf("< Você >\n");
                                    printf("Vida: %d | Mana: %d\n\n", vida_jogador, mana_jogador);
                                
                                // Status do monstro:
                                    
                                    printf("< %s >\n", nome_inimigo);
                                    printf("Vida: %d | Nível: %d\n\n", vida_inimigo, nivel_inimigo);
                                
                                // Opções:
                                    
                                    printf("*------------------------*\n");
                                    printf("|    [1] ataque fraco    |\n");
                                    printf("|    [2] ataque forte    |\n");     
                                    printf("*------------------------*\n");
                                    printf("|  [3] poção de vida | %d |\n", jogador.item.pocaoDeVida);     
                                    printf("*------------------------*\n\n");
                                
                                // Escolha do jogador:
                                    
                                    printf("> ");
                                    scanf("%d", &escolha);

                            // ||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
                            
                            // *---------------------*
                            // | Tratamento de erros |
                            // *---------------------*
                                
                                // (1) Se o jogador digitar algum valor que esteja fora das opções:
                                    
                                    if (escolha < 1 || escolha > 3)
                                    {
                                        printf("> Opção inválida! Tente novamente\n");
                                        
                                        sleep(1);
                                    }
                                
                                // (2) Senão, se o jogador escolher o ataque forte:
                                    
                                    else if (escolha == 2)
                                    {
                                        // Se o jogador não possuir mana:
                                            
                                            if (mana_jogador <= 0)
                                            {
                                                printf("> Mana insuficiente para realizar ataque!\n");
                                                
                                                sleep(1);
                                                
                                                escolha = -1;
                                            }
                                    }
                                
                                // (3) Senão, se o jogador escolher a poção de vida:
                                    
                                    else if (escolha == 3)
                                    {
                                        // Se o jogador não possuir poções:
                                            
                                            if (jogador.item.pocaoDeVida <= 0)
                                            {
                                                printf("> Você não tem poções para usar!\n");
                                                
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
                                // Será gerado um valor aleatório para o dado.
                                    
                                    dado_jogador = rand() % 7;
                                
                                // (1) Se o valor do dado for 0, o jogador erra o ataque.
                                    
                                    if (dado_jogador == 0)
                                    {
                                        printf("Você errou o ataque!\n");
                                        
                                        sleep(2);
                                    }
                                
                                // (2) Senão, o ataque é efetuado.
                                    
                                    else
                                    {
                                        printf("Você usou o ataque fraco!\n\n");
                                        
                                        sleep(1);
                                        
                                        // Será gerado um valor aleatório para o dado.
                                            
                                            dado_jogador = rand() % 5;
                                        
                                        // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                            
                                            if (dado_jogador == 0)
                                            {
                                                printf("|> Dano causado: %d (crítico)\n", dano_atq_fraco + 10);
                                                
                                                sleep(1);
                                                
                                                vida_inimigo -= dano_atq_fraco + 10;
                                            }
                                            
                                        // (2) Senão, o dano do ataque será normal.
                                            
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
                                            
                                         // (2) Caso o ataque não mate o inimigo:
                                         
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
                                // Será gerado um valor aleatório para o dado.
                                    
                                    dado_jogador = rand() % 2;
                                
                                // Se o valor do dado for 0, o jogador erra o ataque.
                                    
                                    if (dado_jogador == 0)
                                    {
                                        printf("Você errou o ataque!\n\n");
                                        
                                        printf("|> Mana: -5\n");
                                        
                                        mana_jogador -= 5;
                                        
                                        sleep(2);
                                    }
                                
                                // Caso for qualquer outro valor, o ataque é efetuado.
                                    
                                    else
                                    {
                                        printf("Você usou o ataque forte!\n\n");
                                        
                                        sleep(1);
                                        
                                        // Será gerado um valor aleatório para o dado.
                                            
                                            dado_jogador = rand() % 7;
                                        
                                        // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                            
                                            if (dado_jogador == 0)
                                            {
                                                printf("|> Dano causado: %d (crítico)\n", dano_atq_forte + 10);
                                                
                                                sleep(1);
                                                
                                                vida_inimigo -= dano_atq_forte + 10;
                                            }
                                            
                                        // (2) Se for qualquer outro valor, o dano do ataque será normal.
                                            
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
                                            
                                        // (2) Caso o ataque não mate o inimigo:
                                         
                                            else
                                            {
                                                printf("|> Vida restante do inimigo: %d\n", vida_inimigo);
                                                
                                                sleep(2);
                                            }
                                    }
                            }
                        
                        // (3) Se for escolhido a poção de vida:
                            
                            else if (escolha == 3)
                            {
                                printf("Você usou uma poção de vida!\n\n");
                                
                                sleep(1);
                                
                                // Será gerado um valor aleatório para o dado.
                                    
                                    dado_jogador = rand() % 2;
                                
                                // (1) Se o valor do dado for 0, o jogador recupera 10 de vida.
                                    
                                    if (dado_jogador == 0)
                                    {
                                        printf("|> Vida: +10\n");
                                        
                                        vida_jogador += 10;
                                    }
                                
                                // (2) Senão, se o valor do dado for 1, o jogador recupera 20 de vida.
                                    
                                    else if (dado_jogador == 1)
                                    {
                                        printf("|> Vida: +20\n");
                                        
                                        vida_jogador += 20;
                                    }
                                
                                // (3) Senão, se o valor do dado for 2, o jogador recupera 30 de vida.
                                    
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
                        
                        // Será gerado um valor aleatório para o dado.
                            
                            dado_inimigo = rand() % 2;
                        
                        // (1) Se o valor do dado for 0, o inimigo erra o ataque.
                            
                            if (dado_inimigo == 0)
                            {
                                printf("%s errou o ataque!\n", nome_inimigo);
                                
                                sleep(2);
                            }
                            
                        // (2) Senão, se o valor do dado for 1, o ataque é efetuado.
                            
                            else if (dado_inimigo == 1)
                            {
                                // Fala do inimigo:
                                    
                                    ExibirFala(inimigo_escolhido);
                                
                                // Nome e ataque do inimigo:
                                    
                                    printf("%s usou %s!\n\n", nome_inimigo, nome_atq_um);
                                    
                                    sleep(1);
                                
                                // Será gerado um valor aleatório para o dado.
                                    
                                    dado_inimigo = rand() % 5;
                                
                                // (1) Se o valor do dado for 0, o dano do ataque aumenta em 10.
                                    
                                    if (dado_inimigo == 0)
                                    {
                                        printf("|> Dano causado: %d (crítico)\n", dano_atq_um + 10);
                                     
                                        sleep(1);
                                        
                                        vida_jogador -= dano_atq_um + 10;
                                    }
                                    
                                // (2) Senão, se for qualquer outro valor, o dano do ataque será normal.
                                    
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
                                    
                                // (2) Caso o ataque não mate o jogador:
                                    
                                    else
                                    {
                                        printf("|> Vida restante do jogador: %d\n", vida_jogador);
                                        
                                        sleep(4);
                                    }
                            }
                            
                        // (3) Senão, se o valor do dado for 2, o monstro efetua o ataque 2.
                            
                            else if (dado_inimigo == 2)
                            {
                                // Caso o inimigo tenha alguma fala.
                                    
                                    ExibirFala(inimigo_escolhido);
                                
                                // Nome e ataque do inimigo
                                    
                                    printf("%s usou %s!\n\n", nome_inimigo, nome_atq_dois);
                                    
                                    sleep(1);
                                
                                // Será gerado um valor aleatório para o dado.
                                    
                                    dado_inimigo = rand() % 5;
                                
                                // Caso o valor do dado seja 0, o dano do ataque aumenta em 10.
                                    
                                    if (dado_inimigo == 0)
                                    {
                                        printf("|> Dano causado: %d (crítico)\n", dano_atq_dois + 10);
                                     
                                        sleep(1);
                                        
                                        vida_jogador -= dano_atq_dois + 10;
                                    }
                                    
                                // Caso não seja 0, o dano do ataque será normal.
                                    
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
                                    
                                // (2) Caso o ataque não mate o jogador:
                                    
                                    else
                                    {
                                        printf("|> Vida restante do jogador: %d\n", vida_jogador);
                                        
                                        sleep(4);
                                    }
                            }
                }
    }

int main()
{
    InicializarItens();
    
    int battle;
    
    // Primeiro combate
        
        battle = Batalha("guerreiro", "slime");
        
        if (battle == 1)
        {
            // Recompensas
            
            jogador.item.pocaoDeVida++;
        }
        
        else
        {
            // Game over
            
            return 0;
        }
    
    // Segundo combate
        
        battle = Batalha("guerreiro", "goblin");
        
        if (battle == 1)
        {
            // Recompensas
            
            jogador.item.pocaoDeVida++;
        }
        
        else
        {
            // Game over
            
            return 0;
        }
    
    // Terceiro combate
        
        battle = Batalha("guerreiro", "lobo");
        
        if (battle == 1)
        {
            // Recompensas
            
            jogador.item.pocaoDeVida++;
        }
        
        else
        {
            // Game over
            
            return 0;
        }
    
    // Quarto combate
        
        battle = Batalha("guerreiro", "espirito");
        
        if (battle == 1)
        {
            // Recompensas
            
            jogador.item.pocaoDeVida++;
        }
        
        else
        {
            // Game over
            
            return 0;
        }
    
    return 0;
}