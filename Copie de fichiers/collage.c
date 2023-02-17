#include <stdio.h>
int main()
{
    FILE *fp1, *fp2;
    char ch;

    // ouvrir le fichier en lecture
    fp1 = fopen("fich1.txt", "r");
    // ouvrir le fichier en écriture
    fp2 = fopen("fich2.txt", "w");


    while (ch != EOF){
      ch = fgetc(fp1);
      if (ch!=EOF) {
        fprintf(fp2, "%c", ch);
      }
    }

    // creat(char* )

    //
    // while((ch = getc(fp1)) != EOF)
    //     putc(ch, fp2);
    //
    // char c;
    // while((c=fgetc(fp2))!=EOF){
    //     printf("%c",fgetc(fp2));
    // }
    fclose(fp1);
    fclose(fp2);

    return 0;
}
