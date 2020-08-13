#include "split_text.h"
#include <stdlib.h>
#include <string.h>

const char delim = '_';

int get_char_count(char *text, char delim)
{
	int count = 0;
	do
	{
		text = strchr(text, delim);
	} while (text != NULL && ++count && ++text);
	return count;
}

char** split_text(char *text)
{
	char **broken = NULL;
	char *l_ptr = text, *t_ptr = text;
	int index = 0;
	size_t w_size;
	int pieces_count = get_char_count(text, delim) + 1;
	
	broken = calloc(pieces_count + 1, sizeof(char*));
	while(t_ptr != NULL && *t_ptr != '\0')
	{
		if(*t_ptr == delim)
		{
			if(t_ptr - l_ptr == sizeof(char))
			{
				// broken = realloc(broken, --pieces_count + 1);
			} else {
				w_size = t_ptr - l_ptr;
				broken[index] = malloc(w_size + 1);
				strncpy(broken[index], l_ptr, w_size);
				index++;
			}
			l_ptr = t_ptr + 1;
			t_ptr = l_ptr;
		} else {
			t_ptr++;
		}
	}
	w_size = t_ptr - l_ptr;
	broken[index] = malloc(w_size + 1);
	strncpy(broken[index], l_ptr, w_size);

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
