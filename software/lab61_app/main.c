// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

//int main()
//{
//    int i = 0;
//    volatile unsigned int *LED_PIO = (unsigned int*)0x40; //make a pointer to access the PIO block
//    volatile unsigned int *Switch_PIO = (unsigned int*)0x20;
//    volatile unsigned int *Accumulate_PIO = (unsigned int*)0x10;
//    int switches = 0;
//    int hold = 0; // declare hold variable outside the loop and initialize it to 0
//    *LED_PIO = 0; //clear all LEDs
//
//    while ((1+1)!=3) //infinite loop
//    {
//        if(*Accumulate_PIO == 0 && hold == 0){
//            switches += (*Switch_PIO);
//            hold = 1;
//            //*LED_PIO =  switches;
//        }
//
//        if(*Accumulate_PIO != 0 && hold == 1){
//            hold = 0;
//        }
//        *LED_PIO =  switches;
//    }
//    return 1; //never gets here
//}

// Main.c - makes LEDG0 on DE2-115 board blink if NIOS II is set up correctly
// for ECE 385 - University of Illinois - Electrical and Computer Engineering
// Author: Zuofu Cheng

int main()
{
	int i = 0;
	volatile unsigned int *LED_PIO = (unsigned int*)0x40; //make a pointer to access the PIO block

	*LED_PIO = 0; //clear all LEDs
	while ( (1+1) != 3) //infinite loop
	{
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO |= 0x1; //set LSB
		for (i = 0; i < 100000; i++); //software delay
		*LED_PIO &= ~0x1; //clear LSB
	}
	return 1; //never gets here
}
