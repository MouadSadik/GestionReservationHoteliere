#include <stdio.h>
#include <malloc.h>
#include "Chaine.h"
#include <ctype.h>




char* SaisirChaine()
{
	int c, nbc = 0;
	char * str = NULL;
	
	while((c = getchar()) != '\n')
	{
		str=(char*)realloc(str, (nbc+1)*sizeof(char));
		str[nbc++] = c;
	}
	if(nbc > 0)
	{
		str = (char*)realloc(str, (nbc+1)*sizeof(char));
		str[nbc] = '\0';
	}
	
	return str;
}


int IsPhoneNumber(const char *phone)
{
    // Check if the phone number contains only digits, spaces, parentheses, or hyphens
    for (int i = 0; phone[i] != '\0'; i++)
    {
        if (!(isdigit(phone[i]) || phone[i] == ' ' || phone[i] == '-' || phone[i] == '(' || phone[i] == ')'))
        {
            return 0;  // Invalid phone number
        }
    }
    return 1;  // Valid phone number
}


int IsEmail(const char *email)
{
    // Check if the email contains "@gmail.com" at the end
    const char *gmailDomain = "@gmail.com";
    size_t emailLen = strlen(email);
    size_t domainLen = strlen(gmailDomain);

    if (emailLen > domainLen && strcmp(email + emailLen - domainLen, gmailDomain) == 0)
    {
        // Check if the email contains '@' and is not just "@gmail.com"
        const char *atSign = strchr(email, '@');
        if (atSign != NULL && atSign != email)
        {
            return 1;  // Valid Gmail email
        }
    }
    return 0;  // Invalid email
}

int IsWebsite(const char *website)
{
    // Check if the website starts with "http://" or "https://"
    if (strncmp(website, "http://", 7) == 0 || strncmp(website, "https://", 8) == 0)
    {
        // Check if the website contains at least one dot (.)
        if (strchr(website, '.'))
        {
            return 1;  // Valid website
        }
    }
    return 0;  // Invalid website
}
