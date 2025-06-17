#define opening_gate  2
#define closeing_gate 3
#define bt_opened     10
#define bt_closed     11
#define motor_c    6
#define motor_ac   7

#define bt_halt A2
#define bt_continue A1

#define opend   0
#define closed  1
#define opening 2
#define closing 3

#define object_sensor A3


int gate_status=opening;

void setup()
{
  pinMode(motor_c, OUTPUT);
  pinMode(motor_ac, OUTPUT);
  pinMode(opening_gate, INPUT_PULLUP);
  pinMode(closeing_gate, INPUT_PULLUP);
  pinMode(bt_opened, INPUT_PULLUP);
  pinMode(bt_closed, INPUT_PULLUP);
  
  pinMode(object_sensor, INPUT_PULLUP);
  
  pinMode(bt_halt, INPUT_PULLUP);
  pinMode(bt_continue, INPUT_PULLUP);
  
  Serial.begin(9600);
}





void loop(){ 
  if(digitalRead(opening_gate)==0){
  		if(gate_status!=opend){
    		gate_opening();
        	gate_status=opening;
      		Serial.println("gate is opening");
     		}
    	else
      		Serial.println("gate is already opened");
  		}
    
    else if(digitalRead(bt_opened)==0){
      		if(gate_status==opening ||gate_status==opend  ){
        		gate_stop();
      			gate_status=opend;
              	Serial.println("gate is opened");
            	}
      		else
              	Serial.println("ERROR");
            }
  if(digitalRead(closeing_gate)==0){
  		if(gate_status!=closed){
    		gate_opening();
        	gate_status=closing;
      		Serial.println("gate is closing");
    		}
    	else
      		Serial.println("gate is already closed");
  		}
  	else if((digitalRead(bt_closed )==0)){
    		if(gate_status ==closing || gate_status ==closed){
      			gate_stop();
      			gate_status=closed;
      			Serial.println("gate is closed");
    			}
      	else
        	Serial.println("ERROR");
          
  		}
  
  
  
	if((digitalRead(bt_halt)==0)){
    	if(gate_status ==closing ||gate_status==opening ){
  			gate_stop();
      		Serial.println("gate is stoped");
    		}
  		else
          Serial.println("gate is already stoped");
      }
    else if((digitalRead(bt_continue)==0)){
    	if(gate_status==opening ){
          	gate_opening();
          	Serial.println("gate is opening");
    		}
    else if((digitalRead(bt_continue)==0)){
        if(gate_status==closing){
        	gate_closing();
        	Serial.println("gate is closing");
			}
      else
        Serial.println("NO FUNCTION");
  
        }
  		 
	}
  if(digitalRead(object_sensor)==0){ 
    	if(gate_status==closing){
      		gate_stop();
       		Serial.println("object detected");
    		}
  		} 
  
}

void gate_stop(){
  digitalWrite(motor_c, 0);
  digitalWrite(motor_ac, 0);
}

void gate_opening(){
  digitalWrite(motor_c, 1);
  digitalWrite(motor_ac, 0);
}

void gate_closing(){
  digitalWrite(motor_c, 0);
  digitalWrite(motor_ac, 1);
 }
  