BLYNK_WRITE(V0)
{
  int pinValue = param.asInt();
  if(pinValue == 1){
//    Serial.println("led is HIGH");
    digitalWrite(relay, LOW);
    Blynk.virtualWrite(V1, 1);
  }
  else{
//    Serial.println("led is LOW");
    digitalWrite(relay, HIGH);
    Blynk.virtualWrite(V1, 0);
  }
}

void myTimerEvent()
{
  bool result = Blynk.connected();

  if(result){
    digitalWrite(connectedLed, HIGH);
  }
  else{
    digitalWrite(connectedLed, LOW);
  }

  if(digitalRead(relay) == 1){
    Blynk.virtualWrite(V1, 0);
//    Blynk.virtualWrite(V0, 1);
  }
  else{
    Blynk.virtualWrite(V1, 1);
//    Blynk.virtualWrite(V0, 0);
  }
//  Serial.println(result);
  
}
