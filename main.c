
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <stdint.h>


const uint8_t CHARSET[][5] PROGMEM = {
	{ 0x00, 0x00, 0x00, 0x00, 0x00 }, // 20 space
	{ 0x00, 0x00, 0x5f, 0x00, 0x00 }, // 21 !
	{ 0x00, 0x07, 0x00, 0x07, 0x00 }, // 22 "
	{ 0x14, 0x7f, 0x14, 0x7f, 0x14 }, // 23 #
	{ 0x24, 0x2a, 0x7f, 0x2a, 0x12 }, // 24 $
	{ 0x23, 0x13, 0x08, 0x64, 0x62 }, // 25 %
	{ 0x36, 0x49, 0x55, 0x22, 0x50 }, // 26 &
	{ 0x00, 0x05, 0x03, 0x00, 0x00 }, // 27 '
	{ 0x00, 0x1c, 0x22, 0x41, 0x00 }, // 28 (
	{ 0x00, 0x41, 0x22, 0x1c, 0x00 }, // 29 )
	{ 0x14, 0x08, 0x3e, 0x08, 0x14 }, // 2a *
	{ 0x08, 0x08, 0x3e, 0x08, 0x08 }, // 2b +
	{ 0x00, 0x50, 0x30, 0x00, 0x00 }, // 2c ,
	{ 0x08, 0x08, 0x08, 0x08, 0x08 }, // 2d -
	{ 0x00, 0x60, 0x60, 0x00, 0x00 }, // 2e .
	{ 0x20, 0x10, 0x08, 0x04, 0x02 }, // 2f /
	{ 0x3e, 0x51, 0x49, 0x45, 0x3e }, // 30 0
	{ 0x00, 0x42, 0x7f, 0x40, 0x00 }, // 31 1
	{ 0x42, 0x61, 0x51, 0x49, 0x46 }, // 32 2
	{ 0x21, 0x41, 0x45, 0x4b, 0x31 }, // 33 3
	{ 0x18, 0x14, 0x12, 0x7f, 0x10 }, // 34 4
	{ 0x27, 0x45, 0x45, 0x45, 0x39 }, // 35 5
	{ 0x3c, 0x4a, 0x49, 0x49, 0x30 }, // 36 6
	{ 0x01, 0x71, 0x09, 0x05, 0x03 }, // 37 7
	{ 0x36, 0x49, 0x49, 0x49, 0x36 }, // 38 8
	{ 0x06, 0x49, 0x49, 0x29, 0x1e }, // 39 9
	{ 0x00, 0x36, 0x36, 0x00, 0x00 }, // 3a :
	{ 0x00, 0x56, 0x36, 0x00, 0x00 }, // 3b ;
	{ 0x08, 0x14, 0x22, 0x41, 0x00 }, // 3c <
	{ 0x14, 0x14, 0x14, 0x14, 0x14 }, // 3d =
	{ 0x00, 0x41, 0x22, 0x14, 0x08 }, // 3e >
	{ 0x02, 0x01, 0x51, 0x09, 0x06 }, // 3f ?
	{ 0x32, 0x49, 0x79, 0x41, 0x3e }, // 40 @
	{ 0x7e, 0x11, 0x11, 0x11, 0x7e }, // 41 A
	{ 0x7f, 0x49, 0x49, 0x49, 0x36 }, // 42 B
	{ 0x3e, 0x41, 0x41, 0x41, 0x22 }, // 43 C
	{ 0x7f, 0x41, 0x41, 0x22, 0x1c }, // 44 D
	{ 0x7f, 0x49, 0x49, 0x49, 0x41 }, // 45 E
	{ 0x7f, 0x09, 0x09, 0x09, 0x01 }, // 46 F
	{ 0x3e, 0x41, 0x49, 0x49, 0x7a }, // 47 G
	{ 0x7f, 0x08, 0x08, 0x08, 0x7f }, // 48 H
	{ 0x00, 0x41, 0x7f, 0x41, 0x00 }, // 49 I
	{ 0x20, 0x40, 0x41, 0x3f, 0x01 }, // 4a J
	{ 0x7f, 0x08, 0x14, 0x22, 0x41 }, // 4b K
	{ 0x7f, 0x40, 0x40, 0x40, 0x40 }, // 4c L
	{ 0x7f, 0x02, 0x0c, 0x02, 0x7f }, // 4d M
	{ 0x7f, 0x04, 0x08, 0x10, 0x7f }, // 4e N
	{ 0x3e, 0x41, 0x41, 0x41, 0x3e }, // 4f O
	{ 0x7f, 0x09, 0x09, 0x09, 0x06 }, // 50 P
	{ 0x3e, 0x41, 0x51, 0x21, 0x5e }, // 51 Q
	{ 0x7f, 0x09, 0x19, 0x29, 0x46 }, // 52 R
	{ 0x46, 0x49, 0x49, 0x49, 0x31 }, // 53 S
	{ 0x01, 0x01, 0x7f, 0x01, 0x01 }, // 54 T
	{ 0x3f, 0x40, 0x40, 0x40, 0x3f }, // 55 U
	{ 0x1f, 0x20, 0x40, 0x20, 0x1f }, // 56 V
	{ 0x3f, 0x40, 0x38, 0x40, 0x3f }, // 57 W
	{ 0x63, 0x14, 0x08, 0x14, 0x63 }, // 58 X
	{ 0x07, 0x08, 0x70, 0x08, 0x07 }, // 59 Y
	{ 0x61, 0x51, 0x49, 0x45, 0x43 }, // 5a Z
	{ 0x00, 0x7f, 0x41, 0x41, 0x00 }, // 5b [
	{ 0x02, 0x04, 0x08, 0x10, 0x20 }, // 5c backslash
	{ 0x00, 0x41, 0x41, 0x7f, 0x00 }, // 5d ]
	{ 0x04, 0x02, 0x01, 0x02, 0x04 }, // 5e ^
	{ 0x40, 0x40, 0x40, 0x40, 0x40 }, // 5f _
	{ 0x00, 0x01, 0x02, 0x04, 0x00 }, // 60 `
	{ 0x20, 0x54, 0x54, 0x54, 0x78 }, // 61 a
	{ 0x7f, 0x48, 0x44, 0x44, 0x38 }, // 62 b
	{ 0x38, 0x44, 0x44, 0x44, 0x20 }, // 63 c
	{ 0x38, 0x44, 0x44, 0x48, 0x7f }, // 64 d
	{ 0x38, 0x54, 0x54, 0x54, 0x18 }, // 65 e
	{ 0x08, 0x7e, 0x09, 0x01, 0x02 }, // 66 f
	{ 0x0c, 0x52, 0x52, 0x52, 0x3e }, // 67 g
	{ 0x7f, 0x08, 0x04, 0x04, 0x78 }, // 68 h
	{ 0x00, 0x44, 0x7d, 0x40, 0x00 }, // 69 i
	{ 0x20, 0x40, 0x44, 0x3d, 0x00 }, // 6a j
	{ 0x7f, 0x10, 0x28, 0x44, 0x00 }, // 6b k
	{ 0x00, 0x41, 0x7f, 0x40, 0x00 }, // 6c l
	{ 0x7c, 0x04, 0x18, 0x04, 0x78 }, // 6d m
	{ 0x7c, 0x08, 0x04, 0x04, 0x78 }, // 6e n
	{ 0x38, 0x44, 0x44, 0x44, 0x38 }, // 6f o
	{ 0x7c, 0x14, 0x14, 0x14, 0x08 }, // 70 p
	{ 0x08, 0x14, 0x14, 0x18, 0x7c }, // 71 q
	{ 0x7c, 0x08, 0x04, 0x04, 0x08 }, // 72 r
	{ 0x48, 0x54, 0x54, 0x54, 0x20 }, // 73 s
	{ 0x04, 0x3f, 0x44, 0x40, 0x20 }, // 74 t
	{ 0x3c, 0x40, 0x40, 0x20, 0x7c }, // 75 u
	{ 0x1c, 0x20, 0x40, 0x20, 0x1c }, // 76 v
	{ 0x3c, 0x40, 0x30, 0x40, 0x3c }, // 77 w
	{ 0x44, 0x28, 0x10, 0x28, 0x44 }, // 78 x
	{ 0x0c, 0x50, 0x50, 0x50, 0x3c }, // 79 y
	{ 0x44, 0x64, 0x54, 0x4c, 0x44 }, // 7a z
	{ 0x00, 0x08, 0x36, 0x41, 0x00 }, // 7b {
	{ 0x00, 0x00, 0x7f, 0x00, 0x00 }, // 7c |
	{ 0x00, 0x41, 0x36, 0x08, 0x00 }, // 7d }
	{ 0x10, 0x08, 0x08, 0x10, 0x08 }, // 7e ~
	{ 0x00, 0x00, 0x00, 0x00, 0x00 } // 7f
};
/* LCD's port */
#define PORT_LCD PORTB 
#define DDR_LCD DDRB   

