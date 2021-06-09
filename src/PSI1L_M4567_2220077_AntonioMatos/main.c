#include <stdio.h>
#include <stdlib.h>
#include <Privado.h>
#include <mysql.h>
#include <time.h>

struct switches
{
    int a;
    int b;
    int c;
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
};

struct randomnum
{
    int lower;
    int upper;
};

struct transferenciadata transferenciadata;
struct randomnum randomnum;
struct login login;
struct registo registo;
struct mysqlvalues mysqlvalues;
struct switches switches;

////////////////////////////////////////

void finish_with_error(MYSQL *con)
{
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
}

////////////////////////////////////////

int main()
{
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
    char *database = "psi";
    con = mysql_init(NULL);
    if(!mysql_real_connect(con, server, user, pass, database, 0, NULL, 0))
    {
        fprintf(stderr, "%s\n", mysql_error(con));
    }
    ////////////////////////////////////////
    idioma();
    fullscreen();
    loadingfunc();
    cls();
    title("Waterbank");
    printf("+-------------------------+\n");
    printf("| Bem-vindo ao WaterBank. |\n");
    printf("+-------------------------+\n");
    sleep(5);
principal:
    cls();
    printf("+-------------------------------------+\n");
    printf("| Escolha umas das opções abaixo.     |\n");
    printf("+-------------------------------------+\n");
    printf("| 1 - Login                           |\n");
    printf("| 2 - Registro                        |\n");
    printf("| 3 - Créditos                        |\n");
    printf("| 4 - Sair                            |\n");
    printf("+-------------------------------------+\n");
    printf("| Resposta: ");
    scanf("%i",&switches.a);
    switch(switches.a)
    {
    case 1:
login:
        cls();
        printf("+---------------+\n");
        printf("| Menu do Login |\n");
        printf("+---------------+\n");
        printf("| Username: ");
        scanf("%s",&login.username);
        printf("| Password: ");
        scanf("%s",&login.password);
        sprintf(mysqlvalues.query1, "SELECT * FROM contas WHERE username = '%s' AND password = '%s'", login.username, login.password);
        if(mysql_query(con, mysqlvalues.query1))
        {
            printf("Query failed: %s\n", mysql_error(con));
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
        printf("+-------------------------------------------+\n");
        printf("| Bem-vindo, escolha uma das opções abaixo. |\n");
        printf("+-------------------------------------------+\n");
        printf("| 1 - Solicitar cartão                      |\n");
        printf("| 2 - Verificar dados/saldo conta bancária  |\n");
        printf("| 3 - Verificar dados cartão                |\n");
        printf("| 4 - Transferir dinheiro                   |\n");
        printf("| 5 - Logout                                |\n");
        printf("| 6 - Sair                                  |\n");
        printf("+-------------------------------------------+\n");
        printf("| Resposta: ");
        scanf("%i",&switches.b);
        switch(switches.b)
        {
        case 1:
            sprintf(mysqlvalues.query2, "SELECT * FROM `contas` WHERE `username` = '%s' AND `Cartao_solicitado` = 0;", login.username);
            if(mysql_query(con, mysqlvalues.query2))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf("O seu cartão já foi solicitado.\n");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
            printf("A solicitação foi feita com sucesso. Aguarde alguns segundos...\n");
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
            printf("| Titular                          |\n");
            printf("| %s\n", login.username);
            printf("|                                  |\n");
            printf("| Nº Cartão %i%i%i%i       |\n", cartao1, cartao2, cartao3, cartao4);
            printf("|                                  |\n");
            printf("| CVC %s          Validade 2025   |\n", cvvchar);
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
            printf("+----------------------------------+\n");
            printf("| Entidade                         |\n");
            printf("| %i%i                            |\n", entidade1, entidade2);
            printf("|                                  |\n");
            printf("| Referência %s             |\n", referencia1char);
            printf("|                                  |\n");
            printf("| Código %s                      |\n", codigocartaochar);
            printf("+----------------------------------+\n");
            sprintf(mysqlvalues.query3, "UPDATE `contas` SET Cartao_solicitado = 1, Cartao_codigo = '%s', Cartao_entidade = '%i%i' WHERE Username = '%s';", codigocartaochar, entidade1, entidade2, login.username);
            if(mysql_query(con, mysqlvalues.query3))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            sprintf(mysqlvalues.query4, "UPDATE `contas` SET Cartao_referencia = '%s', Cartao_numero = '%i%i%i%i', Cartao_ccv = '%s' WHERE Username = '%s';", referencia1char, cartao1, cartao2, cartao3, cartao4, cvvchar, login.username);
            if(mysql_query(con, mysqlvalues.query4))
            {
                printf("Query failed: %s\n", mysql_error(con));
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
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            MYSQL_RES *res = mysql_use_result(con);
            MYSQL_ROW row = mysql_fetch_row(res);
            if(row[0] == NULL)
            {
                erroexit();
            }
            printf("+---------------------------+\n");
            printf("|           IBAN            |\n");
            printf("+---------------------------+\n");
            printf("| %s |\n", row[3]);
            printf("+---------------------------+\n");
            printf("| %s$\n", row[2]);
            printf("+---------------------------+\n");
            mysql_free_result(res);
            pressanykey();
            goto menu;
            break;
        case 3:
            sprintf(mysqlvalues.query11, "SELECT * FROM `contas` WHERE `username` = '%s' AND `Cartao_solicitado` = 1;", login.username);
            if(mysql_query(con, mysqlvalues.query11))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            if(mysql_fetch_row(res) == NULL)
            {
                printf("O seu cartão ainda não foi solicitado.\n");
                sleep(3);
                goto menu;
            }
            mysql_free_result(res);
            sprintf(mysqlvalues.query8, "SELECT * FROM `contas` WHERE Username = '%s';", login.username);
            if(mysql_query(con, mysqlvalues.query8))
            {
                printf("Query failed: %s\n", mysql_error(con));
                exit(0);
            }
            res = mysql_use_result(con);
            row = mysql_fetch_row(res);
            if(row[0] == NULL)
            {
                erroexit();
            }
            printf("+----------------------------------+\n");
            printf("| Titular                          |\n");
            printf("| %s\n", row[0]);
            printf("|                                  |\n");
            printf("| Nº Cartão %s       |\n", row[8]);
            printf("|                                  |\n");
            printf("| CVC %s          Validade 2025   |\n", row[9]);
            printf("+----------------------------------+\n");
            printf("\n");
            printf("+----------------------------------+\n");
            printf("| Entidade                         |\n");
            printf("| %s                            |\n", row[6]);
            printf("|                                  |\n");
            printf("| Referência %s             |\n", row[7]);
            printf("|                                  |\n");
            printf("| Código %s                      |\n", row[5]);
            printf("+----------------------------------+\n");
            mysql_free_result(res);
            pressanykey();
            goto menu;
            break;
        case 4:
transferencias:
            cls();
            printf("+-------------------------------------------+\n");
            printf("| Bem-vindo, escolha uma das opções abaixo. |\n");
            printf("+-------------------------------------------+\n");
            printf("| 1 - Transferir por entidade e referencia  |\n");
            printf("| 2 - Transferir por IBan                   |\n");
            printf("| 3 - Menu anterior                         |\n");
            printf("| 4 - Sair                                  |\n");
            printf("+-------------------------------------------+\n");
            printf("| Resposta: ");
            scanf("%i", &switches.c);
            fflush(stdin);
            switch(switches.c)
            {
            case 1:
                cls();
                printf("Insira a entidade a que deseja fazer uma transferência. (5 números)\n");
                printf("Entidade: ");
                scanf("%i", &transferenciadata.entidade);

                printf("\nInsira a referência a que deseja fazer uma transferência. (9 números)\n");
                printf("Referência: ");
                scanf("%i", &transferenciadata.referencia);

                printf("\nInsira a quantidade em euros que deseja enviar.\n");
                printf("Quantidade: ");
                scanf("%i", &transferenciadata.money);
                if(transferenciadata.money < 1)
                {
                    printf("A quantidade tem de ser acima de 1.");
                    sleep(3);
                    goto transferencias;
                }
                sprintf(mysqlvalues.query9, "SELECT * FROM `contas` WHERE `Cartao_referencia` = '%i' AND `Cartao_entidade` = '%i';", transferenciadata.referencia, transferenciadata.entidade);
                if(mysql_query(con, mysqlvalues.query9))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                if(row == NULL)
                {
                    printf("O perfil inserido não foi encontrado. Tente novamente.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query12, "SELECT * FROM `contas` WHERE `Username` = '%s';", login.username);
                if(mysql_query(con, mysqlvalues.query12))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                int money = atoi(row[2]);
                if(transferenciadata.money > money)
                {
                    printf("Não tem saldo suficiente para efetuar esta operação.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query10, "UPDATE `contas` SET Saldo = Saldo + %i WHERE Cartao_entidade = '%i' AND Cartao_referencia = '%i';", transferenciadata.money, transferenciadata.entidade, transferenciadata.referencia);
                if(mysql_query(con, mysqlvalues.query10))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                sprintf(mysqlvalues.query13, "UPDATE `contas` SET Saldo = Saldo - %i WHERE Username = '%s';", transferenciadata.money, login.username);
                if(mysql_query(con, mysqlvalues.query13))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                printf("Dinheiro transferido com sucesso.\n");
                pressanykey();
                goto menu;
                break;
            case 2:
                printf("Insira o IBan para qual quer enviar.\n");
                printf("IBan: ");
                gets(transferenciadata.iban);
                printf("Insira a quantidade que deseja enviar.\n");
                printf("Quantidade: ");
                scanf("%i", &transferenciadata.money);
                fflush(stdin);
                sprintf(mysqlvalues.query14, "SELECT * FROM `contas` WHERE `IBan` = '%s';", transferenciadata.iban);
                if(mysql_query(con, mysqlvalues.query14))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                if(row == NULL)
                {
                    printf("O perfil inserido não foi encontrado. Tente novamente.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query15, "SELECT * FROM `contas` WHERE `Username` = '%s';", login.username);
                if(mysql_query(con, mysqlvalues.query15))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                res = mysql_use_result(con);
                row = mysql_fetch_row(res);
                money = atoi(row[2]);
                if(transferenciadata.money > money)
                {
                    printf("Não tem saldo suficiente para efetuar esta operação.\n");
                    sleep(3);
                    goto transferencias;
                }
                mysql_free_result(res);
                sprintf(mysqlvalues.query16, "UPDATE `contas` SET Saldo = Saldo + %i WHERE IBan = '%s';", transferenciadata.money, transferenciadata.iban);
                if(mysql_query(con, mysqlvalues.query16))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                sprintf(mysqlvalues.query17, "UPDATE `contas` SET Saldo = Saldo - %i WHERE Username = '%s';", transferenciadata.money, login.username);
                if(mysql_query(con, mysqlvalues.query17))
                {
                    printf("Query failed: %s\n", mysql_error(con));
                    exit(0);
                }
                printf("Dinheiro transferido com sucesso.\n");
                pressanykey();
                goto menu;
                break;
            case 3:
                goto menu;
                break;
            case 4:
                cls();
                printf("A sair do programa...");
                SetConsoleTitle("A sair do programa...");
                sleep(3);
                exit(0);
                break;
            default:
                erroexit();
            }
            break;
        case 5:
            printf("A terminar sessão...");
            sleep(3);
            goto principal;
            break;
        case 6:
            cls();
            printf("A sair do programa...");
            SetConsoleTitle("A sair do programa...");
            sleep(3);
            exit(0);
            break;
        default:
            erroexit();
        }
        break;
    case 2:
registomenu:
        cls();
        printf("+-----------------+\n");
        printf("| Menu do Registo |\n");
        printf("+-----------------+\n");
        printf("| Username: ");
        scanf("%s",&registo.username);
        printf("| Password: ");
        scanf("%s",&registo.password);
        sprintf(mysqlvalues.query7, "SELECT * FROM contas WHERE Username = '%s';", registo.username);
        if(mysql_query(con, mysqlvalues.query7))
        {
            printf("Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        res = mysql_use_result(con);
        if(mysql_fetch_row(res) != NULL)
        {
            printf("Username em utilização.\n");
            mysql_free_result(res);
            sleep(3);
            goto registomenu;
        }
        mysql_free_result(res);
        sprintf(mysqlvalues.query6, "INSERT INTO contas (username, password) VALUES ('%s', '%s');", registo.username, registo.password);
        if(mysql_query(con, mysqlvalues.query6))
        {
            printf("Query failed: %s\n", mysql_error(con));
            exit(0);
        }
        printf("O registo foi efetuado com sucesso. A voltar ao menu...");
        sleep(3);
        goto principal;
        break;
    case 3:
        cls();
        printf("+---------------+\n");
        printf("|  Programador  |\n");
        printf("+---------------+\n");
        printf("| António Matos |\n");
        printf("+---------------+\n");
        pressanykey();
        goto principal;
        break;
    case 4:
        cls();
        printf("A sair do programa...");
        SetConsoleTitle("A sair do programa...");
        sleep(3);
        exit(0);
        break;
    default:
        erroexit();
    }
}

