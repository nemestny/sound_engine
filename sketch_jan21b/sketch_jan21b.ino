int i_0=0;
// int i_1=0;
int j=0;
int x=0;
int OK=0;
int level = 1;
int level_min = 1;   
int level_max = 300;
int lost = 500;
int lost_count = 0;
int lost_min = 2;
int lost_max = 500;
unsigned long leveltime;
int input = A0; // вход для управления

int count = 507;
int sinPWM_0[]={0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4,
 5, 5, 5, 5, 5, 5, 5, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 8, 9, 9, 9, 9, 9, 9,
 9, 9, 10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 13, 13,
 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 17, 17, 17, 17, 17, 17, 17, 17, 17,
 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19, 19, 19, 19, 19, 19, 19,
 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21,
 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 19, 19, 20, 20, 20, 20, 20, 20,
 20, 20, 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18, 17, 17, 17, 17,
 17, 17, 17, 17, 17, 16, 16, 16, 16, 16, 16, 16, 16, 15, 15, 15, 15, 15, 15, 15, 15, 14, 14, 14, 14,
 14, 14, 14, 15, 14, 15, 14, 14, 14, 14, 14, 14, 14, 14, 14, 15, 15, 15, 15, 15, 15, 15, 15, 16, 16,
 16, 16, 16, 16, 16, 16, 17, 17, 17, 17, 17, 17, 17, 17, 17, 18, 18, 18, 18, 18, 18, 18, 18, 18, 19,
 19, 19, 19, 19, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20, 20, 19, 19, 19, 19, 20, 20, 20, 20, 20, 20,
 20, 20, 20, 20, 20, 20, 21, 21, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 21, 21, 21,
 21, 21, 21, 21, 21, 21, 21, 21, 21, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
 20, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 18, 18, 18, 18, 18, 18, 18, 18, 18,
 18, 18, 18, 18, 18, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 17, 16, 16, 15, 15, 15, 15, 15,
 15, 15, 15, 15, 15, 14, 14, 14, 14, 14, 14, 13, 13, 13, 13, 13, 13, 12, 12, 12, 12, 12, 12, 11, 11,
 11, 11, 11, 11, 10, 10, 10, 10, 10, 9, 9, 9, 9, 9, 9, 8, 8, 8, 7, 7, 7, 7, 7, 7, 7,
 7, 6, 5, 5, 5, 5, 5, 5, 5, 5, 5, 4, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 1, 1,
 1, 1, 0, 0, 0, 0, 0}; 

void setup() {
Serial.begin(9600);

pinMode(9, OUTPUT);
pinMode(10,OUTPUT);

cli();// stop interrupts
TCCR1A=0;//reset the value
TCCR1B=0;//reset the value
TCNT1=0;//reset the value
//0b allow me to write bits in binary
TCCR1A=0b10100001;//phase correct pwm mode on 8 bits
TCCR1B=0b00000001; //no prescaler
TCCR0A=0b1000010;//WGM01 bit is 1 to put timer 0 in ctc mode
TCCR0B=0;//reset the value
TCNT0=0;//reset the value

OCR0A=63;// compare match value 63
TCCR0B=0b00000010; // prescaler 8

TIMSK0 |=(1 << OCIE0A);

sei();//enable interrupts
}
ISR(TIMER0_COMPA_vect){// interrupt when timer 0 match with OCR0A value
if(i_0>count && OK==0){// final value from vector for pin 9
i_0=0;// go to first value of vector
lost_count =0;
//OK=1;//enable pin 10
}
if(i_0>count && OK==1){// final value from vector for pin 10
i_0=0;//go to firs value of vector
//OK=0;//enable pin 9
}
// if(i_1>105){
//  i_1 = 0;
//}

x=(sinPWM_0[i_0]*level)/300;// x take the value from vector corresponding to position i(i is zero indexed)

//i_0=i_0+1;// go to the next position
lost_count++;
if(lost_count>lost){
  i_0=i_0+2;
//  lost_count = 0;
  } else {
  i_0=i_0+1;  
    }
j=j+1;
if(OK==0){
OCR1B=0;//make pin 10 0
OCR1A=x;//enable pin 9 to corresponding duty cycle
}
if(OK==1){
OCR1A=0;//make pin 9 0
OCR1B=x;//enable pin 10 to corresponding duty cycle
}
//level_time = millis();
}
void loop() {

  if (j > 333) {
    if (digitalRead(input)==HIGH){
      level++; //увеличение громкости
      lost--; //уменьшение интервала пропуска значений
      if (level > level_max) {
          level = level_max;
        }
      if (lost < lost_min) {
          lost = lost_min;
        }
    } else {
      level--; //уменьшение громкости
      lost++;
      if (level < level_min) {
          level = level_min;
        }
      if (lost > lost_max) {
          lost = lost_max;
        }
      }
      j = 0;
 //   delay(50);
    }
   
}
