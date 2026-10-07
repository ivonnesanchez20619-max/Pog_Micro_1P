void main() {

    TRISB = 0x00;
    PORTB = 0x00;

    while(1) {
        PORTB.F0 = 1;
    }
}
