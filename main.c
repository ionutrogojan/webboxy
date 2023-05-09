#define ARRAY_LENGTH(array)  (sizeof(array) / sizeof((array)[0]))

#include <stdio.h>
#include "lib/weblink.h"

int main() {
	char* links[] = {
		"https://www.linkedin.com/feed/",
		"https://itch.io/dashboard",
		"https://twitter.com/home",
		"https://mail.google.com/mail/u/0/#inbox",
		"https://www.youtube.com/"
	};
	for (int i = 0; i < ARRAY_LENGTH(links); i++) {
		switch (open_link(links[i])) {
			case 0:
				printf("Success: Link \"%s\" opened\n", links[i]);
				break;
			case 1:
				printf("Error: Link \"%s\" invalid\n", links[i]);
				break;
			default:
				printf("Error: Unable to find a provider\n");
				break;
		}
	}
	return 0;
}

// valgrind --leak-check=full /path/to/bin