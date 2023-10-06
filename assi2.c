#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

int a[1000], k = 0, kont=0, upd=-9999, a1[1000];

struct players{         //define our structure
    int id;
    char* name[20];
    char* pos[20];
    int age;
    int goals;
};

int add (struct players pl){
    char c, cc[20];
    for (int i = 0; i < k; i++){    //cheking if id is unique
        if (pl.id == a[i]){
            kont = 1;
        }
    }
    if (strcmp(pl.pos, "Goalkeeper") != 0 && strcmp(pl.pos, "Defender") != 0 && strcmp(pl.pos, "Midfielder") != 0 && strcmp(pl.pos, "Forward") != 0){
        kont = 2;
    }
    if (pl.goals < 0 || pl.goals > 1000){   //cheking if goals are correct
        kont = 3;
    }
    if (pl.age < 18 || pl.age > 100){       //cheking if age is not out of bounds
        kont = 5;
    }
    c=pl.name[0];
    if (c - 'A' < 0 || c - 'A' > 26){       //cheking if name starting with capital letter
        kont = 4;
    }
    if (strlen(pl.name) < 2 || strlen(pl.name) > 15){   //cheking if name's lenght  is not out of bounds
        kont = 6;
    }
    strcpy(cc,pl.name);
    for (int j = 1; j < strlen(pl.name); j++){          //cheking if all letters in name are lower case
        if (cc[j] - 'a' < 0 || cc[j] - 'a' > 26){
            kont = 7;
        }
    }
    return kont;
}
int up(struct players pl){
    char c, cc[20];
    for (int i = 0; i < k; i++){    //find position of updating percon in structure's massive
        if (pl.id == a[i]){
            upd = i;
        }
    }
    if (strcmp(pl.pos, "Goalkeeper") != 0 && strcmp(pl.pos, "Defender") != 0 && strcmp(pl.pos, "Midfielder") != 0 && strcmp(pl.pos, "Forward") != 0){
        kont = 2;
    }
    if (pl.goals < 0 || pl.goals > 1000){   //same as in func add
        kont = 3;
    }
    if (pl.age < 18 || pl.age > 100){
        kont = 4;
    }
    c=pl.name[0];
    if (c - 'A' < 0 || c - 'A' > 26){
        kont = 5;
    }
    if (strlen(pl.name) < 2 || strlen(pl.name) > 15){
        kont = 6;
    }
    strcpy(cc,pl.name);
    for (int j = 1; j < strlen(pl.name); j++){
        if (cc[j] - 'a' < 0 || cc[j] - 'a' > 26){
            kont = 7;
        }
    }
    return kont;
}
int main (){
    struct players n[1000], pl1, n1[1000];
    char s[20];
    int meow = 1, par, ind, z = -9999;
    
    FILE *in, *out;	
    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");
    
    while(meow){
        fscanf(in, "%s", s);
        if (strcmp(s,"Add") == 0){
            fscanf(in,"%d%s%s%d%d", &pl1.id, pl1.name, pl1.pos, &pl1.age, &pl1.goals);
            if (add(pl1) != 0){                 //cheking is data correct
                fprintf(out,"Invalid inputs");
                return 0;
            }
            else{
                n[k]=pl1;                       //adding new player to massive
                a[k]=pl1.id;
                k++;
            }
        }
        if (strcmp(s,"Update") == 0){
            fscanf(in,"%d%s%s%d%d", &pl1.id, pl1.name, pl1.pos, &pl1.age, &pl1.goals);
            if (up(pl1) != 0){                  //cheking is data correct
                fprintf(out,"Invalid inputs");
                return 0;
            }
            if (upd == -9999){
                fprintf(out,"Invalid inputs");
                return 0;
            }
            else{                               //updating information in massive
                n[upd]=pl1;
                a[upd]=pl1.id;
                upd=-9999;
            }
        }
        if (strcmp(s,"Search") == 0){
            fscanf(in,"%d", &z);                //scaning id
            if (z == -9999){
                fprintf(out,"Invalid inputs");
                return 0;
            }
            par=0;
            for (int i = 0; i < k; i++){
                if(a[i] == z){
                    par=1;
                    fprintf(out, "Found\n");
                }
            }
            if (par == 0){
                fprintf(out, "Not found\n");
            }
            z = -9999;
        }
        if (strcmp(s,"Delete") == 0){
            fscanf(in,"%d", &z);
            if (z == -9999){
                fprintf(out,"Invalid inputs");
                return 0;
            }
            par=0;
            ind=0;
            for (int i = 0; i < k; i++){
                if(a[i] == z){
                    par = 1;
                }
                else {                  //copying every element besides which we want to delete
                    a1[ind] = a[i];
                    n1[ind] = n[i];
                    ind++;
                }
            }
            if (par == 0){
                fprintf(out, "Impossible to delete\n");
            }
            else {                      //copying a1 to a, n1 to n and "erase" information from a1 and n1
                memcpy(a, a1,1000);
                memcpy(n, n1,100000);
                memset(a1, 0, 1000);
                memset(n1, 0, 10000);
                k--;
            }
            z = -9999;
        }
        if (strcmp(s,"Display") == 0){
            if (k == 0){
                fprintf(out,"Invalid inputs");
                return 0;
            }
            for (int i = 0; i < k; i++){
                fprintf(out,"ID: %d, Name: %s, Position: %s, Age: %d, Goals: %d\n", n[i].id, n[i].name, n[i].pos, n[i].age, n[i].goals);
            }
            meow=0;
        }
        if (strcmp(s,"Display") != 0 && strcmp(s,"Add") != 0 && strcmp(s,"Update") != 0 && strcmp(s,"Search") != 0 && strcmp(s,"Delete") != 0){
            fprintf(out,"Invalid inputs");
            return 0;
        }
    }
    return 0;
}

