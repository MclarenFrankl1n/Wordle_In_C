#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <stdlib.h>

void pick_word(char Word_List[][5], char *random_word, int word_count);                               /* Get a random word from 200 words Example list of words */
void promp_input();
int check_valid(char *input, char list[][5], int count);
void check_ans(char *word, char *input);


int main(){
    FILE *fp;
    char str[7];
    int line=0, q=300, i, j=1, check, word_count=200, choice;
    char guess[6], Word_List[200][5], random_word[5];

    do{
        printf("\t\tWORDLE\n1. New game\n2. Help\n3. Exit\n\nEnter number indicated to choose : ");
        scanf("%d", &choice);
        if(choice==1){
            fp = fopen("Wordle.txt", "r");
            
            if(fp == NULL) {
            printf("Cannot open file.\n");
            exit(1);}

            while(fgets(str, 80, fp)!=NULL) {          //this segment of codes will copy a set of words from the txt file into an array 
                if(line!=q+1){
                strncpy(Word_List[line], str, 5);
                line++;
                }
            }
            for(i=0; i<200; i++)    printf("%s", Word_List[i]);

            fclose(fp);

            pick_word(Word_List, random_word, word_count);

            printf("Please enter your guess : ");
            do
            {
                printf("Guess %d : ", j);
                gets(guess);
                for(i=0; i<5; i++){
                guess[i]=toupper(guess[i]);
                }
                guess[6]='\0';
                check=check_valid(guess, Word_List, word_count);
                while(check!=0){
                    printf("***Guess invalid***\nGuess %d : ", j);
                    gets(guess);
                    check=check_valid(guess, Word_List, word_count);
                }
                check_ans(random_word, guess);
                j++;
            }while(j<7); 

            printf("%.5s", random_word);  

            // delete word from list

        }
        else if(choice==2){
            printf("\n------- HOW TO PLAY WORDLE -------\n1. A random 5-letter word will be choosen from the list.");
            printf("\n2. Player are required to enter a guess of 6 times.");
            printf("\n3. The guess will be invalid if the guess is as followed\n\ta. Consists of numbers or symbols\n\tb. consists of a word that is not a 5-letter word\n\tc. A 5-letter word that does not appear in the list of valid words\n\td. A 5-letter word that has letters apear more than once (etc. \"refer\"");
            printf("\n4. Green colour will appear if letter is correct & in correct position\n    Yellow if letter is correct but in wrong position\n    Dark grey if it is not in the word\n");
            printf("\nReturn to start menu?\n1. Yes\n2. No\n");
            scanf("%d", &choice);
        }
    }while (choice!=3);

}

void pick_word(char Word_List[][5], char *random_word, int word_count) 
{
    int q;
    srand(time(NULL));
    q=rand() % word_count;
    strncpy(random_word, Word_List[q], 5); 
}


int check_valid(char *input, char list[][5], int count){
    int i=0, j;
    for(i; i<count; i++){
        j=strncmp(list[i], input,5);
        if(j==0){
            return(j);
        }
    }
}

void check_ans(char *word, char *input){       
    int i;
    for(i=0; i<5; i++){
        switch (i){
            case 0:
                if(input[i]==word[0] || input[i]==word[1] || input[i]==word[2] || input[i]==word[3] || input[i]==word[4]){
                    printf("#");
                    //YELLOW color
                }
            case 1:
                if(input[i]==word[0] || input[i]==word[1] || input[i]==word[2] || input[i]==word[3] || input[i]==word[4]){
                    printf("#");
                    //YELLOW color
                }
            case 2:
                if(input[i]==word[0] || input[i]==word[1] || input[i]==word[2] || input[i]==word[3] || input[i]==word[4]){
                    printf("#");
                    //YELLOW color
                }
            case 3:
                if(input[i]==word[0] || input[i]==word[1] || input[i]==word[2] || input[i]==word[3] || input[i]==word[4]){
                    printf("#");
                    //YELLOW color
                }
            case 4:
                if(input[i]==word[0] || input[i]==word[1] || input[i]==word[2] || input[i]==word[3] || input[i]==word[4]){
                    printf("#");
                    //YELLOW color
                }
        }
        if(input[i]==word[i]){
            printf("*");
            //GREEN color
        }
        else if (input[i]!=word[0] || input[i]!=word[1] || input[i]!=word[2] || input[i]!=word[3] || input[i]!=word[4]) 
            printf("-");
    }
}

