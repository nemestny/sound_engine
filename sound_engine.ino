
/*
  Пример для мега и Уно.
  позволяет менять диапазона частот:
  1 Гц - 2 мГц (2000000 Гц) на 16-битных таймеров
  31 Гц - 2 мГц (2000000 Гц) на  8-битных таймеров
  Стандартная частота ШИМ ардуины 500Гц.
  pwmWriteHR() может использоваться пины: на Uno (9 и 10) на Мега (2,3, 5, 6, 7, 8, 11, 12, 44, 45, и 46)
*/
#include <PWM.h>
int speaker = 9; // пин, светодиод
int frequency_min = 1; // частота  1 - 2000000 (Гц)  минимальная частота
int frequency_max = 300; //максимальная частота
int level_min = 0;   // частота ШИМ (0-255) минимальная громкость
int level_max = 40; // максимальная громкость
int frequency = frequency_min; //текущая частота
int level = level_min; //текущая громкость
int input = A0; // вход для управления

void setup() {
  InitTimersSafe();                         //инициализируем все таймеры, кроме 0,
  //SetPinFrequencySafe(speaker, frequency);    //устанавливает частоту для указанного pin
  SetPinFrequency(speaker, frequency);          //устанавливает частоту для указанного pin
  pinMode(input, INPUT); //вход для управления
//  TCCR1A = TCCR1A & 0xe0 | 3;
//  TCCR1B = TCCR1B & 0xe0 | 0x0c; 
}

void loop() {
/*  frequency += 10;

  if (frequency > 1000) {
    frequency = 50;
  }
*/
  if (digitalRead(input)==HIGH){
      level += 1; //увеличение громкости
      frequency +=5; //увеличение частоты
      if (level > level_max) {
          level = level_max;
        }
      if (frequency > frequency_max){
          frequency = frequency_max;
        }
    } else {
      level -= 1; //уменьшение громкости
      frequency -=5; //уменьшение частоты
      if (level < level_min) {
          level = level_min;
        }
      if (frequency < frequency_min){
          frequency = frequency_min;
        }
      }

  SetPinFrequency(speaker, frequency);
  pwmWriteHR(speaker, level);     //0-255   используйте эту функцию вместо analogWrite
  delay(100);//задержка цикла
  //или
  //pwmWriteHR(speaker, levelHR); //0-65536 используйте эту функцию вместо analogWrite
  //  pwmWrite(speaker,0);
}