/*
 * LCD's pins
 */
#define LCD_SCE PB1 
#define LCD_RST PB2 
#define LCD_DC PB3  
#define LCD_DIN PB4 
#define LCD_CLK PB5 

#define LCD_CONTRAST 0x40 

/*
 * Button pins
 */
#define Button_1 PD1 
#define Button_2 PD2 
#define Button_3 PD3 
#define LED PC1      

static struct {
    /* ekran */
    uint8_t screen[504]; // Tablica przechowuj¹ca piksele ekranu LCD

    /* pozycja kursora */
    uint8_t cursor_x; 
    uint8_t cursor_y; 

} nokia_lcd = {
    .cursor_x = 0, 
    .cursor_y = 0  
};

static void write(uint8_t bytes, uint8_t is_data)
{
    register uint8_t i;
    /* w³¹cz kontroler */
    PORT_LCD &= ~(1 << LCD_SCE); 

    /* wysy³amy dane */
    if (is_data)
        PORT_LCD |= (1 << LCD_DC); 
    /* wysy³amy komendy */
    else
        PORT_LCD &= ~(1 << LCD_DC); // Czyœci LCD_DC dla komend

    /* wysy³anie bajtów */
    for (i = 0; i < 8; i++) {
        /* Ustawienie pinu danych zgodnie ze stanem bajtu */
        if ((bytes >> (7-i)) & 0x01)
            PORT_LCD |= (1 << LCD_DIN); 
        else
            PORT_LCD &= ~(1 << LCD_DIN); 

        
        PORT_LCD |= (1 << LCD_CLK); // Wysy³a impuls zegara (1)
        PORT_LCD &= ~(1 << LCD_CLK); // Wysy³a impuls zegara (0)
    }

    /* Wy³¹cz kontroler */
    PORT_LCD |= (1 << LCD_SCE); 
}

