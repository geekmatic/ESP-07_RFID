
String inputString = "";         // переменная типа string для сохранения входных данных
boolean stringComplete = false;  // флаг данные получены 
int IN1 = 3; // Input3 подключен к выводу 5 
int IN2 = 4;
int EN = 2;
int PWM = 6;

void setup() {
  Serial.begin(9600);
  inputString.reserve(200);
  pinMode (EN, OUTPUT); 
  pinMode (IN1, OUTPUT);
  pinMode (IN2, OUTPUT);
  pinMode (PWM, OUTPUT);
  digitalWrite (EN, HIGH);
  digitalWrite (IN1, HIGH);
  digitalWrite (IN2, LOW);
}


void loop() {
  serialEvent(); //вызов нашей коммуникационной функции


  // печатаем ответ в COM-порт и поворачиваем серво на заданный угол:
  if (stringComplete) {
    Serial.println(inputString);


    analogWrite(PWM, inputString.toInt());


    // обнуляем строковую переменную:
    inputString = "";
    stringComplete = false;
  }
}


void serialEvent() {
  while (Serial.available()) {
    // получить новый байт данных:
    char inChar = (char)Serial.read();


    // добавить новый байт к строковой переменной inputString:
    inputString += inChar;


    // если входной символ является новой строкой, взвести флаг
    // что бы основной цикл обработал принятую команду:
    if (inChar == '\n') {
      stringComplete = true;
    }


  }
}
