unsigned long previo, actual;
int EstadoBoton = 0;

void test() {
  if (digitalRead (2) == 0) {
    // el operador % significa modulo
    EstadoBoton = (EstadoBoton + 1) % 3;
    delay(200);
  }
  switch (EstadoBoton)  {
    case 0:
      digitalWrite(6, HIGH);//A
      digitalWrite(7, LOW);//B
      digitalWrite(8, HIGH);//C
      digitalWrite(9, HIGH);//D
      digitalWrite(10, LOW);//E
      digitalWrite(11, HIGH);//F
      digitalWrite(12, HIGH);//G
      break;
    case 1:
      digitalWrite(6, HIGH);//A
      digitalWrite(7, LOW);//B
      digitalWrite(8, HIGH);//C
      digitalWrite(9, HIGH);//D
      digitalWrite(10, HIGH);//E
      digitalWrite(11, HIGH);//F
      digitalWrite(12, HIGH);//G
      break;
    case 2:
      digitalWrite(6, LOW);//A
      digitalWrite(7, LOW);//B
      digitalWrite(8, LOW);//C
      digitalWrite(9, HIGH);//D
      digitalWrite(10, HIGH);//E
      digitalWrite(11, HIGH);//F
      digitalWrite(12, LOW);//G
      break;
  }
}


void setup() //En la función setup() únicamente se inicializa el puerto Serial y se configuran los pines digitales.
{
  Serial.begin(9600);
  //Definimos los pines
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
}

void loop()//aca es donde se calcula el tiempo que tarda la función en ejecutarse.
{

  previo = micros();
  test();
  actual = micros();

  Serial.print( "La función tardó:" );
  Serial.print( actual - previo ); //se restan ambos valores para obtener y enviar el tiempo en microsegundos al monitor serie.
  Serial.println( " us" );

  delay(200);
}
//La función tardó:44 us
//La función tardó:40 us
//La función tardó:44 us
//La función tardó:44 us
//La función tardó:44 us
//La función tardó:40 us
//La función tardó:44 us
//La función tardó:44 us
//La función tardó: 200064 us
//La función tardó: 200064 us
//La función tardó: 200064 us
//La función tardó: 200068 us
//La función tardó: 200064 us
//La función tardó: 200060 us
//La función tardó: 200064 us
//La función tardó: 200064 us
//La función tardó: 200064 us

//Conclusion: el codigo es mas facil de entender pero su tamaño es mayor y su tiempo de ejecucion es mas lento
