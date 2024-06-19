#include <stdio.h>

/*
 * Define to enable or disable engine temperature controller.
 * set following line to 1 to enable the controller .
 */
#define WITH_ENGINE_TEMP_CONTROLLER 1

//Define minimum and maximum values for room temperature
#define MIN_ROOM_TEMP 10
#define MAX_ROOM_TEMP 30

//Define minimum and maximum values for engine temperature
#define MIN_ENGINE_TEMP 100
#define MAX_ENGINE_TEMP 150

//Define speeds according to traffic light
#define REDLIGHT 0
#define YELLOWLIGHT 30
#define GREENLIGHT 100

//Define states for AC and engine controller
#define ON 1
#define OFF 0

//Functions prototype
char options(void);
void turn_on_engine(void);
void turn_off_engine(void);
void quit(void);
void Traffic_light(float *speed);
void Room_temperature(float * room_temp,int * ac_state);
void Engine_temperature(float * engine_tem, int *controller_state);

int main(void) {

	while(1){ //to keep main vehicle menu displayed

		char input=options();
		switch(input){

		case 'A':
		case 'a':
			turn_on_engine(); //calling turn_on_engine function
			break;

		case 'B':
		case 'b':
			turn_off_engine();//calling turn_off_engine function
			break;

		case 'C':
		case 'c':
			quit(); //calling quit function
			return 0; // exit program

		default:
			printf("Enter valid option\n\n");//checks for invalid input from user
		}
	}
}

char options(void){
	char input;
	//obtain what he/she wants to do at main menu
	printf("a. Turn on the vehicle engine\n");
	printf("b. Turn off the vehicle engine\n");
	printf("c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c",&input);
	return input;
}

void turn_off_engine(void){
	printf("Turn off the vehicle engine\n\n");

}

void turn_on_engine(void){
	char input;
	/*initialize speed,room temperature,engine temperature
	 AC state and engine temperature controller state*/
	float speed=70;
	float room_temp=20;
	int ac_state=0;

#if ( WITH_ENGINE_TEMP_CONTROLLER==1)
	float engine_temp=90;
	int engine_controller_state=0;
#endif

	while(1){// to keep (turned on engine) menu displayed
		//obtain what he/she wants to do after turning on the engine
		printf("a. Turn off the engine \n");
		printf("b. Set the traffic light color. \n");
		printf("c. Set the room temperature (Temperature Sensor) \n");

#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		printf("d. Set the engine temperature (Engine Temperature Sensor) \n\n");
#endif
		fflush(stdout);
		scanf(" %c",&input);

		switch(input){

		case 'A':
		case 'a':
			return; //exit from turn_on_engine function and return to main vehicle menu

		case 'B':
		case 'b':
			Traffic_light(&speed); //calling Traffic_light function
			break;

		case 'C':
		case 'c':
			Room_temperature(&room_temp,&ac_state); //calling Room_temperature function
			break;

#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		case 'd':
			Engine_temperature(&engine_temp,&engine_controller_state); //calling Engine temperature function
			break;
#endif
		default:
			printf("Enter valid option\n\n");//checks for invalid input from user
			continue;//to skip displaying states when entering invalid option
		}

		// checking if speed = 30 km/hr
		if(speed==30){
			ac_state=1;
			room_temp=(room_temp*1.25)+1;

#if( WITH_ENGINE_TEMP_CONTROLLER==1)
			engine_temp=(engine_temp*1.25)+1;
			engine_controller_state=1;
#endif
		}

		//Display current vehicle states
		printf("Engine state: ON\n");// engine state

		if(ac_state==ON){ //AC STATE
			printf("AC: ON\n");
		}
		else
		{
			printf("AC: OFF\n");
		}
		printf("Vehicle speed: %g Km/hr\n",speed);//vehicle current speed

		printf("Room temperature: %g°C\n",room_temp);//current room temperature

#if (WITH_ENGINE_TEMP_CONTROLLER==1)
		if(engine_controller_state==ON){ //ENGINE CONTROLLER STATE
			printf("Engine temperature controller state: ON\n");
		}
		else
		{
			printf("Engine temperature controller: OFF\n");
		}
		printf("Engine temperature: %g°C\n\n",engine_temp);//current engine temperature
#endif
	}

}

void Traffic_light(float *speed){
	char input;


	printf("Enter the required color\n");
	while(1){// Keep asking until valid input is provided in case the user entered invalid option
		fflush(stdout);
		scanf(" %c",&input);
		//setting speed value according to traffic light color

		switch(input){

		case 'G':
		case 'g':
			*speed=GREENLIGHT;
			return;// exit loop when valid input is provided

		case 'O':
		case 'o':
			*speed=YELLOWLIGHT;
			return;// exit loop when valid input is provided

		case 'R':
		case 'r':
			*speed=REDLIGHT;
			return;// exit loop when valid input is provided

		default:
			printf("Enter a valid color 'g', 'o', or 'r'\n");//checks for invalid input from user
		}
	}
}

void Room_temperature(float *room_temp,int * ac_state){
	float input;
	printf("Enter the required room temperature\n");
	fflush(stdout);
	scanf("%f",&input);
	//setting AC state according to room temperature

	if((input<MIN_ROOM_TEMP) || (input>MAX_ROOM_TEMP)){
		*room_temp=20;
		*ac_state=1;
	}
	else
	{
		*ac_state=0;
		*room_temp=input;
	}

}

void Engine_temperature(float * engine_temp, int *controller_state){
	float input;
	printf("Enter the required engine temperature\n");
	fflush(stdout);
	scanf("%f",&input);
	//setting engine controller state according to engine temperature

	if((input<MIN_ENGINE_TEMP) || (input>MIN_ENGINE_TEMP)){
		*engine_temp=125;
		*controller_state=1;
	}
	else
	{
		*controller_state=0;
		*engine_temp=input;
	}

}

void quit()
{
	printf("Quit the system\n");
}
