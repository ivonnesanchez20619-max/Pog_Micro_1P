void main() {

    TRISD = 0x00;   // PORTD como salida
    PORTD = 0x00;

    while(1) {

        PORTD = 0x3F;   // 0
        Delay_ms(1000);

        PORTD = 0x06;   // 1
        Delay_ms(1000);

        PORTD = 0x5B;   // 2
        Delay_ms(1000);

        PORTD = 0x4F;   // 3
        Delay_ms(1000);

        PORTD = 0x66;   // 4
        Delay_ms(1000);

        PORTD = 0x6D;   // 5
        Delay_ms(1000);

        PORTD = 0x7D;   // 6
        Delay_ms(1000);

        PORTD = 0x07;   // 7
        Delay_ms(1000);

        PORTD = 0x7F;   // 8
        Delay_ms(1000);

        PORTD = 0x6F;   // 9
        Delay_ms(1000);

        PORTD = 0x77;   // A
        Delay_ms(1000);

        PORTD = 0x7C;   // b
        Delay_ms(1000);

        PORTD = 0x39;   // C
        Delay_ms(1000);

        PORTD = 0x5E;   // d
        Delay_ms(1000);

        PORTD = 0x79;   // E
        Delay_ms(1000);

        PORTD = 0x71;   // F
        Delay_ms(1000);
    }
}