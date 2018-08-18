void func_http()
{
  USE_SERIAL.println("func_http");
  if((WiFiMulti.run() == WL_CONNECTED)) {

        HTTPClient http;

        USE_SERIAL.print("begin...\n");
        String str;
        str = "/1.php";
            
    str += "?a=";
    str += String(ind[0]);
    str += String(ind[1]);
    str += String(ind[2]);
    str += String(ind[3]);
    str += String(ind[4]);
    str += String(ind[5]);
    str += String(ind[6]);
    str += String(ind[7]);
    str += ";";
        USE_SERIAL.println(str);
        
        http.begin("bee.in.ua", 80, str); //HTTP
        USE_SERIAL.print(str);
        USE_SERIAL.print("GET...\n");

        // начало соединения и отсылка HTTP заголовка

        int httpCode = http.GET();

        if(httpCode) {

            // HTTP header has been send and Server response header has been handled

            USE_SERIAL.printf("GET... code: %d\n", httpCode);



            // файл найден на сервере

            if(httpCode == 200) {

               String payload = http.getString();

               //USE_SERIAL.println(payload.substring(145,230));
               USE_SERIAL.println(payload);
               parse_dani(payload);
               
              

            }
           http.end(); //HTTP
           
        } else {
            a2 = 9;
            USE_SERIAL.print("[HTTP] GET... failed, no connection or no HTTP server\n");

        }
        send_a_to_uno = 1;
        outSerial.print(a2);
    }
}
  
void parse_dani(String &outstr)
{
  if (outstr.indexOf("a=")>-1){
    outstr = outstr.substring(outstr.indexOf("a=")+2, outstr.length());
  
    a2 = outstr.toInt();
    USE_SERIAL.print("a2=");
    USE_SERIAL.println(a2);
  }
  else a2 = 9;
}


