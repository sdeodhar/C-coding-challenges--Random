Problem 2 
Pixel reading for camera dependent on 2 bits in DEV_REG
---------------------------------------------------------------------------------------------------------
#define BIT(x)     (1 << (x))
#define DEV_REG (*(unsigned char *)0x60000000)        //0x60000000 is address of register
#define COLOR      (*(unsigned char *)0x80000000)

//if RGB only have on/off values
#define RED            COLOR & BIT(0)
#define GREEN      (COLOR & BIT(1))>>1
#define BLUE            (COLOR & BIT(2))>>2

//if RGB have better resolution like e.g. 5,6,5 << they would have 3 separate 8 bit registers
/*
    #define COLOR_RED         volatile  (*(unsigned char *)0x80000000)
    #define COLOR_GREEN    volatile (*(unsigned char *)0x80000008)
    #define COLOR_BLUE        volatile (*(unsigned char *)0x8000004f)
*/

 /*    while(1) 
    {
        if((DEV_REG & BIT(0))
        {
            if((DEV_REG & BIT(1)){
                read_pixel();
            }
            else    break;
        }
        else
            //schedule other stuff
    }*/

//actually I would check this only on interrupt on input DEV_REG & BIT(0)
//so that the foreground of camera controller can perform other functions like taking user input for //display and auto-focus etc 

//Interrupt triggered on setting of DEV_REG & BIT(0)
interrupt reg_isr()
{
    if((DEV_REG & BIT(1))
{
                if( read_pixel_flag == 0)
                read_pixel_flag =1;
//if DEV_REG is a read/write type of register that needs to be //cleared after reading,

DEV_REG &= ~BIT(0);
DEV_REG &= ~BIT(1);

    }

}

//if interrupt is not available on any port, use timer interrupt and check the port
interrupt reg_isr()
{
    if((DEV_REG & BIT(0))
    {    if((DEV_REG & BIT(1))
{
                if( read_pixel_flag == 0)
                {
                    read_pixel_flag =1;
                }
//if DEV_REG is a read/write type of register that needs to be //cleared after reading,
DEV_REG &= ~BIT(0);
DEV_REG &= ~BIT(1);
}
    }
}

struct Pixel{
    char Red;
    char Green;
    char Blue;
};

Pixel Frame[100] ; //say the it is a 10 X 10 frame

void read_pixel_val( void )
{    char i;
for( i = 0 ; i < 100 ; i++ )
{
    Pixel[i].Red = RED;
    Pixel[i].Green = GREEN;
    Pixel[i].Blue = BLUE;
}
}

int main(void)
{
    if(read_pixel_flag)
    {
        read_pixel_val();
        read_pixel_flag = 0;
    }
}
_______________________________________________________________________
