#include <LiquidCrystal.h>                //librería de display lcd
#define TONE 100                          //frecuencia tono final
#define TONE1 50                          //frecuencia conteo regresivo
#define INTERVALO1 250                    //tiempo de sonido conteo regresivo
#define INTERVALO 1000                    //tiempo sonido final
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);   //inicializar librería
int buzz = 6;                             //pin buzzer
int relay = 5;                            //Pin relé

//imprime horas, minutos y segundos en el LCD
int lcdHoras = 0;
int lcdMinutos = 0;
int lcdSegundos = 0;

int totalSegundos = 0;    //tiempo total en segundos
int mensaje= 0;           //limite mensaje de bienvenida
//int start = A2;           //pulsador para empezar el contador
int start = 4; 
int empieza = 1024;

//pulsadores horas, minutos y segundos
int btnHoras = A5;
int btnMinutos = A4;
int btnSegundos = A3;

//almacenamiento de valor del pulsador
int varbtnHoras = 0;
int varbtnMinutos = 0;
int varbtnSegundos = 0;

void setup()
{
   lcd.begin(16, 2);              //inicializamos LCD con numero de col y row

   //cofiguramos pines, buzzer - salida, pulsadores - entrada
   pinMode(relay, OUTPUT);
   pinMode(buzz, OUTPUT);
   pinMode(btnHoras, INPUT);
   pinMode(btnMinutos, INPUT);
   pinMode(btnSegundos, INPUT);
   //pinMode(start, INPUT);
   pinMode(start, INPUT_PULLUP);

   
   //digitalWrite(relay, LOW);  //apagamos el relé
   
   mensaje = 0;
   empieza = 1024;
   
   //inicializamos variables de almacenamiento de pulsadores
   varbtnHoras = 1;
   varbtnMinutos = 1;
   varbtnSegundos = 1;
}
void loop()
{
     if(mensaje==0)
     {
       //impresion mensaje de inicio
       lcd.setCursor(0,0);
       lcd.print("TEMPORIZADOR");
       lcd.setCursor(1,1);
       lcd.print("ESPERE...");
       delay(2500);
       mensaje = 1;
       lcd.clear();
     }
     do                  
     {
       varbtnHoras = analogRead(btnHoras);        //lee boton horas
       varbtnMinutos = analogRead(btnMinutos);    //lee boton minutos
       varbtnSegundos = analogRead(btnSegundos);  //lee boton segundos
       if(varbtnHoras > 0)    //si se pulsa el boton aumenta la hora
       {
        lcdHoras = lcdHoras + 1 ;
        delay(250);
       } 
        if(varbtnMinutos > 0) //si se pulsa el boton aumenta minutos
       {
         lcdMinutos = lcdMinutos + 1;
         if(lcdMinutos == 60) lcdMinutos = 0;
         delay(250);
       } 
        if(varbtnSegundos > 0)  //si pulsa el boton aumenta segundos
       {
         lcdSegundos = lcdSegundos + 1;
         if(lcdSegundos == 60) lcdSegundos = 0;
         delay(250);
       } 
       lcd.setCursor(0,0);
       lcd.print("Configure el tiempo");
       lcd.setCursor(4,1);

       //imprime el tiempo que se está configurando
      if (lcdHoras < 10) lcd.print("0");
       lcd.print(lcdHoras);
       lcd.print(":");
      if (lcdMinutos < 10) lcd.print("0");
       lcd.print(lcdMinutos);
       lcd.print(":");
      if (lcdSegundos < 10) lcd.print("0");
       lcd.print(lcdSegundos);
     } while(digitalRead(start) == HIGH);//while(analogRead(start) == 0);   //la configuracion se repite hasta que empezemos el temporizador
     totalSegundos = lcdSegundos + (lcdMinutos * 60) + (lcdHoras * 60 * 60);  //convierte la configuracion a segundos
      digitalWrite(relay, HIGH);  //Encendemos el relé una vez configurado el tiempo
      
      //cuando empieze el temporizador
      while (totalSegundos > 0)
      {
        delay (1000);
        
        totalSegundos--;   
        lcdHoras = ((totalSegundos / 60)/ 60);
        lcdMinutos = (totalSegundos / 60) % 60;
        lcdSegundos = totalSegundos % 60;
        lcd.setCursor(0,0);
        lcd.print("Tiempo restante");
        lcd.setCursor(4,1);
        if (lcdHoras < 10) lcd.print("0");
        lcd.print(lcdHoras);
        lcd.print(":");
        if (lcdMinutos < 10) lcd.print("0");
        lcd.print(lcdMinutos);
        lcd.print(":");
        if (lcdSegundos < 10) lcd.print("0");
        lcd.print(lcdSegundos);
          if(totalSegundos <= 30){
            sonarTono(TONE1,INTERVALO1);//Llamamos el buzzer desde los 30 segundos
          }
          if (totalSegundos == 0)
          {          
             while(1)
             {              
                  lcd.clear();
                  lcd.setCursor(5,0);
                  lcd.print("Tiempo");
                  lcd.setCursor(3,1);
                  lcd.print("Finalizado");
                  digitalWrite(relay, LOW); //apagamos el relé cuando finalice la cuenta regresiva
                  sonarTono(TONE,INTERVALO); //llamamos al buzzer
                  lcd.setCursor (0, 1);
                  for (int i = 0; i < 16; ++i)
                  {
                    lcd.write(' ');
                  }
                  break;
             }     
          }
     }
}
//hace sonar el buzzer
void sonarTono(int tono, int duracion)
  {
    tone(buzz,tono,duracion);
    delay(duracion);
  }
