//Led Pattern[wuerfelnumber][lednumber-1]
byte ledPattern [8][7] = {
    {0, 0, 0, 0, 0, 0, 0},//All off
    {1, 1, 1, 1, 1, 1, 1},//All on
    {0, 0, 0, 1, 0, 0, 0},//1
    {1, 0, 0, 0, 1, 0, 0},//2
    {1, 0, 0, 1, 1, 0, 0},//3
    {1, 0, 1, 0, 1, 0, 1},//4
    {1, 0, 1, 1, 1, 0, 1},//5
    {1, 1, 1, 0, 1, 1, 1}//6
};

void setup() {
    Serial.begin(115200);  
    //Define In and Outputs 
    pinMode(A3, INPUT);
    for(int i = 0; i < 7; i++){
        pinMode(i+2, OUTPUT);
        digitalWrite(i+2, ledPattern[1][i]);
        delay(500);
    }
    delay(2000);
    for(int i = 0; i < 7; i++){
        digitalWrite(i+2, ledPattern[0][i]);
    }
}

void loop() {
    //Check Button
    //Serial.println(analogRead(A3));
    if(analogRead(A3) < 400){
       shuffle();
    }
}

void shuffle(){
    int count = 0;
    while(analogRead(A3) < 600){
        for (int i = 2; i < 8; i++){
            for (int j = 0; j < 7; j++){
                digitalWrite(j+2, ledPattern[i][j]);
            }
            delay(100);
        }
        count++;
    }
    //Get Random Number
    int roll = random(2, 8);
    for (int i = 0; i < 7; i++){
        digitalWrite(i+2, ledPattern[roll][i]);
    }
    delay(2000);
    for(int i = 0; i < 7; i++){
        digitalWrite(i+2, ledPattern[0][i]);
    }
}

int randomNumber(int min, int max, int count){
    int number = 0; 
    List<int> possibleNumbers = new List<int>();

    for(int i = min; i < max; i++){
        possibleNumbers.Add(i);
    }
    
    int pos = count % possibleNumbers.Count;
    number = possibleNumbers[pos];

    return number;
}