static void write_cmd(uint8_t cmd)
{
    write(cmd, 0); // Wysy³a komendê (is_data = 0)
}

static void write_data(uint8_t data)
{
    write(data, 1); // Wysy³a dane (is_data = 1)
}

/*
 * Funkcje
 */

void nokia_lcd_init(void)
{
    register unsigned i;
    /* Ustawia piny jako wyjœcia */
    DDR_LCD |= (1 << LCD_SCE); 
    DDR_LCD |= (1 << LCD_RST); 
    DDR_LCD |= (1 << LCD_DC);  
    DDR_LCD |= (1 << LCD_DIN); 
    DDR_LCD |= (1 << LCD_CLK); 

    /* resetuje wyœwietlacz */
    PORT_LCD |= (1 << LCD_RST); 
    PORT_LCD |= (1 << LCD_SCE); 
    _delay_ms(10); 
    PORT_LCD &= ~(1 << LCD_RST); 
    _delay_ms(70); 
    PORT_LCD |= (1 << LCD_RST); 

    /* w³¹cza kontroler */
    PORT_LCD &= ~(1 << LCD_SCE); // Aktywuje kontroler LCD
    /*  -Rozszerzone tryby komend LCD- */
    write_cmd(0x21); 
    /* Tryb zniekszta³cenia LCD */
    write_cmd(0x13); 
    /* wspó³czynnik temperaturowy */
    write_cmd(0x06); 
    /* Domyœlne domyœlne napiêcie zasilania */
    write_cmd(0xC2); 
    /* Tryb standardowych komend, wy³¹czenie zasilania */
    write_cmd(0x20); 
    /* LCD w trybie normalnym */
    write_cmd(0x09); 

    /* Wyczyœæ RAM LCD */
    write_cmd(0x80); 
    write_cmd(LCD_CONTRAST); 
    for (i = 0; i < 504; i++) 
        write_data(0x00); // Wyczyœæ ka¿dy piksel

    /* Aktywuj LCD */
    write_cmd(0x08); // Wy³¹cz tryb wszystkich pikseli
    write_cmd(0x0C); // Ustaw tryb normalny
}

void nokia_lcd_clear(void)
{
    register unsigned i;
    /* kolumna i wierzsz na 0 */
    write_cmd(0x80); 
    write_cmd(0x40); 
    /*reset kursora */
    nokia_lcd.cursor_x = 0; 
    nokia_lcd.cursor_y = 0; 
    /* wyczyœæ wszystko */
    for(i = 0; i < 504; i++) 
        nokia_lcd.screen[i] = 0x00; 
}

void nokia_lcd_power(uint8_t on)
{
    write_cmd(on ? 0x20 : 0x24); // W³¹cz lub wy³¹cz zasilanie LCD
}

void nokia_lcd_set_pixel(uint8_t x, uint8_t y, uint8_t value)
{
    uint8_t *byte = &nokia_lcd.screen[y/8*84+x]; // Pobiera adres bajtu w buforze
    if (value)
        *byte |= (1 << (y % 8)); // Ustawia odpowiedni bit
    else
        *byte &= ~(1 << (y % 8)); // Czyœci odpowiedni bit
}

