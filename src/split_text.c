#include "split_text.h"
#include <stdlib.h>
#include <string.h>

const char delim = '_';

int get_pieces_count(char *text)
{
	int count = 0;
	char * prev;
	do
	{
		// set start of current selection
		prev = text;
		// find next delimiter
		text = strchr(text, delim);
		// If not end of string
		if (text != NULL)
		{
			// If some characters were selected
			if (text - prev > 0)
			{
				// Increment count
				count++;
			}
			// Or proceed
		}
		// finally move text pointer
	} while (text != NULL && ++text);

	// If last part is word
	if (strlen(prev) > 0)
	{
		// Increment count
		count++;
	}

	return count;
}

char** split_text(char *text)
{
	char **broken = NULL;
	char * prev;
	int index = 0;
	size_t w_size;
	int pieces_count = get_pieces_count(text);

	broken = calloc(pieces_count + 1, sizeof(char*));
	do
	{
		// set start of current selection
		prev = text;
		// find next delimiter
		text = strchr(text, delim);
		// If not end of string
		if (text != NULL)
		{
			// If some characters were selected
			if (text - prev > 0)
			{
				w_size = text - prev;
				broken[index] = malloc(w_size + 1);
				strncpy(broken[index], prev, w_size);
				broken[index][w_size] = '\0';
				// Increment index
				index++;
			}
			// Or proceed
		}
		// finally move text pointer
	} while (text != NULL && ++text);

	// If last part is word
	w_size = strlen(prev);
	if (w_size > 0)
	{
		// Copy that too
		broken[index] = malloc(w_size + 1);
		strncpy(broken[index], prev, w_size);
		broken[index][w_size] = '\0';
	}

	return broken;
}

void free_pieces(char** pieces)
{
	for(int i = 0; pieces[i] != NULL; i++)
	{
		free(pieces[i]);
	}
	free(pieces);
}
