#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define REST_INPUT_MAX_LENGTH 180
#define METHOD_NAME_SIZE 30
#define TRUE 1
#define FALSE 0

typedef enum
{
	CMD_VALIDATE = 10
	
}RESTCommand;

typedef struct restinput
{
	int command;
	char *data;
	
}RESTInputStruct;

int validate_comment( char *comment)
{
	//returns true or FALSE;
}
void execute_command(RESTInputStruct RESTInput)
{
		switch(RESTInput.command)
		{
			case 0:
				validate_comment(RESTInput.data);
				break;
			default:
				break;
		}	
}

RESTInputStruct parse_rest_api_command(char *input_rest_api)
{
	char *RESTContract = "https://targetcorp/api/v1/feedback?method=";
	char *method = malloc(METHOD_NAME_SIZE);
	int i, position, cmd_position=0;
	
	RESTInputStruct RestInput;
	
	printf("strlength %d\n", strlen(RESTContract));
	if (strncmp(input_rest_api, RESTContract, strlen(RESTContract)) == 0)
	{	
		printf("%s\n", "Strings matched");
		for (position = strlen(RESTContract); position <= strlen(input_rest_api); ++ position)
		{	
			if (input_rest_api[position] == '=')
				method[cmd_position] = '\0';
			else
				method[cmd_position++] = input_rest_api[position];
		}	
		if (strcmp(method, "check") == 0) 
		{
			RestInput.command = CMD_VALIDATE;
			for (i =0; i<strlen(input_rest_api); ++i)
			{	
				RestInput.data[i] = input_rest_api[position++];
			}	
		}	
		else	
		{
			RestInput.command = 0;
		}	
	}		
	
	/* Parse the query paramenters and identify the command and arguments */
	return RestInput;
}

void main()
{
	char *RESTinput_string;
	RESTInputStruct RESTInput;
	
	RESTinput_string = malloc(REST_INPUT_MAX_LENGTH);
	
	/** REST API input */
	/* Example https://targetcorp/api/v1/feedback?method=check&comment="Comment typed by user"*/
	
	printf("%s", "Enter the REST API to validate");
	scanf("%s", RESTinput_string);
	
	RESTInput = parse_rest_api_command(RESTinput_string);
	execute_command(RESTInput);

}