void nokia_lcd_write_char(char code, uint8_t scale)
{
    register uint8_t x, y;

    for (x = 0; x < 5*scale; x++) // Iteracja przez szerokoœæ znaku, szerokosc znaku 5 pikseli
        for (y = 0; y < 7*scale; y++) // Iteracja przez wysokoœæ znaku, wysokosc znaku 7pikseli
            if (pgm_read_byte(&CHARSET[code-32][x/scale]) & (1 << y/scale))
                nokia_lcd_set_pixel(nokia_lcd.cursor_x + x, nokia_lcd.cursor_y + y, 1); // Ustaw piksel
            else
                nokia_lcd_set_pixel(nokia_lcd.cursor_x + x, nokia_lcd.cursor_y + y, 0); // Wy³¹cz piksel

    nokia_lcd.cursor_x += 5*scale + 1; // Przesuñ kursor w prawo po napisaniu znaku, dodaje przestrzen miedzy znakami
    if (nokia_lcd.cursor_x >= 84) { // Jeœli kursor przekroczy³ szerokoœæ ekranu
        nokia_lcd.cursor_x = 0; //reset kursora
        nokia_lcd.cursor_y += 7*scale + 1; // Przesuñ kursor w dó³
    }
    if (nokia_lcd.cursor_y >= 48) { // Jeœli kursor przekroczy³ wysokoœæ ekranu
        nokia_lcd.cursor_x = 0; // Zresetuj pozycjê x
        nokia_lcd.cursor_y = 0; // Zresetuj pozycjê y
    }
}

void nokia_lcd_write_string(const char *str, uint8_t scale)
{
    while(*str) 
        nokia_lcd_write_char(*str++, scale); // Wpisuj znaki na ekran
}

void nokia_lcd_set_cursor(uint8_t x, uint8_t y)
{
    nokia_lcd.cursor_x = x; 
    nokia_lcd.cursor_y = y; 
}

void nokia_lcd_render(void)
{
    register unsigned i;
    /* Kolumna i wiersz na 0 */
    write_cmd(0x80); 
    write_cmd(0x40); 

    /* Wyœwietl bufor */
    for (i = 0; i < 504; i++) 
        write_data(nokia_lcd.screen[i]); // Wyœlij dane do LCD
}

void button_ports(void)
{
    // Konfiguracja przycisków jako wejœciowych z w³¹czonym rezystorem pull-up
    DDRD &= ~((1 << Button_1) | (1 << Button_2) | (1 << Button_3)); // Ustaw przyciski jako wejœcia
    PORTD |= (1 << Button_1) | (1 << Button_2) | (1 << Button_3); // W³¹cz rezystory pull-up

    // Konfiguracja diody LED jako wyjœciowej
    DDRC |= (1 << LED); 
}

int main(void)
{
    button_ports(); 
    nokia_lcd_init(); 
    nokia_lcd_clear(); 
    nokia_lcd_write_string("Zapal diode?", 1); 
    nokia_lcd_set_cursor(0, 10); 
    nokia_lcd_write_string("Tak/Nie", 1); 
    nokia_lcd_render(); 
    _delay_ms(1000); 

    while (1) {
        if (!(PIND & (1 << Button_1))) { 
            // Czekanie na zwolnienie przycisku (debouncing)
            _delay_ms(50);
            if (!(PIND & (1 << Button_1))) { 
	            PORTC |= (1 << LED); 

	            nokia_lcd_clear(); 
	            nokia_lcd_write_string("Dioda zapalona", 1); 
	            nokia_lcd_render(); 
	            _delay_ms(1000); 
            }
            }
            if (!(PIND & (1 << Button_2))) { 
	            // Czekanie na zwolnienie przycisku (debouncing)
	            _delay_ms(50); 
	            if (!(PIND & (1 << Button_2))) { 
		            PORTC &= ~(1 << LED); 

		            nokia_lcd_clear(); 
		            nokia_lcd_write_string("Dioda zgaszona", 1); 
		            nokia_lcd_render(); 
		            _delay_ms(1000); 
	            }
            }
            if (!(PIND & (1 << Button_3))) {
	            // Czekanie na zwolnienie przycisku (debouncing)
	            _delay_ms(50); 
	            if (!(PIND & (1 << Button_3))) { 
		            nokia_lcd_clear(); 
		            nokia_lcd_write_string("Zapal diode?", 1); 
		            nokia_lcd_set_cursor(0, 10); 
		            nokia_lcd_write_string("Tak/Nie", 1); 
		            nokia_lcd_render(); 
		            _delay_ms(1000); 
	            }
            }

            _delay_ms(50); // OpóŸnienie 50 ms
            }
            }




