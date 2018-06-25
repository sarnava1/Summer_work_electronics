#include<stdio.h>
//#include<bcm2835.h>
#include<stdbool.h> //#this is the library which has the data type boolean
#include<stdlib.h>
//#define CLOCK 4 //this is board pin 7 
//#define DATA 17 //this is board pin 11
//we will use board pin 6 and 9 as ground

struct store{
    bool a;
};
    

int main(int argc, char **argv){
   
    //if(!bcm2835_init())
    //    return 1;

    //bcm2835_gpio_fsel(CLOCK, BCM2835_GPIO_FSEL_INPT);
    
    //bcm2835_gpio_fsel(DATA, BCM2835_GPIO_FSEL_INPT);
    
    struct store s;
    FILE *fptr;
    
    if ((fptr = fopen("C:\\Users\\user\\Desktop\\data.bin","wb")) == NULL){ //eg is if ((fptr = fopen("C:\\program.bin","wb")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
    
    //while(1){
        //if(bcm2835_gpio_lev(CLOCK)==HIGH){
          //  s.a=bcm2835_gpio_lev(DATA);
            //fwrite(&s, sizeof(struct store), 1, fptr);            
      //      }
    //}
    int i;
    for(i=0;i<=1000;i++){
    	if(i%2==0){
    		s.a=0;
    		fwrite(&s, sizeof(struct store), 1, fptr);
		}else{
			s.a=1;
			fwrite(&s, sizeof(struct store), 1, fptr);
		}
	}

    fclose(fptr);

return 0;

}
