#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int get_random_num()
{
    return rand()%255;
}
void rng_setup()
{
    srand(time(NULL));
}
int cbin_to_int(char* bin_arr)
{
    int power = 7;
    int res = 0;
    for(bin_arr; *bin_arr != '\0'; bin_arr++, power--){
        if(*bin_arr == '1')
            res+=(int)pow(2,power);
    }
    return res;
}

int main()
{
    char answer;
    printf("Start Game? [y/n]\n");
    rng_setup();
    int question;
    char response[9];
    while((answer=getchar()) == 'Y' || answer == 'y'){
        question = get_random_num();
        printf("Number: %d\n", question);
        scanf("%s", response);
        getchar(); //flush the new character
        if(cbin_to_int(response) == question){
            printf("You got it right!\n");
        }else{
            printf("You got it wrong...\n");
        }
        printf("Play again? [y/n]\n");
    }
    

}
