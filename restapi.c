#include <stdio.h>

#define REST_INPUT_MAX_LENGTH 180
#define TRUE 1
#define FALSE 0

typedef enum
{
	CMD_VALIDATE;	
	
}RESTCommand;

typedef struct restinput
{
	int command;
	void *data;
	
}RESTInputStruct;

validate_comment( char *comment)
{
	//returns true or FALSE;
}
execute_command(RESTInputStruct RESTInput)
{
		switch(RESTInput.RESTCommand)
		{
			case 0:
				validate_comment(RESTInput.data);
				break;
			default:
				break;
		}	
}

RestInput parse_rest_api_command(char *input_rest_api)
{
	/* Parse the query paramenters and identify the command and arguments */
	return ;
}

void main()
{
	char *RESTinput_string;
	RESTInputStruct RESTInput;
	
	RESTinput_string = malloc(REST_INPUT_MAX_LENGTH);
	
	/** REST API input */
	/* Example https://targetcorp/api/v1/feedback/check?comment="Comment typed by user"*/
	printf("Enter the REST API to validate\");
	scanf("%s", RESTinput_string);
	
	RESTInput = parse_rest_api_command(RESTinput_string);
	execute_command(RESTInput);

}