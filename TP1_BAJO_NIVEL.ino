unsigned long previo, actual;
int EstadoBoton = 0;
#define pin2 2

void test() 
{
  if ( 0 == digitalRead (pin2)) {

    // el operador % significa modulo
    EstadoBoton = (EstadoBoton + 1) % 3;
    delay(200);
  }
  switch (EstadoBoton) {
    case 0: //LETRA S
      PORTD = B01000000;
            //BA;
      PORTB = B00011011;
       //         GFEDC;
      break;
    case 1: //LETRA G
      PORTD = B01000000;
            //BA;
      PORTB = B00011111;
       //         GFEDC;
      break;
    case 2: //LETRA L
      PORTD = B00000000;
            //BA;
      PORTB = B00001110;
       //         GFEDC;
      break;
  }
}
  void setup() //En la función setup() únicamente se inicializa el puerto Serial y se configuran los pines digitales. 
 {
    Serial.begin(9600);
    DDRD = B11000000; //Definimos las salidas, las activamos con un 1, y utilizamos del 6 al 7.
    DDRD = DDRD & B11000111;
    DDRB = B00011111; //Utilizamos las salidas del 8 al 12.
    DDRB = DDRB | B00000000;
  }
 void loop() //aca es donde se calcula el tiempo que tarda la función en ejecutarse. 
 {

  previo = micros();
  test();
  actual = micros();

  Serial.print( "La función tardó:" );
  Serial.print( actual - previo ); //se restan ambos valores para obtener y enviar el tiempo en microsegundos al monitor serie.
  Serial.println( " us" );

  delay(200);
}
//La función tardó:4 us
//La función tardó:4 us
//La función tardó:8 us
//La función tardó:8 us
//La función tardó:8 us
//La función tardó:8 us
//La función tardó:4 us
//La función tardó:8 us
//La función tardó:4 us
//La función tardó:200036 us
//La función tardó:200024 us
//La función tardó:200032 us
//La función tardó:200032 us
//La función tardó:200028 us
//La función tardó:200028 us
//La función tardó:200028 us
//La función tardó:200028 us
//La función tardó:200028 us

//Conclusion: el codigo es mas complejo para entender pero su tiempo de ejecucion y tamaño son menores.
