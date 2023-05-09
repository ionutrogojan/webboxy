// MIT License
// Copyright (c) 2023 Ionut Rogojan
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#define _GNU_SOURCE
#define ARRAY_LENGTH(array)  (sizeof(array) / sizeof((array)[0]))

#include <stdio.h>
#include <stdlib.h>
#include "weblink.h"


const char* provider(void) {
	char* provider_list[] = {
		"www-browser",
		"x-www-browser",
		"gnome-www-browser",
		"xdg-open"
	};
	char* cmd;
	for (int i = 0; i < ARRAY_LENGTH(provider_list); i++) {
		int mem_cmd = asprintf(&cmd, "which %s > /dev/null 2>&1", provider_list[i]);
		if (system(cmd) == 0 && mem_cmd != -1) {
			free(cmd);
			return provider_list[i];
		}
		free(cmd);
	}
	return NULL;
}

int open_link(char link[]) {
	const char* open = provider();
	if (open == NULL) {
		return -1;
	}
	char* cmd;
	int mem_cmd = asprintf(&cmd, "%s %s > /dev/null 2>&1", open, link);
	if (mem_cmd == -1) {
		return mem_cmd;
	}
	int res = system(cmd);
	free(cmd);
	return res;
}