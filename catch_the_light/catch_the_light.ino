int led = 12;
int led1 = 11;
int led2 = 10;
int led3 = 9;
int led4 = 8;
int led5 = 7;
int led6 = 6;
int buttonPin = 5;
int score = 0;

boolean lose = false;

int currentLight = 1;
int lightDirection = 1;

int waitTime = 450;
unsigned long prevMillis = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buttonPin, INPUT);
}



void loop()
{
  while(lose == false && score < 4)
  {
    unsigned long timePassed = millis();

    if(digitalRead(buttonPin))
    {
      if(currentLight == 1 || currentLight == 7)
      {
        score++;
        waitTime = waitTime - 75;
        delay(1000);
        setLights(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
        delay(500);
        setLights(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
        delay(200);
        setLights(LOW, LOW, HIGH, LOW, HIGH, LOW, LOW);
        delay(200);
        setLights(LOW, HIGH, LOW, LOW, LOW, HIGH, LOW);
        delay(200);
        setLights(HIGH, LOW, LOW, LOW, LOW, LOW, HIGH);
        delay(200);
        setLights(LOW, HIGH, LOW, LOW, LOW, HIGH, LOW);
        delay(200);
        setLights(LOW, LOW, HIGH, LOW, HIGH, LOW, LOW);
        delay(200);
        setLights(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
        delay(250);

        if(score == 1)
        {
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(750);
        }
        else if(score == 2)
        {
          setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
          delay(750);
        }
        else if(score == 3)
        {
          setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
          delay(750);
        }
        else if(score == 4)
        {
          setLights(HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
          delay(500);
          setLights(HIGH, HIGH, HIGH, HIGH, LOW, LOW, LOW);
          delay(750);
          break;
        }

        // this will only run if you haven't won yet
        setLights(HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW);
        delay(1000);
        setLights(HIGH, HIGH, LOW, LOW, LOW, LOW, LOW);
        delay(1000);
        setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
        delay(1000);
      }
      else
      {
        lose = true;
        break;
      }
    }

    if(timePassed - prevMillis > waitTime)
    {
      prevMillis = timePassed;

      if(lightDirection == 1)
      {
        if(currentLight == 1)
        {
          setLights(LOW, HIGH, LOW, LOW, LOW, LOW, LOW);
          currentLight = 2;
        }
        else if(currentLight == 2)
        {
          setLights(LOW, LOW, HIGH, LOW, LOW, LOW, LOW);
          currentLight = 3;
        }
        else if(currentLight == 3)
        {
          setLights(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
          currentLight = 4;
        }
        else if(currentLight == 4)
        {
          setLights(LOW, LOW, LOW, LOW, HIGH, LOW, LOW);
          currentLight = 5;
        }
        else if(currentLight == 5)
        {
          setLights(LOW, LOW, LOW, LOW, LOW, HIGH, LOW);
          currentLight = 6;
        }
        else if(currentLight == 6)
        {
          setLights(LOW, LOW, LOW, LOW, LOW, LOW, HIGH);
          currentLight = 7;
          lightDirection = -1;
        }
      }
      else if(lightDirection == -1)
      {
        if(currentLight == 2)
        {
          setLights(HIGH, LOW, LOW, LOW, LOW, LOW, LOW);
          currentLight = 1;
          lightDirection = 1;
        }
        else if(currentLight == 3)
        {
          setLights(LOW, HIGH, LOW, LOW, LOW, LOW, LOW);
          currentLight = 2;
        }
        else if(currentLight == 4)
        {
          setLights(LOW, LOW, HIGH, LOW, LOW, LOW, LOW);
          currentLight = 3;
        }
        else if(currentLight == 5)
        {
          setLights(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
          currentLight = 4;
        }
        else if(currentLight == 6)
        {
          setLights(LOW, LOW, LOW, LOW, HIGH, LOW, LOW);
          currentLight = 5;
        }
        else if(currentLight == 7)
        {
          setLights(LOW, LOW, LOW, LOW, LOW, HIGH, LOW);
          currentLight = 6;
        }
      }
    }
  }
  delay(1000);

  for(int x = 0; x < 3; x++)
  {
    setLights(LOW, LOW, LOW, LOW, LOW, LOW, LOW);
    delay(250);

    if(currentLight == 1 || currentLight == 7)
    {
      setLights(HIGH, LOW, LOW, LOW, LOW, LOW, HIGH);
    }
    else if(currentLight == 2)
    {
      setLights(LOW, HIGH, LOW, LOW, LOW, LOW, LOW);
    }
    else if(currentLight == 3)
    {
      setLights(LOW, LOW, HIGH, LOW, LOW, LOW, LOW);
    }
    else if(currentLight == 4)
    {
      setLights(LOW, LOW, LOW, HIGH, LOW, LOW, LOW);
    }
    else if(currentLight == 5)
    {
      setLights(LOW, LOW, LOW, LOW, HIGH, LOW, LOW);
    }
    else if(currentLight == 6)
    {
      setLights(LOW, LOW, LOW, LOW, LOW, HIGH, LOW);
    }
    delay(250);
  }

  if(currentLight == 1 || currentLight == 7)
  {
    for(int x = 0; x < 10; x++)
    {
      setLights(LOW, HIGH, HIGH, HIGH, HIGH, HIGH, LOW);
      delay(150);
      setLights(HIGH, LOW, LOW, LOW, LOW, LOW, HIGH);
      delay(150);
    }
  }
}

void setLights(int light1, int light2, int light3, int light4, int light5, int light6, int light7)
{
  digitalWrite(led, light1);
  digitalWrite(led1, light2);
  digitalWrite(led2, light3);
  digitalWrite(led3, light4);
  digitalWrite(led4, light5);
  digitalWrite(led5, light6);
  digitalWrite(led6, light7);
}

