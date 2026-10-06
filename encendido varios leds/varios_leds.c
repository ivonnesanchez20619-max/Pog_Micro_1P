void main() {
    TRISB = 0x00;
    PORTB = 0x00;

    while(1) {
        PORTB = 0x01;   // RB0
        Delay_ms(500);

        PORTB = 0x02;   // RB1
        Delay_ms(500);

        PORTB = 0x04;   // RB2
        Delay_ms(500);

        PORTB = 0x08;   // RB3
        Delay_ms(500);
    }
}