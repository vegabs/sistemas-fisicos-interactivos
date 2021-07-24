# Sistemas Físicos Interactivos 1
Repositorio del curso Sistemas Físicos Interactivos, UPB. 

### A tener en cuenta 🚨
- Los push buttons tienes que tener si o si una resistencia de 10k, esto para que la entrada del microcontrolador esté definida en 0 o 1 y no en un rango en el medio.

## Unidad 1
### Retos
- Ejercicio 5: Realiza un programa que lea el estado de dos switches y encienda solo uno de 4 LEDs (un LED para cada combinación posible de los suiches).
    ``` Arduino
    int sw_a, sw_b;

    void setup()
    {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(8,INPUT);
    pinMode(9,INPUT);
    Serial.begin(9600);
    }

    void loop()
    {
    sw_a = digitalRead(8);
    sw_b = digitalRead(9);

    if(sw_a == 0 && sw_b == 0){
        prender_led(2);
    }
    else if(sw_a == 0 && sw_b == 1){
        prender_led(3);
    }
    else if(sw_a == 1 && sw_b == 0){
        prender_led(4);
    }
    else if(sw_a == 1 && sw_b == 1){
        prender_led(5);
    }
    else{
        Serial.println("No valido!");
    }
    }

    int prender_led(int a){
    for(int i=1; i<=5; i++){
        if(i == a){
        digitalWrite(i,1);
        }
        else{
        digitalWrite(i,0);
        }
    }
    }
    ```
    ![Circuito Ejercicio 5](img/reto_5.jpg)
