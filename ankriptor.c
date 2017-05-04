#include <stdio.h>
#include <string.h>

#define MAXLEN 128  //maximum file length

int main()
{
    void encryptor_a(FILE *ifp, FILE *ofp);
    void decryptor_a(FILE *ifp, FILE *ofp);

    char filename[MAXLEN];  // input file name
    char outname[MAXLEN+4]; // output file name
    char option[2];         // encrypt and decrypt options

    FILE *fp;  // pointer to input file
    FILE *op;  // pointer to output file

    printf("Enter Option: ");
    scanf("%s",option);
    while (strcmp(option,"de") && strcmp(option,"en")) {
    /* Excption handler. Checks for option validity */
        printf("Invalid Option! Enter again: ");
        scanf("%s",option);
    }

    if(!strcmp(option,"en")) {
    /* encript file */
        printf("Enter the name of the file to be encrypted: ");
        scanf("%s", filename);
        if ((fp = fopen(filename,"r")) != NULL) {
            strcpy(outname,filename);
            strcat(outname,".enk");   // Append file extension in
                                      // order to change the file name
            op = fopen(outname,"w");
            encryptor_a(fp,op);
        }
        else
            printf("Error occurs while opening %s\n",filename);

        fclose(fp);
        fclose(op);

        printf("Done!\n");
        return 0;
    }

    if(!strcmp(option,"de")) {
    /* decrypt file */
        printf("Enter the name of the file to be decrypted: ");
        scanf("%s", filename);
        if ((fp = fopen(filename,"r")) != NULL) {
            strcpy(outname,filename);
            strcat(outname,".dek");  // Append extension, same thing
            op = fopen(outname,"w");
            decryptor_a(fp,op);
        }
        else
            printf("Error occurs while opening %s\n",filename);
        fclose(fp);
        fclose(op);

        printf("Done!\n");
        return 0;
    }
}

void filecopy(FILE *ifp, FILE *ofp)
{
/* This is a template. Not to be used! */
    int c;
    while((c=getc(ifp)) != EOF)
        putc(c,ofp);
}

void encryptor_a(FILE *ifp, FILE *ofp)
{
/* Simple encryption method _a */
    int c;
    while((c=getc(ifp)) != EOF)
        putc(c+2,ofp);
}

void decryptor_a(FILE *ifp, FILE *ofp)
{
/* Decrypt file of method _a encryption */
    int c;
    while((c=getc(ifp)) != EOF)
        putc(c-2,ofp);
}
