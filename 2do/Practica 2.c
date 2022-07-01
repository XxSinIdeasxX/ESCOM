#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

int esVocal(char letra){
    return letra=='A'||letra=='E'||letra=='I'||letra=='O'||letra=='U';
}

void LeeCad(char cad[]){
    fflush(stdin);
    int i;
	for(i=0;(cad[i]=toupper(getchar()))!='\n';i++);
	cad[i]='\0';
}

void LeeNom(char nom[], char cod[]){
    char nombre[256],random[]="1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i,j,l,espacios;
    printf("\n\t\tIntroduzca sus datos\n\nNombre completo comenzando por los nombres (sin acentos): ");
    LeeCad(nombre);
    l=strlen(nombre);
    nom[3]=nombre[0];
    nom[4]='\0';
    srand(time(NULL));
    cod[3]=random[rand()%37];
    cod[4]=random[rand()%37];
    cod[5]='\0';
    j=1;
    while(1){
        if (!esVocal(nombre[j])){
            cod[2]=nombre[j];
            break;
        }
        j++;
    }
    for(i=l-1,espacios=0;espacios<2;i--){
        if(nombre[i]==' '){
            if (espacios==0){       //Segundo apellido
                nom[2]=nombre[i+1];
                j=i+2;
                while(1){
                    if (!esVocal(nombre[j])){
                        cod[1]=nombre[j];
                        break;
                    }
                    j++;
                }
            }else{                  //Primer apellido
                nom[0]=nombre[i+1];
                j=i+2;
                while(1){
                    if (esVocal(nombre[j])){
                        nom[1]=nombre[j];
                        break;
                    }
                    j++;
                }j=i+2;
                while(1){
                    if (!esVocal(nombre[j])){
                        cod[0]=nombre[j];
                        break;
                    }
                    j++;
                }
            }
            espacios++;
        }
    }
}

void LeeFech(char fech[]){
    char fecha[16];
    printf("Fecha de nacimiento (DD/MM/YYYY): ");
    LeeCad(fecha);
    //fech[YYMMDD\0] fecha[DD/MM/YYYY\0]
    fech[0]=fecha[8];
    fech[1]=fecha[9];
    fech[2]=fecha[3];
    fech[3]=fecha[4];
    fech[4]=fecha[0];
    fech[5]=fecha[1];
    fech[6]='\0';
}

void LeeEnt(char ent[]){
    char entidad[32];
    while(1){
        printf("Entidad federativa (sin acentos): ");
        LeeCad(entidad);
        ent[0]=entidad[0];
        //Comparacion entre cadenas
        if (strcmp(entidad,"AGUASCALIENTES")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"BAJA CALIFORNIA")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"BAJA CALIFORNIA SUR")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"CAMPECHE")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"COAHUILA")==0){ent[1]='L';break;
        }else if(strcmp(entidad,"COLIMA")==0){ent[1]='M';break;
        }else if(strcmp(entidad,"CHIAPAS")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"CHIHUAHUA")==0){ent[1]='H';break;
        }else if(strcmp(entidad,"DISTRITO FEDERAL")==0){ent[1]='F';break;
        }else if(strcmp(entidad,"DURANGO")==0){ent[1]='G';break;
        }else if(strcmp(entidad,"GUANAJUATO")==0){ent[1]='T';break;
        }else if(strcmp(entidad,"GUERRERO")==0){ent[1]='R';break;
        }else if(strcmp(entidad,"HIDALGO")==0){ent[1]='G';break;
        }else if(strcmp(entidad,"JALISCO")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"MEXICO")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"MICHOACAN")==0){ent[1]='N';break;
        }else if(strcmp(entidad,"MORELOS")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"NAYARIT")==0){ent[1]='T';break;
        }else if(strcmp(entidad,"NUEVO LEON")==0){ent[1]='L';break;
        }else if(strcmp(entidad,"OAXACA")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"PUEBLA")==0){ent[1]='L';break;
        }else if(strcmp(entidad,"QUERETARO")==0){ent[1]='T';break;
        }else if(strcmp(entidad,"QUINTANA ROO")==0){ent[1]='R';break;
        }else if(strcmp(entidad,"SAN LUIS POTOSI")==0){ent[1]='P';break;
        }else if(strcmp(entidad,"SINALOA")==0){ent[1]='L';break;
        }else if(strcmp(entidad,"SONORA")==0){ent[1]='R';break;
        }else if(strcmp(entidad,"TABASCO")==0){ent[1]='C';break;
        }else if(strcmp(entidad,"TAMAULIPAS")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"TLAXCALA")==0){ent[1]='L';break;
        }else if(strcmp(entidad,"VERACRUZ")==0){ent[1]='Z';break;
        }else if(strcmp(entidad,"YUCATAN")==0){ent[1]='N';break;
        }else if(strcmp(entidad,"ZACATECAS")==0){ent[1]='S';break;
        }else if(strcmp(entidad,"NACIDO EN EL EXTRANJERO")==0){ent[1]='E';break;
        }else{printf("\n> La entidad introducida no es válida, por favor intentelo de nuevo\n\n");}
    }ent[2]='\0';
}

int main(){
    char nombre[5], fecha[7], sexo[2], entidad[3],codigo[6];   
    LeeNom(nombre,codigo);
    LeeFech(fecha);
    printf("Sexo H / M: ");
    LeeCad(sexo);
    LeeEnt(entidad);
    printf("\nCURP: %s%s%s%s%s",nombre,fecha,sexo,entidad,codigo);
    return 0;
}