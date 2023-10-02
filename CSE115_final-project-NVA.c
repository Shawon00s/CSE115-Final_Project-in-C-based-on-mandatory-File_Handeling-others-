#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void addRecord();
void alldata();
void searchRecord();

struct Nongor
{
    char product_type[20];
    char brand_name[20];
    char model_name[5];
    float price;
};

struct Nongor info;

int main()
{

    char filename[50];
    FILE *fp;
    int choice;
    printf("\t\t\t----------\n");
    printf("\t\t\t  Nongor\n");
    printf("\t\t\t----------\n");
    printf("\t 30/23 Baruthkhana,Zindabazar,Sylhet-3100\n");
    printf("\n\n");

    printf("\n\n\t\t**************************\n");
    printf("\t\t\t MAIN MENU \n");
    printf("\n\t\t**************************\n");
    printf("\n1.Add new Product ");
    printf("\n2.View all data ");
    printf("\n3.Search ");
    printf("\n4.Exit ");
    printf("\n\t\tEnter your choice : ");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        addRecord();
        break;

    case 2:
        alldata();
        break;

    case 3:
        searchRecord();
        break;

    case 4:
        exit(0);
        break;

    default:
        printf("wrong choice!!!\b");
        break;
    }
    void addRecord()
    {

        char another;
        FILE *fp;


        do
        {
            printf("\t\t\t\t=======Add Products=======\n\n\n");
            fp=fopen("Gadget_shop.txt","a");

            printf("\n\t\t\tEnter Product Type     : ");
            scanf("%s",info.product_type);
            printf("\n\t\t\tEnter brand Name     : ");
            scanf("%s",info.brand_name);
            printf("\n\t\t\tEnter price    : ");
            scanf("%f",&info.price);


            printf("\n\t\t\t______________________________\n");

            if(fp==NULL)
            {
                fprintf(stderr,"can't open file");
            }
            else
            {
                printf("\t\t\tRecord stored successfuly\n");
            }
            fwrite(&info, sizeof(struct Nongor), 1, fp);
            fclose(fp);

            printf("\t\t\tYou want to add another record?(y/n) : ");


            scanf("%s",&another);


        }
        while(another=='y'||another=='Y');
    }

    void alldata()
    {

        char another;
        FILE *fp;

        fp=fopen("Gadget_shop.txt","r");

        printf("\t\t\t\t=======ALL DATA =======\n\n\n");

        if(fp==NULL)
        {

            fprintf(stderr,"can't open file\n");
            exit(0);
        }
        else
        {
            printf("\t\t\t\tAll PRODUCTS :\n");
            printf("\t\t\t\t___________\n\n");
        }

        while(fread(&info,sizeof(struct Nongor),1,fp))
        {
            printf("\n\t\t\t\t Product Type     : %s",info.product_type);
            printf("\n\t\t\t\t Brand Name       : %s",info.brand_name);
            printf("\n\t\t\t\t price            : %.2f",info.price);

            printf("\n\t\t\t\t ________________________________\n");

        }
        fclose(fp);

    }

    void searchRecord()
    {

        FILE *fp;
        int found=0;
        char model[30];
        char brand[30];
        char another;

        do
        {

            fp=fopen("Gadget_shop.txt","r");
            printf("\t\t\t\t=======SEARCH PRODUCT RECORD=======\n\n\n");
            printf("\t\t\tEnter Brand name : ");

            scanf("%s",brand);

            printf("\t\t\tEnter Model name : ");

            scanf("%s",model);



            while(fread(&info,sizeof(info),1,fp)>0)
            {

                if(strcmp(info.model_name,model)==0 && strcmp(info.brand_name,brand)==0)
                {

                    found=1;
                    printf("\n\t\t\t\t Product Type     : %s",info.product_type);
                    printf("\n\t\t\t\t Brand Name       : %s",info.brand_name);
                    printf("\n\t\t\t\t Model name       : %s",info.model_name);
                    printf("\n\t\t\t\t Price            : %.2f",info.price);


                    printf("\n\t\t\t\t ________________________________\n");


                }

            }

            if(found==0)
            {
                printf("\n\t\t\tProduct not found\n");
            }

            fclose(fp);
            printf("continue?(y/n) ");
            scanf("%s",&another);

        }
        while(another=='y'||another=='Y');

    }
}
