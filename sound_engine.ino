int i_0=0;
// int i_1=0;
int j=0;
int x=0;
int OK=0;
int level = 1;
int level_min = 1;   
int level_max = 200;
int level_rand = 0;
int lost = 500;
int lost_count = 0;
int lost_min = 10;
int lost_max = 500;
unsigned long leveltime;
int input = A0; // вход для управления

int count = 730;
int sinPWM_0[]={0, 1, 2, 3, 5, 6, 7, 9, 10, 11, 12, 14, 15, 16, 17, 19, 20, 21, 23, 24, 25, 26, 28, 29, 30,
 31, 32, 34, 35, 36, 37, 38, 40, 41, 42, 43, 44, 45, 47, 48, 49, 50, 51, 52, 53, 54, 55, 58, 59, 60,
 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 70, 71, 72, 73, 74, 75, 76, 77, 77, 78, 79, 80, 81, 81, 82,
 83, 84, 84, 85, 86, 86, 87, 88, 88, 89, 90, 90, 91, 91, 92, 92, 93, 93, 94, 94, 95, 96, 96, 97, 97,
 98, 98, 98, 99, 99, 99, 99, 100, 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
 101, 101, 101, 101, 101, 101, 101, 101, 101, 100, 100, 100, 100, 99, 99, 99, 99, 98, 98, 98, 97, 97, 96, 96, 96,
 96, 96, 95, 95, 94, 94, 93, 93, 92, 92, 91, 90, 90, 89, 88, 88, 87, 86, 86, 85, 84, 83, 83, 82, 81,
 80, 79, 79, 78, 77, 76, 75, 74, 73, 72, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 58, 57,
 56, 55, 54, 53, 52, 51, 50, 48, 47, 46, 45, 44, 43, 41, 40, 39, 39, 38, 36, 35, 34, 33, 32, 30, 29,
 28, 27, 25, 24, 23, 21, 20, 19, 18, 16, 15, 14, 13, 11, 10, 9, 7, 6, 5, 4, 3, 4, 5, 6, 7,
 9, 10, 11, 13, 14, 15, 16, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30, 32, 33, 34, 35, 36, 38, 39,
 40, 41, 42, 44, 45, 46, 47, 48, 49, 51, 52, 53, 54, 55, 56, 57, 58, 59, 61, 62, 63, 64, 65, 66, 67,
 68, 69, 70, 71, 72, 73, 73, 74, 75, 76, 77, 78, 79, 80, 80, 81, 82, 83, 84, 84, 85, 86, 87, 87, 88,
 89, 89, 90, 91, 91, 92, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 98, 99, 99, 100, 100, 100, 101,
 101, 101, 101, 102, 102, 102, 102, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103, 103,
 103, 103, 103, 103, 103, 102, 102, 102, 102, 101, 101, 101, 101, 100, 100, 100, 99, 99, 98, 98, 98, 97, 97, 96, 96,
 95, 95, 94, 94, 93, 93, 92, 91, 91, 90, 89, 89, 88, 87, 87, 86, 85, 84, 84, 83, 82, 81, 80, 80, 79,
 78, 77, 76, 75, 74, 73, 73, 72, 71, 70, 69, 68, 67, 66, 65, 64, 63, 62, 61, 59, 58, 57, 56, 55, 54,
 53, 52, 51, 49, 48, 47, 46, 45, 44, 42, 41, 40, 39, 38, 36, 35, 34, 33, 32, 30, 29, 28, 27, 25, 24,
 23, 21, 20, 19, 18, 16, 15, 14, 13, 11, 10, 9, 7, 6, 5, 4, 3, 4, 5, 6, 7, 9, 10, 11, 13,
 14, 15, 16, 18, 19, 20, 21, 23, 24, 25, 27, 28, 29, 30, 32, 32, 33, 34, 35, 37, 38, 39, 40, 41, 43,
 44, 45, 46, 47, 48, 50, 51, 52, 53, 54, 55, 56, 57, 58, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70,
 71, 72, 72, 73, 74, 75, 76, 77, 78, 79, 79, 80, 81, 82, 83, 83, 84, 85, 86, 86, 87, 88, 88, 89, 90,
 90, 91, 92, 92, 93, 93, 93, 93, 94, 94, 95, 95, 96, 96, 96, 97, 97, 98, 98, 98, 99, 99, 99, 99, 100,
 100, 100, 100, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101, 101,
 101, 100, 100, 100, 100, 99, 99, 99, 99, 98, 97, 97, 96, 96, 95, 95, 95, 94, 94, 93, 93, 92, 92, 91, 91,
 90, 90, 89, 88, 88, 87, 86, 86, 85, 84, 84, 83, 82, 81, 81, 80, 79, 78, 77, 77, 76, 75, 74, 73, 72,
 71, 70, 70, 69, 68, 67, 66, 65, 64, 62, 61, 60, 59, 58, 57, 55, 54, 53, 52, 51, 50, 49, 48, 47, 45,
 44, 43, 42, 41, 40, 38, 37, 36, 35, 34, 32, 31, 30, 29, 28, 26, 25, 24, 23, 21, 20, 19, 17, 16, 15,
 14, 12, 11, 10, 9}; 

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
level_rand = random(level/10);
//OK=1;//enable pin 10
}
if(i_0>count && OK==1){// final value from vector for pin 10
i_0=0;//go to firs value of vector
//OK=0;//enable pin 9
}
// if(i_1>105){
//  i_1 = 0;
//}

x=(sinPWM_0[i_0]*(level+level_rand))/level_max;// x take the value from vector corresponding to position i(i is zero indexed)

//i_0=i_0+1;// go to the next position
lost_count++;
if(lost_count>lost){
  i_0=i_0+3;
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

  if (j > 666) {
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
