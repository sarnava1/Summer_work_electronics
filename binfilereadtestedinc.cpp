#include<stdio.h>
//#include<bcm2835.h>
#include<stdbool.h> //#this is the library which has the data type boolean
#include<stdlib.h>
//#define OUTPIN 4 //this is board pin 7 
//#define DATA 17 //this is board pin 11
//we will use board pin 6 and 9 as ground

struct store{
    bool a;
};
    

int main(int argc, char **argv){
   
  //  if(!bcm2835_init())
  //      return 1;

   // bcm2835_gpio_fsel(OUTPIN, BCM2835_GPIO_FSEL_OUTP);
    
    //bcm2835_gpio_fsel(DATA, BCM2835_GPIO_FSEL_INPT);
    
    struct store s;
    FILE *fptr;
    
    if ((fptr = fopen("C:\\Users\\user\\Desktop\\data.bin","rb")) == NULL){ //eg is if ((fptr = fopen("C:\\program.bin","wb")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }
    
//    while(1){
//        fread(&s, sizeof(struct store), 1, fptr); 
//        bcm2835_gpio_write(OUTPIN, s.a);
//    }
     bool b;
     int i;
     for(i=0;i<=10000;i++){
     	fread(&s, sizeof(struct store), 1, fptr);
     	printf("%d\n",s.a);
	 }
    fclose(fptr);

return 0;

}
