#include <stdio.h>
#include <stdlib.h>
#include "Privado.h"
#include <mysql.h>
#include <time.h>

struct switches
{
    int a;
    int b;
    int c;
    int d;
    int e;
};

struct login
{
    char username[20];
    char password[32];
};

struct registo
{
    char username[20];
    char password[32];
};

struct transferenciadata
{
    int entidade;
    int referencia;
    char iban[25];
    int money;
};

struct mysqlvalues
{
    char query1[200];
    char query2[200];
    char query3[200];
    char query4[200];
    char query5[200];
    char query6[200];
    char query7[200];
    char query8[200];
    char query9[200];
    char query10[200];
    char query11[200];
    char query12[200];
    char query13[200];
    char query14[200];
    char query15[200];
    char query16[200];
    char query17[200];
    char query18[200];
    char query19[200];
    char query20[200];
    char query21[200];
    char query22[200];
    char query23[200];
    char query24[200];
    char query25[200];
    char query26[200];
};

struct transferenciadata transferenciadata;
struct login login;
struct registo registo;
struct mysqlvalues mysqlvalues;
struct switches switches;

////////////////////////////////////////

int main()
{
    cls();
    printf(Amarelo);
    loadingfunc();
    FILE *ficheiro;
    ficheiro = fopen("ficheiro.txt", "r+");
    char host[30];
    fscanf(ficheiro, "%s", &host);
    ////////////////////////////////////////
    MYSQL *con;
    MYSQL_RES *res;
    MYSQL_ROW row;
    char *server = host;
    char *user = "root";
    char *pass = "5603";
    // char *pass = "1589227704";
    char *database = "psi";
    con = mysql_init(NULL);
    if(!mysql_real_connect(con, server, user, pass, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
    }
    ////////////////////////////////////////
    idioma();
    fullscreen();
    cls();
    title("Waterbank");
    printf("+-------------------------+\n");
    printf("| " Ciano "Bem-vindo ao WaterBank." Amarelo " |\n");
    printf("+-------------------------+\n");
    sleep(5);
principal:
    cls();
    printf("+-------------------------------------+\n");
    printf("| " Vermelho "  Escolha umas das opções abaixo. " Amarelo "  |\n");
    printf("+-------------------------------------+\n");
    printf("| 1 - "Ciano"Login   "Amarelo"                        |\n");
    printf("| 2 - "Ciano"Registro  "Amarelo"                      |\n");
    printf("| 3 - "Ciano"Créditos  "Amarelo"                      |\n");
    printf("| 4 - "Ciano"Sair       "Amarelo"                     |\n");
    printf("+-------------------------------------+\n");
    printf("| "Vermelho"Resposta"Amarelo": ");
    scanf("%i",&switches.a);
    switch(switches.a)
    {
    case 1:
login:
        cls();
        printf("+---------------+\n");
        printf("| " Vermelho "Menu do Login" Amarelo " |\n");
        printf("+---------------+\n");
        printf("| " Vermelho "Username" Amarelo ": ");
        scanf("%s",&login.username);
        printf("| " Vermelho "Password" Amarelo ": ");
        scanf("%s",&login.password);
        sprintf(mysqlvalues.query1, "SELECT * FROM contas WHERE username = '%s' AND password = '%s'", login.username, login.password);
        if(mysql_query(con, mysqlvalues.query1))
        {
            printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        res = mysql_use_result(con);
        if(mysql_fetch_row(res) == NULL)
        {
            printf("Username ou Password incorreto.\n");
            sleep(3);
            goto login;
        }
        mysql_free_result(res);
menu:
        cls();
        sprintf(mysqlvalues.query18, "SELECT * FROM contas WHERE username = '%s' AND Grupo = 1", login.username);
        if(mysql_query(con, mysqlvalues.query18))
        {
            printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        res = mysql_use_result(con);
        printf("+-------------------------------------------+\n");
        printf("| " Vermelho "Bem-vindo, escolha uma das opções abaixo. "Amarelo"|\n");
        printf("+-------------------------------------------+\n");
        printf("| 1 - "Ciano"Solicitar cartão          "Amarelo"            |\n");
        printf("| 2 - "Ciano"Verificar dados/saldo conta bancária "Amarelo" |\n");
        printf("| 3 - "Ciano"Verificar dados cartão           "Amarelo"     |\n");
        printf("| 4 - "Ciano"Transferir dinheiro             "Amarelo"      |\n");
        printf("| 5 - "Ciano"Logout                         "Amarelo"       |\n");
        printf("| 6 - "Ciano"Sair                          "Amarelo"        |\n");
        if(mysql_fetch_row(res) != NULL)
        {
            printf("| 7 - "Ciano"Admin menu                        "Amarelo"    |\n");
        }
        printf("+-------------------------------------------+\n");
        printf("| " Vermelho "Resposta" Amarelo ": ");
        scanf("%i",&switches.b);
        mysql_free_result(res);
        switch(switches.b)
        {
        case 1:
            sprintf(mysqlvalues.query2, "SELECT * FROM `contas` WHERE `username` = '%s' AND `Cartao_solicitado` = 0;", login.username);
            if(mysql_query(con, mysqlvalues.query2))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf(""Amarelo"O seu cartão já foi solicitado.\n");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
            printf(""Amarelo"A solicitação foi feita com sucesso. Aguarde alguns segundos...\n");
            srand(time(NULL));
            int cartao1 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao2 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao3 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cartao4 = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
            int cvv = (rand() % (999 + 1 - 100)) + 100;
            char cvvchar[5];
            sprintf(cvvchar, "%i", cvv);
            printf("+----------------------------------+\n");
            printf("| "Vermelho"Titular                         "Amarelo" |\n");
            printf("| "Ciano"%s\n", login.username);
            printf(""Amarelo"|                                  |\n");
            printf("| "Vermelho"Nº Cartão "Ciano"%i%i%i%i"Amarelo"       |\n", cartao1, cartao2, cartao3, cartao4);
            printf("|                                  |\n");
            printf("| "Vermelho"CVC "Ciano"%s"Amarelo"          "Vermelho"Validade "Ciano"2025"Amarelo"   |\n", cvvchar);
            printf("+----------------------------------+\n");
            ///////////////////////////////////////////////////////////////////
            sleep(5);
            int entidade1 = (rand() % (999 + 1 - 100)) + 100;
            sleep(5);
            int entidade2 = (rand() % (99 + 1 - 10)) + 10;
            ////////////////////////////////////////////////////////////////////
            int referencia1 = (rand() % (99999 + 1 - 10000)) + 10000;
            sleep(5);
            int referencia2 = (rand() % (9999 + 1 - 1000)) + 1000;
            char referencia1char[20];
            char referencia2char[20];
            itoa(referencia1, referencia1char, 10);
            itoa(referencia2, referencia2char, 10);
            strcat(referencia1char, referencia2char);
            ////////////////////////////////////////////////////////////////////
            int codigocartao = (rand() % (9999 + 1 - 1000)) + 1000;
            char codigocartaochar[5];
            sprintf(codigocartaochar, "%i", codigocartao);
            printf("\n");
            printf(""Amarelo"+----------------------------------+\n");
            printf("| "Vermelho"Entidade                   "Amarelo"      |\n");
            printf("| "Ciano"%i%i "Amarelo"                           |\n", entidade1, entidade2);
            printf("|                                  |\n");
            printf("| "Vermelho"Referência "Ciano"%s "Amarelo"            |\n", referencia1char);
            printf("|                                  |\n");
            printf("| "Vermelho"Código "Ciano"%s            "Amarelo"          |\n", codigocartaochar);
            printf("+----------------------------------+\n");
            sprintf(mysqlvalues.query3, "UPDATE `contas` SET Cartao_solicitado = 1, Cartao_codigo = '%s', Cartao_entidade = '%i%i' WHERE Username = '%s';", codigocartaochar, entidade1, entidade2, login.username);
            if(mysql_query(con, mysqlvalues.query3))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            sprintf(mysqlvalues.query4, "UPDATE `contas` SET Cartao_referencia = '%s', Cartao_numero = '%i%i%i%i', Cartao_ccv = '%s' WHERE Username = '%s';", referencia1char, cartao1, cartao2, cartao3, cartao4, cvvchar, login.username);
            if(mysql_query(con, mysqlvalues.query4))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            pressanykey();
            goto menu;
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        case 2:
            cls();
            sprintf(mysqlvalues.query5, "SELECT * FROM `contas` WHERE Username = '%s';", login.username);
            if(mysql_query(con, mysqlvalues.query5))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            MYSQL_RES *res = mysql_use_result(con);
            MYSQL_ROW row = mysql_fetch_row(res);
            if(row[0] == NULL)
            {
                erroexit();
            }
            printf(""Amarelo"+---------------------------+\n");
            printf("|       "Vermelho"    IBAN         "Amarelo"   |\n");
            printf("+---------------------------+\n");
            printf("| "Ciano"%s"Amarelo" |\n", row[3]);
            printf("+---------------------------+\n");
            printf("| "Ciano"%s"Vermelho"$"Amarelo"\n", row[2]);
            printf("+---------------------------+\n");
            mysql_free_result(res);
            pressanykey();
            goto menu;
            break;
        case 3:
            sprintf(mysqlvalues.query11, "SELECT * FROM `contas` WHERE `username` = '%s' AND `Cartao_solicitado` = 1;", login.username);
            if(mysql_query(con, mysqlvalues.query11))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf(""Amarelo"O seu cartão ainda não foi solicitado.\n");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
            sprintf(mysqlvalues.query8, "SELECT * FROM `contas` WHERE Username = '%s';", login.username);
            if(mysql_query(con, mysqlvalues.query8))
            {
                printf(""Vermelho""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            row = mysql_fetch_row(res);
            if(row[0] == NULL)
            {
                erroexit();
            }
            printf(""Amarelo"+----------------------------------+\n");
            printf("| "Vermelho"Titular            "Amarelo"              |\n");
            printf("| "Ciano"%s"Amarelo"\n", row[0]);
            printf("|                                  |\n");
            printf("| "Vermelho"Nº Cartão "Ciano"%s"Amarelo"       |\n", row[9]);
            printf("|                                  |\n");
            printf("| "Vermelho"CVC "Ciano"%s        "Vermelho"  Validade "Ciano"2025"Amarelo"   |\n", row[10]);
            printf("+----------------------------------+\n");
            printf("\n");
            printf("+----------------------------------+\n");
            printf("| "Vermelho"Entidade              "Amarelo"           |\n");
            printf("| "Ciano"%s                           "Amarelo" |\n", row[7]);
            printf("|                                  |\n");
            printf("| "Vermelho"Referência "Ciano"%s  "Amarelo"           |\n", row[8]);
            printf("|                                  |\n");
            printf("| "Vermelho"Código "Ciano"%s  "Amarelo"                    |\n", row[6]);
            printf("+----------------------------------+\n");
            mysql_free_result(res);
            pressanykey();
            goto menu;
            break;
        case 4:
transferencias:
            cls();
            printf(""Amarelo"+-------------------------------------------+\n");
            printf("| "Vermelho"Bem-vindo, escolha uma das opções abaixo. "Amarelo"|\n");
            printf("+-------------------------------------------+\n");
            printf("| 1 - "Ciano"Transferir por entidade e referencia "Amarelo" |\n");
            printf("| 2 - "Ciano"Transferir por IBan              "Amarelo"     |\n");
            printf("| 3 - "Ciano"Menu anterior                   "Amarelo"      |\n");
            printf("| 4 - "Ciano"Sair                            "Amarelo"      |\n");
            printf("+-------------------------------------------+\n");
            printf("| "Vermelho"Resposta"Amarelo": ");
            scanf("%i", &switches.c);
            fflush(stdin);
            switch(switches.c)
            {
            case 1:
                cls();
                printf(""Amarelo"Insira a entidade a que deseja fazer uma transferência. (5 números)\n");
                printf(""Vermelho"Entidade"Amarelo": ");
                scanf("%i", &transferenciadata.entidade);

                printf("\n"Amarelo"Insira a referência a que deseja fazer uma transferência. (9 números)\n");
                printf(""Vermelho"Referência"Amarelo": ");
                scanf("%i", &transferenciadata.referencia);

                printf("\n"Amarelo"Insira a quantidade em euros que deseja enviar.\n");
                printf(""Vermelho"Quantidade"Amarelo": ");
                scanf("%i", &transferenciadata.money);
                if(transferenciadata.money < 1)
                {
                    printf(""Vermelho"A quantidade tem de ser acima de 1.");
                    sleep(3);
                    goto transferencias;
                }
                sprintf(mysqlvalues.query9, "SELECT * FROM `contas` WHERE `Cartao_referencia` = '%i' AND `Cartao_entidade` = '%i';", transferenciadata.referencia, transferenciadata.entidade);
                if(mysql_query(con, mysqlvalues.query9))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                if(row == NULL)
                {
                    printf(""Vermelho"O perfil inserido não foi encontrado. Tente novamente.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query12, "SELECT * FROM `contas` WHERE `Username` = '%s';", login.username);
                if(mysql_query(con, mysqlvalues.query12))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                int money = atoi(row[2]);
                if(transferenciadata.money > money)
                {
                    printf(""Vermelho"Não tem saldo suficiente para efetuar esta operação.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query10, "UPDATE `contas` SET Saldo = Saldo + %i WHERE Cartao_entidade = '%i' AND Cartao_referencia = '%i';", transferenciadata.money, transferenciadata.entidade, transferenciadata.referencia);
                if(mysql_query(con, mysqlvalues.query10))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                sprintf(mysqlvalues.query13, "UPDATE `contas` SET Saldo = Saldo - %i WHERE Username = '%s';", transferenciadata.money, login.username);
                if(mysql_query(con, mysqlvalues.query13))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                printf(""Amarelo"Dinheiro transferido com sucesso.\n");
                pressanykey();
                goto menu;
                break;
            case 2:
                printf(""Amarelo"Insira o IBan para qual quer enviar.\n");
                printf(""Vermelho"IBan"Amarelo": ");
                gets(transferenciadata.iban);
                printf(""Amarelo"Insira a quantidade que deseja enviar.\n");
                printf(""Vermelho"Quantidade"Amarelo": ");
                scanf("%i", &transferenciadata.money);
                fflush(stdin);
                sprintf(mysqlvalues.query14, "SELECT * FROM `contas` WHERE `IBan` = '%s';", transferenciadata.iban);
                if(mysql_query(con, mysqlvalues.query14))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                if(row == NULL)
                {
                    printf(""Vermelho"O perfil inserido não foi encontrado. Tente novamente.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query15, "SELECT * FROM `contas` WHERE `Username` = '%s';", login.username);
                if(mysql_query(con, mysqlvalues.query15))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                money = atoi(row[2]);
                if(transferenciadata.money > money)
                {
                    printf(""Vermelho"Não tem saldo suficiente para efetuar esta operação.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query16, "UPDATE `contas` SET Saldo = Saldo + %i WHERE IBan = '%s';", transferenciadata.money, transferenciadata.iban);
                if(mysql_query(con, mysqlvalues.query16))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                sprintf(mysqlvalues.query17, "UPDATE `contas` SET Saldo = Saldo - %i WHERE Username = '%s';", transferenciadata.money, login.username);
                if(mysql_query(con, mysqlvalues.query17))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                printf(""Amarelo"Dinheiro transferido com sucesso.\n");
                pressanykey();
                goto menu;
                break;
            case 3:
                goto menu;
                break;
            case 4:
                cls();
                printf(""Amarelo"A sair do programa...");
                SetConsoleTitle("A sair do programa...");
                sleep(3);
                exit(0);
                break;
            default:
                erroexit();
            }
            break;
        case 5:
            printf(""Amarelo"A terminar sessão...");
            sleep(3);
            goto principal;
            break;
        case 6:
            cls();
            printf(""Amarelo"A sair do programa...");
            SetConsoleTitle("A sair do programa...");
            sleep(3);
            exit(0);
            break;
        case 7:
            sprintf(mysqlvalues.query19, "SELECT * FROM contas WHERE username = '%s' AND Grupo = 1", login.username);
            if(mysql_query(con, mysqlvalues.query19))
            {
                printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf(""Vermelho"O utilizador não tem permissão para acessar este menu.");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
admin:
            cls();
            printf(""Amarelo"+---------------------------+\n");
            printf("|   "Vermelho"Menu de Administrador "Amarelo"  |\n");
            printf("+---------------------------+\n");
            printf("| 1 - "Ciano"Gerir utilizadores "Amarelo"   |\n");
            printf("| 2 - "Ciano"Gerir administradores"Amarelo" |\n");
            printf("| 3 - "Ciano"Voltar ao menu  "Amarelo"      |\n");
            printf("| 4 - "Ciano"Terminar Sessão      "Amarelo" |\n");
            printf("| 5 - "Ciano"Sair do programa"Amarelo"      |\n");
            printf("+---------------------------+\n");
            printf("| "Vermelho"Resposta"Amarelo": ");
            scanf("%i", &switches.d);
            fflush(stdin);
            switch(switches.d)
            {
            case 1:
                cls();
                printf(""Amarelo"+---------------------------------+\n");
                printf("|     "Vermelho"Gestão de utilizadores"Amarelo"      |\n");
                printf("+---------------------------------+\n");
                printf("| 1 - "Ciano"Apagar utilizador  "Amarelo"         |\n");
                printf("| 2 - "Ciano"Alterar senha de utilizador"Amarelo" |\n");
                printf("| 3 - "Ciano"Voltar atrás             "Amarelo"   |\n");
                printf("+---------------------------------+\n");
                printf("| "Vermelho"Resposta"Amarelo": ");
                scanf("%i", &switches.e);
                fflush(stdin);
                switch(switches.e)
                {
                case 1:
deleteuser:
                    printf("Insira o nome do utilizador que deseja apagar.\n");
                    char nome[20];
                    gets(nome);
                    sprintf(mysqlvalues.query19, "SELECT * FROM contas WHERE username = '%s';", nome);
                    if(mysql_query(con, mysqlvalues.query19))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    res = mysql_use_result(con);
                    if(mysql_fetch_row(res) == NULL)
                    {
                        printf(""Vermelho"Utilizador não encontrado.\n");
                        sleep(3);
                        goto deleteuser;
                    }
                    mysql_free_result(res);
                    sprintf(mysqlvalues.query20, "DELETE FROM contas WHERE username = '%s';", nome);
                    if(mysql_query(con, mysqlvalues.query20))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    printf(""Amarelo"Utilizador eliminado com sucesso.\n");
                    sleep(3);
                    goto admin;
                    break;
                case 2:
changepassuser:
                    printf(""Amarelo"Insira o utilizador que deseja alterar a senha.\n");
                    char nomecpu[20];
                    gets(nomecpu);
                    sprintf(mysqlvalues.query21, "SELECT * FROM contas WHERE username = '%s';", nomecpu);
                    if(mysql_query(con, mysqlvalues.query21))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    res = mysql_use_result(con);
                    if(mysql_fetch_row(res) == NULL)
                    {
                        printf(""Vermelho"Utilizador não encontrado.\n");
                        sleep(3);
                        goto changepassuser;
                    }
                    mysql_free_result(res);
                    printf(""Amarelo"Insira a nova senha.\n");
                    char password[20];
                    gets(password);
                    sprintf(mysqlvalues.query22, "UPDATE `contas` SET Password = '%s' WHERE Username = '%s';", password, nomecpu);
                    if(mysql_query(con, mysqlvalues.query22))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    printf(""Amarelo"A senha foi alterada com sucesso.\n");
                    pressanykey();
                    goto admin;
                    break;
                case 3:
                    goto admin;
                    break;
                default:
                    erroexit();
                }
                break;
            case 2:
changeusergroup:
                fflush(stdin);
                printf(""Amarelo"Insira o utilizador que deseja alterar.\n");
                char user[20];
                gets(user);
                sprintf(mysqlvalues.query23, "SELECT * FROM contas WHERE username = '%s';", user);
                if(mysql_query(con, mysqlvalues.query23))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                if(mysql_fetch_row(res) == NULL)
                {
                    printf(""Vermelho"Utilizador não encontrado.\n");
                    sleep(3);
                    goto changeusergroup;
                }
                mysql_free_result(res);

                sprintf(mysqlvalues.query24, "SELECT * FROM contas WHERE username = '%s' AND Grupo = 1;", user);
                if(mysql_query(con, mysqlvalues.query24))
                {
                    printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                if(mysql_fetch_row(res) == NULL)
                {
                    sprintf(mysqlvalues.query25, "UPDATE `contas` SET Grupo = 1 WHERE Username = '%s';", user);
                    if(mysql_query(con, mysqlvalues.query25))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    printf(""Amarelo"O utilizador foi promovido para administrador com sucesso.\n");
                    sleep(3);
                    goto admin;
                }
                else
                {
                    mysql_free_result(res);
                    sprintf(mysqlvalues.query25, "UPDATE `contas` SET Grupo = 0 WHERE Username = '%s';", user);
                    if(mysql_query(con, mysqlvalues.query25))
                    {
                        printf(""Vermelho"Query failed: %s\n", mysql_error(con));
                        exit(0);
                    }
                    printf(""Amarelo"O utilizador foi rebaixado para membro com sucesso.\n");
                    sleep(3);
                    goto admin;
                }
                mysql_free_result(res);
            case 3:
                goto menu;
                break;
            case 4:
                printf(""Vermelho"A terminar sessão...");
                sleep(3);
                goto principal;
                break;
            case 5:
                cls();
                printf(""Vermelho"A sair do programa...");
                SetConsoleTitle(""Vermelho"A sair do programa...");
                sleep(3);
                exit(0);
                break;
            default:
                erroexit();
            }
        default:
            erroexit();
        }
        break;
    case 2:
registomenu:
        cls();
        printf(""Amarelo"+-----------------+\n");
        printf("| "Vermelho"Menu do Registo "Amarelo"|\n");
        printf("+-----------------+\n");
        printf("| "Vermelho"Username"Amarelo": ");
        scanf("%s",&registo.username);
        printf("| "Vermelho"Password"Amarelo": ");
        scanf("%s",&registo.password);
        sprintf(mysqlvalues.query7, "SELECT * FROM contas WHERE Username = '%s';", registo.username);
        if(mysql_query(con, mysqlvalues.query7))
        {
            printf(""Vermelho"Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        res = mysql_use_result(con);
        if(mysql_fetch_row(res) != NULL)
        {
            printf(""Vermelho"Username em utilização.\n");
            mysql_free_result(res);
            sleep(3);
            goto registomenu;
        }
        printf(""Amarelo"A inserir a suas informações na base de dados. Aguarde alguns segundos...\n");
        mysql_free_result(res);
        int iban[4];
        for(int i = 0; i < 5; i++)
        {
            iban[i] = (rand() % (9999 + 1 - 1000)) + 1000;
            sleep(5);
        }
        int iban1 = (rand() % (999 + 1 - 100)) + 100;
        sprintf(mysqlvalues.query6, "INSERT INTO contas (username, password, iban) VALUES ('%s', '%s', 'PT%i%i%i%i%i%i');", registo.username, registo.password, iban[0], iban[1], iban[2], iban[3], iban[4], iban1);
        if(mysql_query(con, mysqlvalues.query6))
        {
            printf(""Vermelho"Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        printf(""Amarelo"O registo foi efetuado com sucesso. A voltar ao menu...");
        sleep(3);
        goto principal;
        break;
    case 3:
        cls();
        printf(""Amarelo"+---------------+\n");
        printf("|  "Vermelho"Programador  |\n");
        printf("+---------------+\n");
        printf("| "Ciano"António Matos "Amarelo"|\n");
        printf("+---------------+\n");
        pressanykey();
        goto principal;
        break;
    case 4:
        cls();
        printf(""Vermelho"A sair do programa...");
        SetConsoleTitle(""Vermelho"A sair do programa...");
        sleep(3);
        exit(0);
        break;
    default:
        erroexit();
    }
}

